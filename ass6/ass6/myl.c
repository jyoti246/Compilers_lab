#include "myl.h"
#include <stdio.h>
#define BUFF 20
#define zero '0'
#define MAXLEN 100

int printStr(char *buff){
	int bytes = 0;
	char *temp = buff;
	while (*temp){
		bytes++;
		temp++;
	}
	__asm__ __volatile__ (
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:
		:"S"(buff), "d"(bytes));
	return bytes;
}

int printInt(int n){
	char buff[BUFF];
	int i = 0, j, k, bytes;
	if (n == 0){
		buff[i++] = zero;
	}
	else{
		if (n < 0){
			buff[i++] = '-';
			n = -n;
		}
		// reversed string 
		while (n){
			int d = n%10;
			buff[i++] = (char)(zero+d);
			n /= 10;
		}
		j = 0;
		if (buff[j] == '-')j++;
		k = i -1 ;
		while (j < k){
			char temp = buff[j];
			buff[j++] = buff[k];
			buff[k--] = temp;
		}
	}
	bytes = i;
	__asm__ __volatile__ (
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:
		:"S"(buff), "d"(bytes));
	return bytes;
}

// restrict to 5-decimal place precision
int printFlt(float f){
	char ch[BUFF];
	if (f == 0){
		*ch = zero;
		*(ch+1) = '.';
		for (int i = 2; i <= 6; i++){
			*(ch+i) = zero;
		}
		*(ch+7) = '\n';
		*(ch+8) = '\0';
		printStr(ch);
		return OK;
	}
	int i = 0;
	if(f<0)
	{
		ch[i++]='-';
		f=-f;
	}
		
	int x = (int)f;
	float y = f - x;
	y *= 1000000;
	int rgt = y;
	while(x)
	{
		int d = x%10;
		ch[i++] = (char)(d+zero);
		x /= 10;
	}

	int j = 0;
	if (ch[j] == '-')
		j++;
	int k = i -1 ;
	while (j < k){
		char temp = ch[j];
		ch[j++] = ch[k];
		ch[k--] = temp;
	}
	ch[i++]='.';
	for(k=5; k>=0; k--){
		ch[i+k] = (char)(rgt%10 + zero);
		rgt /= 10;
	}
	i += 6;
	int bytes = i;
	__asm__ __volatile__ (
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:
		:"S"(ch), "d"(bytes));
	return OK;
}

// can read 9-digit integers only
int readInt(int *n){
	//printf("I am here!!\n");
	char buff[BUFF];
	int i;
	__asm__ __volatile__ (
          "movl $0, %%eax \n\t"
          "movq $0, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(BUFF+1)
    ) ;

      __asm__ __volatile__ (
	 		"movl %%eax, %0;"
	 		: "=r"(i)
	 	:);

     if (i < 0)
        return ERR;

    i = 0;
	int val = 0, flag = 0;
	if (buff[0] == '-'){
		i++;
		flag = 1;
	}
	int len = 0;
	while (buff[i] != '\n'){
		int d = (int)(buff[i]-zero);
		if (d < 0 || d > 10)
			return ERR;
		val = val * 10 + (int)(buff[i] - zero);
		len++;
		i++;
	}

	//printf("The value read so far : %d \n !!", val);
	//printf("The value of length : %d \n !!", len);
	if (len > 9)
		return ERR;
	if (flag)
		val = -val;
	//*n = val;
	//printf("The value read is : %d\n !!", val);
	return val;
}

float readFlt(float *f){
	char buff[BUFF];
	int i;
	__asm__ __volatile__ (
          "movl $0, %%eax \n\t"
          "movq $0, %%rdi \n\t"
          "syscall \n\t"
          :
          :"S"(buff), "d"(BUFF+1)
    ) ;

      __asm__ __volatile__ (
	 		"movl %%eax, %0;"
	 		: "=r"(i)
	 	:);

     if (i < 0)
        return ERR;

    i = 0;
	int flag = 0;
	if (buff[0] == '-'){
		i++;
		flag = 1;
	}
	int trailing  = 0;
	int dec = 0;
	float p1 = 1.0, p2 = 1.0;
	float value = 0.0;
	float integral = 0, mantissa = 0;
	while (buff[i] != '\n'){
		if (buff[i] == '.'){
			dec = 1;
			i++;
			continue;
		}
		int d = (int)(buff[i] - zero);
		if (d < 0 || d > 10){
			return ERR;
		}
		if (dec == 1){
			trailing++;
			p2 /= 10.0;
			mantissa += d * p2;
			
		}
		else{
			integral = integral * 10 + d;
		}
		i++;
	}
	// for i/p having a decimal point and no mantissa
	if (dec == 1 && trailing == 0){
		return ERR;
	}
	value = integral + mantissa;
	if (flag){
		value = -1.0 * value;
	}
	//*f = value;
	return value;	
}

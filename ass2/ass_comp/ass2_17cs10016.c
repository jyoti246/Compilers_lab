#include <math.h>
#include "myl.h"
#define BUFF 30
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
	buff[i]='\n';
	bytes = i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:
		:"S"(buff), "d"(bytes));
	return bytes-1;
}

// restrict to 5-decimal place precision
int printFlt(float f){
	char buff[BUFF];
	int i=0;
	if (f == 0){
		i+=9;
		*buff = zero;
		*(buff+1) = '.';
		for (int j = 2; j <= 7; j++){
			*(buff+j) = zero;
		}
		*(buff+8) = '\n';
		
	}
	else{
		
		
		if(f<0){buff[i++]='-';f=-f;}
		int l=(int)f;
		float r=f-l;
		r*=1000000;
		int rt=r;
		while(l){
			int x=l%10;
			buff[i++]=(char)(x+zero);
			l/=10;
		}

		int j = 0;
		if (buff[j] == '-')j++;
		int k = i -1 ;
		while (j < k){
			char temp = buff[j];
			buff[j++] = buff[k];
			buff[k--] = temp;
		}
		buff[i++]='.';
		for(k=5;k>=0;k--){
			buff[i+k]=(char)(rt%10 +zero);
			rt/=10;
		}
		i+=6;
		buff[i++]='\n';
		
	}


	int bytes = i;
	__asm__ __volatile__ (
		"movl $1, %%eax\n\t"
		"movq $1, %%rdi\n\t"
		"syscall\n\t"
		:
		:"S"(buff), "d"(bytes));
	return OK;
}

// can read 9-digit integers only
int readInt(int *n){
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

    
	int val = 0, sign = 0,len = 0,flag=0;
	i = 0;
	if (buff[0] == '-'){
		i++;
		flag = 1;
	}
	
	while (buff[i] != '\n'){
		int digit = (int)(buff[i]-zero);
		if (digit < 0 || digit > 9)        //if any characters other than digit
			return ERR;
		val = val * 10 + (int)(buff[i] - zero);
		len++;
		i++;
	}
	if (len > 9)
		return ERR;
	if (flag)
		val = -val;
	*n = val;
	return OK;
}
// 6 digit after decimal is taken
int readFlt(float *f){
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
	
	while(buff[i] != '.' && buff[i] != '\n'){
		int digit = (int)(buff[i] - zero);
		if (digit < 0 || digit > 9){
			return ERR;     //if any characters other than digit
		}
		value=value*10+digit;
		i++;
	}
	if(buff[i]=='.')i++;

	int count=0;
	float div=10;
	while (buff[i] != '\n'){
		count++;

		float dig = (int)(buff[i] - zero);
		if (dig < 0 || dig > 9){
			return ERR;         //if any characters other than digit
		}
		if(count>6)continue;
		value+=dig/div;
		div*=10;
		i++;
	}

	// for i/p having a decimal point and no mantissa
	if (i!=0 &&(buff[i-1]=='.' && count == 0)){
		return ERR;
	}
	
	if (flag){
		value = -1.0 * value;
	}
	*f = value;
	return OK;	
}
int printInt(int num);
int printStr(char *x);
int main(){
	int a, b;
	a = 5555;
	printInt(a);
	while (a > 10){
		b = a / 2;
		a = b;
	}
	printInt(a);
	return 0;
}

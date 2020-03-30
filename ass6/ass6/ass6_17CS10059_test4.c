int readInt(int *x);
int printInt(int x);
int main()
{
	int lol;
	int a = readInt(&lol);
	char c  = 'a';
	int b = 1;
	int i;
	for(i=0;i<a;i++){
		b = i;
		//printInt(b);
	}
	printInt(b);
	return 0;
}

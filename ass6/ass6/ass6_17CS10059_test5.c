int readInt(int *x);
int printInt(int y);
int readFlt(float *x);
int printFlt(float x);
int main(){
    int n;
    int x = readInt(&n);
    int i = x;
    printInt(i);
    float f;
	f = readFlt(&f);
	printFlt(f);
    return 0;
}

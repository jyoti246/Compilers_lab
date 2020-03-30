float readFlt(float *f);
int printFlt(float d);
int main(){
	float p;
	float a = readFlt(&p);
	printFlt(a);
	return 0;
}

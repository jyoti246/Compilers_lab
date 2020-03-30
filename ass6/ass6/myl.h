#ifndef MYL_H
#define MYL_H
#define ERR 0
#define OK 1
int printStr(char *);	// prints the string and return the number of characters printed
int printInt(int);		// prints the integer and return the number of characters printed
int readInt(int *);		// reads an integer and returns value/ERR flag
float readFlt(float *); 	// reads a floating-point number upto 5 decimal place accuracy and returns value/ERR accordingly
int printFlt(float); 	// prints a floating-point number and returns the number of characters printed
#endif

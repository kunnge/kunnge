#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
typedef unsigned char* byte_pointer;
void show_byte(byte_pointer start, size_t len)
{
    size_t i;
	for ( i = 0; i < len; i++)
	{
		printf("%.2x ", start[i]);
	}
	printf("\n");
}
void show_int(int x)
{
	show_byte((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
	show_byte((byte_pointer)&x, sizeof(float));
}
void show_pointer(void* x)
{
	show_byte((byte_pointer)&x, sizeof(void*));
}
void test_show_byte(int val)
{
	int ival = val;
	float fval = (float)ival;
	int* pval = &ival;
	show_int(ival);
	show_float(fval);
	show_pointer(pval);
}
int main()  
{
	int x = 0x66;
	int y = 0x39;
	printf("%#x", x&!y);
    return 0;
}
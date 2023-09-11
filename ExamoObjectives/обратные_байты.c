#include <stdio.h>
#include <ctype.h>

int main()
{
	unsigned x;
	scanf("%u", &x);
	x = (x & 0x00FF00FF) << 8 | (x & 0xFF00FF00) >> 8;
	x = (x & 0x0000FFFF) << 16 | (x & 0xFFFF000) >> 16;
	printf("%u", x);
	printf("\n");
	
	return 0;
}

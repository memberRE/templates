#include <stdio.h>
union {
	int  num;
	struct {
		unsigned short n1;
		unsigned short n2;
	} b;
} a;
int main() {
	a.num = 0x00005678;
	printf("%x  %x \n", a.b.n1, a.b.n2);
	a.num *= -1;
	printf("%x  %x \n", a.b.n1, a.b.n2);
}
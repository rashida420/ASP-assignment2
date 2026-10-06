#include <stdio.h>

int main() {
    unsigned int a = 0x23456789;
    unsigned char *p = (unsigned char *)&a;
    printf("Value: 0x%X\n", a);
    printf("Byte 0: 0x%X\n", p[0]);
    printf("Byte 1: 0x%X\n", p[1]);
    printf("Byte 2: 0x%X\n", p[2]);
    printf("Byte 3: 0x%X\n", p[3]);
    return 0;
}
# Task 1 — Investigation of Endianness

## Introduction

Byte-addressable memories are organized in a big-endian or little endian fashion. Endianness refers to the order in which bytes are arranged in memory. Word addresses never change both formats and refer to the same four bytes. Only the addresses of bytes within a word differ.

The most significant byte (MSB) is on the left and the least significant byte (LSB) is on the right. For example: `0x23456789`, MSB is 23 while LSB is 89.

## Big-Endian and Little-Endian

**Big-endian (BE):** Stores the most significant byte first, at the lowest memory address. In other words, the "big end" of the value comes first.

**Little-endian (LE):** Stores the least significant byte first, at the lowest memory address. In other words, the "little end" of the value comes first.

To explain further we need to understand the importance of the Most Significant byte. For instance, if we change 3 to 4 in 3453 the difference is only 1, however if we change 3 to 4 the difference is 1000. So MSB is the byte that holds the higest position value, while LSB is the byte that holds lowest position value.

For example, let's consider the 32-bit value `0x23456789`. This value contains four bytes: 23, 45, 67, and 89. In a big-endian system, the most significant byte is stored at the lowest memory address:

```text id="34dn0e"
Address:       0    1    2    3

Big-endian:   23   45   67   89
```

In a little-endian system, the least significant byte is stored at the lowest address:

```text id="0ll2t3"
Address:        0    1    2    3

Little-endian:  89   67   45   23
```

## C Experiment

I used a C program to examine how multi-byte value is stored in the memory in my computer.

```c id="cfioqp"
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
```

Here, `&a` gets the memory address of `a`, while `unsigned char *p` allows us to examine that memory one byte at a time.

### Output

```text id="xpfobh"
Value: 0x23456789

Byte 0: 0x89
Byte 1: 0x67
Byte 2: 0x45
Byte 3: 0x23
```
The result illustrate the the machine is using little-endian becasue the least significant byte 89 is stored at the lowest address (00)

## Why Do We Have Two Representations?

IBM's PowerPC uses big-endian addressing while Intel's IA-32 uses little-endian. Motorola chose Big Endian because it looked cleaner and more intuitive. There was no global standard yet
The choice of endianness is arbitrary but it can create some diffuculties when sharing data between big-endian and little-endian computers.

## Short History
The terms big-endian and little-endian come from Jonathan Swift’s *Gulliver’s Travels*, where the Lilliputians argued about which end of an egg should be broken. The terms were later applied to computer architecture by **Danny Cohen** in his 1980 paper *“On Holy Wars and a Plea for Peace.”*

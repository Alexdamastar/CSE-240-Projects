#include <stdio.h>

union HW_Register
{
    struct Bytes
    {
        unsigned char byte0;
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
    } bytes;

    unsigned int word;
};


int main()
{
    union HW_Register reg;

    reg.word = 0x12345678;
    reg.bytes.byte2 = 0xFF;

    printf("reg.word = %x\n", reg.word);

    printf("sizeof(reg) = %lu\n", sizeof(reg));
}
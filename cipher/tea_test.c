#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "tea.h"

int main(int argc, char *argv[]){
    uint32_t v[2] = {0x20, 0x10}, k[4] = {0x04, 0x03, 0x02, 0x01};
    printf("%08X%08X\n", v[0], v[1]);
    encrypt(v, k);
    printf("%08X%08X\n", v[0], v[1]);
    decrypt(v, k);
    printf("%08X%08X\n", v[0], v[1]);
    return 0;
}

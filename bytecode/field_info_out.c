#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include "bytecode.h"

void print_field_info(struct ClassFile *cfp){
    uint16_t fields_count = cfp->fields_count;
    printf("总共有%u个字段\n", fields_count);
}


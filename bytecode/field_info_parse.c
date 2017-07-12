#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "util.h"
#include "bytecode.h"

void parse_field_info(FILE *fp,struct ClassFile *cfp)
{
    uint16_t fields_count;
    fread(&fields_count, sizeof(uint16_t), 1, fp);
    fields_count = isBigEndian() ? fields_count : BigLittleSwap16(fields_count);
    cfp->fields_count = fields_count;
}


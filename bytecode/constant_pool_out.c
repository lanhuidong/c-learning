#include <stdint.h>
#include <stdio.h>
#include "bytecode.h"

void print_constants(struct ClassFile *cfp){
    uint16_t constant_pool_count = cfp->constant_pool_count;
    printf("constant_pool_count:%u\n", constant_pool_count);
    for(uint16_t i = 0; i < constant_pool_count; i++){
        uint8_t tag = cfp->constant_pool[i].tag;
	switch(tag){
	    case 10:
                printf("#%d=Methodref,#%u.#%u\n", i+1, cfp->constant_pool[i].info.methodref_info.class_index,cfp->constant_pool[i].info.methodref_info.name_and_type_index);
	        break;
	    default:
	    printf("unkonw tag:%u\n", tag);
	}
        break;
    }
}

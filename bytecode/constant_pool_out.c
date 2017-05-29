#include <stdint.h>
#include <stdio.h>
#include "bytecode.h"

void print_constants(struct ClassFile *cfp){
    uint16_t constant_pool_count = cfp->constant_pool_count;
    printf("总共有%u项常量\n", constant_pool_count);
    for(uint16_t i = 0; i < constant_pool_count; i++){
        uint8_t tag = cfp->constant_pool[i].tag;
	printf("#%-5d = ", i + 1);
	switch(tag){
            case 7:
	        printf("Class\t\t#%u\n", cfp->constant_pool[i].info.class_info.name_index);
                break;
	    case 9:
                printf("Fieldref\t\t#%u.#%u\n", cfp->constant_pool[i].info.fieldref_info.class_index,cfp->constant_pool[i].info.fieldref_info.name_and_type_index);
	        break;
	    case 10:
                printf("Methodref\t\t#%u.#%u\n", cfp->constant_pool[i].info.methodref_info.class_index,cfp->constant_pool[i].info.methodref_info.name_and_type_index);
	        break;
	    default:
	    printf("unkonw tag:%u\n", tag);
	}
        if(i==2) {
            break;
	}
    }
}

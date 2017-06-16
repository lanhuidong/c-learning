#include "util.h"

/**
 * 返回0表示小端，返回非0值表示大端
 */
int isBigEndian(void){
    int i = 1;
    char c = *(char *)&i;
    return (int)c != i;
}

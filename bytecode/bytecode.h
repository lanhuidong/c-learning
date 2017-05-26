#ifndef _BYTECODE_H

#define _BYTECODE_H

struct ClassFile {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
};

struct cp_info {
    uint8_t tag;
};

void parse(FILE *fp, struct ClassFile *cfp);

#endif

#ifndef BYTECODE_H

#define BYTECODE_H

#include <stdint.h>

struct Class_info {
    uint16_t name_index;
};

struct Fieldref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct Methodref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct InterfaceMethodref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct String_info {
    uint16_t string_index;
};

struct Integer_info {
    uint32_t bytes;
};

struct Float_info {
    uint32_t bytes;
};

struct Long_info {
    uint32_t high_bytes;
    uint32_t low_bytes;
};

struct Double_info {
    uint32_t high_bytes;
    uint32_t low_bytes;
};

struct NameAndType_info {
    uint16_t name_index;
    uint16_t descriptor_index;
};

struct Utf8_info {
    uint16_t length;
    uint8_t *bytes;
};

struct MethodHandle_info {
    uint8_t reference_kind;
    uint16_t reference_index;
};

struct MethodType_info {
    uint16_t descriptor_index;
};

struct InvokeDynamic_info {
   uint16_t bootstrap_method_attr_index;
   uint16_t name_and_type_index;
};

union Info {
    struct Class_info class_info;
    struct Fieldref_info fieldref_info;
    struct Methodref_info methodref_info;
    struct InterfaceMethodref_info interfaceMethodref_info;
    struct String_info string_info;
    struct Integer_info integer_info;
    struct Float_info float_info;
    struct Long_info long_info;
    struct Double_info double_info;
    struct NameAndType_info nameAndType_info;
    struct Utf8_info utf8_info;
    struct MethodHandle_info methodHandle_info;
    struct MethodType_info methodType_info;
    struct InvokeDynamic_info invokeDynamic_info;
};

struct Cp_info {
    uint8_t tag;
    union Info info;
};

struct Field_info{

};

struct ClassFile {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    struct Cp_info *constant_pool;
    uint16_t access_flags;
    uint16_t this_class;
    uint16_t super_class;
    uint16_t interface_count;
    uint16_t *interfaces;
    uint16_t fields_count;
    struct Field_info *fields; 
};

void parse(FILE *fp);
void parse_constant_pool(FILE *fp, struct ClassFile *cfp);
void print_constants(struct ClassFile *cfp);
void parse_field_info(FILE *fp, struct ClassFile *cfp);
void print_field_info(struct ClassFile *cfp);

#endif

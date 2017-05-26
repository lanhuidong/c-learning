#ifndef _BYTECODE_H

#define _BYTECODE_H

struct CONSTANT_Class_info {
    uint16_t name_index;
};

struct CONSTANT_Fieldref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct CONSTANT_Methodref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct CONSTANT_InterfaceMethodref_info {
    uint16_t class_index;
    uint16_t name_and_type_index;
};

struct CONSTANT_String_info {
    uint16_t string_index;
};

struct CONSTANT_Integer_info {
    uint32_t bytes;
};

struct CONSTANT_Float_info {
    uint32_t bytes;
};

struct CONSTANT_Long_info {
    uint32_t high_bytes;
    uint32_t low_bytes;
};

struct CONSTANT_Double_info {
    uint32_t high_bytes;
    uint32_t low_bytes;
};

struct CONSTANT_NameAndType_info {
    uint16_t name_index;
    uint16_t descriptor_index;
};

struct CONSTANT_Utf8_info {
    uint16_t length;
    uint8_t bytes[];
};

struct CONSTANT_MethodHandle_info {
    uint8_t reference_kind;
    uint16_t reference_index;
};

struct CONSTANT_MethodType_info {
    uint16_t descriptor_index;
};

struct CONSTANT_InvokeDynamic_info {
   uint16_t bootstrap_method_attr_index;
   uint16_t name_and_type_index;
};

union Info {
    struct CONSTANT_Class_info class_info;
    struct CONSTANT_Fieldref_info fieldref_info;
    struct CONSTANT_Methodref_info methodref_info;
    struct CONSTANT_InterfaceMethodref_info interfaceMethodref_info;
    struct CONSTANT_String_info string_info;
    struct CONSTANT_Integer_info integer_info;
    struct CONSTANT_Float_info float_info;
    struct CONSTANT_Long_info long_info;
    struct CONSTANT_Double_info double_info;
    struct CONSTANT_NameAndType_info nameAndType_info;
    struct CONSTANT_Utf8_info utf8_info;
    struct CONSTANT_MethodHandle_info methodHandle_info;
    struct CONSTANT_MethodType_info methodType_info;
    struct CONSTANT_InvokeDynamic_info invokeDynamic_info;
};

struct Cp_info {
    uint8_t tag;
    union Info info;
};

struct ClassFile {
    uint32_t magic;
    uint16_t minor_version;
    uint16_t major_version;
    uint16_t constant_pool_count;
    struct Cp_info constant_pool[];
};

void parse(FILE *fp, struct ClassFile *cfp);

#endif

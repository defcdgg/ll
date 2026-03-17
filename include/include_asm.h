#ifndef GUARD_INCLUDE_ASM_H
#define GUARD_INCLUDE_ASM_H



#define STR(x) #x

#define INCLUDE_ASM(NAME) \
__attribute__((naked)) void NAME(void){\
    asm(".include \"asm/nonmatching/" STR(NAME) ".inc\"");\
}


#endif
#ifndef GUARD_INCLUDE_ASM_H
#define GUARD_INCLUDE_ASM_H



#ifndef INCLUDE_ASM
#define INCLUDE_ASM(FOLDER, NAME)                                                                                                     \
    asm(".include \"" FOLDER "/" #NAME ".s\"\n")
#endif

asm(".include \"asm/macros.inc\"\n");

#endif
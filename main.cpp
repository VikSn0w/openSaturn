#include "headers.h"

char Accumulator_Register [26]; //26bit - Memory address: 0c000
char Result_Register      [26]; //26bit - Memory address: 0c001

int main()
{
    //Setting to 0 the memory bits
    RESET(Accumulator_Register);
    RESET(Result_Register);

    return 0xA11;
}

#include "subs/emu.h"
#include "subs/general.h"




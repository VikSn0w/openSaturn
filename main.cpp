#include "headers.h"

string Accumulator_Register; //26bit - Memory address: 0c000
string Result_Register     ; //26bit - Memory address: 0c001

int main()
{
    //Setting to 0 the memory bits
    RESET(Accumulator_Register);
    RESET(Result_Register);

    return 0xA11;
}

#include "subs/emu.h"
#include "subs/general.h"




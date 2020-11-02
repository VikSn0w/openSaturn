#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <math.h>
#include <cstdlib>

#define N_OPS 18

using namespace std;

void Gotoxy(int X, int Y);

int wordSector_Index = 0;
int wordData_Index = 0;
int wordOps_Index = 0;

struct wordData{string data;};

struct wordInstructions
{
    char parity = '0';
    string address;
    string opcode;

    string totalWord;

    void Composite()
    {
        totalWord = parity + address + opcode;
    }
};

struct sector
{
    wordData WordData[256];
    wordInstructions WordOps[256];

    void SectorCheck()
    {
        if(wordData_Index+wordOps_Index == 510)
        {
            wordSector_Index++;
            wordData_Index = wordOps_Index = 0;
        }
    }
};

void RESET(string REGISTER);
void RESET(string REGISTER);

void DataLoad();
bool DataCheck(string Data);

void OpsLoad();
bool OpsCheck(string Instruction, short int &multi_op);

int OctalToBinary(int octalNum);

const string OPS_CODE[18] =
{
    "0000", "0001", "0010",
    "0011", "0100", "0101",
    "0110", "0111", "1000",
    "1001", "1010", "1011",
    "1100", "1101", "1110",
    "1110", "1110", "1111"
};

const string OPS[18] =
{
    "HOP", "MPY", "SUB",
    "DIV", "TNZ", "MPH",
    "AND", "ADD", "TRA",
    "XOR", "PIO", "STO",
    "TIM", "RSU", "SHR",
    "CDS", "EXM", "CLA"
};

sector WordSectors[64];

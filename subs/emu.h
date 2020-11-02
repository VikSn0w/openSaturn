void RESET(string REGISTER) {for(int i = 0; i < 26; REGISTER[i] = '0', i++);}
void PrintRegister(string REGISTER){cout << REGISTER;}

int OctalToBinary(int octalNum)
{
    int decimalNum = 0, binaryNum = 0, Count = 0;

    while(octalNum != 0)
    {
        decimalNum += (octalNum%10) * pow(8,Count);
        ++Count;
        octalNum/=10;
    }

    Count = 1;

    while (decimalNum != 0)
    {
        binaryNum += (decimalNum % 2) * Count;
        decimalNum /= 2;
        Count *= 10;
    }
    return binaryNum;
}

void DataLoad()
{
    ifstream DATA;

    DATA.open("data.ops");
    if(DATA.is_open())
    {
        string data;
        int line = 0;
        while(!DATA.eof())
        {
            getline(DATA, data);
            if(DataCheck(data) == false)
            {
                string app = "echo x=msgbox(The data word " + data + " at line " + to_string(line) + " is not correct,0, Error 1 >> msgbox_error1_data.vbs";
                system(app.c_str());
                system("start msgbox_error1_data.vbs");
            }
            else
            {
                WordSectors[wordSector_Index].WordData[wordData_Index].data = data;
                wordData_Index++;
                WordSectors->SectorCheck();
            }
            line++;
        }
    }
}

void OpsLoad()
{
    ifstream INSTRUCTIONS;

    INSTRUCTIONS.open("instructions.ops");
    if(INSTRUCTIONS.is_open())
    {
        string instruction;

        int line = 0;

        short int multi_flag = 0x0;

        while(!INSTRUCTIONS.eof())
        {
            getline(INSTRUCTIONS, instruction);
            if(OpsCheck(instruction, multi_flag) == true)
            {
                string app = "echo x=msgbox(The instruction " + instruction + " at line " + to_string(line) + " was not found,0, Error 1 >> msgbox_error1_ops.vbs";
                system(app.c_str());
                system("start msgbox_error1_ops.vbs");
            }
            else
            {
                if(multi_flag == 0x01)
                {

                }
                else
                {
                    string ops = "";
                    ops = instruction[0] + instruction[1] + instruction[2];

                    int j = 0;
                    for(int i = 0; i < N_OPS; i++)
                    {
                        if(ops == OPS[i])
                        {
                            j = i;
                            i = 99;
                        }
                    }

                    string A,B,C, Address = "";

                    A = instruction[4];
                    B = instruction[5];
                    C = instruction[6];

                    if(A != "0")
                    {
                        string app = "";
                        app = to_string(OctalToBinary(atoi(A.c_str())));
                        if(app.size() == 2)
                        {
                            app += "-";
                            app[2] = app[1];
                            app[1] = app[0];
                            app[0] = '0';
                        }
                        else if(app.size() == 1)
                        {
                            app += "--";
                            app[2] = app[0];
                            app[1] = '0';
                            app[0] = '0';
                        }
                        Address += app;
                    }
                    else Address += "000";

                    if(B != "0")
                    {
                        string app = "";
                        app = to_string(OctalToBinary(atoi(A.c_str())));
                        if(app.size() == 2)
                        {
                            app += "-";
                            app[2] = app[1];
                            app[1] = app[0];
                            app[0] = '0';
                        }
                        else if(app.size() == 1)
                        {
                            app += "--";
                            app[2] = app[0];
                            app[1] = '0';
                            app[0] = '0';
                        }
                        Address += app;
                    }
                    else Address += "000";

                    if(C != "0")
                    {
                        string app = "";
                        app = to_string(OctalToBinary(atoi(A.c_str())));
                        if(app.size() == 2)
                        {
                            app += "-";
                            app[2] = app[1];
                            app[1] = app[0];
                            app[0] = '0';
                        }
                        else if(app.size() == 1)
                        {
                            app += "--";
                            app[2] = app[0];
                            app[1] = '0';
                            app[0] = '0';
                        }
                        Address += app;
                    }
                    else Address += "000";

                    WordSectors[wordSector_Index].WordOps[wordOps_Index].opcode  = OPS_CODE[j];
                    WordSectors[wordSector_Index].WordOps[wordOps_Index].address = Address;
                    wordOps_Index++;
                    WordSectors->SectorCheck();
                }
            }
            line++;
        }
    }
}

/*
    short int &multi_op
    0x0  = not multi instrution
    0x01 = multi instrution - CST
*/

bool OpsCheck(string Instruction, short int &multi_op)
{
    string ops = "";

    ops = Instruction[0] + Instruction[1] + Instruction[2];

    bool found = false;

    for(int i = 0; i < N_OPS; i++)
    {
        if(ops == OPS[i])
        {
            found == true;
            i = 999;
            if(ops == "CST") multi_op = 0x01;
            else multi_op = 0x0;
        }
        else found == false;
    }
    return found;
}

bool DataCheck(string Data)
{
    bool error = false;

    if(Data.size() != 26)error = true;

    return error;
}

void OpsExec()
{

}

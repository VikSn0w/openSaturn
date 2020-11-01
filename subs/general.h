void Gotoxy(int X, int Y)
{
    COORD Cur = {SHORT(X), SHORT(Y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

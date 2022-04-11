#include <stdio.h>
#include <windows.h>
#include <time.h>
#define scount 80
#define screen_x 80
#define screen_y 25

HANDLE wHnd;
COORD bufferSize = {screen_x, screen_y};
SMALL_RECT windowSize = {0, 0, screen_x - 1, screen_y - 1};
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = {0, 0}; //ระบุตำแหน่งจอภาพมุมซ้ายที่จะแสดงผล
COORD star[scount];

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

void clear_buffer()
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = ' '; //ตัวอักษร
            consoleBuffer[x + screen_x * y].Attributes = 255;     //สีและพื้นหลัง
        }
    }
}

void fill_data_to_buffer(char a, int b)
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = a; //ตัวอักษร
            consoleBuffer[x + screen_x * y].Attributes = b;     //สีและพื้นหลัง
        }
    }
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void init_star()
{
    for (int i = 0; i < scount; i++)
    {
        star[i].X = 0 + rand() % 80;
        star[i].Y = 0 + rand() % 25;
    }
}

void star_fall()
{
    int i;
    for (i = 0; i < scount; i++)
    {
        if (star[i].Y >= screen_y - 1)
        {
            star[i] = {(rand() % screen_x), 1};
        }
        else
        {
            star[i] = {star[i].X, star[i].Y + 1};
        }
    }
}

void fill_star_to_buffer()
{
    for (int i = 0; i < scount; ++i)
    {
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*'; //ตัวอักษร
        consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;       //สีและพื้นหลัง
    }
}

int main()
{
    setConsole(screen_x, screen_y);
    srand(time(NULL));
    init_star();

    char alphabet;
    int num, i = 0;
    // while (i<10000)
    // {
    //     alphabet = 'A' + rand() % 26;
    //     num = 0 + rand() % 256;
    //     fill_data_to_buffer(alphabet, num);
    //     fill_buffer_to_console();
    //     i++;
    // }
    while (i < 1000)
    {
        // star_fall();
        // clear_buffer();
        fill_star_to_buffer();
        fill_buffer_to_console();
        Sleep(200);
        i++;
    }

        while (true)
    {
    }

    return 0;
}
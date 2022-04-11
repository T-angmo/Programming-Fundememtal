//ส่งอันนี้
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define screen_x 80
#define screen_y 25

HANDLE wHnd;
COORD bufferSize = {screen_x, screen_y};
SMALL_RECT windowSize = {0, 0, screen_x - 1, screen_y - 1};
HANDLE rHnd;
DWORD fdwMode;
DWORD numEvents = 0;
DWORD numEventsRead = 0;
CHAR_INFO consoleBuffer[screen_x * screen_y];
COORD characterPos = {0, 0};
int sx, sy, posx, posy;

int setConsole(int x, int y)
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

int setMode()
{
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}

void draw_ship(int x, int y, int num) //วาดยาน
{
    consoleBuffer[x + screen_x * y].Char.AsciiChar = '<';
    consoleBuffer[x + 1 + screen_x * y].Char.AsciiChar = '-';
    consoleBuffer[x + 2 + screen_x * y].Char.AsciiChar = '0';
    consoleBuffer[x + 3 + screen_x * y].Char.AsciiChar = '-';
    consoleBuffer[x + 4 + screen_x * y].Char.AsciiChar = '>';
    for (int i = 0; i < 5; i++)
    {
        consoleBuffer[x + i + screen_x * y].Attributes = num;
    }
}

void fill_buffer_to_console()
{
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void clear_buffer() //clear หน้าจอ
{
    for (int y = 0; y < screen_y; ++y)
    {
        for (int x = 0; x < screen_x; ++x)
        {
            if (x == sx && y == sy)
            {
                x++;
            }
            consoleBuffer[x + screen_x * y].Char.AsciiChar = ' '; //ตัวอักษร
            consoleBuffer[x + screen_x * y].Attributes = 0;       //สีและพื้นหลัง
        }
    }
}

void init_star() //สุ่มตำแหน่ง *
{
    bool s = true;
    while (s == true)
    {
        sx = 0 + rand() % 80;
        sy = 0 + rand() % 25;
        if (sx != posx || sy != posy)
        {
            s = false;
        }
    }
}

void draw_star() //วาด *
{
    consoleBuffer[sx + screen_x * sy].Char.AsciiChar = '*'; //ตัวอักษร
    consoleBuffer[sx + screen_x * sy].Attributes = 7;
}

int main()
{
    int color = 7, count = 0;
    bool play = true, star = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsole(screen_x, screen_y);
    setMode();
    init_star();
    fill_buffer_to_console();

    while (play)
    {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0)
        {
            INPUT_RECORD *eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i)
            {
                if (eventBuffer[i].EventType == KEY_EVENT && eventBuffer[i].Event.KeyEvent.bKeyDown == true) //ถ้ากดคีย์บอร์ด
                {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) //กด ESC
                    {
                        play = false;
                    }
                    if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c')
                    {
                        color = 0 + rand() % 256;
                        clear_buffer();
                        draw_ship(posx, posy, color);
                        fill_buffer_to_console();
                    }
                    //printf("press : %c\n", eventBuffer[i].Event.KeyEvent.uChar.AsciiChar); //print ปุ่มที่กด
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT) //ถ้าคลิกเมาส์
                {
                    posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;                         //ค่าพิกัดในแกน x ของ mouse
                    posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;                         //ค่าพิกัดในแกน y ของ mouse
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) //คลิ๊กปุ่มซ้าย
                    {
                        color = 0 + rand() % 256;
                        //printf("left click\n");
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) //คลิ๊กปุ่มขวา
                    {
                        //printf("right click\n");
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) //มีการเคลื่อน mouse
                    {
                        clear_buffer();
                        draw_ship(posx, posy, color);
                        fill_buffer_to_console();
                        //printf("mouse position : (%d,%d)\n", posx, posy);
                    }
                }
            }
            delete[] eventBuffer;
        }
        Sleep(100);

        draw_star();
        fill_buffer_to_console();
        if (posx == sx && posy == sy)   //ยานชน *
        {
            init_star();
            draw_star();
            fill_buffer_to_console();
            count++;
        }
        if (count == 10)    //ชนครบ 10 ครั้ง
        {
            play = false;
        }
    }

    return 0;
}
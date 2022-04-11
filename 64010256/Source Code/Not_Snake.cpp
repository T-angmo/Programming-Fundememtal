#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define screen_x 120
#define screen_y 35
int X[100], Y[100], s = 2, l = 5;
int rx, ry, rxs, rys;
bool state_special = false;
char Name[50];

HANDLE wHnd;
COORD bufferSize = {screen_x, screen_y};
SMALL_RECT windowSize = {0, 0, screen_x - 1, screen_y - 1};

int setConsole(int x, int y) //set size console
{
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    return 0;
}

void setcursor(bool visible) //delete cursor
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}
char cursor(int x, int y)
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2];
    COORD c = {x, y};
    DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
        return '\0';
    else
        return buf[0];
}

void setcolor(int fg, int bg)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

//about snake
void draw_headsnake(int x, int y)
{
    gotoxy(x, y);
    setcolor(5, 5);
    printf("  ");
}
void draw_snake(int x, int y)
{
    gotoxy(x, y);
    setcolor(4, 4);
    printf("  ");
}
void eraser_snake(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("  ");
}

void draw_fcourt()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int coler = 8;
    for (int i = 2; i <= 91; i++)
    {
        for (int j = 1; j < 34; j++)
        {
            if (i==2|| i == 3  || i == 90 || i == 91|| j == 1 || j == 33)
            {
                COORD coord;
                coord.X = i;
                coord.Y = j;
                SetConsoleCursorPosition(hConsole, coord);
                SetConsoleTextAttribute(hConsole, coler * 16 + coler);
                printf(" ");
            }
        }
    }
}

//about fruit
void draw_fruit(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 2);
    printf("* ");
}
void random_fruit()
{
    bool checkrand = false;
    while (checkrand == false)
    {
        checkrand = true;
        rx = s * (4 + rand() % (41));
        ry = s * (2 + rand() % (15));
        for (int j = 0; j < l; j++)
        {
            if (rx == X[j] && ry == Y[j])
            {
                checkrand = false;
                break;
            }
        }
    }
}
void random_fruitspecial()
{
    int special;
    special = 1 + rand() % (100);   //start_num + rand() % (number_num)
    if (special == 35)
    {
        state_special = true;
        bool checkrand = false;
        while (checkrand == false)
        {
            checkrand = true;
            rxs = s * (4 + rand() % (41));
            rys = s * (2 + rand() % (15));
            for (int j = 0; j < l; j++)
            {
                if (rxs == X[j] && rys == Y[j])
                {
                    checkrand = false;
                    break;
                }
            }
            if (rxs == rx && rys == ry)
            {
                checkrand = false;
            }
        }
    }
}

void instructions()
{
    //Instructions
    printf("Instructions :\n");
    printf("Use 'W' 'A' 'S' 'D' to control the snake.\n");
    printf("Eat the green food to grow up.\n");
    printf("Eat the yellow food wil give some talent to you ^_^\n");
    printf("Good Luck!!!\n\n");

    //Enter name
    printf("\nPlease enter your name : ");
    scanf("%s", Name);
    system("cls");
}

int main()
{
    SetConsoleTitle(TEXT("Not snake"));
    FILE *fp;
    char name[6][255];
    int allscore[6];

    fp = fopen("highscore.txt", "r");
    char buffer[255];
    int numname = 0, numscore = 0;
    for (int i = 0; i < 10; i++)
    {
        fscanf(fp, "%s", buffer);
        if (i % 2 == 0)
        {
            strcpy(name[numname++], buffer);
        }
        else
        {
            allscore[numscore++] = atoi(buffer); //แปลง string to int
        }
        // printf("%s", buffer);
    }
    fclose(fp);

    int Score = 0, count=0, timesleep = 85, score[6];
    int status_move = 1;
    bool status_x = false, status_y = true;
    char ch = ' ';
    X[0] = 50;
    Y[0] = 10;

    srand(time(NULL));
    instructions();
    setConsole(screen_x, screen_y);
    draw_fcourt();
    setcursor(0);
    Sleep(500);

    //show high score
    gotoxy(100, 8);
    setcolor(7, 0);
    printf("High Score");
    for (int i = 0; i < 5; i++)
    {
        gotoxy(95, 10 + i);
        printf("%s\t\t", name[i]);
        printf("%d", allscore[i]);
    }

    //developer name
    gotoxy(95, 30);
    setcolor(7, 0);
    printf("Natruja Huaysrijun");
    gotoxy(95, 31);
    setcolor(7, 0);
    printf("64010256");

    //draw snake
    draw_headsnake(X[0], Y[0]);
    for (int i = 1; i < l; i++)
    {
        X[i] = X[0] + (i * s);
        Y[i] = Y[0];
        draw_snake(X[i], Y[i]);
    }
    random_fruit(); //draw fruit
    draw_fruit(rx, ry);
    Sleep(timesleep);

    do
    {
        count++;
        if (kbhit()) //ตรวจสอบการกดปุ่ม
        {
            ch = _getch();
            if (ch == 'a' && status_x == true) //left
            {
                status_move = 1;
                status_x = false;
                status_y = true;
            }
            if (ch == 'd' && status_x == true) //right
            {
                status_move = 2;
                status_x = false;
                status_y = true;
            }
            if (ch == 'w' && status_y == true) //up
            {
                status_move = 3;
                status_y = false;
                status_x = true;
            }
            if (ch == 's' && status_y == true) //down
            {
                status_move = 4;
                status_y = false;
                status_x = true;
            }
            fflush(stdin);
        }
        Sleep(timesleep);

        for (int i = 0; i < l; i++) //delete all snake
        {
            eraser_snake(X[i], Y[i]);
        }
        for (int i = l - 1; i > 0; i--) //draw snake body
        {
            X[i] = X[i - 1];
            Y[i] = Y[i - 1];
            draw_snake(X[i], Y[i]);
        }

        //เปลี่ยนทิศทาง
        if (status_move == 1) //left
        {
            X[0] = X[0] - s;
        }
        if (status_move == 2) //right
        {
            X[0] = X[0] + s;
        }
        if (status_move == 3) //up
        {
            Y[0] = Y[0] - 1;
        }
        if (status_move == 4) //down
        {
            Y[0] = Y[0] + 1;
        }
        draw_headsnake(X[0], Y[0]); //draw snake head
        Sleep(timesleep);

        //eat green fruit
        if (X[0] == rx && Y[0] == ry)
        {
            random_fruit();
            draw_fruit(rx, ry);
            l++;
            Score += 10;
        }

        //yellow fruit
        if (state_special == false)
        {
            random_fruitspecial();
        }
        if (state_special == true)
        {
            gotoxy(rxs, rys);
            setcolor(6, 6);
            printf("* ");
            if (X[0] == rxs && Y[0] == rys) //eat yellow fruit
            {
                Score += 50;
                state_special = false;
                count = 0;
                timesleep = 30;
            }
        }
        if (count >= 100) //countdown for speed time
        {
            timesleep = 80;
        }

        //show score
        gotoxy(100, 5);
        setcolor(7, 0);
        printf("Score : ");
        printf("%d", Score);

        //check end game
        if (X[0] == 2 || X[0] == 90 || Y[0] == 1 || Y[0] == 33) //crashed court
        {
            goto end_loop;
        }
        for (int j = 1; j < l; j++)
        {
            if (X[0] == X[j] && Y[0] == Y[j]) //crashed its body
            {
                goto end_loop;
            }
        }

    } while (ch != 'x'); //exit button
end_loop:
    system("cls");

    int m;
    char k[50];
    allscore[5] = Score;
    strcpy(name[5], Name);
    for (int i = 5; i > 0; i--)
    {
        if (allscore[i] > allscore[i - 1])
        {
            m = allscore[i];
            allscore[i] = allscore[i - 1];
            allscore[i - 1] = m;
            strcpy(k, name[i]);
            strcpy(name[i], name[i - 1]);
            strcpy(name[i - 1], k);
        }
        else if (allscore[i] == 0 && allscore[i - 1] == 0)
        {
            strcpy(k, name[i]);
            strcpy(name[i], name[i - 1]);
            strcpy(name[i - 1], k);
        }
        else
        {
            break;
        }
    }

    fp = fopen("highscore.txt", "w+");
    char num[50];
    for (int i = 0; i < 5; i++)
    {
        itoa(allscore[i], num, 10);
        fputs(name[i], fp);
        fputs("\n", fp);
        fputs(num, fp);
        fputs("\n", fp);
    }
    fclose(fp);

    //last page
    printf("Your name : %s\n", Name);
    printf("Your score : %d\n\n", Score);
    printf("\tHigh Score Updated\n\n");
    printf("Rank:\tName:\t\tScore:\n");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d\t%s\t\t %d \n", i + 1, name[i], allscore[i]);
    }
    while (1)
    {
    
    }
    
    
    

    return 0;
}

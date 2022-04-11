#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

int xs[20], ys[20];
int bx, by;

void gotoxy(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
    gotoxy(x, y);
    printf(" <-0-> ");
}

void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    printf("^");
}

void clear_bullet(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
}

void draw_star()
{
    for (int i = 0; i < 20; i++)
    {
        xs[i] = 10 + rand() % 61;
        ys[i] = 2 + rand() % 4;
        for (int j = 0; j < i; j++)
        {
            if (xs[i] == xs[j] && ys[i] == ys[j])
            {
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < 20; i++)
    {
        gotoxy(xs[i], ys[i]);
        printf("*");
    }
}

void draw_newstar()
{
    bool star = true;
    for (int i = 0; i < 20; i++)
    {
        if (bx == xs[i] && by - 1 == ys[i])
        {
            while (star == true)
            {
                xs[i] = 10 + rand() % 61;
                ys[i] = 2 + rand() % 4;
                if (xs[i] == bx && ys[i] == by - 1)
                {
                }
                else
                {
                    gotoxy(xs[i], ys[i]);
                    printf("*");
                    star = false;
                }
            }
            break;
        }
    }
}

void clear_star(int x, int y)
{
    gotoxy(x, y);
    printf(" ");
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

void write_score(int x)
{
    gotoxy(88, 2);
    printf("%d", x);
}

int main()
{
    char ch = '.';
    int x = 38, y = 20, i, score = 0;
    int bullet = 0;
    srand(time(NULL));
    draw_ship(x, y);
    draw_star();
    gotoxy(80, 2);
    printf("Score :");
    write_score(score);
    do
    {
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                draw_ship(--x, y);
            }
            if (ch == 's')
            {
                draw_ship(++x, y);
            }
            if (bullet != 1 && ch == ' ')
            {
                Beep(700, 100);
                bullet = 1;
                bx = x + 3;
                by = y - 1;
            }
            fflush(stdin);
        }
        if (bullet == 1)
        {
            clear_bullet(bx, by);
            if (by == 2)
            {
                bullet = 0;
            }
            else
            {
                if (cursor(bx, by - 1) == '*')
                {
                    score++;
                    write_score(score);
                    bullet = 0;
                    Beep(600, 100);
                    clear_star(bx, by - 1);
                    draw_newstar();
                }
                else
                {
                    draw_bullet(bx, --by);
                }
            }
        }
        Sleep(100);

    } while (ch != 'x');

    return 0;
}
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
//#define clrscr() printf("\e[1;1H\e[2J")

void gotoxy(int  x1, int  y1) {
    COORD c = { x1, y1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void erase_ship(int x3,int y3) {
    gotoxy(x3, y3);
    printf("      ");
}

void draw_ship(int x2, int y2) {
    system("cls");
    gotoxy(x2, y2);
    printf("<-0->");      
}

int main() {

    // for(int i=0 ; i<80 ; i++) {
    //     draw_ship(i+1, 20);        
    // }
    char ch=' ';
    int x=38,y=20;    
    draw_ship(x,y);
    do {
        if(kbhit()) {
            ch = _getch();
            if(ch=='a') {
                //erase_ship(x,y);
                draw_ship(--x,y);
                }
            if(ch=='d' && x<80) {
                //erase_ship(x,y);
                draw_ship(++x,y);
                }
            if(ch=='w') {
                //erase_ship(x,y);
                draw_ship(x,--y);
                }
            if(ch=='s') {
                //erase_ship(x,y);
                draw_ship(x,++y);
                }
            fflush(stdin);
        }
        Sleep(100);
    } while(ch !='x');
        
    return 0;
}
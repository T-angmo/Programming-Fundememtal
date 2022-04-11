#include<stdio.h> 
#include<windows.h> 
#include<conio.h> 
#include <stdbool.h>

void setcursor(bool visible) 
{ 
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
    CONSOLE_CURSOR_INFO lpCursor; 
    lpCursor.bVisible = visible; 
    lpCursor.dwSize = 20; 
    SetConsoleCursorInfo(console,&lpCursor); 
}

void setcolor(int fg,int bg) { 
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
    SetConsoleTextAttribute(hConsole, bg*16+fg); 
}

/////////ship
void gotoxy_ship(int x1, int y1) { 
    COORD c = { x1, y1 };   
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c); 
}
void draw_ship(int x1,int y1) { 
    gotoxy_ship(x1,y1);
    setcolor(2,4); 
    printf(" <-0-> "); 
} 
void erase_ship(int x1,int y1) {
    gotoxy_ship(x1, y1);
    setcolor(0,0);
    printf("                ");
}

/////////shot
void gotoxy_shot(int x2, int y2) { 
    COORD c = { x2, y2 };   
    SetConsoleCursorPosition(  GetStdHandle(STD_OUTPUT_HANDLE) , c); 
} 
void draw_shot(int x2,int y2) {
    gotoxy_shot(x2,y2);
    setcolor(6,6);
    printf(" ");
}
void erase_shot(int x2,int y2) {
    gotoxy_shot(x2, y2);
    setcolor(0,0);
    printf("            ");
}
  
int main() {

    char ch = '.'; 
    int x=38, y=20, status_move; 
    int x1, y1;
    int status_shot = 0; //0 = OFF, 1 = ON
    setcursor(0);
    draw_ship(x,y); 
    do { 
        ////////// ship //////////
        //ตรวจสอบการกดปุ่ม
        if (kbhit()){ 
            ch = getch(); 
            if(ch=='a') {
                status_move = -1;
            }
            if(ch=='d') {
                status_move = 1;
            }
            if(ch=='s') {
                status_move = 0;
            }
            // if((ch == ' ') && (status_shot == 0)) {
            //     status_shot = 1;
            //     x1=x;
            //     y1=y;
            // }
            fflush(stdin); 
        }
        //ตรวจสอบค่าทิศทาง
        if(status_move==-1) {
            erase_ship(x,y);
            draw_ship(--x,y);
        }
        else if(status_move==1) {
            erase_ship(x,y);
            draw_ship(++x,y);
        }
        //หยุดเมื่อสุดขอบจอ
        if(x==0 || x==80) {
            status_move=0;
        }                  
        Sleep(100);  

        ////////// shot //////////
        //ตรวจสอบการกดปุ่ม 
        if (kbhit()) {
            ch = getch();
            if((ch == ' ') && (status_shot == 0)) {
                status_shot = 1;
                x1=x;
                y1=y;
            }
            fflush(stdin);
        }
        //ตรวจสอบว่าสถานะของกระสุน = ON
        if(status_shot == 1) {
            erase_shot(x1,y1);
            if(y1 > 0) {
                draw_shot(x1,--y1);
            }
            else {
                //erase_shot(x1,y1);
                status_shot = 0;
                
            }
        }


    } while (ch!='x'); 

        
    return 0; 
} 
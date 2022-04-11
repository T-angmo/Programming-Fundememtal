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
    printf(" ");
}
  
int main() {

    char ch = '.'; 
    int x=38, y=20, status_move; 
    int x1[5]={0,0,0,0,0}, y1[5]={0,0,0,0,0}, i=-1, count=0;
    int status_shot =-1, pressed = 1; //0 = OFF, 1 = ON
    setcursor(0);
    draw_ship(x,y); 
    do { 
        //ตรวจสอบการกดปุ่ม
        if (kbhit()){ 
            ch = getch(); 
            ////////// ship //////////
            if(ch=='a') {
                status_move = -1;
            }
            if(ch=='d') {
                status_move = 1;
            }
            if(ch=='s') {
                status_move = 0;
            }
            ////////// shot //////////
            if((ch == ' ') && (pressed != 0)) {
                if(count<=4) {                                       
                  status_shot = 1;                    
                  count++; 
                  i++; 
                  if(i>=5) {
                    i=0;
                  }               
                  x1[i]=x;
                  y1[i]=y;
                }                
            }
            fflush(stdin); 
        }
        ////////// ship //////////
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
        //ตรวจสอบว่าสถานะของกระสุน = ON
        if(status_shot == 1) {
            if(count>=5) {
                pressed = 0;
            }
            if(count==0) {
                status_shot = 0;
            }
            for(int j=0 ; j<5 ; j++) {
                if(y1[j]==1) {
                count--;
                pressed = 1;
                }
              if(y1[j]<y) {
                erase_shot((x1[j]+3),y1[j]);
                }            
              if(y1[j] > 0) {
                draw_shot((x1[j]+3),--y1[j]);
                }
              
            }  
            // gotoxy_shot(0,25);
            // setcolor(7,0);
            // printf("\ncount = %d", count);           
        }
        

    } while (ch!='x'); 
        
    return 0; 
} 
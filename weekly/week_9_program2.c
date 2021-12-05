// 73.รับค่าเลขตั้งแต่ 1-1,000,000 แล้วแปลงเป็นเลขในภาษาโรมัน (Level 3)
#include <stdio.h>

int main(void) 
{   
    int num, rem, i = 0, j, k = 0;
    char roman[1000], upper[1000];

    printf("Enter a number: ");
    scanf("%d", &num);

    while(num != 0)
    {
        if (num >= 1000000)       // 1,000,000 - _M
        {
           upper[k++] = '_';
           roman[i++] = 'M'; //_M           
           num -= 1000000;
        }
        else if (num >= 900000)       // 900,000 - _C_M
        {
           upper[k++] = '_';
           roman[i++] = 'C'; //_C
           upper[k++] = '_';
           roman[i++] = 'M'; //_M           
           num -= 900000;
        }
        else if (num >= 500000)       // 500,000 - _D
        {
           upper[k++] = '_';
           roman[i++] = 'D'; //_D
           num -= 500000;
        }
        else if (num >= 400000)       // 400,000 - _C_D
        {
           upper[k++] = '_';
           roman[i++] = 'C'; //_C
           upper[k++] = '_';
           roman[i++] = 'D'; //_D
           num -= 400000;
        }
        else if (num >= 100000)       // 100,000 - _C
        {
           upper[k++] = '_';
           roman[i++] = 'C'; //_C
           num -= 100000;
        }
        else if (num >= 90000)       // 90,000 - _X_C
        {
           upper[k++] = '_';
           roman[i++] = 'X'; //_X
           upper[k++] = '_';
           roman[i++] = 'C'; //_C
           num -= 90000;
        }
        else if (num >= 50000)       // 50,000 - _L
        {
           upper[k++] = '_';
           roman[i++] = 'L'; //_L
           num -= 50000;
        }
        else if (num >= 40000)       // 40,000 - _X_L
        {
           upper[k++] = '_';
           roman[i++] = 'X'; //_X
           upper[k++] = '_';
           roman[i++] = 'L'; //_L
           num -= 40000;
        }
        else if (num >= 10000)       // 10,000 - _X
        {
           upper[k++] = '_';
           roman[i++] = 'X'; //_X
           num -= 10000;
        }
        else if (num >= 9000)       // 9000 - M_X
        {
           upper[k++] = ' ';
           roman[i++] = 'M';
           upper[k++] = '_';
           roman[i++] = 'X'; //_X
           num -= 9000;
        }
        else if (num >= 5000)       // 5000 - _V
        {
           upper[k++] = '_';
           roman[i++] = 'V'; //_V
           num -= 5000;
        }
        else if (num >= 4000)       // 4000 - M_V
        {
           upper[k++] = ' ';
           roman[i++] = 'M';
           upper[k++] = '_';
           roman[i++] = 'V'; //_V
           num -= 4000;
        }
        else if (num >= 1000)       // 1000 - M
        {
           upper[k++] = ' ';
           roman[i++] = 'M';
           num -= 1000;
        }
        else if (num >= 900)   // 900 -  CM
        {
           upper[k++] = ' ';
           roman[i++] = 'C';
           upper[k++] = ' ';
           roman[i++] = 'M';
           num -= 900;
        }
        else if (num >= 500)   // 500 - D
        {           
           upper[k++] = ' ';
           roman[i++] = 'D';
           num -= 500;
        }
        else if (num >= 400)   // 400 -  CD
        {
           upper[k++] = ' ';
           roman[i++] = 'C';
           upper[k++] = ' ';
           roman[i++] = 'D';
           num -= 400;
        }
        else if (num >= 100)   // 100 - C
        {
           upper[k++] = ' ';
           roman[i++] = 'C';
           num -= 100;                       
        }
        else if (num >= 90)    // 90 - XC
        {
           upper[k++] = ' ';
           roman[i++] = 'X';
           upper[k++] = ' ';
           roman[i++] = 'C';
           num -= 90;                                              
        }
        else if (num >= 50)    // 50 - L
        {
           upper[k++] = ' ';
           roman[i++] = 'L';
           num -= 50;                                                                     
        }
        else if (num >= 40)    // 40 - XL
        {
           upper[k++] = ' ';
           roman[i++] = 'X';
           upper[k++] = ' ';
           roman[i++] = 'L';       
           num -= 40;
        }
        else if (num >= 10)    // 10 - X
        {
           upper[k++] = ' ';
           roman[i++] = 'X';
           num -= 10;           
        }
        else if (num >= 9)     // 9 - IX
        {
           upper[k++] = ' ';
           roman[i++] = 'I';
           upper[k++] = ' ';
           roman[i++] = 'X';
           num -= 9;                         
        }
        else if (num >= 5)     // 5 - V
        {
           upper[k++] = ' ';
           roman[i++] = 'V';
           num -= 5;                                     
        }
        else if (num >= 4)     // 4 - IV
        {
           upper[k++] = ' ';
           roman[i++] = 'I';
           upper[k++] = ' ';
           roman[i++] = 'V';
           num -= 4;                                                            
        }
        else if (num >= 1)     // 1 - I
        {
           upper[k++] = ' ';
           roman[i++] = 'I';
           num -= 1;                                                                                   
        }
    }
    for(j = 0; j < 17; j++)
        printf(" ");
    printf("%s\n", upper);
    printf("Roman number is: ");    
    printf("%s", roman);

    return 0;
}
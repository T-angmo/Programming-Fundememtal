// 73.รับค่าเลขตั้งแต่ 1-1,000,000 แล้วแปลงเป็นเลขในภาษาโรมัน (Level 3)
#include <stdio.h>

char romanval[1000], upper[1000];
int i = 0, k = 0;
 
void predigit(char num1, char num2) 
{
    romanval[i++] = num1;
    romanval[i++] = num2;
}
 
void postdigit(char c, int n) 
{
    int j;
    for (j = 0; j < n; j++)
        romanval[i++] = c;
} 

void upline(int a, int b)
{
    if(a == 1)
    {
        for(int j = 0; j < b; j++)
            upper[k++] = ' ';
    }
    else if(a == 2)
    {
        for(int j = 0; j < b; j++)
            upper[k++] = '_';
    }
}

int main() {

    int j;
    long number;
    printf("Enter the number: ");
    scanf("%d", &number);
    
    if (number <= 0 || number > 1000000)     
    {
        printf("Invalid number");        
        return 0;        
    }

    while (number != 0) {
        if (number >= 1000000) //1,000,000
        {
            postdigit('M', number / 1000000); //_M
            upline(2,number / 1000000);
            number = number - (number / 1000000) * 1000000;
        }
        else if (number >= 500000) //500,000-999,999
        {
            if(number < (500000 + 4 * 100000)) 
            {
                postdigit('D', number / 500000); //_D
                upline(2,number / 500000);
                number = number - (number / 500000) * 500000;
            }
            else 
            {
                predigit('C','M'); //_C_M
                upline(2,2);
                number = number - 900000;
            }
        }
        else if (number >= 100000) //100,000-499,999
        {
            if(number < (100000 + 3 * 100000)) 
            {
                postdigit('C', number / 100000); //_C
                upline(2,number / 100000);
                number = number - (number / 100000) * 100000;
               
            }
            else 
            {
                predigit('C','D'); //_C_D
                upline(2,2); 
                number = number - 400000;
            }
        }
        else if (number >= 50000) //50,000-99,999
        {
            if(number < (50000 + 4 * 10000)) 
            {
                postdigit('L', number / 50000); //_L
                upline(2,number / 50000);
                number = number - (number / 50000) * 50000;
            }
            else 
            {
                predigit('X','C'); //_X_C
                upline(2,2);
                number = number - 90000;
            }
        }
        else if (number >= 10000) //10,000-49,9999
        {
            if(number < (10000 + 3 * 10000)) 
            {
                postdigit('X', number / 10000); //_X
                upline(2,number / 10000);
                number = number - (number / 10000) * 10000;
            }
            else 
            {
                predigit('X','L'); //_X_L
                upline(2,2);
                number = number - 40000;
            }
        }
        else if (number >= 5000) //5,000-9,999
        {
            if(number < (5000 + 4 * 1000)) 
            {
                postdigit('V', number / 5000); //_V
                upline(2,number / 5000);
                number = number - (number / 5000) * 5000;
            }
            else 
            {
                predigit('M','X'); //M_X
                upline(1,1);
                upline(2,1);
                number = number - 9000;
            }
        }
        else if (number >= 1000) //1,000-4,999
        {
            if(number < (1000 + 3 * 1000)) 
            {
                postdigit('M', number / 1000);
                upline(1,number / 1000);
                number = number - (number / 1000) * 1000;
            }
            else 
            {
                predigit('M','V'); //M_V
                upline(1,1);
                upline(2,1);
                number = number - 4000;
            }
        }
        else if (number >= 500) //500-999
        {
            if (number < (500 + 4 * 100))
            {
                postdigit('D', number / 500);
                upline(1,number / 500);
                number = number - (number / 500) * 500;
            }
            else
            {
                predigit('C','M');
                upline(1,2);
                number = number - 900;
            }
        }
        else if (number >= 100) //100-499
        {
            if (number < (100 + 3 * 100)) 
            {
                postdigit('C', number / 100);
                upline(1,number / 100);
                number = number - (number / 100) * 100;
            }
            else
            {
                predigit('C','D');
                upline(1,2);
                number = number - 400;
            }
        }
        else if (number >= 50 ) //50-99
        {
            if (number < (50 + 4 * 10))
            {
                postdigit('L', number / 50);
                upline(1,number / 50);
                number = number - (number / 50) * 50;
            }
            else
            {
                predigit('X','C');
                upline(1,2);
                number = number - 90;
            }
        }
        else if (number >= 10) //10-49
        {
            if (number < (10 + 3 * 10))
            {
                postdigit('X', number / 10);
                upline(1,number / 10);
                number = number - (number / 10) * 10;
            }
            else
            {
                predigit('X','L');
                upline(1,2);
                number = number - 40;
            }
        }
        else if (number >= 5) //5-9
        {
            if (number < (5 + 4 * 1))
            {
                postdigit('V', number / 5);
                upline(1,number / 5);
                number = number - (number / 5) * 5;
            }
            else
            {
                predigit('I', 'X');
                upline(1,2);
                number = number - 9;
            }
        }
        else if (number >= 1) //1-4
        {
            if (number < 4)
            {
                postdigit('I', number / 1);
                upline(1,number / 1);
                number = number - (number / 1) * 1;
            }
            else
            {
                predigit('I', 'V');
                upline(1,2);
                number = number - 4;
            }
        }
    }
    for(j = 0; j < 17; j++)
        printf(" ");
    for(j = 0; j < k; j++)
        printf("%c", upper[j]);    
    printf("\n");
    printf("Roman number is: ");
    for(j = 0; j < i; j++) 
        printf("%c", romanval[j]);
    
    return 0;
}
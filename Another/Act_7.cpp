//ให้นักศึกษาทดลองเขียนโปรแกรมเก็บข้อมูล ชื่อผู้เล่น ,level และ คะแนนของผู้เล่น  
//จำนวน 5 คน เก็บไว้ใน Text File หรือ Binary File อย่างใดอย่างหนึ่ง

#include <stdio.h>

int main()
{
    struct player
    {
        char name[50];
        int level;
        int score;
    };
    player p[5];
    struct player1
    {
        char name1[50];
        int level1;
        int score1;
    };
    player1 p1[5];
    for (int i = 0; i < 5; i++)
    {
        printf("player %d name : ", i + 1);
        scanf("%s", &p[i].name);
        printf("player %d level : ", i + 1);
        scanf("%d", &p[i].level);
        printf("player %d score : ", i + 1);
        scanf("%d", &p[i].score);
    }

    FILE *fp;
    fp = fopen("player.txt", "w");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "%s %d %d\n", p[i].name, p[i].level, p[i].score);
    }
    fclose(fp);

    fp = fopen("player.txt", "r");
    for (int i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %d %d", &p1[i].name1, &p1[i].level1, &p1[i].score1);
    }
    fclose(fp);

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%s", p1[i].name1);
    //     printf("%d", p1[i].level1);
    //     printf("%d", p1[i].score1);
    // }

    return 0;
}
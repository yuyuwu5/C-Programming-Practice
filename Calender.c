#include<stdio.h>
int main(void)
{
    int year, month, day, i, j, k = 0;
    scanf("%d%d%d", &year, &month, &day);
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        year = 1;
    else
        year = 2;

    switch(year){
case 1 :
    switch(month){
case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================");
    printf("\n");
    if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 32; i++){
        if(((i + day -1) % 7 == 6) || i == 31){
        printf("%3d\n", i);
        }
        else
            printf("%3d", i);
    }
     printf("=====================");
     printf("\n");
    break;
case 4: case 6: case 9: case 11:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
     printf("=====================");
     printf("\n");
      if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 31; i++){
        if(((i + day -1) % 7 == 6) || i == 30){
        printf("%3d\n", i);
}
         else
            printf("%3d", i);
    }
     printf("=====================");
     printf("\n");
    break;
case 2:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================");
    printf("\n");
      if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 30; i++){
        if(((i + day -1) % 7 == 6) || i == 29){
        printf("%3d\n", i);
}
         else
            printf("%3d", i);
    }
     printf("=====================");
     printf("\n");
    break;
default :
    printf("invalid\n");
    break;
    }break;
case 2:
    switch(month){
case 1: case 3: case 5: case 7: case 8: case 10: case 12:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================");
    printf("\n");
      if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 32; i++){
        if(((i + day -1) % 7 == 6) || i == 31){
        printf("%3d\n", i);
    }
        else
            printf("%3d", i);
    }
     printf("=====================");
     printf("\n");
    break;
case 4: case 6: case 9: case 11:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================");
    printf("\n");
      if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 31; i++){
        if(((i + day -1) % 7 == 6) || i == 30){
        printf("%3d\n", i);
        }
         else
            printf("%3d", i);
    }
    printf("=====================");
    printf("\n");
    break;
case 2:
    if(day < 0)
    {
         printf("invalid\n");
         break;
    }
    else
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================");
    printf("\n");
      if(day == 6)
            printf("                  ");
    else if(day == 5)
            printf("               ");
    else if(day == 4)
            printf("            ");
    else if(day == 3)
            printf("         ");
    else if(day == 2)
            printf("      ");
    else if(day == 1)
            printf("   ");
    for(i = 1; i < 29; i++){
        if(((i + day -1) % 7 == 6) || i == 28){
        printf("%3d\n", i);
        }
         else
            printf("%3d", i);
    }
    printf("=====================");
    printf("\n");
    break;
    default :
    printf("invalid\n");
}
    }
}

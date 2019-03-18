#include<stdio.h>
#include<ctype.h>
char map[200][1000];
void instruction(int width, int height, int number[15], int j)
{
    int i,k,l;
    for(l = 0; l < height; l++)
        for(k = 0; k < width * j-1 ; k++)
            map[l][k] = ' ';
    for(i = 0; i < j; i++){
    switch(number[i]){
case 0:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2){
        map[l][0 + width * i] = '0';
        map[l][width -2 + width * i] = '0';
    }
    for(k = 1; k < width -2; k++){
        map[0][k+ width * i] = '0';
        map[height-1][k + width * i] = '0';
    }
    break;
case 1:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2)
        map[l][width -2 + width * i] = '1';
    break;
case 2:
    for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][0 + width * i] = '2';
    for(l = 1; l < (height-1)/2; l++)
        map[l][width -2 + width * i] = '2';

    for(k = 1; k < width -2; k++){
        map[0][k + width * i] = '2';
        map[(height-1)/2][k + width * i] = '2';
        map[height-1][k + width * i] = '2';
    }
    break;
case 3:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2)
        map[l][width -2 + width * i] = '3';
    for(k = 1; k < width -2; k++){
        map[0][k+ width * i] = '3';
        map[(height-1)/2][k + width * i] = '3';
        map[height-1][k + width * i] = '3';
    }
    break;
case 4:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2)
        map[l][width -2 + width * i] = '4';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '4';
    for(k = 1; k < width -2; k++)
        map[(height-1)/2][k + width * i] = '4';
    break;
case 5:
    for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][width-2 + width * i] = '5';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '5';
    for(k = 1; k < width -2; k++){
        map[0][k + width * i] = '5';
        map[(height-1)/2][k + width * i] = '5';
        map[height-1][k + width * i] = '5';
    }
    break;
case 6:
   for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][width-2 + width * i] = '6';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '6';
    for(k = 1; k < width -2; k++){
        map[0][k + width * i] = '6';
        map[(height-1)/2][k + width * i] = '6';
        map[height-1][k + width * i] = '6';
    }
    for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][0 + width * i] = '6';

    break;
case 7:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2)
        map[l][width -2 + width * i] = '7';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '7';
     for(k = 1; k < width -2; k++)
        map[0][k + width * i] = '7';

    break;
case 8:
    for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][width-2 + width * i] = '8';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '8';
    for(k = 1; k < width -2; k++){
        map[0][k + width * i] = '8';
        map[(height-1)/2][k + width * i] = '8';
        map[height-1][k + width * i] = '8';
    }
    for(l = (height-1)/2 + 1 ; l < height - 1; l++)
        map[l][0 + width * i] = '8';
    for(l = 1; l < (height-1)/2; l++)
        map[l][width -2 + width * i] = '8';
    break;
case 9:
    for(l = 1; l < height - 1; l++)
    if(l != (height-1)/2)
        map[l][width -2 + width * i] = '9';
    for(l = 1; l < (height-1)/2; l++)
        map[l][0 + width * i] = '9';
    for(k = 1; k < width -2; k++)
        map[(height-1)/2][k + width * i] = '9';
    for(k = 1; k < width -2; k++)
        map[0][k+ width * i] = '9';
    break;
}
}

int count = 0;
   for(l = 0; l < height; l++)
        for(k = 0; k < width * j-1; k++){
            if(count % (width * j) == width * j- 2){
            printf("%c\n", map[l][k]);
            count++;
        }
            else{
                printf("%c", map[l][k]);
                count++;
            }
        }
}

int main(void)
{
         int i=0, j, k, width, height, number[150];
         char c[1000];
         while(scanf("%c", &c[i]) != EOF){
            if(c[i] == '\n'){
                if(isspace(c[i-2])){
                    height = c[i-1] - '0';
                    width = c[i-3] - '0';
                    for(j = 0; j < i-4; j++)
                        number[j] = c[j] - '0';
                    instruction(width, height, number, j);
                    i = 0;
                    continue;
                }
                else{
                    height = (c[i-2] - '0') * 10 + c[i-1] - '0';
                    width = c[i-4] - '0';
                    for(j = 0; j < i-5; j++)
                        number[j] = c[j] - '0';
                     instruction(width, height, number, j);
                     i = 0;
                     continue;
                }
            }
            else
            i++;
         }

return 0;
}

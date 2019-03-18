#include<stdio.h>
int main(void)
{
    int n, m, x = 0, y = 0, instruction;
    scanf("%d%d", &n, &m);
    printf("%d\n%d\n", x, y);
    while(scanf("%d", &instruction) != EOF){
        if(instruction % 5 == 1){
            if(x +instruction < n){
            x += instruction;
            printf("%d\n%d\n", x, y);
            continue;
            }
            else
              continue;
        }
        else if(instruction % 5 == 2){
          if(x - instruction >= 0){
            x -= instruction;
            printf("%d\n%d\n", x, y);
            continue;
            }
            else
               continue;
        }
        else if(instruction % 5 == 3){
            if(y + instruction < m){
            y += instruction;
            printf("%d\n%d\n", x, y);
            continue;
            }
            else
                continue;
        }
        else if(instruction % 5 == 4){
           if(y - instruction >= 0){
            y -= instruction;
            printf("%d\n%d\n", x, y);
            continue;
           }
           else
            continue;
        }
        else if(instruction % 5 == 0)
            continue;
    }
}

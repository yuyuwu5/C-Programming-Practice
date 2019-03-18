#include<stdio.h>
#include<string.h>
int main()
{
    char food[105][70], ingredient[105][15][70], request_food[10][70];
    char *ptr;
    int how_many_food, how_ingredient[105], request;
    int food_num0, food_num1, flag = 0, count = 0;
    char output[105][70];
    scanf("%d",&how_many_food);
    for(int i = 0; i < how_many_food; i++){
        scanf("%s",food[i]);
        scanf("%d",&how_ingredient[i]);
        for(int j = 0; j < how_ingredient[i]; j++){
            scanf("%s", ingredient[i][j]);
        }
    }
    scanf("%d", &request);
    for(int i = 0; i < request; i++){
        scanf("%s%s", request_food[0], request_food[1]);
        for(int j = 0; j < how_many_food; j++){
            if(strlen(food[j]) == strlen(request_food[0])){
                if(strlen(request_food[0]) >=3){
                if((food[j][0] == request_food[0][0]) && (food[j][1] == request_food[0][1]) && (food[j][2] == request_food[0][2])){
                    food_num0 = j;
                    break;
                }
                }
                else {
                    if((food[j][0] == request_food[0][0]) && (food[j][strlen(food[j])-1] == request_food[0][strlen(request_food[0])-1])){
                    food_num0 = j;
                    break;
                }
                }
            }
        }
        for(int j = 0; j < how_many_food; j++){
            if(strlen(food[j]) == strlen(request_food[1])){
                    if(strlen(request_food[1]) >=3){
                if((food[j][0] == request_food[1][0]) && (food[j][1] == request_food[1][1]) && (food[j][2] == request_food[1][2])){
                    food_num1 = j;
                    break;
                }
            }
             else {
                    if((food[j][0] == request_food[1][0]) && (food[j][strlen(food[j])-1] == request_food[1][strlen(request_food[1])-1])){
                    food_num1 = j;
                    break;
                }
                }
        }
        }

       for(int j = 0; j < how_ingredient[food_num0]; j++){
         for(int k = 0; k < how_ingredient[food_num1]; k++){
            if(strlen(ingredient[food_num0][j]) == strlen(ingredient[food_num1][k])){
                    if(strlen((ingredient[food_num0][j])) >= 3){
            if((ingredient[food_num0][j][0] == ingredient[food_num1][k][0])
                  && (ingredient[food_num0][j][1] == ingredient[food_num1][k][1]) &&(ingredient[food_num0][j][2] == ingredient[food_num1][k][2])){
                 strcpy(output[count], ingredient[food_num0][j]);
                count++;
                break;
            }
                    }
                   else{
                            if((ingredient[food_num0][j][0] == ingredient[food_num1][k][0])&&
                                (ingredient[food_num0][j][strlen((ingredient[food_num0][j]))-1] == ingredient[food_num1][k][strlen((ingredient[food_num1][k]))-1])){
                  strcpy(output[count], ingredient[food_num0][j]);
                  count++;
                  break;
                                }
                   }
         }
        }
  }
        if(count == 0){
            printf("nothing\n");
            continue;
        }
        else{
            char temp[70];
            if(count == 2){
                    if(strcmp(output[0], output[1]) > 0){
                        strcpy(temp, output[0]);
                        strcpy(output[0], output[1]);
                        strcpy(output[1], temp);
                    }
                }
            else{
            for(int j = count-2; j >= 0; j--){
             for(int k = 0; k <= j; k++){
                if(strcmp(output[k], output[k+1]) > 0){
                    strcpy(temp, output[k]);
                    strcpy(output[k], output[k+1]);
                    strcpy(output[k+1], temp);
                }
            }
            }
        }
            for(int j = 0; j < count; j++){
                if(j == count-1)
                    printf("%s", output[j]);
                else
                printf("%s ", output[j]);
            }
            count = 0;
        }
        printf("\n");

    }
}

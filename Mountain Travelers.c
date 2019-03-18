#include <stdio.h>
//#include "travel.h"
int map[1024][1024], newmap[1024][1024];
void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[])
{
    int h, j, max, min , k, l, m, n, counta = 0, countb=0;
    for(h = 0; h < N; h++)
        for(j = 0; j < M; j++)
          newmap[h][j] = map[h][j];

    newmap[A_r][A_c] = -1;
    newmap[B_r][B_c] = -2;
    int flaga = 0, flagb = 0;

    while(flaga == 0 || flagb == 0){
    if(flaga == 0){
    max = map[A_r][A_c];
    for(h = -1; h <= 1; h++)
     for(j = -1; j <= 1; j++){
       if(A_r+h >= 0 && A_r+h < N && A_c+j >= 0 && A_c+j < M){
          if(max < map[A_r+ h][A_c + j]){
           max = map[A_r+ h][A_c + j];
           k = h;
           l = j;
          }
       }
    }
        if(max == map[A_r][A_c]){
            directionA[counta] = -1;
            counta++;
            flaga = 1;
        }

        else {
          A_r += k;
          A_c += l;
             if(k == 0 && l == 1){
            directionA[counta] = 0;
            counta++;
             }
             if(k == 0 && l == -1){
            directionA[counta] = 1;
             counta++;
             }
             if(k == 1 && l == 0){
            directionA[counta] = 2;
             counta++;
             }
             if(k == -1 && l == 0){
            directionA[counta] = 3;
             counta++;
             }
             if(k == 1 && l == 1){
            directionA[counta] = 4;
             counta++;
             }
             if(k == -1 && l == -1){
            directionA[counta] = 5;
             counta++;
             }
             if(k == -1 && l == 1){
            directionA[counta] = 6;
             counta++;
             }
             if(k == 1 && l == -1){
            directionA[counta] = 7;
             counta++;
             }
          }
          if(newmap[A_r][A_c] == -2){
             directionA[counta] = -1;
             counta++;
             flaga = 1;
          }
        }
    if(flagb == 0){
    min = map[B_r][B_c];
    for(h = -1; h <= 1; h++)
     for(j = -1; j <= 1; j++){
       if(B_r+h >= 0 && B_r+h < N && B_c+j >= 0 && B_c+j < M){
          if(min > map[B_r+ h][B_c + j]){
           min = map[B_r+ h][B_c + j];
           m = h;
           n = j;
          }
       }
   }
           if(min == map[B_r][B_c]){
            directionB[countb] = -1;
            countb++;
            flagb = 1;
        }
        else {
          B_r += m;
          B_c += n;
            if(m == 0 && n == 1){
            directionB[countb] = 0;
            countb++;
            }
             if(m == 0 && n == -1){
            directionB[countb] = 1;
             countb++;
            }
             if(m == 1 && n == 0){
            directionB[countb] = 2;
             countb++;
            }
             if(m == -1 && n == 0){
            directionB[countb] = 3;
             countb++;
            }
             if(m == 1 && n == 1){
            directionB[countb] = 4;
             countb++;
            }
             if(m == -1 && n == -1){
            directionB[countb] = 5;
             countb++;
            }
             if(m == -1 && n == 1){
            directionB[countb] = 6;
             countb++;
            }
             if(m == 1 && n == -1){
            directionB[countb] = 7;
             countb++;
            }
           if(newmap[B_r][B_c] == -1){
             directionB[countb] = -1;
             countb++;
             flagb =1;
          }
    }
    }
    if(B_r ==A_r && B_c == A_c){
        directionA[counta] = -1;
        directionB[countb] = -1;
        break;
    }
    else{
        newmap[A_r][A_c] = -1;
        newmap[B_r][B_c] = -2;
    }

   }
}

int main() {
    int N, M;
    int A_r, A_c, B_r, B_c;
    int directionA[1024], directionB[1024];

    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    scanf("%d%d%d%d", &A_r, &A_c, &B_r, &B_c);

    travel(map, N, M, A_r, A_c, B_r, B_c, directionA, directionB);

    int i = 0;
    while (directionA[i] != -1) {
        printf("%d ", directionA[i]);
        i++;
    }
    printf("-1\n");
    i = 0;
    while (directionB[i] != -1) {
        printf("%d ", directionB[i]);
        i++;
    }
    printf("-1\n");

    return 0;
}

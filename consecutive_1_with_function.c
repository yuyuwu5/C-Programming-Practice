#include <stdio.h>
#define MAXN 256
int findLength (int array[][256], int N, int r, int c, int dr, int dc){
    int conti=0,max=-1;
    if(dr==1&&dc==0){
        int start=r;
    while(start<N){
        if(array[start][c]){
            conti++;
        }else{
            if(max<conti)max=conti;
            conti=0;
        }
            start++;
        }
    if(max<conti)max=conti;
    }else if(dr==1&&dc==1){
        int start_y=r,start_x=c;
        while(start_x<N&&start_y<N){
        if(array[start_y][start_x]){
                    conti++;
        }else{
            if(max<conti)max=conti;
            conti=0;
        }
            start_x++;
            start_y++;
        }
    if(max<conti)max=conti;
    }else if(dr==0&&dc==1){
        int start=c;
        while(start<N){
        if(array[r][start]==1){
            conti++;
        }else{
            if(max<conti)max=conti;
            conti=0;
        }
            start++;
        }
    if(max<conti)max=conti;
    }else if(dr==-1&&dc==1){
        int start_y=r,start_x=c;
        while(start_y>=0&&start_x<N){
        if(array[start_y][start_x]){
                    conti++;
        }else{
            if(max<conti)max=conti;
            conti=0;
        }
            start_y--;
            start_x++;
        }
    if(max<conti)max=conti;
    }return max;
}
int main () {
    int array[256][256];
    int N, r, c;
    int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);
    int max=-1;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                int tmp=findLength(array, N, i, j, direction[k][0], direction[k][1]);
                if(max<tmp)max=tmp;
            }

        }
    }
    printf("%d\n",max );
}

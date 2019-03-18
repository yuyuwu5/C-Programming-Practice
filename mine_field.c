#include<stdio.h>
#include<stdlib.h>
int out[10][10]={0},field[10][10];
void set(int r,int c,int v){
    for(int i=r-1;i<=r+1;i++)
            for(int j=c-1;j<=c+1;j++)
                field[i+1][j+1]+=v;
}
void print(){
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            printf("%d%c",out[i][j],(j==8)?'\n':' ');
}
int check(){
    for(int i=1;i<=9;i++)
        for(int j=1;j<=9;j++)
            if(field[i][j]!=0) return 0;
    return 1;
}
void Bomb(int ind){
    if(ind==81) {
        if(check()){
            print();
            exit(0);
        }return;
    }int r=ind/9 , c=ind%9; 
    if(field[r][c]>1) return; 
    else if(field[r][c]==1){
        out[r][c]=1;
        set(r,c,-1);
        Bomb(ind+1);
        out[r][c]=0;
        set(r,c,1);
        return;
    }int conflict=0;
    for(int i=r-1;i<=r+1;i++)
        for(int j=c-1;j<=c+1;j++)
            if(field[i+1][j+1]==0) conflict=1;
    if(!conflict){
        out[r][c]=1;
        set(r,c,-1);
        Bomb(ind+1);
        out[r][c]=0;
        set(r,c,1);
    }Bomb(ind+1);
}
int main(){
    for(int i=1;i<10;i++)for(int j=1;j<10;j++)scanf("%d",&field[i][j]);
    for(int i=0;i<10;i++) field[i][0]=field[0][i]=field[i][10]=field[10][i]=-1;
    Bomb(0) ;
    printf("no solution\n");
}

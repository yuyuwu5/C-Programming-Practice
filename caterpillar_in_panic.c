#include<stdio.h>
int Y,X,map[1002][1002]={0},move_y[1010002],move_x[1010002],h_y,h_x,t_y,t_x;
void print(){
    for(int i=0;i<Y;i++){
        for(int j=0;j<X;j++){
            printf("%d",map[i][j]);
        }puts("");
    }
}
int main(){
    int num,now=0;
    scanf("%d%d%d%d%d%d%d",&Y,&X,&h_y,&h_x,&t_y,&t_x,&num);
    if(h_y==t_y){
        if(h_x>t_x)
            for(int i=t_x;i<=h_x;i++){
            map[h_y][i]=1;
            move_y[now]=h_y;
            move_x[now++]=i;
 
        }else for(int i=t_x;i>=h_x;i--){
            map[h_y][i]=1;
            move_y[now]=h_y;
            move_x[now++]=i;
        }
    }else{
        if(h_y>t_y)for(int i=t_y;i<=h_y;i++){
            map[i][h_x]=1;
            move_x[now]=h_x;
            move_y[now++]=i;
        }else for(int i=t_y;i>=h_y;i--){
            map[i][h_x]=1;
            move_x[now]=h_x;
            move_y[now++]=i;
        }
    }int ta=1;
    for(int i=0;i<num;i++){
        int instruct;
        scanf("%d",&instruct);
        map[t_y][t_x]=0;
        if(instruct==0){
            if(h_y+1<Y&&map[h_y+1][h_x]==0){
                h_y++;
                map[h_y][h_x]=1;
                move_x[now]=h_x;
                move_y[now++]=h_y;
                t_y=move_y[ta];
                t_x=move_x[ta++];
            }else {
                map[t_y][t_x]=1;
                print();
                return 0;
            }
        }
        if(instruct==1){
            if(h_y-1>=0&&map[h_y-1][h_x]==0){
                h_y--;
                map[h_y][h_x]=1;
                move_x[now]=h_x;
                move_y[now++]=h_y;
                t_y=move_y[ta];
                t_x=move_x[ta++];
            }else {
                map[t_y][t_x]=1;
                print();
                return 0;
            }
        }
        if(instruct==2){
            if(h_x+1<X&&map[h_y][h_x+1]==0){
                h_x++;
                map[h_y][h_x]=1;
                move_x[now]=h_x;
                move_y[now++]=h_y;
                t_y=move_y[ta];
                t_x=move_x[ta++];
            }else {
                map[t_y][t_x]=1;
                print();
                return 0;
            }
        }
        if(instruct==3){
            if(h_x-1>=0&&map[h_y][h_x-1]==0){
                h_x--;
                map[h_y][h_x]=1;
                move_x[now]=h_x;
                move_y[now++]=h_y;
                t_y=move_y[ta];
                t_x=move_x[ta++];
            }else {
                map[t_y][t_x]=1;
                print();
                return 0;
            }
        }
    }print();
}

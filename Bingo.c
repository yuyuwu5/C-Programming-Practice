#include<stdio.h>
int map[10][256][256],n,m;
int count_row[10][256]={0}, count_column[10][256]={0},count_diagonal[10][2]={0},winer[10];
int check(int lucky_num)
{
  int index=0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < m; k++){
        //printf("aaaaaaa\n");
        if(map[i][j][k]==lucky_num){
          //printf("%d %d %d\n",count_row[i][k],count_column[i][j],count_diagonal[i][0],count_diagonal[i][1]);          
          count_row[i][k]++;
          count_column[i][j]++;
          if(j==k)
            count_diagonal[i][0]++;
          if(j==m-k-1)
            count_diagonal[i][1]++;
          if(count_row[i][k]==m || count_column[i][j]==m || count_diagonal[i][1]==m || count_diagonal[i][0]==m){
            winer[index++]=i;
            //printf("%d %d %d\n",count_row[i][k],count_column[i][j],count_diagonal[i][0],count_diagonal[i][1]);
          }
          //printf("%d %d %d\n",count_row[i][k],count_column[i][j],count_diagonal[i][0],count_diagonal[i][1]);  
        }
      }
    }
  }//printf("%d\n",index);
  return index;
}
int main()
{
  scanf("%d%d",&n,&m);
  char name[10][64];
  for(int i = 0; i < n; i++){
    scanf("%s",name[i]);
    for(int j = 0; j < m; j++){
      for(int k = 0; k < m; k++){
        scanf("%d",&map[i][j][k]);
       // printf("%d ",map[i][j][k]);
      }
     // printf("\n");
    }
    //printf("\n");
  }
  //printf("%d\n",count_diagonal[1][1]);
  int lucky_num,stop=0;
  while(scanf("%d",&lucky_num)!=EOF){
    stop=check(lucky_num);
    if(stop>0){
      printf("%d",lucky_num);
      for(int i = 0; i < stop; i++)
        printf(" %s",name[winer[i]]);
      break;
    }
  }
}
#include <stdio.h>
void find_sort(int in, int bookshelf[],int count,int ss)
{
    int flag=-1;
    for(int i = 0; i < count; i++)
        if(in==bookshelf[i]){flag=i;}
    //printf("%d %d\n", in,bookshelf[0]);
    //printf("%d\n", flag);
    if(flag==-1){
        if(ss==0){bookshelf[count-1]=in;}
        else{
            for (int i = 0; i < count-1; i++)
                bookshelf[i]=bookshelf[i+1];
            bookshelf[7]=in;
    }
    }else{
        for(int i = flag; i < count-1; i++)
            bookshelf[i]=bookshelf[i+1];
 
        bookshelf[count-1]=in;
    }
    //for(int i = 0; i < 8; i++)
    //    printf("%d ", bookshelf[i]);
    //printf("\n");
    return;
}
int main(void)
{
    int bookshelf[9]={0}, in,count=0,ss=0,temp=0;
    while(scanf("%d",&in)!=EOF){
        if(count < 8){
            for(int i = 0; i < count;i++)
                if(bookshelf[i]==in){temp=1;}
            if(temp==0){count++;}
        }
        //printf("%d\n",count);
        //printf("%d\n",ss);
        find_sort(in,bookshelf,count,ss);
        if(count==8){ss=1;}
        temp=0;
    }
    if(count==8){
    for(int i = 0; i < 7; i++)
        printf("%d ", bookshelf[i]);
    printf("%d", bookshelf[7]);
    }
    if(count<8){
        for(int i=0; i <8-count;i++)
            printf("0 ");
        for(int i = 0; i < count-1;i++)
            printf("%d ",bookshelf[i]);
        printf("%d", bookshelf[count-1]);
    }

}
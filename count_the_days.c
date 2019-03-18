#include<stdio.h>
#include <stdlib.h>
void count_day(int year, int day, int month, int results[7]){
	int start=day-1,days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%400==0||year%4==0&&year%100!=0)days[2]=29;
	for(int i=1;i<month;i++){
		for(int j=1;j<=days[i];j++){
			start++;
			start%=7;
		}
	}
	for(int i=1;i<=days[month];i++){
		start++;
		start%=7;
		results[start]++;
	}
}
int main(){
    int year, day, month, results[7] = {0}, i;

    while(scanf("%d %d %d", &year, &day, &month) == 3){
        for(i = 0; i < 7; i++)
            results[i] = 0;
        count_day(year, day, month, results);
        for(i = 0; i < 6; i++)
            printf("%d ", results[i]);
        printf("%d\n", results[i]);
    }
    return 0;
}

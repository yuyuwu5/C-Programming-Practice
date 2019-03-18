#include<stdio.h>
int  allstudent[32768] = {0}, student[32768][256], friends[32768] = {0}, party[32768];
int main(void)
{
    int n, e, i, num1, num2;
    scanf("%d%d", &n, &e);
   int k = 0, j = 0;
    for(i = 0; i < e; i++){
        scanf("%d%d", &num1, &num2);
        student[num1][friends[num1]] = num2;
        friends[num1]++;
        student[num2][friends[num2]] = num1;
        friends[num2]++;
    }


  while(scanf("%d", &party[k]) != EOF)
     k++;

  for(j = 0; j < k; j++){
  for(i = 0; i < friends[party[j]]; i++)
   allstudent[student[party[j]][i]] = 1;
  }
  for(j = 0; j < k; j++)
   allstudent[party[j]] = 1;


   for(i = 0; i < n; i++)
    if(allstudent[i] == 0)
    printf("%d\n", i);

   return 0;
}

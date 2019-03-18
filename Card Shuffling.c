#include <stdio.h>
//#include "card.h"
 void shuffle(int *deck[])
 {
     int i = 0, j, k;
     int stake1, stake2;
     int array1[5000] = {0}, array2[5000] = {0}, newarray[10000];
     while(deck[i] != NULL)
        i++;
     if(i % 2 == 0)
        stake1 = i / 2;
     else
        stake1 = (i + 1)/2;
     stake2 = i - stake1;
     for(j = 0; j < stake1; j++)
        array1[j] = *deck[j];
     for(j = stake1; j < i; j++)
        array2[j-stake1] = *deck[j];
     int count = 0;
     for(j = 0; j < i; j=j+2){
        if(array1[count] != 0)
        newarray[j] = array1[count];
        if(array2[count] != 0)
        newarray[j+1] = array2[count];
        count++;
     }
     count = 0;
     for(j = 0; j < i; j++)
        *deck[j] = newarray[j];


 }
 void print(int *deck[])
 {
     int i = 0, j;
     while(deck[i] != NULL)
        i++;
     for(j = 0; j < i; j++){
        if(j != i-1)
        printf("%d ", *deck[j]);
        else
        printf("%d", *deck[j]);
     }
 }
int main()
{
  int card[10000];
  int *deck[10000];
  int index = 0;

  while (scanf("%d", &(card[index])) != EOF) {
    deck[index] = &(card[index]);
    index++;
  }
  deck[index] = NULL;
  shuffle(deck);
  print(deck);
  return 0;
}

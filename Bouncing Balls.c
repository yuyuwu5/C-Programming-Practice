#include<stdio.h>
int main(void)
{
   int x, y, x1, y1, x2, y2, dx1, dy1, dx2, dy2, t, i;
   scanf("%d%d%d%d%d%d%d%d%d%d%d",  &x, &y, &x1, &y1, &x2, &y2, &dx1, &dy1, &dx2, &dy2, &t);
  while(t > 0)
  {
    if(x1 == x2 && y1 == y2 ){
    if((x1 == 1 && y1 == 1) || (x1 == 1 && y1 == y) || (x1 == x && y1 == 1) || (x1 == x && y1 == y)){
        dx1 = -dx1;
        dy1 = -dy1;
        x1 += dx1;
        y1 += dy1;
        dx2 = -dx2;
        dy2 = -dy2;
        x2 += dx2;
        y2 += dy2;
        t--;
        continue;
    }
    else if(x1 == 1 || x1 == x || y1 == 1 || y1 == y){
         dx1 = -dx1;
        dy1 = -dy1;
        x1 += dx1;
        y1 += dy1;
        dx2 = -dx2;
        dy2 = -dy2;
        x2 += dx2;
        y2 += dy2;
        t--;
        continue;
    }
    else{
         int temp;
        temp = dx1;
         dx1 = dx2;
         dx2 = temp;

        temp = dy1;
         dy1 = dy2;
         dy2 = temp;

         x1 += dx1;
         y1 += dy1;
         x2 += dx2;
         y2 += dy2;
         t--;
         continue;
      }
 }
   else{
      if((x1 == 1 && y1 == 1) || (x1 == x && y1 == y) || (x1 == x && y1 == 1) || (x1 == 1 && y1 == y)){
        dx1 = -dx1;
        dy1 = -dy1;
        x1 += dx1;
        y1 += dy1;
      }
      else if(x1 == 1 || x1 == x){
        dx1 = -dx1;
        x1 += dx1;
        y1 += dy1;
      }
      else if(y1 == 1 || y1 == y){
        dy1 = -dy1;
        x1 += dx1;
        y1 += dy1;
      }
      else{
        x1 += dx1;
        y1 += dy1;
      }

      if((x2 == 1 && y2 == 1) || (x2 == x && y2 == y) || (x2 == x && y2 == 1) || (x2 == 1 && y2 == y)){
        dx2 = -dx2;
        dy2 = -dy2;
        x2 += dx2;
        y2 += dy2;
      }
      else if(x2 == 1 || x2 == x){
        dx2 = -dx2;
        x2 += dx2;
        y2 += dy2;
      }
      else if(y2 == 1 || y2 == y){
        dy2 = -dy2;
        x2 += dx2;
        y2 += dy2;
      }
      else{
        x2 += dx2;
        y2 += dy2;
      }
  }
  t--;
  }
  printf("%d\n%d\n%d\n%d\n", x1, y1, x2, y2);
}


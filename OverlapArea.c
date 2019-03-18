#include<stdio.h>
int square(int x1, int y1,int x2,int y2)
{
	return (x2-x1)*(y2-y1);
}
int determine(int ax1,int ay1,int ax2,int ay2,int bx1,int by1,int bx2,int by2)
{
    int newx1=0,newy1=0,newx2=0,newy2=0,area;
	if (ax1<=bx1 && ax2<=bx2 && ax2>=bx1){
    	newx1=bx1;
    	newx2=ax2;
    }if (ax1>=bx1 && ax2>=bx2 && ax1<=bx2){
    	newx1=ax1;
    	newx2=bx2;
    }if (ay1<=by1 && ay2<=by2 && ay2>=by1){
    	newy1=by1;
    	newy2=ay2;
    }if (ay1>=by1 && ay2>=by2 && ay1<=by2){
    	newy1=ay1;
    	newy2=by2;
    }if (ax1>=bx1 && ax2<=bx2){
        newx1=ax1;
        newx2=ax2;	
    }if (ax1<=bx1 && ax2>=bx2){
    	newx1=bx1;
    	newx2=bx2;
    }if (ay1>=by1 && ay2<=by2){
        newy1=ay1;
        newy2=ay2;	
    }if (ay1<=by1 && ay2>=by2){
    	newy1=by1;
    	newy2=by2;
    }
    area= square(newx1,newy1,newx2,newy2);
    return area;
}
int max(int a,int b,int c)
{
	int max;
	if(b>=a){max=b;}
	else{max=a;}
	if(c>max){max=c;}
	return max;
}
int min(int a,int b,int c)
{
	int min;
	if(b>=a){min=a;}
	else{min=b;}
	if(c<min){min=c;}
	return min;
}
int main(void)
{
    int ax1,ay1,ax2,ay2,bx1,by1,bx2,by2,cx1,cy1,cx2,cy2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&ax1,&ay1,&ax2,&ay2,&bx1,&by1,&bx2,&by2,&cx1,&cy1,&cx2,&cy2);
    int a, b, c, a_and_b, a_and_c, b_and_c, a_and_b_and_c;
    a = square(ax1,ay1,ax2,ay2);
    b = square(bx1,by1,bx2,by2);
    c = square(cx1,cy1,cx2,cy2);
    a_and_b = determine(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2);
    a_and_c = determine(ax1,ay1,ax2,ay2,cx1,cy1,cx2,cy2);
    b_and_c = determine(bx1,by1,bx2,by2,cx1,cy1,cx2,cy2);
    int gx1,gy1,gx2,gy2;
    if(a_and_b!=0 && a_and_c!=0 && b_and_c !=0){
    	gx1=max(ax1,bx1,cx1);
    	gx2=min(ax2,bx2,cx2);
    	gy1=max(ay1,by1,cy1);
    	gy2=min(ay2,by2,cy2);
    	a_and_b_and_c=square(gx1,gy1,gx2,gy2);
    }else{a_and_b_and_c = 0;}
    printf("%d\n",a+b+c-a_and_b-a_and_c-b_and_c+a_and_b_and_c);
    //printf("%d %d %d\n", a,b,c);
    //printf("%d %d %d %d\n", gx1,gy1,gx2,gy2);   
}

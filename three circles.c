#include <stdio.h>
main()
{
	long long int xa, ya, xb, yb, xc, yc;
	int ra, rb, rc;
	int num, i;
	long long int m, n;
	scanf("%d", &num);
	for(i = 1 ; i<= num ; i++){
		int count = 0;
		scanf("%lld%lld%d%lld%lld%d%lld%lld%d", &xa, &ya, &ra, &xb, &yb, &rb, &xc, &yc, &rc);
		for(m = xa-ra ; m <= xa+ra ; m++){
			for(n = ya-ra ; n <= ya+ra ; n++){
				if((((m-xa)*(m-xa)+(n-ya)*(n-ya)) <= ra*ra)&&(((m-xb)*(m-xb)+(n-yb)*(n-yb)) <= rb*rb)&&(((m-xc)*(m-xc)+(n-yc)*(n-yc)) <= rc*rc)){
					count++;
				}
				}
		}
		for(m = xa-ra ; m <= xa+ra ; m++){
			for(n = ya-ra ; n <= ya+ra ; n++){
				if((((m-xa)*(m-xa)+(n-ya)*(n-ya)) <= ra*ra)&&(((m-xb)*(m-xb)+(n-yb)*(n-yb)) > rb*rb)&&(((m-xc)*(m-xc)+(n-yc)*(n-yc)) > rc*rc)){
					count++;
				}
				}
		}
		for(m = xb-rb ; m <= xb+rb ; m++){
			for(n = yb-rb ; n <= yb+rb ; n++){
				if((((m-xb)*(m-xb)+(n-yb)*(n-yb)) <= rb*rb)&&(((m-xa)*(m-xa)+(n-ya)*(n-ya)) > ra*ra)&&(((m-xc)*(m-xc)+(n-yc)*(n-yc)) > rc*rc)){
					count++;
				}
				}
		}
		for(m = xc-rc ; m <= xc+rc ; m++){
			for(n = yc-rc ; n <= yc+rc ; n++){
				if((((m-xc)*(m-xc)+(n-yc)*(n-yc)) <= rc*rc)&&(((m-xa)*(m-xa)+(n-ya)*(n-ya)) > ra*ra)&&(((m-xb)*(m-xb)+(n-yb)*(n-yb)) > rb*rb)){
					count++;
				}
				}
		}
		printf("%d\n", count);
	}
}

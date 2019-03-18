#include <stdio.h>
int main()
{
  unsigned long long a, b, n;
  while(scanf("%llu%llu%llu",&a,&b,&n)!=EOF)
  	printf("%llu\n", (unsigned long long)(((unsigned __int128)(a % n) * (b % n)) % n));
}
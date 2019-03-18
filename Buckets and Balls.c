#include<stdio.h>
int main(void)
{
    int r, capa, capb, weight;
    scanf("%d%d%d", &capa,&capb,&r);
    while(scanf("%d", &weight) != EOF){
            switch(r){
        case 0:
            if(capa >= weight )
                capa -= weight;
            else if (capa <= weight && capb >= weight)
                capb -= weight;
            break;
        case 1:
            if(capa >= weight && capb < weight)
                capa -= weight;
            else if(capb >= weight && capa < weight)
                capb -= weight;
            if(capa >= weight && capb >= weight){
                if (capa - weight <= capb - weight)
                      capa -= weight;
                else if(capb - weight < capa - weight)
                      capb -= weight;
            }
             break;
    }
    printf("%d %d\n", capa, capb);
    }
}

#include<stdio.h>
main()
{
    int year, month, day, days, n, a, i, k, l;
    scanf("%d%d", &year, &day);
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
        year = 1;
    else
        year = 2;
    switch(year){
case 1 :
    scanf("%d", &a);
    for(i = 0; i < a; i++){
    scanf("%d%d", &month, &days);
    if((month <= 0) || (month > 12)){
        k = -1;
        printf("%d\n", k);
        continue;
    }
    if ((month > 0) && (month < 13))
        if ((month ==1) || (month ==3) || (month ==5) || (month ==7) ||
            (month ==8) || (month ==10) || (month ==12))
            if ((days > 31) || (days <= 0)){
                k = -2;
            printf("%d\n", k);
            continue;
            }

    if ((month > 0) && (month < 13))
        if ((month ==4) || (month ==6) || (month ==9) || (month ==11))
            if ((days > 30) || (days <= 0)){
                k = -2;
            printf("%d\n", k);
            continue;
            }

    if ((month > 0) && (month < 13))
        if (month ==2)
            if((days > 29) || (days <= 0)){
                k = -2;
            printf("%d\n", k);
             continue;
            }
    if (month == 1){
       k = (days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 2){
       k = (31 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 3){
       k = (60 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 4){
       k = (91 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 5){
       k = (121 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 6){
       k = (152 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 7){
       k = (182 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 8){
       k = (213 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 9){
       k = (244 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 10){
       k = (274 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 11){
       k = (305 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 12){
       k = (335 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }

    }


    break;
case 2 :
    scanf("%d", &a);
    for(i = 0; i < a; i++){
    scanf("%d%d", &month, &days);
    if((month <= 0) || (month > 12)){
            k = -1;
            printf("%d\n", k);
            continue;
        }

    if ((month > 0) && (month < 13))
        if ((month ==1) || (month ==3) || (month ==5) || (month ==7) ||
            (month ==8) || (month ==10) || (month ==12))
            if ((days > 31) || (days <= 0)){
                k = -2;
                printf("%d\n", k);
                continue;
            }
    if ((month > 0) && (month < 13))
        if ((month ==4) || (month ==6) || (month ==9) || (month ==11))
            if ((days > 30) || (days <= 0)){
                k = -2;
                printf("%d\n", k);
                continue;
            }
    if ((month > 0) && (month < 13))
        if (month ==2)
            if((days > 28) || (days <= 0)){
                k = -2;
                printf("%d\n", k);
                continue;
            }
        if (month == 1){
       k = (days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 2){
       k = (31 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 3){
       k = (59 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 4){
       k = (90 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 5){
       k = (120 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 6){
       k = (151 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 7){
       k = (181 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 8){
       k = (212 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 9){
       k = (243 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 10){
       k = (273 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 11){
       k = (304 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }
    if (month == 12){
       k = (334 + days - 1) % 7;
       l = (day + k) % 7;
       printf("%d\n", l);
       continue;
    }

    break;
    }
}
}

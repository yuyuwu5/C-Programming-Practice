#include"values.h"
int value(int type, int width, int height, int length)
{
    int i, money, k;
    switch (type)
    {
    case 79 :
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 30 * width * height * length ;
    return money;
        break;
    case 47:
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 10 *  width * height * length;
    return money;
        break;
    case 29:
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 4 *  width * height * length;
    return money;
        break;
    case 82:
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 5 *  width * height * length;
    return money;
        break;
    case 26:
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 3 *  width * height * length;
    return money;
        break;
    case 22:
        if(width <= 0 || height <= 0 || length <= 0){
            return -2;
            break;
    }
    else
    for(i = width; i > 0; i--){
        if(width % i == 0 && height % i == 0 && length % i == 0){
            k = i;
            break;
        }
    }
    money = k * k * k * 9 *  width * height * length;
    return money;
        break;

    default:
        return -1;
    }
}

int main(void)
{
    int type, width, height, length, price;
    scanf("%d%d%d%d", &type, &width, &height, &length);
    price = value(type, width, height, length);
    printf("%d\n", price);
}


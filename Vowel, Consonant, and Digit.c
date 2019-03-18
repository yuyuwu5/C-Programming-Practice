#include<stdio.h>
#include<ctype.h>
int main(void)
{
    int  digits = 0, letters = 0, vowels = 0, consonants = 0;
    char c;
    while(scanf("%c", &c) != EOF){
        if(isdigit(c))
            digits++;
        if(isalpha(c)){
            letters++;
            if(c == 'a' || c == 'A' || c == 'e'|| c == 'E'|| c == 'I'|| c == 'i'|| c == 'O'|| c == 'o' || c == 'u' || c == 'U')
                vowels++;
            else
                consonants++;
        }
    }
    printf("%d %d %d %d", digits, letters, vowels, consonants);
}

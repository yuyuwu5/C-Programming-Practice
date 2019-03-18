#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "complex.h"
typedef struct{
    float a,b;
}complex;
complex *init(complex *c, float a, float b){
    c->a=a;
    c->b=b;
    return c;
}
void complex_print(complex *x){
    printf("%.3f%+.3fi\n", x->a, x->b);
}
complex complex_add(complex *x, complex *y){
    complex c;
    return *init(&c,x->a+y->a,x->b+y->b);
}
complex complex_sub(complex *x, complex *y){
    complex c;
    return *init(&c,x->a-y->a,x->b-y->b);
}
complex complex_mul(complex *x, complex *y){
    complex c;
    return *init(&c,x->a*y->a - x->b*y->b,x->a*y->b + x->b*y->a);
}
int main() {
    complex (*FUNC[])(complex *, complex *) = {
        complex_add, complex_sub, complex_mul
    };
    int cmd;
    float x, y, p, q;
    while (scanf("%d %f %f %f %f", &cmd, &x, &y, &p, &q) == 5) {
        complex *A = (complex *) malloc(sizeof(complex));
        complex *B = (complex *) malloc(sizeof(complex));
        init(A, x, y), init(B, p, q);
        complex C = FUNC[cmd](A, B);
        complex_print(&C);
    }
    return 0;
}
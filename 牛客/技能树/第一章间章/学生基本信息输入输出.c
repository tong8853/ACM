#include <stdio.h>

int main(){
    int id;
    double a, b, c;
    if(scanf("%d;%lf,%lf,%lf",&id,&a,&b,&c) == 4){
        a += 1e-6;
        b += 1e-6;
        c += 1e-6;
        printf("The each subject score of No. %d is %.2lf, %.2lf, %.2lf.",id,a,b,c);
    }
    return 0;
}
#include <stdio.h>
#include <math.h>

int main() 
{
    double S2 = 0;
    for (int i = 50; i >= 1; i--) {
        S2 += pow(2, i) / (51 - i);
    }
    
    printf("S2 = %lf\n", S2);
    return 0;
}
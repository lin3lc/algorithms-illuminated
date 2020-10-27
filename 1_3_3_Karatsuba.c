#include <stdio.h>
#include <stdlib.h>

/*
 * input    :two n-digit positive integers x and y.
 * output   :the product x*y.
 * assumption   :n is a power of 2.
 */

int karatsuba(int x, int y, int n);
int checkN(int x, int y);
void printMessage();

int main(int argc, char *argv[]){
    int length = argc - 1;
    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    int n = checkN(array[0], array[1]);

    int result = karatsuba(array[0], array[1], n);

    printf("%d ", result);
    puts("");
}

void printMessage(){
    printf("input    :two n-digit positive integers x and y.\n"  
            "assumption   :n is a power of 2.\n");
}

int checkN(int x, int y){
    if(x <= 0 || y <= 0){
        printMessage();
        exit(0);
    }
    int xN=1, yN=1;
    while(x /= 10){
        xN += 1;
    }
    while(y /= 10){
        yN += 1;
    }
    if(xN != yN || (xN & xN - 1)){
        printMessage();
        exit(0);
    }
    return xN;
}


int karatsuba(int x, int y, int n){
    if(n==1){
        return x*y;
    } else {
        n /= 2;

        int a = x;
        for(int i=0; i<n; i++){
            a /= 10;
        }
        int temp1 = a;
        for(int i=0; i<n; i++){
            temp1 *= 10;
        }

        int b = x-temp1;
                        
        int c = y;
        for(int i=0; i<n; i++){
            c /= 10;
        }
        int temp2 = c;
        for(int i=0; i<n; i++){
            temp2 *= 10;
        }
        int d = y-temp2;

        int p = a+b,
            q = c+d;

        int ac = karatsuba(a, c, n);
        int bd = karatsuba(b, d, n);

        int tempN = checkN(p, q);
        int pq = karatsuba(p, q, tempN);

        /*ad + bc*/
        int adbc = pq - ac - bd;

        int result = 0, 
            factor1 = 1, 
            factor2 = 1;
        for(int i=0; i<2*n; i++){
            factor1 *= 10;
        }
        for(int i=0; i<n; i++){
            factor2 *= 10;
        }
        result = factor1 * ac + factor2 * adbc + bd;

        return result;
    }
}

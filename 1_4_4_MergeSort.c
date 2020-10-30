#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void merge_sort(int *a, int p, int r);
void merge(int *a, int p, int q, int r);

int main(int argc, char *argv[]){
    int length = argc - 1;
    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    merge_sort(array, 0, length-1);

    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    puts("");
}


void merge_sort(int *a, int p, int r){
    if(r > p){
        int q = (r-p)/2 + p;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void merge(int *a, int p, int q, int r){
    int n1 = q-p+1,
        n2 = r-q;
    int left[n1+1],
        right[n2+1];
    left[n1] = right[n2] = INT_MAX;
    for(int i = 0; i < n1; i++){
        left[i] = a[p+i];
    }
    for(int i = 0; i < n2; i++){
        right[i] = a[q+1+i];
    }

    int j = 0, k = 0;
    for(int i = p; i <= r; i++){
        if(left[j] < right[k]){
            a[i] = left[j];
            j++;
        } else {
            a[i] = right[k];
            k++;
        }
    }
}

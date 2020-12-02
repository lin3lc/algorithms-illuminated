#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b);
int choose_pivot(int *arr, int l, int r);
int partition(int *arr, int l, int r);
void quicksort(int *arr, int l, int r);

int main(int argc, char **argv){
    int len = argc - 1;
    int array[len];

    for(int i=0; i<len; i++){
        array[i] = atoi(argv[i+1]);
    }

    quicksort(array, 0, len-1);

    for(int i=0; i<len; i++){
        printf("%d ", array[i]);
    }
    puts("");
}


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int choose_pivot(int *arr, int l, int r){
    srand((unsigned)time(NULL));
    int p = rand() % (r-l+1);
    return p;
}

/*以第一个元素为pivot*/
int partition(int *arr, int l, int r){
    int p_val = arr[l];
    int i = l+1;

    for(int j=i; j<=r; j++){
        if(arr[j]<p_val){
            swap(arr+i, arr+j);
            i++;
        }
    }
    swap(arr+l, arr+i-1);
    return i-1;
}

/*从小到大排*/
void quicksort(int *arr, int l, int r){
    if(r>l){
        //相对值
        int p = choose_pivot(arr, l, r);
        //不要忘了2边都要加l
        swap(arr+l, arr+l+p);
        //绝对值
        p = partition(arr, l, r);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, r);
    }
}

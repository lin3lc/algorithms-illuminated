#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b);
int choosePivot(int l, int r);
int partition(int *arr, int l, int r);
int rselect(int *arr, int l, int r, int i);

//输入格式:第一个是待查找的位置，后面是array
int main(int argc, char **argv){
    int order = atoi(argv[1]);
    int len = argc-2;
    int arr[len];
    for(int i = 0; i < len; i++){
        arr[i] = atoi(argv[i+2]);
    }

    int result = rselect(arr, 0, len-1, order);

    printf("the %dth order statistic of array is %d.\n", order, result);
}


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int choosePivot(int l, int r){
    srand((unsigned)time(NULL));
    int p = rand() % (r-l+1);
    return p;
}

int partition(int *arr, int l, int r){
    int i = l+1;
    int p_val = arr[l];
    for(int j = i; j <= r; j++){
        if(arr[j] < p_val){
            swap(arr+i, arr+j);
            i++;
        }
    }
    swap(arr+l, arr+i-1);
    return i-1;
}

int rselect(int *arr, int l, int r, int i){
    if(r == l){
        return arr[l];
    }else if(r > l){
        int p = choosePivot(l, r);
        swap(arr+l, arr+l+p);
        int pivot_order = partition(arr, l, r);
        int order = i-1;
        if(pivot_order == order){
            return arr[pivot_order];
        }else if(pivot_order > order){
            //取左边
            return rselect(arr, l, pivot_order-1, i); 
        }else if(pivot_order < order){
            //取右边
            return rselect(arr, pivot_order+1, r, i);
        }
    }
}

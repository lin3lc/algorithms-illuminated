#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
 * Input: array A of n distinct integers.
 */

int sort_and_count_inv(int *a, int p, int r);
int merge_and_count_split_inv(int *a, int p, int q, int r);

int main(int argc, char *argv[]){
    int length = argc - 1;
    int array[length];
    for(int i=0; i<length; i++){
        array[i] = atoi(argv[i+1]);
    }

    int result = sort_and_count_inv(array, 0, length-1);

    printf("the number of inversions is %d", result);
    puts("");
}

int sort_and_count_inv(int *a, int p, int r){
    if(r>p){
        int mid = (r+p)/2;

        int left_count = sort_and_count_inv(a, p, mid);
        int right_count = sort_and_count_inv(a, mid+1, r);
        int split_count = merge_and_count_split_inv(a, p, mid, r);

        return left_count + right_count + split_count;
    } else {
        return 0;
    }
}
int merge_and_count_split_inv(int *a, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int left[n1+1],
        right[n2+1];
    left[n1] = right[n2] = INT_MAX;

//复制2个临时数组
    for(int i=0; i<n1; i++){
        left[i] = a[p+i];
    }
    for(int i=0; i<n2; i++){
        right[i] = a[q+1+i];
    }


    int id1 = 0, id2 = 0, inv_count = 0;
    for(int i=p; i<=r; i++){
        if(left[id1] < right[id2]){
            a[i] = left[id1];
            id1++;
        } else {
            a[i] = right[id2];
            id2++;
            inv_count += n1 - id1;
        }
    }

    return inv_count;
}

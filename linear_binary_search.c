#include <stdio.h>

int linear_search(int arr[], int element, int size){
    for (int i=0; i<size; i++){
        if (arr[i] == element){
            return i+1;
        }
    }
    return 0;
}

int binary_search(int arr[], int element, int size){
    int l, m, h;
    l = 0;
    h = size-1;
    while (l<=h){
        m = (l+h)/2;
        if (arr[m] == element){
            return m+1;
        } else if (arr[m] < element){
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return 0;
}

int main(){
    int arr[20] = {2,5,8,15,35,42,48, 49, 53, 56, 59, 64, 66,68, 72};
    printf("%d\n", linear_search(arr, 254, 6));
    int element = 53;
    int searchedIndex = binary_search(arr, element, 15);
    printf("The element %d was found at index %d\n",element, searchedIndex);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int *ptr;
    int size;
    int length;
    void (*dis)();
} Array;

void display(Array arr){
    for (int i=0; i<arr.size; i++){
        printf("%d ", arr.ptr[i]);
    }
    printf("\n");
}

int min_element(Array arr){
    int min;
    min = arr.ptr[0];
    for (int i=1; i<arr.size; i++){
        if (arr.ptr[i] < min){
            min = arr.ptr[i];
        }
    }
    return min;
}

int max_element(Array arr){
    int max;
    max = arr.ptr[0];
    for (int i=1; i<arr.size; i++){
        if (arr.ptr[i] > max){
            max = arr.ptr[i];
        }
    }
    return max;
}

int append(Array *arr, int element){
    if (arr->size < arr->length){
        arr->ptr[arr->size] = element;
        arr->size += 1;
        return 1;
    } else {
        return 0;
    }
}

int search_element(Array arr, int element){
    for (int i=0; i<arr.size; i++){
        if (arr.ptr[i] == element){
            return i+1;
        }
    }
    return -1;
}

void set_element(Array arr, int index, int element){
    arr.ptr[index-1] = element;
}

void reverse(Array arr){
    int temp;
    for (int i=0; i<(arr.size)/2; i++){
        temp = arr.ptr[i];
        arr.ptr[i] = arr.ptr[arr.size-i-1];
        arr.ptr[arr.size-i-1] = temp;
    }
}

int insert_element(Array *arr, int index, int element){
    if (arr->size < arr->length){
        for (int i=arr->size; i >= index-1; i--){
            arr->ptr[i+1] = arr->ptr[i];
        }
        arr->ptr[index-1] = element;
        arr->size += 1;
        return 1;
    } else {
        return 0;
    }
}

void delete_element(Array *arr, int index){
    for (int i=index-1; i<arr->size; i++){
        arr->ptr[i] = arr->ptr[i+1];
    }
    arr->size -= 1;
}

void shift_array(Array *arr, int n, int dir){
    // left: 0 and right: 1
    int temp;
    if (dir==0){
        while (n--){
            temp = arr->ptr[0];
            for (int i=0; i<arr->size-1; i++){
                arr->ptr[i] = arr->ptr[i+1];
            }
            arr->ptr[arr->size-1] = temp;
        }
    } else {
        while(n--){
            temp = arr->ptr[arr->size - 1];
            for (int i=arr->ptr[arr->size-1]; i>0; i--){
                arr->ptr[i] = arr->ptr[i-1];
            }
            arr->ptr[0] = temp;
        }    
    }
}

void sort(Array arr){
    int temp;
    for (int i=0; i<arr.size-1; i++){
        for (int j=i+1; j<arr.size; j++){
            if (arr.ptr[i] > arr.ptr[j]){
                temp = arr.ptr[i];
                arr.ptr[i] = arr.ptr[j];
                arr.ptr[j] = temp;
            }
        }
    }
}

void descending_sort(Array arr){
    // this algorithm will take more time
    sort(arr);
    reverse(arr);
}

int main(){
    // int arr[] = {4,5,6,7,8,9};
    // int size = sizeof(arr)/sizeof(arr[0]);
    Array arr;
    arr.size = 6;
    arr.length = 20;
    arr.ptr = (int *) malloc(arr.size * sizeof(int));
    

    for (int i=0, j=452; i<arr.size; i++, j++){
        arr.ptr[i] = j;
    }

    display(arr);

    int min = min_element(arr);
    printf("min: %d\n", min);

    int max = max_element(arr);
    printf("max: %d\n", max);
    
    append(&arr, 458);
    display(arr);
    
    int index = search_element(arr, 453);
    printf("element %d index: %d\n", 453, index);

    set_element(arr, 7, 431);
    display(arr);

    reverse(arr);
    display(arr);

    insert_element(&arr, 6, 456);
    display(arr);

    delete_element(&arr, 1);
    delete_element(&arr, 7);
    display(arr);

    shift_array(&arr, 2, 1);
    display(arr);
     
    sort(arr);
    display(arr);

    descending_sort(arr);
    display(arr);
    return 0;
}
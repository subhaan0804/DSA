#include <stdio.h>

void displayArray(int arr[], int size){
    for (int i=0; i<size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sorted_insertion(int arr[], int pos, int element,int *size, int capacity){
    if (*size >= capacity){
        printf("Insertion operation Unsuccessful.\n");
        return 0;
    } else {
        for (int i=*size-1; i>=pos-1; i--){
            arr[i+1] = arr[i];
        }
        arr[pos-1] = element;
        *size += 1;
        printf("Insertion operation Successful.\n");
        return 1;
    }
}

int simple_insertion(int arr[], int pos, int element, int *size, int capacity){
    if (*size >= capacity){
        printf("Insertion operation unsuccessful.\n");
        return 0;
    } else {
        arr[*size] = arr[pos-1];
        arr[pos-1] = element;
        *size++;
    }
}

int deletion(int arr[], int pos, int *size){
    if (pos > *size){
        printf("Deletion fail.\n");
    } else {
        for (int i=pos-1; i<*size; i++){
            arr[i] = arr[i+1];
        }
        (*size)--;
    }
}
int main(){
    int arr[20] = {452,453,454,455,457};
    int size = 5;
    displayArray(arr, size);
    deletion(arr, 4, &size);
    deletion(arr, 1, &size);
    deletion(arr, 3, &size);
    deletion(arr, 2, &size);
    displayArray(arr, size);

    return 0;
}
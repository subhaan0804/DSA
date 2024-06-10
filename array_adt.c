#include <stdio.h>
#include <stdlib.h>

struct myArray {
    int total_size;
    int used_size;
    int *ptr;

    
};

void createArray(struct myArray* arr, int tSize, int uSize){
    // (*arr).total_size = tSize;
    // (*arr).used_size = uSize;
    // (*arr).ptr = (int *) malloc(tSize * sizeof(int)); 

    arr->total_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *) malloc(tSize * sizeof(int));
}



void setValue(struct myArray * arr){
    int n;
    for (int i=0; i < arr->used_size; i++){
        printf("enter element %d: ",i);
        scanf("%d", &n);
        (arr->ptr)[i] = n;
    }
}

int main(){
    struct myArray marks;
    createArray(&marks, 10, 2);
    setValue(&marks);
    show(&marks);
    return 0;
}
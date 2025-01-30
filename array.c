#include <stdio.h>

void print1DArray(int arr[], size_t size) {
    printf("1D Array:\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
/*
Array Definition:
    Case 1: Definition with Initialization (Valid)
        If you define an array with an initializer, the compiler automatically determines the number of elements
        int arr[] = { 1, 2, 3, 4, 5 }; // Compiler deduces size as 5
    Case 2: Definition without Initialization (Invalid)
        If you define an array without specifying the size and without initializing it, the compiler does not know the size, leading to error.
        int arr[]; // Error: The compiler doesn't know the size
    Case 3: Explicit Size Specification (Valid)
        int arr[5]; // Valid: Size is explicitly defined
    Case 4: Function Parameters (Valid but Different Mearning)
        When you pass an array to a function, writing int arr[] is valid, but it actually means int *arr (poiter to the first element)
        void do_sth(int arr[], size_t size); // Valid: int arr[] in function parameters is treated as int *arr, meaning it does not store array size information
*/
    printf("Ex: 1D Array\n");
    // array declaration and initialization
    int arr[] = { 15, 25, 35, 45, 55 };
    // calculate number of elements of array
    size_t size = sizeof(arr) / sizeof(arr[0]);
    // print array
    print1DArray(arr, size);
    //modifying element at index 2
    arr[2] = 100;
    print1DArray(arr, size);

    printf("\nEx: 2D Array\n");
    int two_d_arr[2][3] = { 10, 20, 30, 40, 50, 60 };
    printf("2D Array:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", two_d_arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
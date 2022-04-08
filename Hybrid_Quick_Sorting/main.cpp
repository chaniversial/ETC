#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <Windows.h>

#define FRONT_BACK_SIZE 30
#define MAX_SIZE 10000
#define PLUS_UNIT 10000
#define LINE 10
#define BASE 1

void shuffle(int *arr, int size) {
    int index = 0;
    bool *check;
    check = (bool *) calloc(size, sizeof(bool));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        index = rand() % size;
        while (check[index])
            index = rand() % size;
        check[index] = true;
        arr[i] = index + BASE;
    }
}

void Hybrid_Quick_Sort_Method(int *arr, int left, int right) {
    if (left >= right)
        return;
    if ((right - left) < 50) {
        int min_index;
        for (int i = left; i < right; i++) {
            min_index = i;
            for (int j = i + 1; j < right + 1; j++) {
                if (arr[j] < arr[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                int temp = arr[min_index];
                arr[min_index] = arr[i];
                arr[i] = temp;
            }
        }

        return;
    }
    int Store_Index, Pivot_Index, Pivot_Value, temp;

    Pivot_Index = (left + right) / 2;
    Store_Index = left;
    Pivot_Value = arr[Pivot_Index];

    temp = arr[Pivot_Index];
    arr[Pivot_Index] = arr[right];
    arr[right] = temp;

    for (int i = left; i < right; i++) {
        if (arr[i] < Pivot_Value) {
            temp = arr[i];
            arr[i] = arr[Store_Index];
            arr[Store_Index] = temp;
            Store_Index++;
        }
    }
    temp = arr[Store_Index];
    arr[Store_Index] = arr[right];
    arr[right] = temp;


    if (left < (Store_Index - 1))
        Hybrid_Quick_Sort_Method(arr, left, Store_Index - 1);
    if ((Store_Index + 1) < right)
        Hybrid_Quick_Sort_Method(arr, Store_Index + 1, right);
}

void Hybrid_Quick_sort(int *arr, int size) {
    Hybrid_Quick_Sort_Method(arr, 0, size - 1);
}

void print(int *arr) {
    for (int i = 0; i < FRONT_BACK_SIZE; i++) {
        if (i % LINE == 0)
            printf("\n");
        printf("%10d", arr[i]);
    }
    printf("\n...\n");
    for (int i = MAX_SIZE - FRONT_BACK_SIZE; i < MAX_SIZE; i++) {
        if (i % LINE == 0)
            printf("\n");
        printf("%10d", arr[i]);
    }
}

int main(void) {
    int *arr;
    arr = (int *) calloc(MAX_SIZE, sizeof(int));
    for (int i = 0; i < MAX_SIZE; i++)
        arr[i] = i+BASE;

    // print section
    // 1. We Check the Array Status
    // 2. Shuffle and Check
    // 3. Time Check
//    LARGE_INTEGER freq, start, end;
    printf("Generate the array...\n");
    print(arr);

    printf("\n\nShuffle the array...\n");
    shuffle(arr, MAX_SIZE);
    print(arr);

    printf("\n\nStart the Hybrid Quick Sort...\n");
    Hybrid_Quick_sort(arr, MAX_SIZE);
    print(arr);
}
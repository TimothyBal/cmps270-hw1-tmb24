#define SIZE 10
#include <stdio.h>

void arrayHistogram(int arr[]) {
    int frequencyArr[3] = {0}; //frequency array
    int i = 0;
    while (i < SIZE) {
        frequencyArr[arr[i]-1]++;
        i++;
    }
    i =0;
    printf("Value\tFrequency\tHistogram\n");
    while (i < 3) {
        printf("%d\t%d\t\t", i+1, frequencyArr[i]);
        for(int j=0; j<frequencyArr[i]; j++) {
            printf("*");
        }
        printf("\n");
        i++;
    }
}

void printArray(int arr[]) {
    int i=0;
    printf("Index\tValue\n");
    while (i < SIZE) {
        printf("    %d\t    %d\n", i, arr[i]);
        i++;
    }
}

void swapValues(int arr[], int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

void bubbleSort(int arr[]) {
    for(int i=0; i<SIZE-1; i++) {
        for(int j=0; j<SIZE-1; j++) {
            if(arr[j] >= arr[j+1])
                swapValues(arr, j, j+1);
        }
    }
}

float median(int arr[]) {
    if(SIZE%2==0)
        return (arr[SIZE/2-1] + arr[SIZE/2])/2;
    else 
        return arr[(SIZE-1)/2];
}

int mode(int arr[]) {
    int max = 0;
    int frequency[3] = {0};
    int i = 0;
    while (i < SIZE) {
        frequency[arr[i]-1]++;
        i++ ;
    }
    while (i < 3) {
        max = (max > frequency[i])? max:frequency[i];
        i++;
    }
    return max;
}

int isSorted(int arr[], int n) {
    int answer = 1;
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1])
            answer = 0;
    }
    return answer;
}

int main() {
    int arr[SIZE] = {3,1,2,1,2,1,2,1,1,3};

    printArray(arr);
    arrayHistogram(arr);
    
    printf("\n%d %d\n", arr[2], arr[5]);
    swapValues(arr, 2, 5);
    printf("swapped : \n%d %d\n", arr[2], arr[5]);
    bubbleSort(arr);
    float MEDIAN = median(arr);
    printf("median of array - %.2f\n", MEDIAN);
    
    int MODE = mode(arr);
    printf("mode of the array - %d\n", MODE);
    
    int sorted = isSorted(arr, SIZE);
    if(sorted) {
        printf("sorted\n");
        printArray(arr);
    }
    else
        printf("not sorted\n");
    return 0;
}
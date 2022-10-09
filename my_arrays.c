//Timothy Baloukji
//202101807

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
    printf("Value    Frequency    Histogram\n");
    while (i < 3) {
        printf("%d        %d            ", i+1, frequencyArr[i]);
        for(int j=0; j<frequencyArr[i]; j++) {
            printf("*");
        }
        printf("\n");
        i++;
    }
}

void printArray(int arr[]) {
    int i=0;
    printf("Index    Value\n");
    while (i < SIZE) {
        printf("    %d        %d\n", i, arr[i]);
        i++;
    }
}

void swapValues(int arr[], int i1, int i2) {
    int temp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = temp;
}

// keep traversing until there is no pair such that for i < j, arr[ i ] > arr[ j ],
void bubbleSort(int arr[]) {
    for(int i=0; i<SIZE-1; i++) {
        for(int j=0; j<SIZE-1; j++) {
            if(arr[j] >= arr[j+1])
                swapValues(arr, j, j+1);
        }
    }
}

//average of elements in the middle (can return a float if array is of odd size)
float median(int arr[]) {
    if(SIZE%2!=0)
        return arr[(SIZE-1)/2];
    else 
        return (arr[SIZE/2-1] + arr[SIZE/2])/2;
}

// return the element with maximum frequency
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

// check if the next element (i+1) is greater than i
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
    printf("median : %.2f\n", MEDIAN);
    
    int MODE = mode(arr);
    printf("mode : %d\n", MODE);
    
    int sorted = isSorted(arr, SIZE);
    if(sorted) {
        printf("sorted\n");
        printArray(arr);
    }
    else
        printf("not sorted\n");
    return 0;
}
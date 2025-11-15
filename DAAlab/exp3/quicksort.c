#include <stdio.h>
#include<time.h>
// Function to swap two elements
void swap(int* a, int* b) {
int temp = *a;
*a = *b;
*b = temp;
}
// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
int j;
int pivot = arr[high]; // Choose the last element as the pivot
int i = (low - 1); // Index of smaller element
for (j = low; j <= high - 1; j++) {
// If current element is smaller than or equal to pivot
if (arr[j] <= pivot) {
i++; // Increment index of smaller element
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
if (low < high) {
// pIndex is partitioning index, arr[pIndex] is now at right place
int pIndex = partition(arr, low, high);
// Separately sort elements before partition and after partition
quickSort(arr, low, pIndex - 1);
quickSort(arr, pIndex + 1, high);
}
}
// Function to print an array
void printArray(int arr[], int size) {
int i;
for ( i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}
// Main function to test the Quick Sort
int main() {
int arr[] = {10, 7, 8, 9, 1, 5};
clock_t start,end;
double cpu_time_used;
int n = sizeof(arr) / sizeof(arr[0]);
printf("Original array: ");
printArray(arr, n);
start=clock();
quickSort(arr, 0, n - 1);
end=clock();
cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nSorted array is \n");
printArray(arr, n);
printf("Execution time:%f",cpu_time_used);
return 0;
}
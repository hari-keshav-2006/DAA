#include <stdio.h>
#include <stdlib.h> 
#include<time.h>// For malloc and free
// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
int i, j, k;
int n1 = mid - left + 1;
int n2 = right - mid;
// Create temporary arrays to store left and right subarrays
int *L = (int *)malloc(n1 * sizeof(int));
int *R = (int *)malloc(n2 * sizeof(int));
// Copy data to temporary arrays L[] and R[]
for (i = 0; i < n1; i++)
L[i] = arr[left + i];
for (j = 0; j < n2; j++)
R[j] = arr[mid + 1 + j];
// Merge the temporary arrays back into arr[left..right]
i = 0; // Initial index of first subarray
j = 0; // Initial index of second subarray
k = left; // Initial index of merged subarray
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
} else {
arr[k] = R[j];
j++;
}
k++;
}
// Copy the remaining elements of L[], if any
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
// Copy the remaining elements of R[], if any
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
// Free the dynamically allocated memory

free(L);
free(R);
}
// Function to perform Merge Sort
void mergeSort(int arr[], int left, int right) {
if (left < right) {
// Find the middle point
int mid = left + (right - left) / 2;
// Recursively sort the first and second halves
mergeSort(arr, left, mid);
mergeSort(arr, mid + 1, right);
// Merge the sorted halves
merge(arr, left, mid, right);
}
}
// Function to print an array
void printArray(int arr[], int size) {
int i;
for (i = 0; i < size; i++)
printf("%d ", arr[i]);
printf("\n");
}
// Main function to test the Merge Sort implementation
int main() {
int arr[] = {12, 11, 13, 5, 6, 7};
int arr_size = sizeof(arr) / sizeof(arr[0]);
clock_t start,end;
double cpu_time_used;
printf("Given array is \n");
printArray(arr, arr_size);
start=clock();
mergeSort(arr, 0, arr_size - 1);
end=clock();
cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
printf("\nSorted array is \n");
printArray(arr, arr_size);
printf("Execution time:%f",cpu_time_used);
return 0;
}
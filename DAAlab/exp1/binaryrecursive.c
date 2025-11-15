#include <stdio.h>
#include <time.h>
// Recursive Binary Search Function
int recursiveBinarySearch(int arr[], int low, int high, int key) {
if (high < low)
return -1; // not found
int mid = low + (high - low) / 2;
if (arr[mid] == key)
return mid;
else if (arr[mid] > key)
return recursiveBinarySearch(arr, low, mid - 1, key);
else
return recursiveBinarySearch(arr, mid + 1, high, key);
}

int main() {
int n = 100000;
int arr[n];
// Fill the array with sorted values 0 to n-1
for (int i = 0; i < n; i++) {
arr[i] = i;
}
int key = 99999; // element to search for (worst case)
clock_t start, end;
double cpu_time_used;
start = clock(); // start time
int result = recursiveBinarySearch(arr, 0, n - 1, key);
end = clock(); // end time
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
if (result != -1)
printf("Element found at index %d\n", result);
else
printf("Element not found\n");
printf("Execution time: %f seconds\n", cpu_time_used);
return 0;
}
#include <stdio.h>
#include <time.h>
// Binary Search Function
int binarySearch(int arr[], int n, int key) {
int low = 0, high = n - 1;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid] == key)
return mid; // key found
else if (arr[mid] < key)
low = mid + 1; // search right half
else
high = mid - 1; // search left half
}

return -1; // not found
}
int main() {
int n = 100000;
int arr[n];
// Fill sorted array with values 0 to n-1
for (int i = 0; i < n; i++) {
arr[i] = i;
}
int key = 99999; // element to search for
clock_t start, end;
double cpu_time_used;
start = clock(); // start time
int result = binarySearch(arr, n, key);
end = clock(); // end time
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
if (result != -1)
printf("Element found at index %d\n", result);
else
printf("Element not found\n");
printf("Execution time: %f seconds\n", cpu_time_used);
return 0;
}
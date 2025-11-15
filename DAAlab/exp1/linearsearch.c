#include <stdio.h>
#include <time.h>
int linearSearch(int arr[], int n, int key) {
for (int i = 0; i < n; i++) {
if (arr[i] == key)
return i; // Return index if found
}
return -1; // Not found
}
int main() {
int n = 100000;
int arr[n];
int key = 99999; // Element to search
// Fill the array with values 0 to n-1
for (int i = 0; i < n; i++) {
arr[i] = i;
}
clock_t start, end;
double cpu_time_used;
start = clock(); // Start time
int result = linearSearch(arr, n, key);
end = clock(); // End time
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
if (result != -1)
printf("Element found at index %d\n", result);
else
printf("Element not found\n");
printf("Execution time: %f seconds\n", cpu_time_used);
return 0;
}
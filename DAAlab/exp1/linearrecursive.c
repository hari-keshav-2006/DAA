#include <stdio.h>
#include <time.h>
// Recursive Linear Search Function
int recursiveLinearSearch(int arr[], int size, int key, int index) {
if (index >= size)
return -1; // Base case: not found
if (arr[index] == key)

return index; // Element found
return recursiveLinearSearch(arr, size, key, index + 1);
}
int main() {
int n = 100000; // Size of array
int arr[n];
// Fill the array with values 0 to n-1
for (int i = 0; i < n; i++) {
arr[i] = i;
}
int key = 99999; // Element to search (worst case)
clock_t start, end;
double cpu_time_used;
start = clock(); // Start time
int result = recursiveLinearSearch(arr, n, key, 0);
end = clock(); // End time
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
if (result != -1)
printf("Element found at index %d\n", result);
else
printf("Element not found\n");
printf("Execution time: %f seconds\n", cpu_time_used);
return 0;
}
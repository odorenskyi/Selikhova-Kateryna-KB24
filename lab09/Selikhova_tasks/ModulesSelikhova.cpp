#include "ModulesSelikhova.h"

int factorial(int n) {
    if (n < 0) return -1;
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int sumArray(const int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return sum;
}

int minInArray(const int arr[], int size) {
    if (size <= 0) return 0;
    int min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

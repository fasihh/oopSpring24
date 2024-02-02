/*
 * Creator: Fasih Hasan
 * Date: 1/2/24
 * Desc: Recursive swapping
 */

#include <iostream>

using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum, int currentSum) {
    if (size < 0) return false;

    if (currentSum < targetSum) return hasSubsetSum(arr+1, size-1, targetSum, currentSum+*arr);
    
    arr -= 1;
    if (currentSum > targetSum) return hasSubsetSum(arr, size-1, targetSum, 0);

    return true;
}

bool hasSubsetSum(int arr[], int size, int targetSum) {
    int currentSum = 0;
    for (int *cptr = arr; cptr < arr+size; ) {
        if (targetSum == currentSum) return true;

        if (targetSum < currentSum) currentSum += *cptr;
        else if (targetSum > currentSum) currentSum = 0;
    }

    return false;
}

int main() {
    int arr[5] = {2, 3, 1, 4, 5};

    cout << (hasSubsetSum(arr, 5, 1, 0) ? "true" : "false") << endl;

    return 0;
}
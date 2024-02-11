/*
 * Creator: Fasih Hasan
 * Date: 1/2/24
 * Desc: finding a subset that sums to a target sum in a given array
 */

#include <iostream>

using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum) {
    if (!size) return false;
    if (!targetSum) return true;

    if (arr[size] < targetSum) return hasSubsetSum(arr, size-1, targetSum-arr[size-1]);

    // exclude last number
    bool flag1 = hasSubsetSum(arr, size-1, targetSum);
    // include last number
    bool flag2 = hasSubsetSum(arr, size-1, targetSum-arr[size-1]);

    return flag1 || flag2;
}

int main() {
    int arr[5] = {2, 3, 1, 4, 5};

    cout << (hasSubsetSum(arr, 5, 1) ? "true" : "false") << endl;

    return 0;
}
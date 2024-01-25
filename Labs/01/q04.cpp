#include <iostream>
#include <cstdlib>

int get_max_area(int *arr, int n) {
    int max_area = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            max_area = std::max(max_area, abs(i - j) * std::min(arr[i], arr[j]));
        }
    }

    return max_area;
}

int main() {
    int heights[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::cout << get_max_area(heights, 9) << std::endl;

    return 0;
}

#include <iostream>

int *find_target(int *nums, int n, int target) {
	int *arr = new int[2];

	bool flag = true;
	for (int i = 0; i < n && flag; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) 
				continue;

			if (nums[i] + nums[j] == target) {
				arr[0] = i, arr[1] = j;
				flag = false;
				break;
			}
		}
	}

	return arr;
}

int main() {
	int nums[4] = {2, 7, 11, 15};
	int *arr = find_target(nums, 4, 9);

	std::cout << arr[0] << " " << arr[1] << std::endl;

	return 0;
}

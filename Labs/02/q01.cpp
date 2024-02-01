/*
 * Creator: Fasih Hasan
 * Date: 1/2/24
 * Desc: Recursive swapping
 */

#include <iostream>

void recursive_swap(int *val1, int *val2, int c = 2) {
	*val1 ^= *val2;
	if (c) recursive_swap(val2, val1, c-1);
}

int main(int argc, char const *argv[])
{
	int val1 = 1, val2 = 2;

	recursive_swap(&val1, &val2);
	std::cout << val1 << " " << val2 << std::endl;

	return 0;
}

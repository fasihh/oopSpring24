#include <iostream>

int main()
{
	int arr[5] = {1, 2, 3, 4, 5};
	char *p = (char *)arr;

	int c = 0;
	while (p[c] != 5) { // last digit in the array
	    std::cout << (int)p[c] << std::endl;
		p++, c++;
	}
	std::cout << (int)p[c] << std::endl;
	
	std::cout << std::endl << c;

	return 0;
}

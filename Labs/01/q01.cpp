#include <iostream>

int is_prime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    int num;

    std::cout << "Enter number: ";
    std::cin >> num;
    std::cout << (is_prime(num) ? "true" : "false") << std::endl;

    return 0;
}

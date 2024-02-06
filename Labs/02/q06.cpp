/*
 * Creator: Fasih Hasan
 * Date: 6/2/24
 * Desc: finding LCM and GCD of 2 numbers
 */

#include <iostream>

using namespace std;

int calculateGCD(int a, int b) {
    // euclid's method of GCD

    // if result of previous mod is 0 then previous b is GCD
    if (!b) return a;

    // else find mod of a and b and mod it with b in next step
    return calculateGCD(b, a % b);
}

int calculateLCM(int a, int b, int c = 1) {
    // check if c is divisible by both numbers - LCM
    if (not (c%a) and not (c%b)) return c;

    // else check for next c
    return calculateLCM(a, b, c+1);
}

int main()
{
    int var1 = 123, var2 = 36;

    cout << var1 << " and " << var2 << ": " << calculateGCD(var1, var2) << endl;
    cout << var1 << " and " << var2 << ": " << calculateLCM(var1, var2);
    return 0;
}

#include <iostream>

using namespace std;

inline double strike_rate(int runs, int balls) { return runs/balls * 100; }
inline double batting_average(int runs, int outs) { return runs/outs; }

int main() {
    int balls, runs, outs;
    cout << "Enter number of balls: ";
    cin >> balls;
    cout << "Enter number of runs: ";
    cin >> runs;
    cout << "Enter number of outs: ";
    cin >> outs;

    cout << "Strike rate: " << strike_rate(runs, balls) << "\n";
    cout << "Batting average: " << batting_average(runs, outs) << endl;

    return 0;
}
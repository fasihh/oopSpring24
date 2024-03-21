#include <iostream>
#include <cmath>

using namespace std;

class StatisticalAnalyzer {
private:
public:
    static float computeAverage(int *array, int size) {
        float average = 0;
        for (int i = 0; i < size; i++)
            average += array[i];
        return average/size;
    }

    static float standardDeviation(int *array, int size) {
        float mean = StatisticalAnalyzer::computeAverage(array, size);

        float variance = 0;
        for (int i = 0; i < size; i++)
            variance += pow(array[i] - mean, 2);

        return sqrt(variance/(size-1));
    }
};

int main() {
    int array[5] = { 1, 2, 3, 4, 5 };
    cout << StatisticalAnalyzer::computeAverage(array, 5) << '\n';
    cout << StatisticalAnalyzer::standardDeviation(array, 5) << '\n';

    return 0;
}
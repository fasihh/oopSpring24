#include <iostream>

using namespace std;

class LoanHelper {
public:
    const float rate;
    float amount;
    int months;

    LoanHelper(float rate, float amount, int months) : rate(rate), amount(amount), months(months) {}

    void calculate() {
        float monthly = amount / months, totalPayment = 0;
        for (int i = 0; i < months; ++i)
            totalPayment += monthly + (totalPayment * rate);
        cout << "You have to pay " << totalPayment << " every month for " << months << " months to repay your loan" << endl;
    }
};

int main() {
    LoanHelper loanHelper(0.005f, 10000.0f, 12);
    loanHelper.calculate();

    return 0;
}
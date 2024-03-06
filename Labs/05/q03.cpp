#include <iostream>

using namespace std;

class ValidateString {
private:
    string str;
public:
    ValidateString(string str) : str(str) {}

    // it is not changing any values in the function
    bool isValid() const {
        for (char c : str)
            if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    ValidateString str1("HelloWorld");
    ValidateString str2("HelloWorld!");

    cout << "str1: " << str1.isValid() << "\n" << "str2: " << str2.isValid() << endl;
    return 0;
}

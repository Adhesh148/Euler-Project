#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int getSumOfDigits(int n) {
    // Calculate number of digits in 2^n.
    int len = (int) (floor(n/log2(10)) + 1);
    // Allocate digit string buffer.
    char *digitStr = new char[len + 1];
    // Calculate 2^n and write the result to the digit string.
    // NOTE: Need to use long double since we need to support
    //       up to 2^10000, and double only supports up to
    //       2^1023.  Assuming that long double is the 80-bit
    //       x87 floating point type, we then can support 
    //       results up to 2^16383.
    if(sprintf(digitStr, "%.0Lf", exp2((long double) n)) < 0) {
        cout << "Error writing to digit string." << endl;
        return -1;
    }
    int sum = 0;
    // Sum the digits.
    for(int i = 0; i < len; i++) {
        sum += static_cast<int>(digitStr[i] - '0');
    }
    delete[] digitStr;
    return sum;
}

int main() {
    int t;
    cin >> t;
    int n;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        cout << getSumOfDigits(n) << endl;
    }
    return 0;
}
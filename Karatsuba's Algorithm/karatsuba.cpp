#include <iostream>
#include <math.h>
using namespace std;


//////////////////
/// Main Logic ///
//////////////////
long long karatsuba(long long num1, long long num2) {
    // ---------------------------------- //
    // Base Condition for smaller numbers //
    // ---------------------------------- //
    if (num1<10 || num2<10) return num1*num2;

    // ----------------------------- //
    // Initialize starting variables //
    // ----------------------------- //
    int n = max(log10(num1)+1, log10(num2)+1);
    int half = n/2;
    long long p = pow(10, half);

    // ----------------- //
    // Split the numbers //
    // ----------------- //
    // First number
    int a = num1 / p;
    int b = num1 % p;
    // Second number
    int c = num2 / p;
    int d = num2 % p;
   
    // --------------------------- //
    // 3 recursive multiplications //
    // --------------------------- //
    int z0 = karatsuba(a,c);
    int z1 = karatsuba(b,d);
    int z2 = karatsuba(a+b, c+d);

    // ------------ //
    // Final result //
    // ------------ //
    return z2*p*p + (z1-z2-z0)*p + z0; 
}

///////////////////
/// Driver Code ///
///////////////////
int main() {
    long long num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    
    long long res = karatsuba(num1, num2);
    cout << "The result is: " << res << endl;

    return 0;
}

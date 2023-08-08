#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a no.: ";
    cin >> n;

    int prod = 1;
    int sum = 0;
    while (n != 0)
    {
        int digit = n % 10;
        prod *= digit;
        sum += digit;
        n /= 10;
    }
    cout<< "Product of digits - sum of digits of "<<n<<" is: "<<prod - sum;
}
#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
            // checking last bit
            if(n&1){
                count++;
            }
            n = n>>1;
        }
        return count;
    }

int main() {
    int n = 0101;

    int result = hammingWeight(n);
    cout << "Number of 1 bits (Hamming code) in the given binary number is: " << result << endl;
    return 0;
}
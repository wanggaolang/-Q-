#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        long long i = 5, sum = 0;
        while (n >= i) {
            int temp=n/i;
            sum+=temp;
            i*=5;
        }
        return sum;
    }
};

int main() {
    Solution s;
    int i;
    cin >> i;
    cout << s.trailingZeroes(i) << endl;

}

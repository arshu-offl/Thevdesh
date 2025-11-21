#include <bits/stdc++.h>
using namespace std;

int solution(const vector<int>& alpha2beta, const vector<int>& beta2alpha, int missions) {
    int t = 0;
    for (int i = 0; i < missions; ++i) {
        // find earliest shuttle from Alpha to Beta at or after time t
        auto itA = lower_bound(alpha2beta.begin(), alpha2beta.end(), t);
        if (itA == alpha2beta.end()) {
            // According to problem statement, this shouldn't happen (it's guaranteed possible)
            return -1;
        }
        int depA = *itA;
        int arriveBeta = depA + 100;

        // find earliest shuttle from Beta to Alpha at or after arrivalBeta
        auto itB = lower_bound(beta2alpha.begin(), beta2alpha.end(), arriveBeta);
        if (itB == beta2alpha.end()) {
            // According to problem statement, this shouldn't happen (it's guaranteed possible)
            return -1;
        }
        int depB = *itB;
        int arriveAlpha = depB + 100;

        t = arriveAlpha; // start next mission from this time
    }
    return t;
}

int main() {
    // Base test cases (from screenshots / examples)

    // Test 1
    vector<int> a1 = {0, 200, 500};
    vector<int> b1 = {99, 210, 450};
    int missions1 = 1;
    cout << "Test1 result: " << solution(a1, b1, missions1) << " (expected 310)\n";

    // Test 2
    vector<int> a2 = {109, 200, 500};
    vector<int> b2 = {99, 210, 600};
    int missions2 = 2;
    cout << "Test2 result: " << solution(a2, b2, missions2) << " (expected 700)\n";

    // Test 3
    vector<int> a3 = {5, 206};
    vector<int> b3 = {105, 306};
    int missions3 = 2;
    cout << "Test3 result: " << solution(a3, b3, missions3) << " (expected 406)\n";

    return 0;
}

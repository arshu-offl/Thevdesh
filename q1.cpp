#include <bits/stdc++.h>
using namespace std;

// Returns {highestEver, currentRating}
vector<int> solution(const vector<int>& diffs) {
    int current = 1500;
    int highest = 1500;
    for (int d : diffs) {
        current += d;
        if (current > highest) highest = current;
    }
    return {highest, current};
}

void printResult(const vector<int>& res) {
    cout << "[" << res[0] << ", " << res[1] << "]\n";
}

int main() {
    // Base case 1: example from prompt
    vector<int> diffs1 = {100, -200, 350, 100, -600};
    vector<int> res1 = solution(diffs1);
    cout << "Test 1 (expected [1850, 1250]): ";
    printResult(res1);

    // Base case 2: empty diffs
    vector<int> diffs2 = {};
    vector<int> res2 = solution(diffs2);
    cout << "Test 2 (expected [1500, 1500]): ";
    printResult(res2);

    // Extra quick test
    vector<int> diffs3 = {50, 50, -100, 200};
    vector<int> res3 = solution(diffs3);
    // Sequence: 1500 -> 1550 -> 1600 -> 1500 -> 1700  => highest 1700, current 1700
    cout << "Test 3 (expected [1700, 1700]): ";
    printResult(res3);

    return 0;
}

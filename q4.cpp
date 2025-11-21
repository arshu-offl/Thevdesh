#include <bits/stdc++.h>
using namespace std;

// Returns a vector where ans[i] is the length of the longest contiguous segment
// of built houses after executing queries[0..i].
vector<int> solution(const vector<int>& queries) {
    vector<int> ans;
    ans.reserve(queries.size());
    unordered_map<long long,int> length; // maps an endpoint (or a built point) -> segment length
    int currentMax = 0;

    for (long long x : queries) {
        // If x already present (not required here since queries guaranteed unique),
        // skip. But safe-guard:
        if (length.find(x) != length.end()) {
            ans.push_back(currentMax);
            continue;
        }

        int L = 0, R = 0;
        auto itL = length.find(x - 1);
        if (itL != length.end()) L = itL->second;
        auto itR = length.find(x + 1);
        if (itR != length.end()) R = itR->second;

        int merged = L + 1 + R;

        // Update endpoints of the merged segment:
        // leftmost = x - L, rightmost = x + R
        length[x - L] = merged;
        length[x + R] = merged;
        // Also put x itself (helps neighbors query directly):
        length[x] = merged;

        if (merged > currentMax) currentMax = merged;
        ans.push_back(currentMax);
    }

    return ans;
}

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) cout << ", ";
        cout << v[i];
    }
    cout << "]\n";
}

int main() {
    // Base case 1: queries = [2, 1, 3] -> output should be [1, 2, 3]
    vector<int> q1 = {2, 1, 3};
    auto r1 = solution(q1);
    cout << "Test 1 (expected [1, 2, 3]): ";
    printVec(r1);

    // Base case 2: queries = [1, 3, 0, 4] -> output should be [1, 1, 2, 2]
    vector<int> q2 = {1, 3, 0, 4};
    auto r2 = solution(q2);
    cout << "Test 2 (expected [1, 1, 2, 2]): ";
    printVec(r2);

    // Extra test: contiguous builds in order -> [0,1,2,3] => [1,2,3,4]
    vector<int> q3 = {0,1,2,3};
    auto r3 = solution(q3);
    cout << "Test 3 (expected [1, 2, 3, 4]): ";
    printVec(r3);

    return 0;
}

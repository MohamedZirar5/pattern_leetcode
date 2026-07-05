#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

long long dfs(const vector<int>& digs, int pos, bool tight, bool leading, vector<vector<vector<long long>>>& memo) {
    if (pos == (int)digs.size()) return 1;
    long long &out = memo[pos][tight][leading];
    if (out != -1) return out;
    out = 0;
    int limit = tight ? digs[pos] : 9;
    for (int d = 0; d <= limit; ++d) {
        if (d == 4) continue;
        bool ntight = tight && (d == limit);
        bool nleading = leading && (d == 0);
        out += dfs(digs, pos + 1, ntight, nleading, memo);
    }
    return out;
}

long long countWithout4(long long N) {
    if (N < 0) return 0;
    string s = to_string(N);
    vector<int> digs;
    for (char c: s) digs.push_back(c - '0');
    int n = digs.size();
    vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(2, vector<long long>(2, -1)));
    return dfs(digs, 0, true, true, memo);
}

int main() {
    assert(countWithout4(9) == 9);
    assert(countWithout4(20) == 19);
    assert(countWithout4(99) == 81);
    assert(countWithout4(100) == 82);
    cout << "Digit DP tests passed." << endl;
    return 0;
}

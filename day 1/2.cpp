#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6;
int table[N]{};

int main(){
    vector<int> nums;
    nums.reserve(1024);

    int a, b;

    while(cin >> a >> b){
        nums.push_back(a);
        table[b]++;
    }

    auto scores = nums | views::transform([](int a) { return a * table[a]; });

    cout << accumulate(scores.begin(), scores.end(), 0);

    return 0;
}
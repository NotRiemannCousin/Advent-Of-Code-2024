#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> n1;
    vector<int> n2;

    n1.reserve(1024);
    n2.reserve(1024);

    int a, b;

    while(cin >> a >> b){
        n1.push_back(a);
        n2.push_back(b);
    }
    ranges::sort(n1);
    ranges::sort(n2);


    auto distances = views::zip_transform([](int a, int b) { return abs(a - b); }, n1, n2);

    cout << accumulate(distances.begin(), distances.end(), 0);

    return 0;
}
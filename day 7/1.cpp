#include <bits/stdc++.h>

using namespace std;
using ll = long long unsigned int;

int main()
{
    ll res{};

    ll goal{};
    vector<ll> data;
    
    function<bool(ll, ll)> solve;
    solve = [&](ll pos, ll acc) -> bool{
        if(pos == data.size()) return (acc == goal);
        if(acc >  goal)        return false;

        return solve(pos + 1, acc + data[pos]) ||
               solve(pos + 1, acc * data[pos]);
    };

    long long temp;
    string line;
    
    while(getline(cin, line)){
        data.clear();

        stringstream str(line);
        str >> goal;
        str.ignore();
        while(str >> temp)
            data.push_back(temp);
        
        if(solve(1, data[0]))
            res += goal;
    }
    cout << res;

    return 0;
}

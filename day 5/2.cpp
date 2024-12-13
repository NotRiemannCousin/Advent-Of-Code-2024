#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_set<int>> dependents;

// Yeah very shit solution but it works


int CheckIntersection(const set<pair<int, int>>& a, const unordered_set<int>& b){
    for(auto [num, index] : a)
        if(b.contains(num))
            return index;

    return -1;
}


void CorrectUpdates(span<int> nums) {
    set<pair<int, int>> alreadyAdded;


    for(int i{}; i < nums.size(); i++)
    {
        auto intersects = CheckIntersection(alreadyAdded, dependents[nums[i]]);
        if(intersects != -1)
        {
            swap(nums[i], nums[intersects]);
            CorrectUpdates(nums);
            return;
        }
        alreadyAdded.insert({nums[i], i});
    }
}


int main()
{
    int res{};
    string line{};


    int a, b;
    char discard;
    while(getline(cin, line), line != ""){
        stringstream str(line);
        str >> a >> discard >> b;
        dependents[a].insert(b);
    }


    vector<int> data;
    int temp;

    while(getline(cin, line)){
        data.clear();
        line += ',';
        stringstream str(line);
        while(str >> temp >> discard) data.push_back(temp);
        vector<int> copy = data;

        CorrectUpdates(data);

        if(data != copy)
            res += data[data.size()/2];
    }


    cout << res;


    return 0;
}
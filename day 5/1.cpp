#include <bits/stdc++.h>

using namespace std;

unordered_map<int, unordered_set<int>> dependents;


bool CheckIntersection(const unordered_set<int>& a, const unordered_set<int>& b){
    if(a.size() > b.size())
        return CheckIntersection(b, a);
    
    for(int num : a)
        if(b.contains(num))
            return true;

    return false;
}


bool CorrectUpdates(span<int> nums) {
    unordered_set<int> alreadyAdded;

    for(int num : nums)
    {
        if(CheckIntersection(alreadyAdded, dependents[num]))
            return false;
        alreadyAdded.insert(num);
    }

    return true;
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

        if(CorrectUpdates(data))
            res += data[data.size()/2];
    }


    cout << res;


    return 0;
}
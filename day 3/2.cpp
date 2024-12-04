#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res{};
    string line;
    regex mulPattern(R"((?:mul\((\d{1,3}),(\d{1,3})\))|(?:do\(\))|(?:don't\(\)))");
    bool isActive {true};

    while(cin >> line)
    {
        vector<smatch> matches(sregex_iterator(line.begin(), line.end(), mulPattern), sregex_iterator());

        for(auto match : matches)
        {
            if(match[0] == "do()")
                isActive = true;
            else if(match[0] == "don't()")
                isActive = false;
            else if(isActive)
                res += stoi(match[1]) * stoi(match[2]);
        }
    }

    cout << res;

    return 0;
}
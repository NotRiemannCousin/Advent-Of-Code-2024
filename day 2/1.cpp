#include <bits/stdc++.h>

using namespace std;

bool checkConstraintsDes(int num)
{
    return clamp(num, 1, 3) != num;
}
bool checkConstraintsAsc(int num)
{
    return checkConstraintsDes(-num);
}

template<ranges::range R>
bool isSafe(R data, function<bool(int)> predicate){
    auto count = ranges::count_if(data, predicate);

    return count == 0;
}

int main()
{
    int res{};
    int temp;
    string line;

    while (getline(cin, line))
    {
        istringstream iss(line);
        vector<int> report;
        while (iss)
        {
            iss >> temp;
            report.push_back(temp);
        }
        report.pop_back();

        auto diff = report | views::pairwise_transform(minus{});

        if(isSafe(diff, checkConstraintsDes) || isSafe(diff, checkConstraintsAsc))
            res++;
    }

    cout << res;
    return 0;
}
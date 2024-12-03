#include <bits/stdc++.h>

using namespace std;

bool checkConstraintsDec(int num)
{
    return clamp(num, 1, 3) != num;
}
bool checkConstraintsAsc(int num)
{
    return checkConstraintsDec(-num);
}

template<ranges::range R>
bool isSafe(R data, function<bool(int)> predicate){
    auto count = ranges::count_if(data, predicate);
        
    switch (count){
        case 0:
            return true;
        case 1:
            if(predicate(data.front()) || predicate(data.back()))
                return true;
        case 2:
            for (auto [f, l] : data | views::pairwise)
                if ((count == predicate(f) + predicate(l)) && !predicate(f + l))
                    return true;
        default:
            return false;
    }

    // if (count == 0)
    //     return true;
    // if (count > 2)
    //     return false;
    // if(count == 1 && (predicate(data.front()) || predicate(data.back())))
    //     return true;
    
    // for (auto [f, l] : data | views::pairwise)
    //     if ((count == predicate(f) + predicate(l)) && !predicate(f + l))
    //         return true;
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

        if(isSafe(diff, checkConstraintsDec) || isSafe(diff, checkConstraintsAsc))
            res++;
    }

    cout << res;
    return 0;
}
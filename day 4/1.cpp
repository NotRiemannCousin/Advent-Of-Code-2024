#include <bits/stdc++.h>

using namespace std;


const string key = "XMAS";

int directions[8][2]{
    {+1, +0},
    {+1, +1},
    {+0, +1},
    {-1, +1},
    {-1, +0},
    {-1, -1},
    {+0, -1},
    {+1, -1},
};

int main()
{
    int res{};
    string line;
    vector<string> grid;

    while(cin >> line) grid.push_back(line);

    int n = grid.size();
    int m = line.size();


    function<bool(int, int, int, int, int)> path;
    path = [&](size_t index, int x, int y, int _x, int _y) -> bool{
        if(index >= key.size())
            return true;
        if(x != clamp(x, 0, n - 1) || y != clamp(y, 0, m - 1))
            return false;
        
        return grid[x][y] == key[index] ? path(index + 1, x + _x, y + _y, _x, _y) : false;
    };



    for(int i{}; i < n; i++)
        for(int j{}; j < n; j++)
        {
            for(auto [_x, _y] : directions)
                if(path(0, i, j, _x, _y))
                    res++;
        }

    cout << res;

    return 0;
}
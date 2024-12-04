#include <bits/stdc++.h>

using namespace std;

int directions[4][2]{
    {+1, +1},
    {-1, +1},
    {-1, -1},
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
        if(x != clamp(x, 1, n - 2) || y != clamp(y, 1, m - 2))
            return false;
        return 
            grid[x - _x][y - _y] == 'M' &&
            grid[x     ][y     ] == 'A' &&
            grid[x + _x][y + _y] == 'S';
    };


    for(int i{}; i < n; i++)
        for(int j{}; j < n; j++)
        {
            int occorencies{};
            for(auto [_x, _y] : directions)
                if(path(0, i, j, _x, _y))
                    occorencies++;
            if(occorencies == 2)
                res++;
        }

    cout << res;

    return 0;
}
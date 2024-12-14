#include <bits/stdc++.h>
//
// this may not work if the stack size is to small
//
using namespace std;

int directions[4][2]{
    {-1, -0},
    {+0, +1},
    {+1, +0},
    {+0, -1},
};


int main()
{
    int res{};
    vector<string> grid;
    
    string line;
    while(getline(cin, line)){
        grid.push_back(line);
    }

    int n = grid.size();
    int m = grid[0].size();

    function<char(int, int)> getNode = [&](int x, int y) -> char{
        if(x != clamp(x, 0, n - 1) || y != clamp(y, 0, m - 1))
            return ' ';
        return grid[x][y];
    };

    function<void(int, int, int)> navigate;
    navigate = [&](int x, int y, int dirr) -> void{
        auto [_x, _y] = directions[dirr];
        auto node     = getNode(x     , y     );
        auto next     = getNode(x + _x, y + _y);

        if(node != '@')
            res++;
        grid[x][y] = '@';

        switch(next){
            case ' ': return;
            case '#':
                navigate(x, y, (dirr + 1) % 4); // just rotate
                break;
            default:
                navigate(x + _x, y + _y, dirr); // goes foward
        }
    };


    for(int i{}; i < n; i++)
        for(int j{}; j < m; j++)
            if(grid[i][j] == '^')
                navigate(i, j, 0);
    

    cout << res;


    return 0;
}
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
char mode[4]{
    0b0001,
    0b0010,
    0b0100,
    0b1000,
};

enum StateEnum{
    RUNNING,
    OPEN,
    LOOP
};

auto pairHash = [](const pair<int, int>& pair) {
    return hash<int>()(pair.first) ^ (hash<int>()(pair.second) << 1);
};

unordered_set<pair<int, int>, decltype(pairHash)> Path(0, pairHash);

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

    auto copy = grid;
    function<char(int, int)> getNode = [&](int x, int y) -> char{
        if(x != clamp(x, 0, n - 1) || y != clamp(y, 0, m - 1))
            return ' ';
        return copy[x][y];
    };

    function<void(int, int, int)> computePossiblePlaces;
    computePossiblePlaces = [&](int x, int y, int dirr) -> void{
        auto [_x, _y] = directions[dirr];
        auto next     = getNode(x + _x, y + _y);

        Path.insert({x, y});

        switch(next){
            case ' ': return;
            case '#':
                computePossiblePlaces(x, y, (dirr + 1) % 4); // just rotate
                break;
            default:
                computePossiblePlaces(x + _x, y + _y, dirr); // goes foward
        }
    };
    int i{}, j{};
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            if(grid[i][j] == '^')
                goto out_loop;
    out_loop:
    

    computePossiblePlaces(i, j, 0);
    int index{};

    for(auto [a, b] : Path)
    {
        if(index == 45)
            cout << ' ';
        copy = grid;
        StateEnum state = StateEnum::RUNNING;
        copy[a][b] = '#';
        int x = i;
        int y = j;
        int dirr{};

        while(state == StateEnum::RUNNING){
            auto [_x, _y] = directions[dirr];
            auto node     = getNode(x     , y     );
            auto next     = getNode(x + _x, y + _y);

            if(node < 0b1111 && (node & mode[dirr]))
            {
                state = StateEnum::LOOP;
                break;
            }
            if(copy[x][y] > 0b1111)
                copy[x][y] = 0;
            copy[x][y] |= mode[dirr];

            switch(next){
                case ' ': state = StateEnum::OPEN; break;
                case '#': dirr = (dirr + 1) % 4;   break; // just rotate
                default : x += _x, y += _y;        break; // goes foward
            }
        };
        if(state == StateEnum::LOOP)
            res++;
    }
    
    cout << res;


    return 0;
}
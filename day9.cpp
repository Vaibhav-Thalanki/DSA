class Solution
{
public:
    int areaOfIsland(vector<vector<int>> &grid, int sr, int sc)
    {
        stack<pair<int, int>> stac;
        set<pair<int, int>> checkIfExists;
        stac.push(make_pair(sr, sc));
        checkIfExists.insert(make_pair(sr, sc));
        int cnt = 1;
        while (!stac.empty())
        {
            sr = stac.top().first;
            sc = stac.top().second;
            grid[sr][sc] = 0;
            checkIfExists.erase(make_pair(sr, sc));
            stac.pop();

            if (sr - 1 >= 0 && grid[sr - 1][sc] && checkIfExists.find(make_pair(sr - 1, sc)) == checkIfExists.end())
            {
                stac.push(make_pair(sr - 1, sc));
                checkIfExists.insert(make_pair(sr - 1, sc));
                cnt++;
            }
            if (sr + 1 < grid.size() && grid[sr + 1][sc] && checkIfExists.find(make_pair(sr + 1, sc)) == checkIfExists.end())
            {
                stac.push(make_pair(sr + 1, sc));
                checkIfExists.insert(make_pair(sr + 1, sc));
                cnt++;
            }
            if (sc + 1 < grid[0].size() && grid[sr][sc + 1] && checkIfExists.find(make_pair(sr, sc + 1)) == checkIfExists.end())
            {
                stac.push(make_pair(sr, sc + 1));
                checkIfExists.insert(make_pair(sr, sc + 1));
                cnt++;
            }
            if (sc - 1 >= 0 && grid[sr][sc - 1] && checkIfExists.find(make_pair(sr, sc - 1)) == checkIfExists.end())
            {
                stac.push(make_pair(sr, sc - 1));
                checkIfExists.insert(make_pair(sr, sc - 1));
                cnt++;
            }

            // for(stack<pair<int,int>> s = stac;!s.empty();s.pop()){
            //     cout<<s.top().first<<" "<<s.top().second<<endl;
            // }
            // cout<<"\n\n\n";
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max = 0, tmp;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    tmp = areaOfIsland(grid, i, j);
                    if (max < tmp)
                        max = tmp;
                }
            }
        }
        return max;
    }
};
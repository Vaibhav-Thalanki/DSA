// BFS with recursion:
class Solution
{
public:
    void flood(vector<vector<int>> &image, int sr, int sc, int color, int oldcolor)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldcolor)
        {
            return;
        }
        image[sr][sc] = color;
        flood(image, sr + 1, sc, color, oldcolor);
        flood(image, sr, sc + 1, color, oldcolor);
        flood(image, sr, sc - 1, color, oldcolor);
        flood(image, sr - 1, sc, color, oldcolor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;
        flood(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};

// BFS with queue:
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        queue<pair<int, int>> q;
        int old = image[sr][sc];
        q.push(make_pair(sr, sc));
        while (!q.empty())
        {
            if (image[q.front().first][q.front().second] != old)
                q.pop();
            else
            {
                cout << q.front().first << "," << q.front().second << "\n";
                image[q.front().first][q.front().second] = color;
                // update to solve
                sc = q.front().second;
                sr = q.front().first;
                if (sc + 1 < image[0].size() && image[sr][sc + 1] != color)
                {
                    q.push(make_pair(sr, sc + 1));
                }

                if (sr + 1 < image.size() && image[sr + 1][sc] != color)
                {

                    q.push(make_pair(sr + 1, sc));
                }

                if (sc - 1 >= 0 && image[sr][sc - 1] != color)
                {

                    q.push(make_pair(sr, sc - 1));
                }

                if (sr - 1 >= 0 && image[sr - 1][sc] != color)
                {
                    q.push(make_pair(sr - 1, sc));
                }
                q.pop();
            }
        }
        return image;
    }
};

// DFS with stack

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        stack<pair<int, int>> q;
        int old = image[sr][sc];
        q.push(make_pair(sr, sc));
        while (!q.empty())
        {
            if (image[q.top().first][q.top().second] != old)
                q.pop();
            else
            {

                image[q.top().first][q.top().second] = color;
                // update to solve
                sc = q.top().second;
                sr = q.top().first;
                q.pop();

                if (sc + 1 < image[0].size() && image[sr][sc + 1] != color)
                {
                    q.push(make_pair(sr, sc + 1));
                }

                if (sr + 1 < image.size() && image[sr + 1][sc] != color)
                {

                    q.push(make_pair(sr + 1, sc));
                }

                if (sc - 1 >= 0 && image[sr][sc - 1] != color)
                {

                    q.push(make_pair(sr, sc - 1));
                }

                if (sr - 1 >= 0 && image[sr - 1][sc] != color)
                {
                    q.push(make_pair(sr - 1, sc));
                }
            }
            // for(stack<pair<int,int>> s=q;!s.empty();s.pop()){
            //     cout<<s.top().first<<"-"<<s.top().second<<" ";
            // }
            // cout<<"\n";
        }
        return image;
    }
};
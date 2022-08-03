class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        vector<vector<int>> mat2(mat.size(), vector<int>(mat[0].size(), -1));
        int flag = 0;
        // front propogation
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat[0].size(); j++)
            {
                flag = 0;
                if (mat[i][j] == 0)
                {
                    mat2[i][j] = 0;
                    flag = 1;
                }
                if (i - 1 >= 0 && mat[i - 1][j] == 0 && mat2[i][j] == -1)
                {
                    mat2[i][j] = 1;
                    flag = 1;
                }
                if (i + 1 < mat.size() && mat[i + 1][j] == 0 && mat2[i][j] == -1)
                {
                    mat2[i][j] = 1;
                    flag = 1;
                }
                if (j - 1 >= 0 && mat[i][j - 1] == 0 && mat2[i][j] == -1)
                {
                    mat2[i][j] = 1;
                    flag = 1;
                }
                if (j + 1 < mat[0].size() && mat[i][j + 1] == 0 && mat2[i][j] == -1)
                {
                    mat2[i][j] = 1;
                    flag = 1;
                }
                if (flag == 0)
                {
                    if (i - 1 >= 0 && j - 1 >= 0 && mat2[i - 1][j] != -1 && mat2[i][j - 1] != -1)
                    {
                        mat2[i][j] = 1 + min(mat2[i - 1][j], mat2[i][j - 1]);
                        continue;
                    }
                    if (i - 1 >= 0 && mat2[i - 1][j] != -1)
                    {
                        mat2[i][j] = 1 + mat2[i - 1][j];
                    }
                    else if (j - 1 >= 0 && mat2[i][j - 1] != -1)
                    {
                        mat2[i][j] = 1 + mat2[i][j - 1];
                    }
                }
            }
        }
        // back propogation
        for (int i = mat.size() - 1; i >= 0; i--)
        {
            for (int j = mat[0].size() - 1; j >= 0; j--)
            {
                flag = 0;
                if (mat[i][j] == 0)
                {
                    mat2[i][j] = 0;
                    flag = 1;
                }
                else
                {
                    if (i - 1 >= 0 && mat[i - 1][j] == 0)
                    {
                        mat2[i][j] = 1;
                        flag = 1;
                    }
                    if (i + 1 < mat.size() && mat[i + 1][j] == 0)
                    {
                        mat2[i][j] = 1;
                        flag = 1;
                    }
                    if (j - 1 >= 0 && mat[i][j - 1] == 0)
                    {
                        mat2[i][j] = 1;
                        flag = 1;
                    }
                    if (j + 1 < mat[0].size() && mat[i][j + 1] == 0)
                    {
                        mat2[i][j] = 1;
                        flag = 1;
                    }
                }

                if (flag == 0)
                {
                    if (i + 1 < mat.size() && j + 1 < mat[0].size())
                    {
                        int t = 1 + min(mat2[i + 1][j], mat2[i][j + 1]);
                        if (mat2[i][j] != -1)
                            mat2[i][j] = min(t, mat2[i][j]);
                        else
                            mat2[i][j] = t;
                        continue;
                    }
                    if (i + 1 < mat.size())
                    {
                        if (mat2[i][j] != -1)
                            mat2[i][j] = min(1 + mat2[i + 1][j], mat2[i][j]);
                        else
                            mat2[i][j] = 1 + mat2[i + 1][j];
                    }
                    else if (j + 1 < mat[0].size())
                    {
                        if (mat2[i][j] != -1)
                            mat2[i][j] = min(1 + mat2[i][j + 1], mat2[i][j]);
                        else
                            mat2[i][j] = 1 + mat2[i][j + 1];
                    }
                }
            }
        }

        return mat2;
    }
};
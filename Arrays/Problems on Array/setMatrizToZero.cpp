#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{

    vector<int> row(matrix.size(), 1);
    vector<int> col(matrix[0].size(), 1);

    for (int i = 0; i < row.size(); i++)
    {
        for (int j = 0; j < col.size(); j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }
        for (int i = 0; i < row.size(); i++)
        {
            for (int j = 0; j < col.size(); j++)
            {
                if (row[i] == 0 || col[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }


int main()
{

    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}};

    for (auto it : matrix)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout<<endl;
    }
    setZeroes(matrix);

    for (auto it : matrix)
    {
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    int m  = mat.size();
    int n = mat[0].size();
    if(m*n != r*c) return mat;
    vector<vector<int>> result(r,vector<int>(c,0));

    vector<int> dummy ;
    for (auto it :mat)
    {
        for (auto i : it) dummy.push_back(i);     
        
    }
    int index = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            result[i][j] = dummy[index];
            index++;
        }
        
    }
    return result;


}

int main()
{

    vector<vector<int>> mat = {
        {1, 2},
        {2, 3}

    };
    int r = 1, c = 4;

    for (auto it : matrixReshape(mat, r, c))
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
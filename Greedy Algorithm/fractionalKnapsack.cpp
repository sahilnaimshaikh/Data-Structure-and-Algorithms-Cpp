#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(Item i1, Item i2)
    {
        double s1 = (double)i1.value / (double)i1.weight;
        double s2 = (double)i2.value / (double)i2.weight;
        return (s1 > s2);
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp); // sort descending of values/weight
        double maxVal = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight <= W)
            {
                maxVal += arr[i].value;
                W -= arr[i].weight;
            }
            else
            {
                maxVal += (double)W * (arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return maxVal;
    }
};

int main()
{

    int N = 3, W = 50;
    int values[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    Item arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i].value = values[i];
        arr[i].weight = weight[i];
    }
    Solution sol;
    cout << sol.fractionalKnapsack(W, arr, N);

    return 0;
}
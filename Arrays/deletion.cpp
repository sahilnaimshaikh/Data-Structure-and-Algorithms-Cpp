#include <iostream>
using namespace std;

void deleteFromArray(int arrae[], int index, int &size)
{
    if (index > size - 1)
    {
        cout << "Cannot delete, Index out of bound" << endl;
    }
    else
    {
        for (int i = index; i < size; i++)
        {
            arrae[i] = arrae[i + 1];
        }
        size -= 1;
    }
}

void display(int arrae[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arrae[i] << "\t";
    }
    cout << endl;
}

int main()
{

    int arrae[100] = {1, 23, 4, 45, 2, 75, 4};
    int size = 7, capacity = 100, index = 2;
    display(arrae, size);
    // cout << size << endl;
    deleteFromArray(arrae, index, size);
    display(arrae, size);
    // cout << size << endl;

    return 0;
}
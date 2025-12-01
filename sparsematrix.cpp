// 2)	Develop a program to identify and efficiently store a sparse matrix using compact representation and perform basic operations like display and simple transpose.
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout << "Enter no of rows :";
    cin >> n;
    int m;
    cout << "Enter no of columns :";
    cin >> m;

    vector<vector<int>> array(n, vector<int>(m));

    cout << "Enter elements of the array : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            array[i][j] = val;
        }
    }
    cout << endl;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                count++;
            }
        }
    }
    vector<vector<int>> sparse(count, vector<int>(3));
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (array[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = array[i][j];
                k++;
            }
        }
    }
    cout << "Row " << "Column " << "Element " << endl;
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << "      ";
        }
        cout << endl;
    }
}

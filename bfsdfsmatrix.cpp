// 1) Write a Program to accept a graph from a user and represent it with Adjacency
// Matrix and perform BFS and DFS traversals on it.
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
void BFS(int start, int v, vector<vector<int>> &adj)
{
    vector<bool> visited(v, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty())
    {

        int node = q.front();
        q.pop();

        cout << node << " ";
        for (int i = 0; i < v; i++)
        {

            if (!visited[i] && adj[node][i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
void DFS(int start, vector<vector<int>> &adj, int V)
{
    vector<bool> visited(V, false);
    stack<int> st;
    st.push(start);

    cout << "DFS Traversal : ";
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        while (!visited[node])
        {
            cout << node << " ";
            visited[node] = true;
        }
        for (int i = adj[node].size() - 1; i >= 0; i--)
        {
            if (!visited[i] && adj[node][i])
                st.push(i);
        }
    }
}
int main()
{
    // vector<vector<int>> adj{
    //     {0, 1, 1, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0},
    //     {0, 0, 1, 1, 0, 1, 1},
    //     {0, 0, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0}};
    // int n = 7;
    int n;
    cout << "Enter number of vertices in matrix : ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    cout << "Enter adjacecny matrix " << n << "x" << n << " : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    int start;
    cout << "Enter start Node : ";
    cin >> start;

    cout << endl;
    BFS(start, n, adj);
    cout << endl;
    DFS(start, adj, n);
    return 0;
}

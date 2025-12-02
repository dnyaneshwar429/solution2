// 3) Write a Program to implement Prim’s algorithm to find minimum
// spanning tree of a user defined graph. Use Adjacency List to represent a graph.
#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int findMinvertex(vector<int> &key, vector<bool> &mst, int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!mst[i] && (minvertex == -1 || key[i] < key[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}

void PrimsAlgo(vector<vector<pair<int, int>>> &graph, int n)
{
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> parent(n, -1);

    key[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int u = findMinvertex(key, mst, n);
        mst[u] = true;

        for (auto edge : graph[u])
        {
            int v = edge.first;
            int weight = edge.second;

            if (!mst[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    cout << "Edges in MST:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << " : " << key[i] << endl;

        totalWeight += key[i];
    }

    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main()
{

    // adj[0] = {1, 2, 3};
    // adj[1] = {0, 2};
    // adj[2] = {0, 1, 3, 4};
    // adj[3] = {0, 2, 4};
    // adj[4] = {2, 3, 5, 6};
    // adj[5] = {4};
    // adj[6] = {4};

    int vertices, edges;
    cout << "Enter number of vertices : ";
    cin >> vertices;

    cout << "Enter number of edges : ";
    cin >> edges;

    vector<vector<pair<int, int>>> adj(vertices);
    cout << "Enter edges between U and V : ";
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int start;
    cout << "Enter start Node : ";
    cin >> start;

    return 0;
}

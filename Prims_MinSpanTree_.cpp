#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int minimum_key(const vector<int> &key, const vector<bool> &mstSet)
{
    int min = numeric_limits<int>::max(), minIndex;

    for (size_t v = 0; v < key.size(); v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;

    return minIndex;
}

void prim(const vector<vector<int>> &graph)
{
    int vertices = graph.size();
    vector<int> parent(vertices);
    vector<int> key(vertices, numeric_limits<int>::max());
    vector<bool> mstSet(vertices, false);

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minimum_key(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < vertices; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "\n Edge \t  Weight\n";
    for (int i = 1; i < vertices; i++)
        cout << " " << parent[i] << " <-> " << i << "    " << graph[i][parent[i]] << "\n";
}

int main()
{
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < vertices; i++)
        for (int j = 0; j < vertices; j++)
            cin >> graph[i][j];

    prim(graph);
    return 0;
}

/*
    0 2 1 0 0
    2 0 1 0 0
    1 1 0 2 2
    0 0 2 0 1
    0 0 2 1 0
*/
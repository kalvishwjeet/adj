#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edges
{
public:
    int u, v, w;

    void set(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};
bool comp(Edges e1, Edges e2)
{
    return e1.w < e2.w;
}

class Graph
{
public:
    vector<vector<int>> graph;
    int n;

    Graph()
    {
        cout << "\nEnter number of vertices: ";
        cin >> n;
        graph.resize(n, vector<int>(n, 0));
    }

    void createGraph()
    {
        cout << "\nEnter matrix: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    void showGraph()
    {
        cout << "\nGraph Matrix: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }

    void kruskals()
    {
        vector<int> components(n, 0);

        vector<Edges> edg;
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Edges temp;
                if (graph[i][j] != 0)
                {
                    temp.set(i, j, graph[i][j]);
                    edg.push_back(temp);
                }
            }
        }

        sort(edg.begin(), edg.end(), comp);

        for (auto it : edg)
        {
            cout << it.u << " " << it.v << " " << it.w << endl;
        }

        for (int i = 0; i < n; i++)
        {
            components[i] = i;
        }

        Edges edge;
        int cu, cv;
        int ne = n - 1;
        int u, v, w;
        int i = 0;
        while (ne > 0)
        {
            u = edg[i].u;
            v = edg[i].v;
            w = edg[i].w;

            cu = components[u];
            cv = components[v];

            if (cu != cv)
            {
                ne--;
                cout << "Edge:-> " << u << " " << v << endl;
                for (int j = 0; j < n; j++)
                {
                    if (components[j] == cu)
                    {
                        components[j] = cv;
                    }
                }
            }
            i++;
        }
    }
};

int main()
{
    Graph grp;
    grp.createGraph();
    grp.showGraph();
    grp.kruskals();
}

/*
0 10 0 30 100
10 0 50 0 0
0 50 0 20 10
30 0 20 0 60
100 0 10 60 0

0 10 0 30 10
10 0 50 0 0
0 50 0 20 30
10 0 20 0 10
10 0 30 10 0
*/

/*
    0 2 0 1 4 0
    2 0 3 3 0 7
    0 3 0 5 0 8
    1 3 5 0 9 0
    4 0 0 9 0 0
    0 7 8 0 0 0

*/
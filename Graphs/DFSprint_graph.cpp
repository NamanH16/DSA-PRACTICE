/*NOTE: In graphs, we actually make an adjacency matrix of size n x n, all initialized to 0(false)
Then we are taking 2 vertices as inputs for any one particular edge and making changes for the same
in the adjacency table.*/
#include <iostream>
using namespace std;

// This 'print()' will print in DFS(Depth First Search) manner
// DFS: will keep going in depth, until we stop finding vertices
void print(int **edges, int n, int sv, bool *visited) // sv stands for starting vertex,assuming sv = 0
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }

        if (edges[sv][i] == 1)
        {
            if (visited[i] == true)
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

int main()
{
    int n; // number of vertices
    int e; // number of edges
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0; // assuming we have no edges between any vertices
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s; // f = first vertex, s = second vertex
        cin >> f >> s;
        edges[f][s] = 1; // currently we have no directions in a graph
        edges[s][f] = 1; // so first and second are both connected to each other
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false; // since not visited any vertices yet, all initialized to false
    }

    print(edges, n, 0, visited);

    // Delete extra memory
    delete[] visited;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
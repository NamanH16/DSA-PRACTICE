#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv); // starting vertex directly pushed
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front(); // stored the top of queue
        pendingVertices.pop();                       // deleted that top element
        cout << currentVertex << " ";

        for (int i = 0; i < n; i++)
        { // now checked for its vertices
            if (i == currentVertex)
            {
                continue;
            }
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
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

    bool *visited = new bool[n]; // visited array to keep the track of nodes
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    printBFS(edges, n, 0, visited); // starting vertex = 0
    delete[] visited;
}
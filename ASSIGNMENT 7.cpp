#include <iostream>
using namespace std;

const int MAX = 100;

int adj[MAX][MAX];
bool visited[MAX];
int n;

// DFS function
void DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == false)
        {
            DFS(i);
        }
    }
}

int main()
{
    int e;
    int u, v;
    int start;

    // Step 1: Read number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Step 2: Read number of edges
    cout << "Enter number of edges: ";
    cin >> e;

    // Add edges
    for (int k = 1; k <= e; k++)
    {
        cout << "Enter source and destination vertex: ";
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;   // Undirected graph
    }

    // Step 3: Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Step 5: Read starting vertex
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(start);

    cout << endl;

    return 0;
}

#include <iostream>

using namespace std;

// Function to find the shortest path from source node to all other nodes using Dijkstra's algorithm
void dijkstra(int graph[6][6], int shortest[]) {
    bool visited[6] = {false}; // Array to keep track of the nodes that have been visited
    for (int i = 0; i < 6; i++) {
        int min = -1;
        // Find the node with minimum shortest path value that has not yet been visited
        for (int j = 0; j < 6; j++) {
            if (!visited[j] && (min == -1 || shortest[j] < shortest[min])) {
                min = j;
            }
        }
        visited[min] = true; // Mark the selected node as visited
        // Update shortest path values of all adjacent nodes that have not yet been visited
        for (int j = 0; j < 6; j++) {
            if (graph[min][j] != 0 && shortest[min] + graph[min][j] < shortest[j]) {
                shortest[j] = shortest[min] + graph[min][j];
            }
        }
    }
}

int main()
{
    int shortest[] = {0, 9999, 9999, 9999, 9999, 9999}; // Array to store the shortest path values from source node to all other nodes
    int graph[6][6] = 
    {
        {0, 6, 0, 4, 0, 0},
        {6, 0, 10, 7, 7, 0},
        {0, 10, 0, 8, 5, 6},
        {4, 7, 8, 0, 12, 0},
        {0, 7, 5, 12, 0, 7},
        {0, 0, 6, 0, 7, 0}
    }; // Adjacency matrix representation of the graph

    dijkstra(graph, shortest); // Call dijkstra function to find the shortest path from source node to all other nodes

    char vertices = 'A';
    // Print the shortest path values from source node to all other nodes
    for (int i = 0; i < 6; i++)
    {
        cout << vertices++ << " : "<< "[ " << shortest[i] << " ] " << endl;
    } cout << endl;
}

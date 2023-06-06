#include <iostream>
#include <limits.h>

// Number of Vertices in the graph
#define NODE 6

using namespace std;

// Function to find the node with minimum key value that has not yet been included in the MST
int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < NODE; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

int main()
{
    int mst = 0; // Variable to store the total weight of the MST
    int graph[NODE][NODE] = 
    {
        {0, 6, 0, 4, 0, 0},
        {6, 0, 10, 7, 7, 0},
        {0, 10, 0, 8, 5, 6},
        {4, 7, 8, 0, 12, 0},
        {0, 7, 5, 12, 0, 7},
        {0, 0, 6, 0, 7, 0}
    }; // Adjacency matrix representation of the graph
    
    int parent[NODE]; // Array to store the parent of each node in the MST
    int key[NODE]; // Array to store the minimum weight edge for each node
    bool mstSet[NODE]; // Array to keep track of the nodes included in the MST
    
    // Initialize key[] values to INT_MAX and mstSet[] values to false
    for (int i = 0; i < NODE; i++)
        key[i] = INT_MAX, mstSet[i] = false;
        
    key[0] = 0; // Set the key value of the first node to be zero so that it is picked first
    parent[0] = -1; // Set the parent of the first node to be -1
    
    // Loop until all nodes have been included in the MST
    for (int count = 0; count < NODE-1; count++)
    {
        int u = minKey(key,mstSet); // Find the node with minimum key value that has not yet been included in the MST
        mstSet[u] = true; // Add the selected node to the MST
        
        // Update key values of all adjacent nodes that have not yet been included in the MST
        for (int v = 0; v < NODE; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u,key[v] = graph[u][v];
    }
    
    // Calculate the total weight of the MST by summing up the weights of all edges in the MST
    for (int i =1; i < NODE; i++)
        mst += graph[i][parent[i]];
        
    cout << "Minimum Spanning Tree: " << mst << endl;
}

/* 
Here is a brief documentation for the code:

This program calculates the minimum spanning tree (MST) of a given graph using Prim’s algorithm. The graph is represented as an adjacency matrix where graph[i][j] represents the weight of the edge between nodes i and j. If there is no edge between nodes i and j, then graph[i][j] is 0.

The program starts by initializing an array key[] to store the minimum weight edge for each node and an array mstSet[] to keep track of the nodes included in the MST. The key[] values are initialized to INT_MAX and the mstSet[] values are initialized to false.

The program then enters a loop that runs until all nodes have been included in the MST. In each iteration of the loop, the program selects the node with the minimum key value that has not yet been included in the MST and adds it to the MST. The program then updates the key values of all adjacent nodes that have not yet been included in the MST.

After all nodes have been included in the MST, the program calculates the total weight of the MST by summing up the weights of all edges in the MST and stores the result in the mst variable. */
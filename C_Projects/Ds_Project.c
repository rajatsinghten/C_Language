#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 7 // Number of vertices in the graph

// List of airport names corresponding to the vertices of the graph
const char* airports[V] = {"Hyderabad", "Bangalore", "Chennai", "Kochi", "Goa", "Andaman", "Lakshadweep"};

// ANSI Color Codes for enhancing terminal output visibility
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// Function to map airport names to their respective graph indices
int getAirportIndex(const char* name) {
    for (int i = 0; i < V; i++) {
        if (strcmp(airports[i], name) == 0) {
            return i;
        }
    }
    return -1; // If airport not found, return -1
}

// Function to find the vertex with minimum distance which is not included in shortest path tree
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Recursive function to construct path from source to destination
void constructPath(char* buffer, int parent[], int j) {
    if (parent[j] == -1) {
        sprintf(buffer + strlen(buffer), "%s", airports[j]);
        return;
    }
    constructPath(buffer, parent, parent[j]);
    sprintf(buffer + strlen(buffer), " -> %s", airports[j]);
}

// Function to print the solution of the path found
void printSolution(int dist[], int parent[], int src, int dest) {
    char path[1024] = ""; // Buffer to store path
    constructPath(path, parent, dest);
    
    printf("\n" ANSI_COLOR_YELLOW "+----------------------------------------------------+" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN "| From          | To            | Cost               |" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_YELLOW "+----------------------------------------------------+" ANSI_COLOR_RESET "\n");
    printf("| %-13s | %-13s | " ANSI_COLOR_GREEN"%-13d"ANSI_COLOR_RESET "|\n", airports[src], airports[dest], dist[dest]);
    printf(ANSI_COLOR_YELLOW "+----------------------------------------------------+" ANSI_COLOR_RESET "\n");
    printf("| Route: %s |\n", path);
    printf(ANSI_COLOR_YELLOW "+----------------------------------------------------+" ANSI_COLOR_RESET "\n");
}

// Implementation of Dijkstra's algorithm for shortest path from src to dest
void dijkstra(int graph[V][V], int src, int dest) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    int sptSet[V]; // Shortest path tree set
    int parent[V]; // Parent array to store shortest path tree

    // Initialize all distances as infinite and stpSet[] as false
    for (int i = 0; i < V; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0; // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1; // Mark the picked vertex as processed

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printSolution(dist, parent, src, dest); // print the constructed distance array
}

int main() {
    // Graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 1200, 1500, 0, 0, 0, 0},
        {1200, 0, 1300, 0, 1400, 0, 0},
        {1500, 1300, 0, 1400, 0, 0, 0},
        {0, 0, 1400, 0, 1600, 0, 0},
        {0, 1400, 0, 1600, 0, 1700, 0},
        {0, 0, 0, 0, 1700, 0, 1800},
        {0, 0, 0, 0, 0, 1800, 0}
    };

    // Welcoming message and available airports
    printf(ANSI_COLOR_BLUE "Welcome to South Indian Airlines!\n" ANSI_COLOR_RESET);
    printf(ANSI_COLOR_YELLOW "Available airports:\n+------------------+\n" ANSI_COLOR_RESET);
    for (int i = 0; i < V; i++) {
        printf(ANSI_COLOR_CYAN "| %-16s |\n" ANSI_COLOR_RESET, airports[i]);
    }
    printf(ANSI_COLOR_YELLOW "+------------------+\n" ANSI_COLOR_RESET);

    // User input for source and destination
    char start[100], end[100];
    printf("Flying from: ");
    scanf("%s", start);
    printf("Flying to: ");
    scanf("%s", end);
    
    // Fetching index of source and destination
    int srcIndex = getAirportIndex(start);
    int destIndex = getAirportIndex(end);

    // Checking for valid airport entries
    if (srcIndex == -1 || destIndex == -1) {
        printf(ANSI_COLOR_RED "Invalid airport name(s). Please enter a valid airport from the list provided.\n" ANSI_COLOR_RESET);
        return 1;
    }

    // Running Dijkstra's algorithm to find the shortest path
    dijkstra(graph, srcIndex, destIndex);
    return 0;
}
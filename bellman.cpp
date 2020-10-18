 #include <bits/stdc++.h> 
  using namespace std;
// a structure to represent a weighted edge in graph 
struct Edge { 
	int src, dest, weight; 
}; 

// Graph to represent a connected, directed and 
// weighted graph 
struct Graph { 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges. 
	struct Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = new Graph; 
	graph->V = V; 
	graph->E = E; 
	graph->edge = new Edge[E]; 
	return graph; 
} 

// A utility function used to print the solution 
void displaySol(int dist[], int n) 
{ 
	cout<<"Vertex Distance from Source"<<endl; 
	for (int i = 0; i < n; ++i) 
	     cout<<i<<"  "<<dist[i]<<endl;
		//printf("%d \t\t %d\n", i, dist[i]); 
} 
//  Bellman-Ford algorithm. The function 
// also detects negative weight cycle 
void BellmanSol(struct Graph* graph, int src) 
{ 
	int V = graph->V; 
	int E = graph->E; 
	int dist[V]; 

	// Initialize distances from src to all other vertices as INFINITE 
	for (int i = 0; i < V; i++) 
		dist[i] = INT_MAX; 
	dist[src] = 0; 

	// Relax all edges |V| - 1 times. A simple shortest 
	// path from src to any other vertex can have at-most |V| - 1 
	// edges 
	for (int i = 1; i <= V - 1; i++) { 
		for (int j = 0; j < E; j++) { 
			int u = graph->edge[j].src; 
			int v = graph->edge[j].dest; 
			int weight = graph->edge[j].weight; 
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
				dist[v] = dist[u] + weight; 
		} 
	} 

	// check for negative-weight cycle.
	for (int i = 0; i < E; i++) { 
		int u = graph->edge[i].src; 
		int v = graph->edge[i].dest; 
		int weight = graph->edge[i].weight; 
		if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) { 
			cout<<"Graph contains negative weight cycle"; 
			return; // If negative cycle is detected, simply return 
		} 
	} 

	displaySol(dist, V); 

	return; 
} 

//main  Driver program 
int main() 
{ 
	/* Let us create the graph given in above example */
	/*int V  // Number of vertices in graph 
	int E  // Number of edges in graph 
    */
    int V,E;
    cout<<"enter Number of vertex and Edge in the grapgh"<<endl;
    cin>>V>>E;
	struct Graph* graph = createGraph(V, E); 
    cout<<"enter source ,destination and weight"<<endl;
    for(int i=0;i<E;i++)
    {
      cin>>graph->edge[i].src; 
	    cin>>graph->edge[i].dest; 
	   cin>> graph->edge[i].weight; 
    }

		BellmanSol(graph, 0); 

	return 0; 
} 

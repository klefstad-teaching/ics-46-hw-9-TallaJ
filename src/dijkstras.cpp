#include "dijkstras.h"
#include <queue>
#include <vector> 

using namespace std; 

vector<int> dijkstra_shortest_path(const Graph & G, int source, vector<int> & previous){
    vector<int> dist(G.numVertices, INF); 
    previous.assign(G.numVertices, -1); 
    using int_pairs = pair<int, int>;
    priority_queue<int_pairs, vector<int_pairs>, greater<int_pairs>> pq; 
    pq.push({0, source})
    while(!pq.empty()){
        int d = pq.top().first; 
        int u = pq.top().second; 
        pq.pop(); 

        if(u > dist[u]){
            continue; 
        }
        for (Edge e: G[u]){
            int v = e.dst; 
            int weight = e.weight; 
            if (dist[u] + weight < dist[v] && dist[u] != INF){
                dist[v] = dist[u] + weight; 
                previous[v] = u; 
                pq.push({dist[v], v}); 
            }
        }
    }
    return dist; 
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination) {
    vector<int> path;
    for (int at = destination; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}

void print_path(const vector<int>& v, int total){
    int len = v.size(); 
    for (int i = 0; i < len; ++i) {
        cout << v[i] << " ";
    }
    cout << "\nTotal cost is" << total << "\n";
}
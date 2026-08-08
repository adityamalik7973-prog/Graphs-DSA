#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    vector<vector<pair<int,int>>> adjList;
public:
    Graph(int V){
        this->V=V;
        adjList.resize(V);
    }
    void addEdge(int x,int y,int wt){
        adjList[x].push_back({y,wt});
    }
    void dijkstras(vector<int> &dist,int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            if(d>dist[u])continue;
            for(auto neigh:adjList[u]){
                auto [v,weight]=neigh;
                if(dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    pq.push({dist[v],v});
                }
            }
        }
    }
};
int main(){
    Graph g(6);
    vector<int> distances(6,INT_MAX);
}
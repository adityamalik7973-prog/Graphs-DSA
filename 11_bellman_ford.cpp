#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    vector<vector<pair<int,int>>> l;
public:
    Graph(int V){
        this->V=V;
        l.resize(V);
    }
    void addEdge(int x,int y,int wt){
        l[x].push_back({y,wt});
    }
    vector<int> shortest(int src){
        vector<int> dist(V,1e9);
        dist[src]=0;
        for(int i=0;i<V-1;i++){
            for(int u=0;u<V;u++){
                for(auto ngbr:l[u]){
                    auto [v,weight]=ngbr;
                    if(dist[u]!=1e9 && dist[v]>dist[u]+weight)dist[v]=dist[u]+weight;
                }
            }
        }
        return dist;
    }
};
#include<bits/stdc++.h>
using namespace std;
class UnionFind{
    int n;
    vector<int> rank,par;
public:
    UnionFind(int n){
        this->n=n;
        rank.resize(n);
        par.resize(n);
        for(int i=0;i<n;i++){
            rank[i]=0;
            par[i]=i;
        }
    }
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    void unite(int a,int b){
        int parA=find(a),parB=find(b);
        if(parA==parB)return;
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB])par[parB]=parA;
        else par[parA]=parB;
    }
};
class Graph{
    int V;

public:
    Graph(int V){
        this->V=V;
    }
    vector<vector<int>> edges;
    void addEdge(int x,int y,int wt){
        edges.push_back({wt,x,y});
    }
    int kruskal(){
        
        int cost=0;
        UnionFind dsu(V);
        sort(edges.begin(),edges.end());
        for(int i=0;i<edges.size();i++){
            int weight=edges[i][0],a=edges[i][1],b=edges[i][2];
            if(dsu.find(a)!=dsu.find(b)){
                cost+=weight;
                dsu.unite(a,b);
            }
        }
        return cost;
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(1,3,3);
    g.addEdge(2,3,5);
    cout<<g.kruskal();
    
}
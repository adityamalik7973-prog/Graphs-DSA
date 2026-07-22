#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void dfshelper(int src,vector<bool> &visited){
        cout<<src<<" ";
        visited[src]=true;
        for(int v:l[src]){
            if(!visited[v]){
                dfshelper(v,visited);
            }
        }
    }
    void dfs(){
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfshelper(i,visited);
            }
        }
    }
};
int main(){
    int n;cin>>n;
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.dfs();
    return 0;
}
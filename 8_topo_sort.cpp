#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y);
    }
    void topoSortHelper(int src,vector<bool> &visited,stack<int> &s){
        visited[src]=true;
        for(int ngbr:l[src]){
            if(!visited[ngbr]){
                topoSortHelper(ngbr,visited,s);
            }
        }
        s.push(src);
    }
    void topoSort(){
        vector<bool> visited(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i])topoSortHelper(i,visited,s);
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
    }
};
int main(){
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.topoSort();
}
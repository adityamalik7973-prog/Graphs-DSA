#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V=V;
        l=new list<int>[V];
    }
    void addEdge(int x,int y,bool bidir){
        l[x].push_back(y);
        if(bidir) l[y].push_back(x);
    }
    bool cycle(int src,vector<bool> &recPath,vector<bool> &visited){
        visited[src]=true;
        recPath[src]=true;
        for(int ngbr:l[src]){
            if(!visited[ngbr]){
                if(cycle(ngbr,recPath,visited)) return true;
            }else if(recPath[ngbr])return true;
        }
        recPath[src]=false;
        return false;
    }
    bool helper(){
        vector<bool> recPath(V,false);
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycle(i,recPath,visited))return true;
            }
        }
        return false;
    }
};
int main(){
    Graph g(4);
    g.addEdge(1,0,false);
    g.addEdge(0,2,false);
    g.addEdge(0,3,false);
    g.addEdge(2,3,false);
    cout<<g.helper();
}
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
    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool cycleExist(int src,int par,vector<bool> visited){
        visited[src]=true;
        for(int ngbr:l[src]){
            if(!visited[ngbr]){
                if(cycleExist(ngbr,src,visited))return true;
            }else if(ngbr!=par)return true;
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    // g.addEdge(0,2);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(0,3);
    vector<bool> visited(5,false);
    cout<<g.cycleExist(0,-1,visited);
}
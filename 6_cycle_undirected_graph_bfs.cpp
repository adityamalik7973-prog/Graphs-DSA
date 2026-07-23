#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
        l[y].push_back(x);
    }
    bool bfs(vector<bool> &visited,int src){
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src]=true;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(int v:l[p.first]){
                if(!visited[v]){
                    q.push({v,p.first});
                    visited[v]=true;
                }else if(v!=p.second){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(){
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(bfs(visited,i))return true;
            }
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
    
    cout<<g.isCycle();
}
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>> l;
public:
    void addEdge(T u, T v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void bfs(T src){
        map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            T u=q.front();
            q.pop();
            for(auto ngbr:l[u]){
                if(!visited[ngbr]){
                    q.push(ngbr);
                    visited[ngbr]=true;
                }
            }
            cout<< u <<" ";
        }
    }
};
int main(){
    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.bfs(0);
    return 0;
}
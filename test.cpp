#include<iostream>
#include<list>
#include<queue>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
public: 
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printList(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int neigh:l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(){
        queue<int> q;
        vector<bool> vis(V,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(3,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(2,1);
    g.bfs();
    g.printList();
    return 0;
}
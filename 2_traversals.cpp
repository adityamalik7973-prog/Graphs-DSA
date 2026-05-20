#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;//int *arr
public:
    Graph(int V){
        this->V=V;
        l=new list<int> [V];
        //arr=new int [V]
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void printAdjList(){
        for(int i=0;i<V;i++){
            cout<<i<<" : ";
            for(int neigh: l[i]){
                cout<<neigh<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(){//O(V+E))
        queue<int> Q;
        vector<bool> vis(V,0);
        vis[0]=1;
        Q.push(0);
        while(Q.size()>0){
            int u=Q.front();
            Q.pop();
            cout<<u<<" ";
            for(int v: l[u]){//v is immediate neighbour
                if(!vis[v]){
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
        cout<<endl;
    }
    void dfsHelper(int u,vector<bool> &vis){
        cout<<u<<" ";
        vis[u]=1;
        for(int v: l[u]){
            if(!vis[v]){
                dfsHelper(v,vis);
            }
        }
    }
    void dfs(){
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){//for disconnected graphs
            if(!vis[i]){
                dfsHelper(i,vis);
            }
        }
        cout<<endl;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
   
    g.addEdge(2,4);
    g.printAdjList();
    cout<<endl;
    g.dfs();
    return 0;
}
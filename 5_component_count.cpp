#include<iostream>
#include<vector>
#include<list>
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
    void dfshelper(int u,vector<booL> &Vis){
        Vis[u]=1;
        for(int v:l[u]){
            if(!vis[v]){
                dfshelper(v,Vis);
            }
        }
    }
    int dfs(){
        vector<bool> Vis(V,0);
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfshelper(i,Vis);
                cnt++;
            }
        }
        return cnt;
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
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.printAdjList();
    return 0;
}
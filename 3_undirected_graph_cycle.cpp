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
    bool dfscyclehelper(int src,vector<bool> &vis,int par){//O(V+E)
        vis[src]=true;
        for(int v:l[src]){
            if(!vis[v]){
                if(dfscyclehelper(v,vis,src))return true;
            }
            else{
                if(v!=par)return true;
            }
        }
        return false;
    }
    bool dfscycle(){
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfscyclehelper(i,vis,-1))return true;
            }
        }
        return false;
    }
    bool bfscyclehelper(int src,vector<bool> &vis){
        queue<pair<int,int>> q;
        q.push({src,-1}); 
        vis[src]=1;
        while(q.size()>0){
            int u=q.front().first;
            int parU=q.front().second;
            q.pop();
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=1;
                    q.push({v,u});
                }else if(v!=parU){
                    return true;
                }
            }
        }
        return false;
    }
    bool bfscycle(){
        vector<bool> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(bfscyclehelper(i,vis))return true;
            }
        }
        return false;
    }
};
int main(){
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(2,0);
    g.addEdge(3,4);
    g.printAdjList();
    cout<<endl<<g.dfscycle()<<endl<<g.bfscycle();
    return 0;
}
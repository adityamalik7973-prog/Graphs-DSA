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
    void kahns(){
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(int v:l[i])indegree[v]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int curr=q.front();
            cout<<curr<<" ";
            q.pop();
            for(int ngbr:l[curr]){
                indegree[ngbr]--;
                if(indegree[ngbr]==0)q.push(ngbr);
            }
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
    g.kahns();
}
#include<bits/stdc++.h>
using namespace std;
class Graph{
    unordered_map<string,list<pair<string,int>>> l;
public:
    void addEdge(string u,string v,bool bidir,int wt){
        l[u].push_back(make_pair(v,wt));
        if(bidir)l[v].push_back(make_pair(u,wt));
    }
    void printAdjList(){
        for(auto p:l){
            cout<<"city "<<p.first<<" -> ";
            for(auto ngbr:p.second){
                cout<<"( "<<ngbr.first << ", "<<ngbr.second<<" ) ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.addEdge("C","D",true,40);
    g.addEdge("D","B",true,30);
    g.printAdjList();
}
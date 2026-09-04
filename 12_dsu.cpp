#include<bits/stdc++.h>
using namespace std;
class DisjointSetUnion{
    int n;
    vector<int> par,rank;
public:
    DisjointSetUnion(int n){
        this->n=n;
        for(int i=0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    void DisjointSetUnite(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB)return;
        if(rank[parA]==rank[parB]){
            par[parB]=parA;
            rank[parA]++;
        }else if(rank[parA]>rank[parB]){
            par[parB]=parA;
        }else{
            par[parA]=parB;
        }
    }
    void getInfo(){
        for(int i=0;i<n;i++)cout<<par[i]<<" ";
        cout<<'\n';
        for(int i=0;i<n;i++)cout<<rank[i]<<" ";
    }
};
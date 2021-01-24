#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int,int>>> adj; //{nei,wei}

vector<int> dijkstra(int source){
    set<pair<int,int>> s; //{dist,node}
    vector<int> d(n+1,1000);
    d[source]=0;
    s.insert({d[source],source});

    while(!s.empty()){
        auto it=s.begin();
        int i=it->second;
        s.erase(it); 
        
        for(auto e:adj[i]){
            int nb=e.first;
            int w=e.second;

            if(d[i]+w<d[nb]){
                cout<<"node ne"<<nb<<" wieght"<<w<<endl;
                s.erase({d[nb],nb});
                d[nb]=d[i]+w;
                s.insert({d[nb],nb});
            }
        }
    }
    return d;

}

vector<int> dijkstra_par(int source){
    set<pair<int,int>> s; //{dist,node}
    vector<int> d(n+1,1000),par(n+1);
    d[source]=0;
    s.insert({d[source],source});

    while(!s.empty()){
        auto it=s.begin();
        int i=it->second;
        s.erase(it); 
        
        for(auto e:adj[i]){
            int nb=e.first;
            int w=e.second;

            if(d[i]+w<d[nb]){
                par[nb]=i;
                cout<<"node ne"<<nb<<" wieght"<<w<<endl;
                s.erase({d[nb],nb});
                d[nb]=d[i]+w;
                s.insert({d[nb],nb});
            }
        }
    }
    return par;

}

void getPath(int i,vector<int> &d, vector<int> &par){
    if (d[i]==1000){
       
        return;
    }
    if (par[i]==0){
        cout<<i<<"-->";
        return;
    }
    getPath(par[i],d,par);
    cout<<i<<"-->";
}

int main(){
    int m;
    cin>>n>>m;
    
    adj.resize(n+1);
    while(m--){
        int i,j,w;
        cin>>i>>j>>w;
        
        adj[i].push_back({j,w});
        adj[j].push_back({i,w});
    }
    
    int source;
    cin>>source;
 
    vector<int> d=dijkstra(source);
    vector<int> p=dijkstra_par(source);
    for(int a=1;a<=n;a++){
        cout<<a<<"\t"<<d[a]<<endl;
    }

    for(int a=1;a<=n;a++){
        cout<<a<<"\t";
        getPath(a,d,p);
        cout<<endl;
    }
    return 0;
}

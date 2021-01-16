# include <bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    public:
        map<T ,list<T> > adjlist;

        void addEdge(T u, T v, int dist,bool bidirec = 1)
	    {
		    adjlist[u].push_back(v);
            if (bidirec){
                adjlist[v].push_back(u);
            }
	    }

        void print_adj(){
        for (auto n : adjlist){
            cout << n.first<<" : ";
            for (auto a : n.second ){
            cout <<"( "<<a<<" ) " ;
                }
            cout << endl;
            }
        } 

        void bfs(T start){
             map<T,bool> visited;
             queue<T> q;
             q.push(start);
             while(!q.empty()){
                 T front_element=q.front();
                 q.pop();
                 if(!visited[front_element]){
                     cout<<front_element<<"-->";
                     visited[front_element]=true;
                 }
                 for(auto adj:adjlist[front_element]){
                    if (!visited[adj])
                    q.push(adj);
                 }
             }   
        }

        void dfshelper(T start,map<T,bool> &visited)
        {    visited[start]=true;
             for(auto adj:adjlist[start]){
                 if (!visited[adj]){
                     cout<<adj<<"-->";
                     dfshelper(adj,visited);}
             }
             
        }

        void dfs(T start){
            map<T,bool> visited;
            cout<<endl;
            cout<<"dfs = "<<start<<"-->";
            dfshelper(start,visited);

        }
};

int main()
{
	Graph<char> g;
	g.addEdge('0', '1',4, 1);
	g.addEdge('0', '7',8, 1);
	g.addEdge('1', '7',11, 1);
	g.addEdge('1', '2',8, 1);
	g.addEdge('7', '8',7, 1);
	
	g.print_adj();
    g.bfs('0');
    g.dfs('0');
	
	return 0;
}
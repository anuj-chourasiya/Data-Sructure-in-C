import java.util.*;

public class graph{
    
    static void addEdge(ArrayList<ArrayList<Integer>> adj,int u,int v,boolean directed)
    {
        if (!directed){
        adj.get(u).add(v);
        adj.get(v).add(u);
        }
        else{
            adj.get(u).add(v);
        }
    }
    
    public static void printAdj(ArrayList<ArrayList<Integer>> adj){
        for (int i=0;i<adj.size();i++){
            System.out.print("Vertex "+i+" --> ");
            for (int j=0;j<adj.get(i).size();j++){
                System.out.print(adj.get(i).get(j)+" ");
            }
            System.out.println();
        }
    }

    //Depth FIrst Search
    static void dfs(ArrayList<ArrayList<Integer>> adj){
        HashSet<Integer> visited=new HashSet<>();
        int curr=5;
        System.out.println(curr+" ");
        dfshelper(curr,adj,visited);
    }

    static void dfshelper(int curr,ArrayList<ArrayList<Integer>> adj,HashSet<Integer> visited){
        visited.add(curr);
        for(int node : adj.get(curr)){
            if (!(visited.contains(node))){
                System.out.println(node+" ");
                dfshelper(node,adj,visited);

            }
        }
    }

    //Breadth first Search
    static void bfs(int startNode,ArrayList<ArrayList<Integer>> adj){
        HashSet<Integer> visited= new HashSet<>();
        Queue<Integer> queue=new LinkedList<>();
        queue.add(startNode);
        visited.add(startNode);
        while(!queue.isEmpty()){
            int curr=queue.remove();
            System.out.println(curr);
            for(int node:adj.get(curr)){
                if (!visited.contains(node)){
                    queue.add(node);
                    visited.add(node);
                }
            }
        }
    }

    static void isCyclePresent(ArrayList<ArrayList<Integer>> adj){
        HashSet<Integer> visited=new HashSet<>();
        boolean cycle=dfscyclehelper(5,adj,visited,-1);
        System.out.println(cycle);
    }

    static boolean dfscyclehelper(int curr,ArrayList<ArrayList<Integer>> adj, HashSet<Integer> visited,int parent){
        visited.add(curr);
        for(int node : adj.get(curr)){
            if (!visited.contains(node)){
                System.out.println(node+" ");
                if (dfscyclehelper(node,adj,visited,curr)==true){
                    return true;
                }
            }
            else if(parent!=node){
                    return true;
            }
        }
        return false;
    }

    static boolean isCyclePresentInDirected(ArrayList<ArrayList<Integer>> adj,int numVertices){
        boolean []visited = new boolean[numVertices];
        boolean []stackrecur = new boolean[numVertices];
        for(int i=0; i < numVertices; i++){
            if (visited[i]==false){
            if (isCyclePresentInDirectedHelper(i,adj,visited,stackrecur)==true){
                return true;
                }
            }
        }
        return false;

    }

    static boolean isCyclePresentInDirectedHelper(int startNode,ArrayList<ArrayList<Integer>> adj,boolean []visited,boolean []stackrecur)
    {
        visited[startNode]=true;
        stackrecur[startNode]=true;
        for (int node : adj.get(startNode)){

            if (visited[node]==false && isCyclePresentInDirectedHelper(node,adj,visited,stackrecur)==true){
                return true;
            }
            else if (stackrecur[node]==true){
                return true;
            }
        }
        stackrecur[startNode]=false;
        return false;
    }

    static void topologicalSort(ArrayList<ArrayList<Integer>> adj,int numOfVertices){
        ArrayList<Integer> indegree=new ArrayList<>();
        for(int i=0;i<numOfVertices;i++){
            indegree.add(0);
        }
        
        for (int i=0;i<adj.size();i++){
            for(int j=0;j<adj.get(i).size();j++){
                int ele=adj.get(i).get(j);
                int ans=indegree.get(ele);
                ans++;
                indegree.set(ele,ans);
            }
        }
        Queue<Integer> queue = new LinkedList<>();
        for(int i=0;i<numOfVertices;i++){
            if (indegree.get(i)==0){
            queue.add(i);
            }
        }
        while(!queue.isEmpty()){
            int ele=queue.remove();
            System.out.print(ele+" ");
            for(int nei : adj.get(ele)){
                int temp=indegree.get(nei);
                temp--;
                indegree.set(nei,temp);
                if (indegree.get(nei)==0){
                    queue.add(nei);
                }
            }
        }
    }

    public static void main(String args[]) {
        //no of vertices
        int v=6;
        boolean directed=false;
        ArrayList<ArrayList<Integer>> adj= new ArrayList<ArrayList<Integer>>(v);
        for(int i=0;i<v;i++){
            adj.add(new ArrayList<Integer>());
        }   
        addEdge(adj,0,1,directed);
        addEdge(adj,1,2,directed);
        addEdge(adj,3,0,directed);
        addEdge(adj,3,4,directed);
        addEdge(adj,2,4,directed);
        addEdge(adj,4,5,directed);
        printAdj(adj);
        dfs(adj);
        bfs(5,adj);
        isCyclePresent(adj); //In undirected graph
        directed=true;
        addEdge(adj,0,1,directed);
        addEdge(adj,2,1,directed);
        addEdge(adj,2,3,directed);
        addEdge(adj,3,4,directed);
        addEdge(adj,4,2,directed);
        boolean ans=isCyclePresentInDirected(adj,5); //In directed graph
        System.out.println(ans);
        directed=true;
        addEdge(adj,0,1,directed);
        addEdge(adj,0,2,directed);
        addEdge(adj,1,3,directed);
        addEdge(adj,1,4,directed);
        addEdge(adj,4,5,directed);
        topologicalSort(adj,6);

    }
}



def canFinish(numCourses,prerequisites):
#converting edge list into adjacency list
    if len(prerequisites)==0:
        return True
    adj={}
    for i in range(len(prerequisites)):
        if adj.get(prerequisites[i][1],-1)==-1:
            adj[prerequisites[i][1]]=[]
            adj[prerequisites[i][1]].append(prerequisites[i][0])
            if adj.get(prerequisites[i][0],-1)==-1:
                adj[prerequisites[i][0]]=[]
                
        else:
            adj[prerequisites[i][1]].append(prerequisites[i][0])
            if adj.get(prerequisites[i][0],-1)==-1:
                adj[prerequisites[i][0]]=[]
    #print(adj)
    #getting indegree of each node
    idg={}
    for course in adj:
        idg[course]=idg.get(course,0)+0
        for nei in adj[course]:
            idg[nei]=idg.get(nei,0)+1
            
    #print(idg)
    
    queue=[]
    for i in adj:
        if idg[i]==0:
            queue.append(i)
    #print(queue)
    count=len(queue)
    while(queue):
        front=queue.pop(0)
        for nei in adj[front]:
            idg[nei]-=1
            if idg[nei]==0:
                queue.append(nei)
                count+=1
    
    if count==len(idg):
        return True
    else:
        return False

print(canFinish(4,[[1,0],[2,1],[3,2],[1,3]]))
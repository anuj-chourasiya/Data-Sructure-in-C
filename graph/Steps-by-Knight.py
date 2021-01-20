#checking if current position is out of grid or not
def isSafe(i,j,N):
    if i>=0 and j>=0 and i<N and j<N:
        return True
    else:
        return False


def minStepToReachTarget(KnightPos, TargetPos, N):
    # 1 based indexing
    KnightPos[0]-=1
    KnightPos[1]-=1
    TargetPos[0]-=1
    TargetPos[1]-=1

    queue=[]
    visited=[[0 for rows in range(N)]for i in range(N)]
    distance=[[0 for rows in range(N)]for i in range(N)]
    queue.append(KnightPos)
    visited[KnightPos[0]][KnightPos[1]]=1
    
    # direction for Knight
    dx=[-1,-1,1,1,2,-2,2,-2]
    dy=[2,-2,2,-2,-1,-1,1,1]
    
    #bfs
    while((queue)):
        
        front=queue.pop(0)
        
        #iterating over all direction
        for d in range(8):
            
            #checking if upcoming dirction is safe and not visited
            if isSafe(front[0]+dx[d],front[1]+dy[d],N) and visited[front[0]+dx[d]][front[1]+dy[d]]==0:
                
                visited[front[0]+dx[d]][front[1]+dy[d]]=1
                newdirx=front[0]+dx[d]
                newdiry=front[1]+dy[d]
                
                distance[newdirx][newdiry]=distance[front[0]][front[1]]+1
                
                #if newdirection is Target direction
                if [newdirx,newdiry]==TargetPos:
                    return distance[newdirx][newdiry]

                queue.append([newdirx,newdiry])
    
    #if target position can not be reached be Knight
    return 0
    


print(minStepToReachTarget([4,5],[1,1], 6))
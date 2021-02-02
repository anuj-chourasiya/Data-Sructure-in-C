class MaxHeap:
    def __init__(self):
        self._list=[]
        
    def get_left_child(self,k):
        return (2*k)+1
    def get_right_child(self,k):
        return (2*k)+2
    def get_parent(self,k):
        return (k-1)//2

    def swim(self,k):
        #looping untill key grater than 0 and child is greater  than parent
        while(k > 0 and self._list[self.get_parent(k)] < self._list[(k)] ):
            #swapping key if it is greater
            (self._list[k], self._list[self.get_parent(k)])=( self._list[self.get_parent(k)],self._list[k])
            k=self.get_parent(k)
                
    def sink(self,k):
        #looping untill current child is less than len of heap and current key is less than left child or right child
        while(self.get_left_child(k)<(len(self._list)-1) and (self._list[k]<self._list[self.get_left_child(k)] or self._list[k]<self._list[self.get_right_child(k)])):
            j=self.get_left_child(k)
            #if right child is greater 
            if(self._list[j]<self._list[j+1]):
                j=j+1
            #swap max ele with key    
            (self._list[k],self._list[j])=(self._list[j],self._list[k])

            k=j
            
    def insert(self,data):
        self._list.append(data)
        key=self._list.index(data)
        self.swim(key) #if given element is bigger then adjusting it according to the heap

    def delMax(self):
        #swap first and last element
        (self._list[0],self._list[-1])=(self._list[-1],self._list[0])
        #gettng ele at last index
        ele=self._list[-1]
         
        self._list.remove(ele)
        self.sink(0)
        return ele
        

def main():
    items=[11,4,7,10,123,100]
    node = MaxHeap()
    for i in items:
        node.insert(i)
    for ele in items:
        ele=node.delMax()
        print(ele,end=" ")
   
    print("node list=",node._list)


main()


from collections import defaultdict

class TrieNode:
    def __init__(self,data):
        self.data=data
        self.children=defaultdict(lambda: None)
        self.freq=0
        self.isTerminal=False

    def __str__(self):
        return "hey "+(self.data)
    
class Trie:
    def __init__(self,data):
        self.root=self.getNode(data)
    
    def getNode(self,data):
        return TrieNode(data)
    
    def insert(self,word):
        pointer=self.root
        for char in word:
            if not pointer.children[char]:
                pointer.children[char]=TrieNode(char)
            
            pointer=pointer.children[char]
            pointer.freq+=1

        pointer.isTerminal = True
    
    def firstOne(self,word):
        ans=""
        pointer=self.root
        for char in word:
            if pointer.freq>1 or pointer.freq==0:
                ans+=char
                pointer=pointer.children[char]
            elif pointer.freq==1 :
                return ans
        if pointer.freq==1:
            return ans
        return -1

        
def uniqueSmallestPrefix(words):
    root=Trie(0)
    ans=[]

    for word in words:
        root.insert(word)
    for word in words:
        ans.append(root.firstOne(word))
    return ans
   



inp=["don","duck","donhaihum","dont","anuj","aman"]
ans=uniqueSmallestPrefix(inp)
print(inp)
print(ans)

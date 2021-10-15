class DisjointSets:
    def __init__(self, vertices):
        self.vertices=vertices
        # initially parant of the vertex will be vertex itself.
        self.parent={}
        for v in vertices:
            self.parent[v]=v
        # dict based on vertices stores rank, default all rank to 0
        self.rank= dict.fromkeys(vertices,0)
        
    def find(self, item):
        if self.parent[item]==item:
            # only one element in set
            return item
        else:
            return (self.find(self.parent[item]))
        
    def union(self, x,y):
        xroot=self.find(x)
        yroot=self.find(y)
        
        if self.rank[xroot]< self.rank[yroot]:
            self.parent[xroot]=yroot
        elif self.rank[xroot]>self.rank[yroot]:
            self.parent[yroot]=xroot
        else:
            self.parent[yroot]=xroot
            self.rank[xroot]+=1
            
vertices= [ "a","b","c","d","e"]
ds=DisjointSets(vertices)
print( " Parent of A is : ", ds.find("a"))
print( " Parent of B is : ", ds.find("b"))
ds.union("a","b")
print( " Parent of A is : ", ds.find("a"))
print( " Parent of B is : ", ds.find("b"))
ds.union("a","c")
print( " Parent of C is : ", ds.find("c"))


'''
  OUTPUT
 Parent of A is :  a
 Parent of B is :  b
 Parent of A is :  a
 Parent of B is :  a
 Parent of C is :  a
 '''
 

class graph:
    def __init__(self, v, mat):
        self.v = v
        self.matrix = mat

    def FWA(self):
        for i in range(self.v):
            for j in range(self.v):
                for k in range(self.v):
                    self.matrix[i][j] = min(self.matrix[i][j], self.matrix[i][k] + self.matrix[k][j])

    def show(self):
        for i in range(self.v):
            for j in range(self.v):
                print(self.matrix[i][j], end="    ")
            print()


v = int(input("Enter the number of vertices: "))
k = []
for i in range(v):
    print("Enter the edge lengths between vertex %d and others , if none exists enter 999: "%(i+1))
    n = input().split()
    n = list(map(int, n))
    k.append(n)

g = graph(v, k)
g.FWA()
g.show()

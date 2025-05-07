'''
1.  Implement depth first search algorithm and Breadth First Search algorithm. Use an undirected graph and
    develop a recursive algorithm for searching all the vertices of a graph or tree data structure.  
'''

from collections import deque

# Sample input
sample = {
    'a':['b','c','e'],
    'b':['a','d'],
    'c':['a','f'],
    'd':['b','e'],
    'e':['d','f'],
    'f':['c','e']
}

adj_list = {}

def add_edge(u, v):
    if u not in adj_list:
        adj_list[u] = []
    if v not in adj_list:
        adj_list[v] = []
    adj_list[u].append(v)
    adj_list[v].append(u)

def BFS(adj_list, start):
    q = deque()
    visited = set()
    q.append(start)

    while len(q):
        cur = q.popleft()
        print(cur, end = " ")
        visited.add(cur)

        for node in adj_list[cur]:
            if node not in visited:
                q.append(node)
                visited.add(node)

def DFS(adj_list, node, visited:set):
    print(node, end=" ")
    visited.add(node)

    for v in adj_list[node]:
        if v not in visited:
            DFS(adj_list, v, visited)


n = int(input("Enter number of edges: "))
print("Enter edges in the format:\na b\na c\nb c\n...")
adj_list = {}
for i in range(0, n):
    e = input("Edge: ")
    u, v = e.split()
    add_edge(u, v)



print("BFS: ")
BFS(adj_list, 'a')
print("\nDFS: ")
DFS(adj_list, 'a', set())

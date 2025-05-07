'''
VI. Kruskal's Minimal Spanning Tree Algorithm 
'''

def kruskal(nodes, edges:list):
    parent = {i:i for i in nodes}

    def find_parent(u: chr):
        while (u != parent[u]):
            parent[u] = parent[parent[u]]
            u = parent[u]
        
        return u
    
    def union(u:chr, v:chr):
        ulp_u = find_parent(u)
        ulp_v = find_parent(v)

        if (ulp_u != ulp_v):
            parent[u] = parent[v]
            return True
        return False
    
    edges.sort(key=lambda x: x[2])
    mst_edges = []
    mst_cost = 0

    for edge in edges:
        if (union(edge[0], edge[1])):
            mst_edges.append((edge[0], edge[1]))
            mst_cost += edge[2]
    return mst_edges, mst_cost
    

nodes = ['A', 'B', 'C', 'D']
edges = [('A', 'B', 1), ('B', 'C', 1), ('A', 'C', 3), ('C', 'D', 5), ('B', 'D', 6)]
mst, cost = kruskal(nodes, edges)
print("Edges in MST (Kruskal):", mst)
print("Total cost:", cost)



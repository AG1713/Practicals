'''
II. Minimum Spanning Tree 
'''
import heapq

sample1 = {
    'a': [('b', 1), ('c', 1), ('e', 7)],
    'b': [('a', 1), ('d', 4)],
    'c': [('a', 1), ('f', 6)],
    'd': [('b', 4), ('e', 1)],
    'e': [('d', 1), ('f', 1)],
    'f': [('c', 6), ('e', 1)]
}

sample2 = {
    'a': [('B', 1), ('C', 3)],
    'b': [('A', 1), ('C', 1), ('D', 6)],
    'c': [('A', 3), ('B', 1), ('D', 5)],
    'd': [('B', 6), ('C', 5)]
}


def prims(adj_list:dict, start:chr):
    pq = [(0, start)]
    visited = {key: False for key in adj_list}

    visited[start] = 0
    span_cost = 0

    while pq:
        cost, node = heapq.heappop(pq)

        if (visited[node]): continue
        visited[node] = True
        span_cost += cost

        for n, c in adj_list[node]:
            if (visited[n]): continue
            heapq.heappush(pq, (c, n))

    return span_cost



print("Total cost of minimum spanning tree: ", prims(sample1, 'a'))

    
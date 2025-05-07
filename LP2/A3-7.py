'''
VII. Dijkstra's Minimal Spanning Tree Algorithm 
'''

import heapq

sample = {
    'a': [('b', 1), ('c', 1), ('e', 7)],
    'b': [('a', 1), ('d', 4)],
    'c': [('a', 1), ('f', 6)],
    'd': [('b', 4), ('e', 1)],
    'e': [('d', 1), ('f', 1)],
    'f': [('c', 6), ('e', 1)]
}


def dijktras(adj_list, start, goal):
    pq = [(0, start)]
    visited = {key: float('inf') for key in adj_list}
    visited[start] = 0
    
    while (len(pq)):
        d, node = heapq.heappop(pq)

        for entry in adj_list[node]:
            new_dist = d+entry[1]
            if visited[entry[0]] > new_dist:
                visited[entry[0]] = new_dist
                heapq.heappush(pq, (new_dist, entry[0]))
    
    return visited

print(dijktras(sample, 'a', 'f'))

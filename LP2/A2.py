'''
2.  Implement A star Algorithm for any game search problem. 
'''
import heapq

grid = [
    [0, 0, 0, 0, 0],
    [1, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 1, 1, 0],
    [0, 0, 0, 0, 0]
]


def h(a:tuple, b:tuple): # Manhattan heuristic
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

def a_star(grid:list, start:tuple, goal:tuple):
    rows, cols = len(grid), len(grid[0])
    open_list = [(0 + h(start, goal), 0, start, [start])] # f, g, position, path
    closed_list = set() # It is ok to use set as closed list in a grid environment, but not in general for A*
    # since items in closed list may go to open list later (meaning, the g(n) to reach a somehwere may change later)
    closed_list.add(start)

    while len(open_list):
        f, g, cur, path = heapq.heappop(open_list)

        if (cur == goal): return path

        moves = [(0,1),(1,0),(0,-1),(-1,0)]
        for move in moves:
            new_cur = (cur[0] + move[0], cur[1] + move[1])

            if (new_cur[0] >= rows or new_cur[1] >= cols or new_cur[0] < 0 or new_cur[1] < 0): continue
            if (new_cur in closed_list) or (grid[new_cur[0]][new_cur[1]] == 1): continue

            new_g = g+1
            new_f = new_g + h(new_cur, goal)
            heapq.heappush(open_list, (new_f, new_g, new_cur, path + [new_cur]))
    
    return None


rows, cols = len(grid), len(grid[0])

# -------------------------------Not mandatory-------------------------------
print("Grid:")
for i in range(0, rows):
    for j in range(0, cols):
        if (grid[i][j] == 0): print("O", end=" ")
        elif (grid[i][j] == 1): print("X", end=" ")
    print()
# ---------------------------------------------------------------------------

path = a_star(grid, (0,0), (4,1))

sol = grid.copy()
for pos in path:
    sol[pos[0]][pos[1]] = 'X'

print("\nPath: ", path)

# -------------------------------Not mandatory-------------------------------
print("\nSolution: ")
for i in range(0, rows):
    for j in range(0, cols):
        if (grid[i][j] == 0): print("O", end=" ")
        elif (grid[i][j] == 1): print("X", end=" ")
        else: print(0, end=" ")
    print()
# ---------------------------------------------------------------------------
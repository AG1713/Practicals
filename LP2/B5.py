'''
4.  Implement a solution for a Constraint Satisfaction Problem using Branch and Bound and Backtracking for
    n-queens problem or a graph coloring problem. 
'''
# This code is completely AI-generated

def solve_n_queens(n):
    board = [-1] * n  # board[i] = column position of queen in row i
    solutions = []

    def is_safe(row, col):
        for prev_row in range(row):
            # Check same column or diagonal conflicts
            if board[prev_row] == col or \
               abs(board[prev_row] - col) == abs(prev_row - row):
                return False
        return True

    def backtrack(row):
        if row == n:
            solutions.append(board[:])  # Found a valid solution
            return
        for col in range(n):
            if is_safe(row, col):  # Branch and Bound: prune invalid branches
                board[row] = col
                backtrack(row + 1)
                board[row] = -1  # Backtrack

    backtrack(0)
    return solutions

# Pretty print function
def print_solutions(solutions):
    for idx, sol in enumerate(solutions, 1):
        print(f"\nSolution {idx}:")
        for row in sol:
            line = ['.'] * len(sol)
            line[row] = 'Q'
            print(' '.join(line))

# Run
n = 4
solutions = solve_n_queens(n)
print_solutions(solutions)

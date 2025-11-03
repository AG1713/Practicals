import java.util.Scanner;

class NQueensWithFirstPlaced {

    // Function to print the final board
    void printBoard(int[][] board, int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    // Function to check if a queen can be placed at board[row][col]
    boolean isSafe(int[][] board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1)
                return false;

        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;

        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    // Recursive function to solve N-Queens using backtracking
    boolean solveNQueens(int[][] board, int row, int n) {
        // Base condition: all queens placed
        if (row == n)
            return true;

        // Skip the row if the queen is already placed manually
        boolean alreadyPlaced = false;
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 1) {
                alreadyPlaced = true;
                break;
            }
        }

        if (alreadyPlaced)
            return solveNQueens(board, row + 1, n);

        // Try placing queen in all columns
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 1; // Place queen
                if (solveNQueens(board, row + 1, n))
                    return true; // Found solution
                board[row][col] = 0; // Backtrack
            }
        }
        return false;
    }

}

public class A5 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter dimensions of the board (n): ");
        int n = sc.nextInt();

        int[][] board = new int[n][n];

        // Place the first queen manually\
        System.out.println("Row for first queen: ");
        int firstRow = sc.nextInt();
        System.out.println("Column for first queen: ");
        int firstCol = sc.nextInt();
        board[firstRow][firstCol] = 1;

        // Solve for remaining queens

        NQueensWithFirstPlaced nq = new NQueensWithFirstPlaced();

        if (nq.solveNQueens(board, 0, n)) {
            System.out.println("Final N-Queens Matrix:");
            nq.printBoard(board, n);
        } else {
            System.out.println("No solution exists with the first queen at (" + firstRow + "," + firstCol + ")");
        }
    }
}

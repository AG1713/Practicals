import java.util.Arrays;
import java.util.Scanner;

class NQueens {

    void displayBoard(char[][] board, int n) {
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    boolean isSafe(char[][] board, int n, int row, int col) {
        // Checking column
        for (int i=0 ; i<n ; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // upper-left diagonal
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // lower-left diagonal
        for (int i = row+1, j = col-1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // upper-right diagonal
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        // lower-right diagonal
        for (int i = row+1, j = col+1; i < n && j < n; i++, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    boolean solveNQueens(char[][] board, int n, int row) {
        if (row == n) return true;

        // Check if there is already a queen on the current row
        for (int col=0 ; col<n ; col++) {
            if (board[row][col] == 'Q') return solveNQueens(board, n, row+1);
        }

        // Normal
        for (int col=0 ; col<n ; col++) {
            if (isSafe(board, n, row, col)) {
                board[row][col] = 'Q';

                if (solveNQueens(board, n, row+1)) return true;
                board[row][col] = '-';
            }
        }
        return false;
    }

}

public class A5 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = sc.nextInt();

        if (n <= 0) System.out.println("Invalid input");

        char[][] board = new char[n][n];
        for (int i=0 ; i<n ; i++) {
            char[] arr = new char[n];
            Arrays.fill(arr, '-');
            board[i] = arr;
        }

        System.out.println("Indexes are 1-based...");
        System.out.print("First queen row: ");
        int i = sc.nextInt();
        System.out.print("First queen column: ");
        int j = sc.nextInt();

        NQueens q = new NQueens();

        if (i>n || j>n || i<=0 || j<=0) {
            System.out.println("Invalid inputs");
        }
        else {
            board[i-1][j-1] = 'Q';

            if (q.solveNQueens(board, n, 0)) {
                System.out.println();
                q.displayBoard(board, n);
            } else {
                System.out.println("No valid solution");
            }
        }

        /*
        Sample input: 5 3 2
        Sample output:
        Q - - - -
        - - - Q -
        - Q - - -
        - - - - Q
        - - Q - -
        */

    }
}
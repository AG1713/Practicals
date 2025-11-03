import java.util.Scanner;

class Solution {

    int fibonacci_rec(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;

        int result = fibonacci_rec(n-1) + fibonacci_rec(n-2);
        return result;
    }

    int fibonacci_iter(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;

        int ans = 1, prev = 0;
        for (int i=2 ; i<=n ; i++) {
            int next = prev + ans;
            prev = ans;
            ans = next;
        }

        return ans;
    }


}


public class A1 {

    public static void main(String[] args) {

        Solution obj = new Solution();
        long start;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        int n = sc.nextInt();
        sc.close();

        start = System.nanoTime();
        System.out.println("\nn'th fibonacci using iterative (nanoseconds): " + obj.fibonacci_iter(n));
        System.out.println("Time for iterative: " + (System.nanoTime() - start));

        start = System.nanoTime();
        System.out.println("\nn'th fibonacci using recursive (nanoseconds): " + obj.fibonacci_rec(n));
        System.out.println("Time for recursive: " + (System.nanoTime() - start));

    }

}
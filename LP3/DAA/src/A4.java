import java.util.Scanner;

class DP {

    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapsackDP(int W, Item[] items) {
        int n = items.length;
        int[] dp = new int[W + 1];

        for (int i = 1; i <= n; i++) {
            for (int w = W; w >= 0 && items[i - 1].weight <= w ; w--) {
                dp[w] = Math.max(
                        items[i - 1].value + dp[w - items[i - 1].weight],
                        dp[w]
                );
            }
        }
        return dp[W];
    }

}

public class A4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the capacity of Knapsack: ");
        int W = sc.nextInt();
        System.out.print("Enter the number of items: ");
        int n = sc.nextInt();

        Item[] items = new Item[n];
        for (int i=0 ; i<n ; i++) {
            System.out.print("Enter profit for item " + (i+1) + ": ");
            int val = sc.nextInt();
            System.out.print("Enter weight for item " + (i+1) + ": ");
            int w = sc.nextInt();
            items[i] = new Item(val, w);
        }

        DP dp = new DP();
        System.out.println("\nMaximum profit using Dynamic Programming: " + dp.knapsackDP(W, items));


        sc.close();

        // Sample input: 10 5 40 2 50 3 100 1 95 5 30 3
        // Sample input's answer: 245

    }
}
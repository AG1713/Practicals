import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

class DP {

    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapsackDP(int W, Item[] items) {
        int n = items.length;
        int[][] dp = new int[n + 1][W + 1]; // dp[i][w] = max value using first i items and capacity w

        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0)
                    dp[i][w] = 0;
                else if (items[i - 1].weight <= w)
                    dp[i][w] = Math.max(items[i - 1].value + dp[i - 1][w - (int)items[i - 1].weight],
                            dp[i - 1][w]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        return dp[n][W];
    }

    int knapsack(int W, Item[] items) {
        int n = items.length;
        return knapsackDP(W, items);
    }

}

// --------------------------------------- Branch and Bound ---------------------------------------

class Node {
    int level, profit;
    float weight;
    double bound;
}


class BranchBoundKnapsack {

    double bound(Node u, int n, int W, Item[] items) {
        if (u.weight >= W)
            return 0;

        double profitBound = u.profit;
        int j = u.level + 1;
        float totalWeight = u.weight;

        while (j < n && totalWeight + items[j].weight <= W) {
            totalWeight += items[j].weight;
            profitBound += items[j].value;
            j++;
        }

        if (j < n)
            profitBound += (W - totalWeight) * items[j].value / items[j].weight;

        return profitBound;
    }

    int knapsack(int W, Item[] items, int n) {
        Arrays.sort(items, (a, b) -> Double.compare((double)b.value/b.weight, (double)a.value/a.weight));

        Queue<Node> pq = new PriorityQueue<>((a, b) -> Double.compare(b.bound, a.bound));

        Node u = new Node(), v = new Node();
        u.level = -1;
        u.profit = 0;
        u.weight = 0;
        u.bound = bound(u, n, W, items);

        pq.add(u);
        int maxProfit = 0;

        while (!pq.isEmpty()) {
            u = pq.poll();

            if (u.level == n - 1) continue;

            v = new Node();
            v.level = u.level + 1;

            // include current item
            v.weight = u.weight + items[v.level].weight;
            v.profit = u.profit + items[v.level].value;

            if (v.weight <= W && v.profit > maxProfit)
                maxProfit = v.profit;

            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit)
                pq.add(v);

            // exclude current item
            v = new Node();
            v.level = u.level + 1;
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v, n, W, items);

            if (v.bound > maxProfit)
                pq.add(v);
        }

        return maxProfit;
    }

}
// --------------------------------------- Main ---------------------------------------
public class A4 {
    public static void main(String[] args) {

        int W = 10;
        int W1 = 10;
        Item[] items = {
                new Item(40, 2),
                new Item(50, 3.14f),
                new Item(100, 1.98f),
                new Item(95, 5),
                new Item(30, 3)
        };

        Item[] items1 = {
                new Item(40, 2),
                new Item(50, 3),
                new Item(100, 1),
                new Item(95, 5),
                new Item(30, 3),
        };

        int n = items.length;
        int n1 = 3;

        DP dp = new DP();
        BranchBoundKnapsack bb = new BranchBoundKnapsack();

        System.out.println("Maximum possible profit using DP = " + dp.knapsack(W, items));
        System.out.println("Maximum possible profit using DP = " + dp.knapsack(W1, items1));
        System.out.println("Maximum possible profit using BB = " + bb.knapsack(W, items, n));

    }
}
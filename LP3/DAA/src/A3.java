import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class A3 {

    private static double fractionalKnapsack(int[] values, float[] weights, int W) {
        Item[] items = new Item[values.length];

        for (int i=0 ; i<values.length ; i++) {
            items[i] = new Item(values[i], weights[i]);
        }

        Arrays.sort(items, new Comparator<Item>() {
            public int compare(Item a, Item b) {
                double profitA = (double) a.value/a.weight;
                double profitB = (double) b.value/b.weight;

                return Double.compare(profitB, profitA);
            }
        });

        double profit = 0;
        int rem = W;
        int i=0;

        while (i<items.length && rem > 0) {
            if (items[i].weight <= rem) {
                profit += items[i].value;
                rem -= items[i].weight;
                i++;
            }
            else {
                double fraction = ((double) rem/(double) items[i].weight);
                profit += (items[i].value*fraction);
                rem = 0;

                break;
            }
        }

        return profit;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] val = new int[n];
        float[] wt = new float[n];

        System.out.println("Enter values: ");
        for (int i=0 ; i<n ; i++) {
            val[i] = sc.nextInt();
        }

        System.out.println("Enter weights: ");
        for (int i=0 ; i<n ; i++) {
            wt[i] = sc.nextFloat();
        }

        System.out.println("Maximum profit: " + fractionalKnapsack(val, wt, n));
        // Sample input
        // 3
        // 60 100 120
        // 10 20 30


    }

}
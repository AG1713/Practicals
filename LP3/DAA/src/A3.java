import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class FractionalKnapsack {
    public double knapsack(int W, Item[] items) {

        Arrays.sort(items, new Comparator<Item>() {
            public int compare(Item a, Item b) {
                double profitA = (double) a.value/a.weight;
                double profitB = (double) b.value/b.weight;

                return Double.compare(profitB, profitA);
            }
        });

        double profit = 0;
        float rem = W;
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
                break;
            }
        }

        return profit;
    }

}

public class A3 {

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

        FractionalKnapsack kp = new FractionalKnapsack();

        System.out.println("\nMaximum profit: " + kp.knapsack(W, items));
        // Sample input: 10 5 40 2 50 3 100 1 95 5 30 3
        // Sample input's output: 268.3333...


    }

}
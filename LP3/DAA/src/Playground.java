import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Scanner;

class Practice {

    HNode constructHTree(Map<Character, Integer> freqMap) {
        PriorityQueue<HNode> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.freq, o2.freq));

        for (Map.Entry<Character, Integer> entry : freqMap.entrySet()) {
            pq.offer(new HNode(entry.getKey(), entry.getValue()));
        }

        while (pq.size() > 1) {
            HNode first = pq.poll();
            HNode second = pq.poll();

            HNode newNode = new HNode(null, first.freq + second.freq);
            newNode.left = first;
            newNode.right = second;
            pq.offer(newNode);
        }

        return pq.poll();
    }

    void traverse(HNode node, Map<Character, String> codes, String code) {
        if (node == null) return;
        if (node.left == null && node.right == null) {
            codes.put(node.c, code);
            return;
        }
        traverse(node.left, codes, code + '0');
        traverse(node.right, codes, code + '1');
    }

    Map<Character, Integer> generateMap(String input) {
        Map<Character, Integer> ans = new HashMap<>();
        for (char c : input.toCharArray()) {
            ans.put(c, ans.getOrDefault(c, 0) + 1);
        }
        return ans;
    }

}

public class Playground {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string: ");
        String input = sc.nextLine();

        Practice p = new Practice();
        Map<Character, Integer> mp = p.generateMap(input);
        System.out.println("Input map:\n" + mp);

        Map<Character, String> output = new HashMap<>();
        p.traverse(p.constructHTree(mp), output, "");
        System.out.println("\nOutput: \n" + output);

        // Sample input: azdjkqwejaadjjqkzzxqaa
        // Sample output: {a=01, q=110, d=1111, e=11100, w=11101, x=1000, j=00, z=101, k=1001}
    }
}

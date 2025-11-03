// Java program for the above approach:
import java.util.*;

// Class to represent huffman tree 
class HNode {
    int data;
    char c;
    HNode left, right;
    HNode(char c, int x) {
        this.c = c;
        data = x;
        left = null;
        right = null;
    }
}

class Huffman {

    // Function to traverse tree in preorder
    // manner and push the huffman representation
    // of each character.
    void preOrder(HNode root, ArrayList<String> ans, String curr) {
        if (root == null) return;

        // Leaf node represents a character.
        if (root.left == null && root.right == null) {
            ans.add(root.c + ": " + curr);
            return;
        }

        preOrder(root.left, ans, curr + '0');
        preOrder(root.right, ans, curr + '1');
    }

    ArrayList<String> huffmanCodes(String s, int[] freq) {

        int n = s.length();

        // Min heap for node class.
        PriorityQueue<HNode> pq = new PriorityQueue<>((a, b) -> {
            if (a.data < b.data) return -1;
            else if (a.data == b.data) return 0;
            return 1;
        });
        for (int i = 0; i < n; i++) {
            HNode tmp = new HNode(s.charAt(i), freq[i]);
            pq.add(tmp);
        }

        // Construct huffman tree.
        while (pq.size() >= 2) {

            // Left node
            HNode l = pq.poll();

            // Right node
            HNode r = pq.poll();

            HNode newNode = new HNode(' ',l.data + r.data);
            newNode.left = l;
            newNode.right = r;

            pq.add(newNode);
        }

        HNode root = pq.poll();
        ArrayList<String> ans = new ArrayList<>();
        preOrder(root, ans, "");
        return ans;
    }



}

public class A2 {
    public static void main(String[] args) {
        String s = "abcdef";
        int[] freq = {2, 2, 3, 6, 7, 9};

        Huffman hf = new Huffman();
        ArrayList<String> ans = hf.huffmanCodes(s, freq);
        for (int i = 0; i < ans.size(); i++) {
            System.out.println(ans.get(i));
        }
    }
}
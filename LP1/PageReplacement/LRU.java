package PageReplacement;

import java.util.LinkedList;
import java.util.Scanner;

public class LRU {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of pages");
        int n = sc.nextInt();
        System.out.println("Enter the size of the frame");
        int nf = sc.nextInt();
        int[] pagerefrencestring = new int[n];
        System.out.println("Enter the page refrence string");
        for(int i=0;i<n;i++){
            pagerefrencestring[i] = sc.nextInt();
        }
        // int[] frames = new int[nf];
        LinkedList<Integer> memory = new LinkedList<>();

        int pf=0;
        int ph=0;

        for(int page : pagerefrencestring){
            if(!memory.contains(page)){
                if(memory.size() >=  nf){
                    memory.removeFirst();
                }
                memory.addLast(page);
                pf++;
            }
            else{
                memory.remove(memory.indexOf(page));
                memory.addLast(page);
                ph++;
            }

            System.out.print("frame : ");
            for(int f : memory){
                System.out.print(f+" ");
            }
            System.out.println();
        }

        System.out.println("no of page faults "+pf);
        System.out.println("no of page htis "+ph);
        sc.close();


        // Sample input: 14 4 7 0 1 2 0 3 0 4 2 3 0 3 2 3
    }
}

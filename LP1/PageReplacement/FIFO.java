package PageReplacement;

import java.util.Arrays;
import java.util.Scanner;

public class FIFO {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of pages");
        int n = sc.nextInt();
        System.out.println("Enter the page refrence string");
        int[] pagerefrencestring = new int[n];
        for(int i=0;i<n;i++){
            pagerefrencestring[i] = sc.nextInt();
        }
        System.out.println("Enter the size of frames");
        int noframes = sc.nextInt();
        int[] frames = new int[noframes];
        Arrays.fill(frames, -1);
        int pf=0;
        int ph=0;
        int currentidx=0;

        for(int page : pagerefrencestring){
            boolean pagehit = false;
            for(int fr : frames){
                if(page == fr){
                    pagehit=true;
                    ph++;
                }
            }
            if(!pagehit){
                pf++;
                frames[currentidx] = page;
                currentidx = (currentidx+1)%noframes;
            }

            System.out.print("frames : ");
            for(int fram : frames){
                System.out.print(fram+" ");
            }
            System.out.println();

            // Sample input: 7 1 3 0 3 5 6 3 3
        }

        System.out.println("page faults "+pf);
        System.out.println("page hits "+ph);
        sc.close();
    }    
}

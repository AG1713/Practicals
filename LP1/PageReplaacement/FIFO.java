package PageReplaacement;

import java.util.Scanner;

class FirstInFirstOut {
    private int[] arr;
    private int pageSize;
    private int currentIndex;
    private int pageFaults;

    FirstInFirstOut(int pageSize){
        if (pageSize > 0) this.pageSize = pageSize;
        currentIndex = 0;
        pageFaults = 0;
        arr = new int[pageSize];
        for (int i=0 ; i<pageSize ; i++){
            arr[i] = -1; // Default value
        }
    }

    public void display(){
        System.out.print("[");
        for (int i=0 ; i<pageSize ; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("]");
    }

    private boolean hitOrMiss(int x){

        for (int i=0 ; i<pageSize ; i++){
            if (x == arr[i]) return true;
        }
        return false;
    }
    public void replace(int x){

        if (!hitOrMiss(x)){
            // Miss
            arr[currentIndex] = x;
            currentIndex = (currentIndex+1)%pageSize;
            pageFaults++;
        }
        // If hit, do nothing
    }

    public int getPageFaults() {
        return pageFaults;
    }
}

public class FIFO {

    public static void main(String[] args) {
        // 1 3 0 3 5 6 3

        FirstInFirstOut obj = new FirstInFirstOut(3);
        int n = 0;
        int pageSize = 0;
        int[] pageReferenceArray;

        // Get input pages
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the no. of page references : ");
        n = sc.nextInt();
        pageReferenceArray = new int[n];

        System.out.println("Enter the page reference one by one");
        for (int i=0 ; i<n ; i++){
            int val;
            System.out.print("Page Reference " + (i+1) + " : ");
            val = sc.nextInt();
            pageReferenceArray[i] = val;
        }

        System.out.print("Enter the page size : ");
        pageSize = sc.nextInt();
        int[] input = new int[pageSize];


        for (int i=0 ; i<n ; i++){
            obj.replace(pageReferenceArray[i]);
            obj.display();
        }

        System.out.println("Page Faults : " + obj.getPageFaults());

        System.out.println("End of the program");

    }




}

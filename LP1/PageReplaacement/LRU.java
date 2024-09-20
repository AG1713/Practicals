package PageReplaacement;

class LeastRecentlyUsed {
    private int pageSize;

    // TODO - Replace array with arraylist
    private int[] arr;
    private int[] usedAt;
    private int pageFaults;


    LeastRecentlyUsed(int pageSize){
        this.pageSize = pageSize;
        arr = new int[pageSize];
        usedAt = new int[pageSize];
        pageFaults = 0;

        for (int i=0 ; i<pageSize ; i++){
            arr[i] = -1;
            usedAt[i] = Integer.MIN_VALUE;
        }

    }


    private int getMinIndex(){
        int min = 0;

        for (int i=0 ; i<pageSize ; i++){
            if (arr[min] > arr[i]){
                min = i;
            }
        }

        return min;
    }

    public void display(){
        System.out.print("[");
        for (int i=0 ; i<pageSize ; i++){
            System.out.print(arr[i] + " ");
        }
        System.out.println("]");
    }

    private int hitOrMiss(int x){

        for (int i=0 ; i<pageSize ; i++){
            if (x == arr[i]) return i;
        }
        return -1;
    }

    public void replace(int x, int currentIndex){
        int index = hitOrMiss(x);

        if (index == -1){
            // MISS


        }
        else {
            // HIT
            usedAt[index] = currentIndex;

        }

    }



}
public class LRU {
}

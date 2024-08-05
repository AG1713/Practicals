import java.util.*;


class Solution{
    Scanner sc1 = new Scanner(System.in);

    private int num_processes;
    private String processes[];
    private int arrival_times[];
    private int burst_times[];
    private int completion_times[];
    private int TAT[];
    private int waiting_times[];

    private float avg_TAT;
    private float avg_waiting_time;



    Solution(int num_processes){
        this.num_processes = num_processes;

        processes = new String[num_processes];
        arrival_times = new int[num_processes];
        burst_times = new int[num_processes];
        completion_times = new int[num_processes];
        TAT = new int[num_processes];
        waiting_times = new int[num_processes];
        avg_TAT = 0;
        avg_waiting_time = 0;
    }

    private void sortBasedOnArrival(){
        // insertion sort
        for (int i=1 ; i<num_processes ; i++){
            int arrival_time = arrival_times[i];

            String process = processes[i];
            int burst_time = burst_times[i];
            // The above are all keys

            int j = i-1;

            while (j >= 0 && arrival_times[j] > arrival_time) {
                arrival_times[j+1] = arrival_times[j];

                processes[j+1] = processes[j];
                burst_times[j+1] = burst_times[j];
                j--;
            }
            arrival_times[j+1] = arrival_time;
            processes[j+1] = process;
            burst_times[j+1] = burst_time;
        }
    }

    public void takeInputs(){

        for (int i=0 ; i<num_processes ; i++){
            processes[i] = "P" + String.valueOf(i+1);

            System.out.print("Enter arrival time of process " + (i+1) + " : ");
            arrival_times[i] = sc1.nextInt();

            System.out.print("Enter burst time of process " + (i+1) + " : ");
            burst_times[i] = sc1.nextInt();
        }

    }

    public void calculateTimesFCFS(){

        sortBasedOnArrival();

        for (int i=0 ; i<num_processes ; i++){
            if (i == 0) {
                completion_times[i] = arrival_times[i] + burst_times[i];
            }
            else {
                completion_times[i] = completion_times[i-1] + burst_times[i];

            }
            TAT[i] = completion_times[i] - arrival_times[i];
            waiting_times[i] = TAT[i] - burst_times[i];

            avg_TAT += TAT[i];
            avg_waiting_time += waiting_times[i];

        }

        avg_TAT = avg_TAT/num_processes;
        avg_waiting_time = avg_waiting_time/num_processes;

    }

    public void calculateTimesSJF(){
        sortBasedOnArrival();

        // Linearly increase time by 1 unit
        int time = 0;
        int remaining_processes = num_processes;
        int[] remaining_times = new int[num_processes];
        for (int i=0 ; i<num_processes ; i++){
            // Copying burst times to remaining times
            remaining_times[i] = burst_times[i];
        }

        int current_job = 0; // Holds the job with the minimum remaining time
        while (remaining_processes != 0 ){

            for (int i=0 ; i<num_processes && arrival_times[i] <= time ; i++){
                if (remaining_times[i] < remaining_times[current_job]){
                    current_job = i;
                }
            }

            remaining_times[current_job]--;
            if (remaining_times[current_job] == 0){
                remaining_processes--;
                remaining_times[current_job] = Integer.MAX_VALUE;

                // Updating values of remaining times
                completion_times[current_job] = time+1;
                TAT[current_job] = completion_times[current_job] - arrival_times[current_job];
                waiting_times[current_job] = TAT[current_job] - burst_times[current_job];
                avg_TAT += TAT[current_job];
                avg_waiting_time += waiting_times[current_job];

            }

            // Increase time for every iteration
            time++;
        }

        avg_TAT = avg_TAT/num_processes;
        avg_waiting_time = avg_waiting_time/num_processes;

    }




    public void displayTable(){
        System.out.println("\n\nProcess\t\tArrival Time\t\tBurst time\t\tCompletion time\t\tTurn around time\t\tWaiting time");
        System.out.println("--------------------------------------------------------------------------------------");

        for (int i=0 ; i<num_processes ; i++){
            System.out.println(processes[i] + "\t\t\t" + arrival_times[i] + "ms\t\t\t\t" +
                    burst_times[i] + "ms\t\t\t" + completion_times[i] + "ms\t\t\t" + TAT[i] + "ms\t\t\t" + waiting_times[i]);

        }

        System.out.println("Average turn around time : " + avg_TAT + "ms");
        System.out.println("Average waiting time : " + avg_waiting_time + "ms");

    }


}


public class JobScheduling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num_processes;
        int choice = 0;


        System.out.println("Enter option :\n1) FCFS\n2) SJF");
        choice = sc.nextInt();

        Solution solution;



        switch (choice) {
            case 1:
                num_processes = 0;

                System.out.print("Enter the number of processes : ");
                num_processes = sc.nextInt();
                solution = new Solution(num_processes);

                solution.takeInputs();
                solution.calculateTimesFCFS();
                solution.displayTable();

                break;

            case 2:
                num_processes = 0;

                System.out.print("Enter the number of processes : ");
                num_processes = sc.nextInt();
                solution = new Solution(num_processes);


                solution.takeInputs();
                solution.calculateTimesSJF();
                solution.displayTable();

                break;

            default:
                System.out.println("Invalid Choice");
                break;
        }



        sc.close();


        // Sample inputs
        // FCFS - 5 0 4 1 3 2 1 3 2 4 5
        // Average waiting time - 3.8

        // SJF - 4 0 6 1 4 2 2 3 3
        // Average waiting time - 3.75


    }

}
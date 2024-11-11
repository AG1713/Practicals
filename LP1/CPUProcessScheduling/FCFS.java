package CPUProcessScheduling;
import java.util.*;

class FirstComeFirstServe{
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

    FirstComeFirstServe(int num_processes){
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

// ****************************************************************************************************
public class FCFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num_processes;

        FirstComeFirstServe solution;
        num_processes = 0;

        System.out.print("Enter the number of processes : ");
        num_processes = sc.nextInt();
        solution = new FirstComeFirstServe(num_processes);

        solution.takeInputs();
        solution.calculateTimesFCFS();
        solution.displayTable();
        // Sample inputs
        // FCFS - 5 0 4 1 3 2 1 3 2 4 5
        // Average waiting time - 3.8

        // Output:
        /*
        Process		Arrival Time		Burst time		Completion time		Turn around time		Waiting time
        --------------------------------------------------------------------------------------
        P1			0ms				4ms			4ms			4ms			0
        P2			1ms				3ms			7ms			6ms			3
        P3			2ms				1ms			8ms			6ms			5
        P4			3ms				2ms			10ms			7ms			5
        P5			4ms				5ms			15ms			11ms			6
        Average turn around time : 6.8ms
        Average waiting time : 3.8ms
        */

        sc.close();
    }

}
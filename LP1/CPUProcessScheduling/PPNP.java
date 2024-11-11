package CPUProcessScheduling;

import java.util.Scanner;

class Process1 {
    int pid, arrival, burst, turnaround, waiting, priority, completionTime;

    public Process1(int pid, int arrival, int burst, int priority) {
        this.pid = pid;
        this.arrival = arrival;
        this.burst = burst;
        this.priority = priority;
    }
}

public class PPNP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of processes:");
        int n = sc.nextInt();
        Process1[] processes = new Process1[n];

        System.out.println("Enter the arrival time, burst time, and priority for each process:");
        for (int i = 0; i < n; i++) {
            int at = sc.nextInt();
            int bt = sc.nextInt();
            int pt = sc.nextInt();
            processes[i] = new Process1(i + 1, at, bt, pt);
        }

        // Sort processes based on priority (Highest priority first)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (processes[j].priority < processes[j + 1].priority) {
                    Process1 temp = processes[j];
                    processes[j] = processes[j + 1];
                    processes[j + 1] = temp;
                }
            }
        }

        // Calculate completion time, turnaround time, and waiting time
        int currentTime = 0; // Tracks the time
        int completed = 0;
        StringBuilder ganttChart = new StringBuilder();

        while (completed < n) {
            boolean found = false;
            for (int i = 0; i < n; i++) {
                // Process can execute if its arrival time is <= currentTime and it hasn't finished
                if (processes[i].arrival <= currentTime && processes[i].completionTime != 0) {
                    found = true;
                    processes[i].completionTime = currentTime + processes[i].burst;
                    currentTime = processes[i].completionTime;

                    // Calculate turnaround and waiting times
                    processes[i].turnaround = processes[i].completionTime - processes[i].arrival;
                    processes[i].waiting = processes[i].turnaround - processes[i].burst;
                    ganttChart.append("P" + processes[i].pid + " ");

                    completed++;
                    break;
                }
            }

            // If no process is found to execute (idle time)
            if (!found) {
                currentTime++;
//                ganttChart.append("idle ");
            }
        }

        // Output the Gantt Chart
        System.out.println("Gantt Chart: " + ganttChart);

        // Calculate and display the average waiting time and turnaround time
        int totalWaitingTime = 0, totalTurnaroundTime = 0;
        for (Process1 p : processes) {
            totalWaitingTime += p.waiting;
            totalTurnaroundTime += p.turnaround;
        }

        double avgWaitingTime = (double) totalWaitingTime / n;
        double avgTurnaroundTime = (double) totalTurnaroundTime / n;

        System.out.println("Average Waiting Time: " + avgWaitingTime);
        System.out.println("Average Turnaround Time: " + avgTurnaroundTime);

        // Display process details
        System.out.println("Process\tArrival\tBurst\tPriority\tTurnaround\tWaiting");
        for (Process1 p : processes) {
            System.out.println("P" + p.pid + "\t" + p.arrival + "\t" + p.burst + "\t" + p.priority + "\t" +
                    p.turnaround + "\t" + p.waiting);
        }

        sc.close();


        // Sample input:
        /*
        5
        0 11 2 5 28 0 12 2 3 2 10 1 9 16 4

        */
    }
}

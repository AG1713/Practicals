package CPUProcessScheduling;

import java.util.Scanner;

class Process {
    int pid, arrival, burst, turnaround, waiting, Priority, remaining;

    // Correct constructor
    public Process(int pid, int arrival, int burst, int pt) {
        this.pid = pid;
        this.arrival = arrival;
        this.burst = burst;
        this.Priority = pt;
        this.remaining = burst;
    }
}

public class PP {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no of processes");
        int n= sc.nextInt();
        System.out.println("Enter the arrival burst and priorty");
        Process[] processes = new Process[n];
        for(int i=0;i<n;i++){
            int at = sc.nextInt();
            int bt = sc.nextInt();
            int pt = sc.nextInt();
            processes[i] = new Process((i+1), at, bt, pt);
        }        

        int completionTime=0;
        int completed=0;
        StringBuilder gantchart = new StringBuilder();

        while (completed < n) {
            int highestpriority = Integer.MIN_VALUE;
            int idx = -1;

            for(int i=0;i<n;i++){
                if(processes[i].arrival <= completionTime && processes[i].remaining > 0 && processes[i].Priority > highestpriority){
                    highestpriority = processes[i].Priority;
                    idx = i;
                }
            }

            if(idx != -1){
                processes[idx].remaining--;
                completionTime++;
                gantchart.append("p").append(processes[idx].pid).append(" ");
                if(processes[idx].remaining ==0){
                    processes[idx].turnaround = completionTime - processes[idx].arrival;
                    processes[idx].waiting = processes[idx].turnaround - processes[idx].burst; 
                    completed++; 
                }
            }else{
                gantchart.append("idle ");
                completionTime++;
            }
        }

        System.out.println("gantchart"+gantchart);
        int twt=0,ttat=0;
        for(int i=0;i<n;i++){
            twt += processes[i].waiting;
            ttat += processes[i].turnaround;
        }

        twt /= n;
        ttat /= n;

        System.out.println("avg waiting time"+twt);
        System.out.println("avg turnaround time"+ttat);

        System.out.println("processes"+"\t"+"arrival"+"\t"+"burst"+"\t"+"turnaround"+"\t"+"waiting");
        for(int i=0;i<n;i++){
            System.out.print("p"+(i+1)+"\t"+processes[i].arrival+"\t"+processes[i].burst+"\t"+processes[i].turnaround+"\t"+processes[i].waiting+"\n");
        }
        System.out.println("gantchart"+gantchart);

        sc.close();
    }
}

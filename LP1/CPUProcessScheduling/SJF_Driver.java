package CPUProcessScheduling;


import java.util.ArrayList;
import java.util.Scanner;

class SJF {
    ArrayList<CPU_Process> processes;
    int size = 0;
    Scanner sc;

    public SJF(){
        sc = new Scanner(System.in);

        System.out.print("Enter the number of processes : ");
        this.size = sc.nextInt();
        processes = new ArrayList<>();

        for (int i=0 ; i<size ; i++){
            String name = "P"+(i+1);
            int arrivalTime;
            int burstTime;

            System.out.print("Enter arrival time for process " + name + ": ");
            arrivalTime = sc.nextInt();
            System.out.print("Enter burst time for process " + name + ": ");
            burstTime = sc.nextInt();

            processes.add(new CPU_Process(name, arrivalTime, burstTime));
        }

        sc.close();
        sortBasedOnArrival();
    }

    private void sortBasedOnArrival(){
        // insertion sort
        for (int i=1 ; i<size ; i++){
            CPU_Process temp = processes.get(i);
            int j = i-1;

            while (j >= 0 && processes.get(j).arrivalTime > temp.arrivalTime) {
                processes.set(j+1, processes.get(j));
                j--;
            }
            processes.set(j+1, temp);

        }

//        for (int i=0 ; i<size ; i++){
//            System.out.println(processes.get(i).arrivalTime);
//        }
    }

    public void generateTimes(int unit){

        int time = 0;
        int remainingProcesses = this.size;
        int currentProcessIndex = -1;

        while (remainingProcesses > 0){

            // Check whether new process arrives, if no current process running
            if (currentProcessIndex == -1) {
                int minBurstTime = Integer.MAX_VALUE;
                for (int i = 0; i < size; i++) {
                    CPU_Process process = processes.get(i);

                    // Check if the process has arrived and is not completed
                    if (process.arrivalTime <= time && process.remainingTime > 0) {
                        // Select the process with the smallest burst time
                        if (process.burstTime < minBurstTime) {
                            minBurstTime = process.burstTime;
                            currentProcessIndex = i;
                        }
                    }
                }
            }

            time = time+unit;

            if (currentProcessIndex != -1){
                CPU_Process currentProcess = processes.get(currentProcessIndex);

                if (currentProcess.startTime == -1) currentProcess.startTime = time-unit;

                currentProcess.remainingTime = currentProcess.remainingTime - unit;

                if (currentProcess.remainingTime == 0){
                    currentProcess.completionTime = time;
                    currentProcess.turnAroundTime = currentProcess.completionTime - currentProcess.arrivalTime;
                    currentProcess.waitingTime = currentProcess.turnAroundTime - currentProcess.burstTime;
                    currentProcessIndex = -1;
                    remainingProcesses--;
                }
            }

        }

    }

    public void displayTable(){
        String spacing = "\t\t";
        String spacing2 = "\t\t\t\t";
        float avg_waiting = 0;
        float avg_TAT = 0;

        System.out.println("No." + spacing +
                "Name" + spacing +
                "Arrival Time" + spacing +
                "Burst time" + spacing +
                "Waiting time" + spacing +
                "Start time" + spacing +
                "Completion time" + spacing +
                "Turn Around Time");

        for (int i=0 ; i<size ; i++){
            System.out.println((i+1) + spacing2 +
                    processes.get(i).name + spacing2 +
                    processes.get(i).arrivalTime + spacing2 +
                    processes.get(i).burstTime + spacing2 +
                    processes.get(i).waitingTime + spacing2 +
                    processes.get(i).startTime + spacing2 +
                    processes.get(i).completionTime + spacing2 +
                    processes.get(i).turnAroundTime);
            avg_waiting += processes.get(i).waitingTime;
            avg_TAT += processes.get(i).turnAroundTime;
        }
        avg_waiting = avg_waiting/size;
        avg_TAT = avg_TAT/size;

        System.out.println("\nAverage waiting time: " + avg_waiting);
        System.out.println("Average turn around time: " + avg_TAT);


    }


}
public class SJF_Driver {
    public static void main(String[] args) {
        SJF obj = new SJF();
        obj.generateTimes(1);
        obj.displayTable();


        // Sample input: 5 2 6 5 2 1 8 0 3 4 4
        /*
        Sample output:
        No.		Name		Arrival Time		Burst time		Waiting time		Start time		Completion time		Turn Around Time
        1				P4				0				3				0				0				3				3
        2				P3				1				8				14				15				23				22
        3				P1				2				6				1				3				9				7
        4				P5				4				4				7				11				15				11
        5				P2				5				2				4				9				11				6

        Average waiting time: 5.2
        Average turn around time: 9.8
        */
    }


}

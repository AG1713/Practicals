package CPUProcessScheduling;


import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

class RoundRobin{
    ArrayList<CPU_Process> processes;
    int size = 0;
    Scanner sc;

    public RoundRobin(){
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

    }


    public void generateTables(int unit){
        ArrayList<CPU_Process> currentProcesses = new ArrayList<>();
        int time = 0;
        int remainingProcesses = this.size;
        String gant = "";

        while (remainingProcesses > 0){
            for (CPU_Process newProcess : processes){
                if ((newProcess.arrivalTime <= time) && (newProcess.remainingTime > 0) && (!currentProcesses.contains(newProcess)))
                    currentProcesses.add(newProcess);
            }

            if (currentProcesses.isEmpty()) {
                time += unit;
                continue;
            }

            CPU_Process process = currentProcesses.get(0);
            currentProcesses.remove(0);
            gant += process.name + " ";

            if (process.startTime == -1) process.startTime = time;

            int execution_time = Integer.min(process.remainingTime, unit);
            process.remainingTime -= execution_time;
            time += execution_time;
            gant += time + " ";

            for (CPU_Process newProcess : processes){
                if ((newProcess.arrivalTime <= time) && (newProcess.remainingTime > 0) && (!currentProcesses.contains(newProcess)))
                    currentProcesses.add(newProcess);
            }

            if (process.remainingTime > 0){
                currentProcesses.add(process);
            }
            else {
                process.completionTime = time;
                process.turnAroundTime = process.completionTime - process.arrivalTime;
                process.waitingTime = process.turnAroundTime - process.burstTime;
                remainingProcesses--;
            }


        }

        System.out.println("\n\nGant: " + gant);
    }


    public void displayTable(){
        String spacing = "\t\t";
        String spacing2 = "\t\t\t\t";
        float avg_waiting = 0;
        float avg_TAT = 0;

        System.out.println("\n\nNo." + spacing +
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
public class RoundRobin_Driver {
    public static void main(String[] args) {
        RoundRobin obj = new RoundRobin();
        obj.generateTables(2);
        obj.displayTable();

        // Sample input: 4 0 5 1 4 2 2 4 1
        // Sample input 2: 6 0 5 1 6 2 3 3 1 4 5 6 4

    }
}

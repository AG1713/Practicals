package CPUProcessScheduling;

public class CPU_Process {
    public String name;
    public int arrivalTime;
    public int burstTime;
    public int startTime;
    public int remainingTime;
    public int completionTime;
    public int waitingTime;
    public int turnAroundTime;

    public CPU_Process(String name, int arrivalTime, int burstTime) {
        this.name = name;
        this.arrivalTime = arrivalTime;
        this.burstTime = burstTime;
        this.remainingTime = burstTime;
        this.startTime = -1;

    }
}

'''
IV. Job Scheduling Problem 
'''
# Assumptions - All processes have same burst time

# Process - (name, arrival time, priority)
# More priority for bigger numbers
processes = [
    ('P1', 0, 2),
    ('P2', 1, 4),
    ('P3', 1, 1),
    ('P4', 2, 5),
    ('P5', 2, 6)
]

# Priority based Job Scheduling
def job_scheduling(jobs):
    n = len(jobs)

    time = 0
    current_jobs = []
    order = [] # Ans

    def add_to_current_jobs():
        for job in jobs:
            if (job[1] == time): # If current time == arrival time
                current_jobs.append(job)
    
    def choose_job():
        choice = None
        for job in current_jobs:
            if (choice == None or job[2] > choice[2]): # Choosing the job with highest priority
                choice = job
    
        if (choice): current_jobs.remove(choice)
        return choice

    while (len(order) < n):
        add_to_current_jobs()
        cur = choose_job()
        if (cur): order.append(cur[0])
        time = time+1
    
    return order

print(job_scheduling(processes))

processes=[]
arrival_time={}
burst_time={}
counter=0

with open('processes.txt','r') as file:
    for line in file:
        data=line.split()
        processes.insert(counter,data[0])
        arrival_time[data[0]]=int(data[1])
        burst_time[data[0]]=int(data[2])
        counter=counter+1

file.close();

start_time=0
total_time=0
running=[]
avg_turnaround_time=0
avg_waiting_time=0

while processes!=[]:
    for time in arrival_time:
        if arrival_time[time]==total_time:
            running.insert(0,time)

    total_time=total_time+1
    re_burst_time = burst_time[running[len(running)-1]] - 1
    burst_time[running[len(running)-1]] = re_burst_time

    if burst_time[running[len(running)-1]] == 0:
        avg_turnaround_time = avg_turnaround_time + (total_time - burst_time[running[len(running)-1]])
        avg_waiting_time = avg_waiting_time + (start_time - arrival_time[running[len(running)-1]])
        print (str(start_time) + " to " + str(total_time) + " : " + running[len(running)-1])
        del burst_time[running[len(running)-1]]
        processes.pop()
        running.pop()
        start_time = total_time

print ("\naverage turnaround time = " + str(avg_turnaround_time/len(arrival_time.keys())))
print ("average waiting time = " + str(avg_waiting_time/len(arrival_time.keys())))

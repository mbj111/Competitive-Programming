import numpy as np

day = [[] for i in range(7)]

count = [ 0 for i in range(7)]
i = 0 #0 stand for monday
nn = raw_input()
for num in range(int(nn)):
    n = raw_input()
    day[i%7].append(int(n))
    i += 1
avg = []
for j in range(7):
    avg.append(np.mean(day[j]))

for j in range(30):
    print int(avg[i%7])
    i += 1

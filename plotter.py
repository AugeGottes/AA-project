import matplotlib.pyplot as plt
import pandas as pd
# headers=['graham_scan','jarvis_march']
x=[]
y=[]
with open('log.csv') as f:
    lines = f.readlines()
for i in lines:
    temp=i.split(sep=",")
    x.append(float(temp[0]))
    y.append(float(temp[1][:-1]))
    
plt.plot(x,y)
plt.show()
x=[]
while(True):
   a=input()
   if(a!='q'):
      x.append(int(a))
   else:
      break
y=list(filter(lambda a:a<=0 or a>120,x))
if(len(y)>0 or len(x)>20):
   print("INVALID INPUT")
else:
   sum=0
   for i in range of(len(x)):
       if(x[i]<17):
          sum+=200
       elif(x[i]>=17 and x[i]<=40):
          sum+=400
       else:
          sum+=300
   print("Total Income {} INR".format(sum)
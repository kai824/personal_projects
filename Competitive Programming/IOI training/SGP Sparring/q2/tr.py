f=open('py_in.txt','r')

f2=open('out2.txt','w')
mod=(1000000007)
for line in f:
    ans=eval(line)%mod
    if ans<0:ans+=mod
    f2.write(str(ans)+'\n')
f2.close()

f.close()

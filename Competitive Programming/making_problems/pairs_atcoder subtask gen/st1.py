import os,shutil,random

def create(outfile):
    f=open(outfile,'w')
    n=random.randint(900,1000)
    k=random.randint(1,n*(n-1)/2)

    f.write(f'{n} {k}\n')
    for i in range(n):
        a=random.randint(-1000000000,1000000000)
        if i>0:
            f.write(' ')
        f.write(str(a))
    f.write('\n')
    f.close()

for i in range(80,100):
    create(f'st1/{i}.in')

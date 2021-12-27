import os,shutil,random

files=os.listdir('st2')
if '.DS_Store' in files: files.remove('.DS_Store')

files.sort()

for i,file in enumerate(files,100):
    f=open(f'st2/{file}','r')
    k=f.read()
    k=k.replace('-','')
    os.remove(f'st2/{file}')
    f.close()
    f=open(f'st2/{i}.in','w')
    f.write(k)
    f.close()

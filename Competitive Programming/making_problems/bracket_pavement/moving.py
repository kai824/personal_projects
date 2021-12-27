import os
import shutil

cnt=1

def func(string):
    second=''
    while string[-1].isdigit()==False:
        second=string[-1]+second
        string=string[:-1]
    return (int(string),second)

for folder in ['st1','st2','st3']:
    files=os.listdir(folder)
    files.sort(key=func)
    if '.DS_Store' in files:
        files.remove('.DS_Store')

    for i in range(0,len(files),2):#+2 instead of 1
        shutil.copy(f'{folder}/{files[i]}',f'to_upload/{cnt}.in')#in
        print(f'{folder}/{files[i]}',f'to_upload/{cnt}.in')
        shutil.copy(f'{folder}/{files[i+1]}',f'to_upload/{cnt}.out')#out
        print(f'{folder}/{files[i+1]}',f'to_upload/{cnt}.out')
        cnt+=1

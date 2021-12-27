import os,shutil

os.system('g++ sol.cpp -std=c++11')

for i in range(80,100):
    os.system(f'./a.out st1/{i}.in outputs/{i}.out')

for i in range(100,179):
    os.system(f'./a.out st2/{i}.in outputs/{i}.out')

import subprocess

print("Quick - 10")
subprocess.run(["time ./volsort -m quick -n < in_10.txt > out.txt"], shell=True)
print("Quick - 100")
subprocess.run(["time ./volsort -m quick -n < in_100.txt"], shell=True)
print("Quick - 1grand")
subprocess.run(["time ./volsort -m quick -n < in_1grand.txt"], shell=True)
print("Quick - 10grand")
subprocess.run(["time ./volsort -m quick -n < in_10grand.txt"], shell=True)
print("Quick - 100grand")
subprocess.run(["time ./volsort -m quick -n < in_100grand.txt"], shell=True)
print("Quick - 1mil")
subprocess.run(["time ./volsort -m quick -n < in_1mil.txt"], shell=True)
print("Quick - 10mil")
subprocess.run(["time ./volsort -m quick -n < in_10mil.txt"], shell=True)



# !time ./volsort -m merge -n < in_1mil.txt
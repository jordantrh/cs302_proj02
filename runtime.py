import subprocess
import sys

# STL
subprocess.run(["time ./volsort -m stl -n < in_10.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_100.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_1grand.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_10grand.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_100grand.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_1mil.txt"], shell=True)
subprocess.run(["time ./volsort -m stl -n < in_10mil.txt"], shell=True)

# QSORT
subprocess.run(["time ./volsort -m qsort -n < in_10.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_100.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_1grand.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_10grand.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_100grand.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_1mil.txt"], shell=True)
subprocess.run(["time ./volsort -m qsort -n < in_10mil.txt"], shell=True)

# MERGE
subprocess.run(["time ./volsort -m merge -n < in_10.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_100.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_1grand.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_10grand.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_100grand.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_1mil.txt"], shell=True)
subprocess.run(["time ./volsort -m merge -n < in_10mil.txt"], shell=True)

# QUICK
subprocess.run(["time ./volsort -m quick -n < in_10.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_100.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_1grand.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_10grand.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_100grand.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_1mil.txt"], shell=True)
subprocess.run(["time ./volsort -m quick -n < in_10mil.txt"], shell=True)
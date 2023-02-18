# cs302_proj02
```
| Mode   | Size | Elapsed Time  |
| STL    | 1E1  | 0m0.001s      |
| STL    | 1E2  |	0m0.001s      |
| STL    | 1E3  |	0m0.004s      |
| STL    | 1E4  |	0m0.022s      |
| STL    | 1E5  |	0m0.360s      |
| STL    | 1E6  |	0m4.469s      |
| STL    | 1E7  |	0m41.640s     |
| Qsort  | 1E1  |	0m0.001s      |
| Qsort  | 1E2  |	0m0.002s      |
| Qsort  | 1E3  |	0m0.003s      |
| Qsort  | 1E4  |	0m0.020s      |
| Qsort  | 1E5  |	0m0.270s      |
| Qsort  | 1E6  |	0m3.494s      |
| Qsort  | 1E7  |	0m33.843s     |
| Merge  | 1E1  |	0m0.001s      |
| Merge  | 1E2  |	0m0.001s      |
| Merge  | 1E3  |	0m0.003s      |
| Merge  | 1E4  |	0m0.023s      |
| Merge  | 1E5  |	0m0.294s      |
| Merge  | 1E6  |	0m3.387s      |
| Merge  | 1E7  |	0m38.046s     |
| Quick  | 1E1  |	0m0.001s      |
| Quick  | 1E2  |	0m0.001s      |
| Quick  | 1E3  |	0m0.003s      |
| Quick  | 1E4  |	0m0.020s      |
| Quick  | 1E5  |	0m0.320s      |
| Quick  | 1E6  |	0m4.588s      |
| Quick  | 1E7  |	2m21.858s     |
```

1) The sorting algorithms from fastest to slowest are qsort, mergesort, stl, and quicksort. QSort and STL programming-wise require having to place the linked list into a container and uses a function from a library, meanwhile Quicksort and Mergesort are much more involved and do not reqiure a vector to do. 
2) Theoretical time complexity does not actually have a correction on how long the code actually takes the time to run, as time complexity only focuses on the duration of the algorithm than the actual code itself.
3) In our opinion mergesort is the best as it doesn;t require having to place nodes in a container and is supposed to be faster according to theoretical time complexity, however, it is not the fastest compared to other sorting methods in terms of the time it takes for the code to actually run.
4) Matthew worked on the implementation of the quick sort algorithm. Matthew developed the Algorithm and Jordan made a
few changes to get to fully work. Joran and Austin worked on List.cpp and volsort.h together. Jordan completed merge sort and Austin 
completed stl and qsort. Jordan made the python script and c++ file to generate numbers. and Matthew made the c++ code to read the 
file and create a table using the data from the python script. We worked toegther on the questions.

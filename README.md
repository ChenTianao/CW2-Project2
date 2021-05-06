# Readme.md
## About test code:
>1.Comment out line 20 of the main function, as shown in the figure below.
```c
//scanf("%ld%ld",&startnode_id,&endnode_id);  //C
```
>2.Remove the double slash from lines 14,15,16,21,42,45,47 of the main function,, as shown in the figure below.
```c
test_code3();
test_code4();
test_code5();
test_code1();
test_code2();
test_code6();
test_code7();   //C
```
## About how to run the programme:
>Enter the id of the starting id and the ending id.
>If the id is out the range of the data set, error message would be printed.
## About Gnuplot:
The code for data visualization using Gnuplot is as follows：
```gnuplot
plot "F:\all.txt" using 1:2 with linespoints linecolor 3 linewidth 1 pointtype 16 pointsize 0.9,"F:\short.txt" using 1:2 with linespoints linecolor 7 linewidth 1 pointtype 16 pointsize 0.9
```
## Explanation:
1.The "F:\all.txt"  is the absolute path to the file that stores all the point information.
2.The "F:\short.txt" is the absolute path of a file that stores information about the shortest path between two points.
If you would to visualize the data, copy the second line of code to GNUPLOT's command line.

# Ahnaf Raihan
# Dijkstra

C++ program to run Dijkstra’s shortest path algorithm on an adjacency matrix.

compile:
$ make

run:
$ ./Dijkstra <input_file.txt> <source_node>
  
    - <input_file.txt> = text file containing size of matrix and then matrix thereafter
    - <source_node> = integer designating source node for algorithm
    
clean:
$ make clean

input_file sample: inputA.txt

6
0 2 5 1 0 0
2 0 3 2 0 0
5 3 0 3 1 5
1 2 3 0 1 0
0 0 1 1 0 2
0 0 5 0 2 0

output sample:

./Dijkstra inputA.txt 0
Step	      N'	    D(0),p(0)   D(1),p(1)	    D(2),p(2)	    D(3),p(3)	    D(4),p(4)	  D(5),p(5)	
0	          0:       - 	         2,0	         5,0	         1,0	         ∞ 	         ∞ 	         
1	          03:      - 	         2,0	         4,3	         - 	         2,3	         ∞ 	         
2	          034:     - 	         2,0	         3,4	         - 	         - 	           4,4	         
3	          0341:    - 	         - 	           3,4	         - 	         - 	           4,4	         
4	          03412:   - 	         - 	           - 	           - 	         - 	           4,4	         
5	          034125:  - 	         - 	           - 	           - 	         - 	           - 	 

N' designates the shortest path
Each step illsutrates the decision-making process used

# Artificial Intelligence Assignments

***Assignment 1:*** Problem Solving 8-Queens problem using Uniform Cost Search
## Eight Queen Problem using UCS

Initial State - No queens are on the board

States - A state is any arrangement of 0 to 8 queens on the board. We can even have a state where any arrangement of 0-8 queens is done with no queen under attack.

Actions - The operators add queens to any empty square or add queen to leftmost empty square such that it is not attacked by other queens.

Path cost - 1 per every move

Goal state - Arranging 8 queens on the board such that no one is under attack by any other queen.

### Compilation Instruction

g++ 8Queens.cpp

### Input Output Files

[8Queens Output file](IO/8queens_OUTPUT.txt)

---
***Assignment 2:***
Problem Solving Travelling Salesman using A* Heuristic Search
## TSP using A*

Initial State - Agent in the start city and has not visited any other city

Edge-cost - distance between the cities represented by the nodes, use this cost to calculate g(n).

Heuristic h(n) - distance to the nearest unvisited city from the current city + estimated distance to travel all the unvisited cities (MST heuristic used here) + nearest distance from an unvisited city to the start city. 

Goal State - Agent has visited all the cities and reached the start city again

### Compilation Instruction

g++ TSP.cpp

### Input Output Files

[TSP Input File](IO/TSP_INPUT.txt)

[TSP Output File](IO/TSP_OUTPUT.txt)

---
***Assignment 3:***
Grouping n students having random marks in m subjects into k groups such that each group has minimum diversity.

## K-Means (Genetic ALgorithm)

Chromosome - Generate random marks of N student in M subjects.

Population - Randomly select any 50 chromosome for Init population which is divided into K groups and Group Representative is Average value of that group.

Fitness Value - Take absolute value of difference of group representative and student's marks.

Selection - Select 2 parent by Tournament Selection.

Crossover - Choose a random point and execute single point crossover.

Mutation - Randomly select a gene from each chromosome of the crossover population and mutating with random group representative to increase diversity.

### Compilation Instruction

g++ K-Means\ (Genetic\ Algorithm).cpp

### Input Output Files

[kmeans Input File](IO/kmeans_INPUT.txt)

[kmeans Output File](IO/kmeans_OUTPUT.txt)

---
***Assignment 4:***
The game of sticks: To design a Min/Max game tree with alpha-beta pruning for the game.

## The game of sticks

1. It is a 2-player game.
2. There is a heap of sticks on a board, say N.
3. Each player picks up sticks alternatively.
4. On their turn, each player has to pick at least 1 stick and he can pick at most 3 sticks.
5. The one who has to pick the final stick will be the loser.•First turn will be randomly decided with toss.
6. To design AIvsHUMAN and AIvsAI game.

### Compilation Instruction

g++ Game\ of\ sticks.cpp

### Input Output Files

[Game of Sticks Input File](IO/Game_INPUT.txt)

[Game of Sticks Output File](IO/Game_OUTPUT.txt)
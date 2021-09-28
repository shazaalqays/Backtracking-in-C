# Backtracking-in-C
## Algorithm
```
1.	Take the matrix from the user.
2.	Backtracking:
For each row in the matrix:
Take a number (color) from the matrix.
Check if the number is duplicated in the other rows or other cols:
a.	If it is not duplicated backtrack.
b.	Else rotate the current line.
3.	Check result of backtracking
a.	If true print the matrix.
b.	Else print to user that there’s no solution.
```
## Complexity
Backtracking function O(n)<br/>
print the matrix function O(n^2). Where n is the size of matrix.

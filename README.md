# Report

| UFID | 45705087      |
| Name | Alexander Dao |

## Question 1

## Question 2


## Question 3

**Pseudocode:**

```
LCS(A, B, v):
  n = A.len
  m = B.len
  dp[0..n][0..m] = 0
  map v(char -> value)
  for i = 1 to n:
    for j = 1 to m:
      if A[i] = B[j]:
        dp[i][j] = max(dp[i-1][j-1] + v[A[i]], dp[i-1][j], dp[i][j-1])
      else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1])

  backtrack = ""
  i = n, j = m
  while i > 0 and j > 0:
    if A[i] = B[j] and dp[i][j] = dp[i-1][j-1] + v[A[i]]:
      backtrack = A[i] + backtrack // string operation
      i--; j--;
    else if dp[i-1][j] >= dp[i][j-1]:
      i--;
    else:
      j--

  return backtrack, dp[n][m]

```

The runtime would be O(n * m) since you need to compute every cell of the n * m table. Computing each of the cell is O(1) operation since you compare a constant set of inputs, dp[i-1][j-1], dp[i-1][j], dp[i][j-1]. Backtracking does the same operations but in reverse so it also takes the same amountof time.

# Compilation

## Nix Method (Tested and Recommended)

Dependencies: any system that can install nix-determinate (including non-immutable Unix systems), and run

``` bash
install.sh
```

## Manual

Install g++ (C++17)

```bash
g++ -std=c++17 -O2 src/main.cpp -o binary/main
g++ -std=c++17 -O2 src/test-generator.cpp -o binary/test-generator
./test.sh
```

# Execution

## Run on a custom input

Create a file example.in following the format in the assignment:

```
K
x1 v1
x2 v2
...
xK vK
A
B
```

and run:

```bash
./binary/main < example.in
```

## Generate a random test case, given k, lenA, lenB

```bash
./binary/test-generator < tests/test1/input.txt > tests/test1/test-case.txt
./binary/main < tests/test1/test-case.txt
```

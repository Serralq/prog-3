# Report

| UFID | 45705087      |
| Name | Alexander Dao |

## Question 1

Copied from timing.org which came from one of the test runs over the test/ folder

| Test   |  K | lenA | lenB |      n*m | avg/run |
|--------+----+------+------+----------+---------|
| test1  |  4 |   25 |   25 |      625 | 4.6ms   |
| test2  |  8 |   50 |   50 |     2500 | 4.0ms   |
| test3  | 10 |  100 |  100 |    10000 | 3.8ms   |
| test4  | 10 |  200 |  200 |    40000 | 4.6ms   |
| test5  | 15 |  500 |  500 |   250000 | 6.6ms   |
| test6  | 20 | 1000 | 1000 |  1000000 | 11.2ms  |
| test7  | 20 | 2000 | 2000 |  4000000 | 32.4ms  |
| test8  | 26 | 3000 | 3000 |  9000000 | 69.0ms  |
| test9  | 26 | 4000 | 4000 | 16000000 | 124.2ms |
| test10 | 26 | 5000 | 5000 | 25000000 | 191.0ms |

Graph is found in graph.png, made from plotting inside of google-sheets.

## Question 2

Let i be a pointer to the word A and j be a pointer to the word B.
Let optimal of i,j be the highest value that can be achieved using subsections A[1..i] and B[1..j].

- The base case would be to have an empty subsequence since that is always valid with a value of 0.
- Then the next case would be to match or not match A[i] and B[j].
- If they do not match then we get the max between skipping A[i] or B[j] by keeping i or j constant and then access the other variable - 1 -> dp[i][j - 1] or dp[i - 1][j]
- If they do match then we do the previous check and do an additional max check against adding the current letter A[i]'s value to the previous subsection of both A and B thus it must be dp[i - 1][j - 1] + val(A[i]).
- Thus opt(i, j) = {

    0 if i or j is 0

    max { opt(i - 1, j - 1) + 1, opt(i - 1, j), opt(i, j - 1) } if A[i] == B[j]

    max { opt(i - 1, j), opt(i, j - 1) } if A[i] != B[j]

  }

This is correct since every subsequence of A[1..i] and B[1..j] can only get its value from either adding the matching value, skipping A[i] or skipping B[i] and we take the max from all these three cases. Given non-negative values this algo will only increase and surface the highest possible value.

## Question 3

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

#include <bits/stdc++.h>

using Table = std::vector<std::vector<int>>;

Table dp_func(std::string &A, std::string &B,
              std::unordered_map<char, int> &val) {
  int n = A.size(), m = B.size();
  Table dp(n + 1, std::vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);

      if (A[i - 1] == B[j - 1])
        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + val[A[i - 1]]);
    }
  }

  return dp;
}

std::string backtrack(Table &dp, std::string &A, std::string &B,
                      std::unordered_map<char, int> &val) {
  std::string result;
  int i = A.size(), j = B.size();

  while (i > 0 && j > 0) {
    if (A[i - 1] == B[j - 1] && dp[i][j] == dp[i - 1][j - 1] + val[A[i - 1]]) {
      result += A[i - 1];
      i--;
      j--;
    } else if (dp[i - 1][j] >= dp[i][j - 1])
      i--;
    else
      j--;
  }

  std::reverse(result.begin(), result.end());
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k;
  std::cin >> k;

  std::unordered_map<char, int> val;
  while (k--) {
    char c;
    int v;
    std::cin >> c >> v;
    val[c] = v;
  }

  std::string A, B;
  std::cin >> A >> B;

  auto dp = dp_func(A, B, val);
  std::string result = backtrack(dp, A, B, val);

  std::cout << dp[A.size()][B.size()] << "\n" << result << "\n";
}

#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int k, lenA, lenB;
  std::cin >> k >> lenA >> lenB;

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> rd_val(1, 100);
  std::uniform_int_distribution<> rd_char(0, k - 1);

  std::cout << k << "\n";
  for (int i = 0; i < k; i++)
    std::cout << (char)('a' + i) << " " << rd_val(gen) << "\n";

  while (lenA--)
    std::cout << (char)('a' + rd_char(gen));
  std::cout << "\n";

  while (lenB--)
    std::cout << (char)('a' + rd_char(gen));
  std::cout << "\n";

  return 0;
}

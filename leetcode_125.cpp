// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
// it reads the same forward and backward. Alphanumeric characters include letters and numbers.

#include <iostream>
#include <string>

int solve(std::string s)
{
  std::string filtered;
  for (char c: s)
  {
    if (isalnum(c))
    {
      filtered += tolower(c);
    }
  }

  std::string reversed(filtered.rbegin(), filtered.rend());
  return filtered == reversed;
}

int main()
{
  int N;
  std::cin >> N;

  while (N --)
  {
    std::string s;
    std::cin >> s;
    std::cout << (solve(s) ? "True" : "False") << std::endl;
  }

  return 0;
}
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include <iostream>
#include <string>
#include <algorithm>

bool solve(std::string s1, std::string s2)
{
  if (s1.length() != s2.length())
  {
    return false;
  }

  return s1 == s2;
}

int main()
{
  int N;
  std::cin >> N;

  while (N --)
  {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    std::cout << (solve(s1, s2) ? "true" : "false") << std::endl;
  }

  return 0;
}
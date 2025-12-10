// Design an algorithm to encode a list of strings to a string.
// The encoded string is then sent over the network and is decoded back to the original list of strings.

#include <iostream>
#include <string>

std::string encode(std::string* strs, int strsSize)
{
  std::string encoded;

  for (int i = 0; i < strsSize; i++)
  {
    encoded += std::to_string(strs[i].size()) + "#" + strs[i];
  }

  return encoded;
}

std::string* decode(std::string s)
{
  std::string* decoded = new std::string[1000];

  for (int i = 0; i < s.size(); i++)
  {
    int j = i;
    while (s[j] != '#')
    {
      j++;
    }

    int len = std::stoi(s.substr(i, j - i));
    std::string str = s.substr(j + 1, len);
    i = j + len;

    decoded[i] = str;
  }

  return decoded;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int strsSize;
    std::string* strs = new std::string[strsSize];

    for (int i = 0; i < strsSize; i++)
    {
      std::cin >> strs[i];
    }

    std::string encoded = encode(strs, strsSize);
    std::string* decoded = decode(encoded);
  }

  return 0;
}
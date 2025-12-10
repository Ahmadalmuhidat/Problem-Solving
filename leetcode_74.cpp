// You are given an m x n integer matrix matrix with the following two properties:
// • Each row is sorted in non-decreasing order.
// • The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false other
// You must write a solution in o(log(m * n)) time complexity.

#include <iostream>

int* solve(int matrix[][100], int m, int n, int target)
{
  int left = 0; // first index in the first row
  int right = m * n - 1; // last index in the last row

  while (left <= right)
  {
    int mid_index = left + (right - left) / 2; // mid index in the row
    int mid_value = matrix[mid_index / n][mid_index % n]; // mid value in the matrix

    if (mid_value == target)
    {
      return &matrix[mid_index / n][mid_index % n];
    }
    else if (mid_value < target)
    {
      left = mid_index + 1;
    }
    else
    {
      right = mid_index - 1;
    }
  }

  return nullptr;
}

int main()
{
  int N;
  std::cin >> N;

  while (N--)
  {
    int m, n, target;
    std::cin >> m >> n >> target;
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        std::cin >> matrix[i][j];
      }
    }

    int* result = solve(matrix, m, n, target);
    if (result)
    {
      std::cout << "Found: " << *result << std::endl;
    }
    else
    {
      std::cout << "Not Found" << std::endl;
    }
  }

  return 0;
}
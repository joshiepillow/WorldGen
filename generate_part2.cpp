#include "stupid.h"

std::vector<std::vector<int>> generate_part2(std::vector<std::vector<int>> input, int seed) {
  //changable variables
  float chance_of_addition = 0.3;
  int number_of_times = 2;

  //code
  srand(seed);
  auto check = [&](int x, int y)
  {
    try 
    {
      if (input[x][y] == 1) return false;
      if (x - 1 >= 0 && input[x-1][y] == 1) return true;
      if (x + 1 < input.size() && input[x+1][y] == 1) return true;
      if (y - 1 >= 0 && input[x][y-1] == 1) return true;
      if (y + 1 < input[0].size() && input[x][y+1] == 1) return true;
      return false;
    } catch (...) 
    {
      std::cout << "check error";
      return false;
    }
  };

  auto add = [&]() 
  {
    std::vector output = input;
    for (int i = 1; i < input.size()-1; i++) 
    {
      for (int j = 1; j < input[0].size()-1; j++) 
      {
        if (check(i, j)) 
        {
          //std::cout << "x: " << i << " y: " << j <<"\n";
          if ((float) rand() / (float) RAND_MAX < chance_of_addition) 
          {
            output[i][j] = 1;
          }
        }
      }
    }
    return output;
  };
  for (int i = 0; i < number_of_times; i++) {
    input = add();
  }
  return input;
}
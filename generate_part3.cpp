#include "stupid.h"

std::vector<std::vector<int>> generate_part3(std::vector<std::vector<int>> input) 
{
  auto check = 
  [&](int x, int y){
    bool minx = (x-1>=0);
    bool maxx = (x+1<input.size());
    bool miny = (y-1>=0);
    bool maxy = (y+1<input[0].size());
    if (minx) {
      if (miny && input[x-1][y-1] == 0) return false;
      if (input[x-1][y] == 0) return false;
      if (maxy && input[x-1][y+1] == 0) return false;
    }
    if (miny && input[x][y-1] == 0) return false;
    if (maxy && input[x][y+1] == 0) return false;
    if (maxx) {
      if (miny && input[x+1][y-1] == 0) return false;
      if (input[x+1][y] == 0) return false;
      if (maxy && input[x+1][y+1] == 0) return false;
    }
    return true;
  };
  std::vector output = input;
  for (int i = 1; i < input.size() - 1; i++) 
  {
    for (int j = 1; j < input[0].size() - 1; j++) 
    {
      if (check(i, j)) 
      {
        output[i][j] = 0;
      }
    }
  }
  return output;
}
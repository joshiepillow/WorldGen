#include "stupid.h"

int getRoomSeed(int x, int y, int seed) 
{
  unsigned int a = ((x >= 0) ? x * 2 : x * -2 - 1);
  unsigned int b = ((y >= 0) ? y * 2 : y * -2 - 1);
  unsigned int ab = ((a+b) * (a+b+1) * 1/2 + b);
  unsigned int finalSeed = ((ab + seed) * (ab + seed+1) * 1/2 + seed);
  return finalSeed;
}

std::vector<int> helper(int x, int y, int seed, int length) 
{
  //adjustable variables
  std::vector<int> chances = {1, 1};

  //code
  int total = 0;
  for (int i = 0; i < chances.size(); i++) {
    total += chances[i];
  }

  std::vector<int> vec;
  srand(getRoomSeed(x, y, seed));
  int numberOfExits;
  {
    int random = rand()  % total;
    int currentSection = 0;
    for(int i = 0; i < chances.size(); i++) {
      currentSection += chances[i];
      if (random < currentSection) {
        numberOfExits = i + 1;
        break;
      }

    }
  }
  std::vector<int> possible;
  for (int i = 0; i < length; i++) {
    possible.push_back(length);
  }
  for (int i = 0; i < numberOfExits; i++) {
    int num = rand() % possible.size();
    vec.push_back(num);
    possible.erase(possible.begin() + num);
  }
  return vec;
}

std::vector<std::vector<int>> getEdges(int x, int y, int seed, int length) {

  x = x * 2;
  y = y * 2;
  std::vector<int> up = helper(x, y+1, seed, length);
  std::vector<int> down = helper(x, y-1, seed, length);
  std::vector<int> left = helper(x-1, y, seed, length);
  std::vector<int> right = helper(x+1, y, seed, length);

  return {up, down, left, right};
}
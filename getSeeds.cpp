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
  std::vector<int> vec;
  srand(getRoomSeed(x, y, seed));
  if (rand() % 2)
  {
    int first = rand() % length;
    int second = rand() % length - 1;
    if (second == first) {
      second = length - 1;
    }
    vec = {first, second};
  } else {
    int first = rand() % length;
    vec = {first};
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
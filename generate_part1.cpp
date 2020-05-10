#include "stupid.h"

std::vector<std::vector<int>> generate_part1(int up, int down, int left, int right, int seed, int length) 
{
  srand(seed);

  std::vector<std::vector<int>> dists;
  for(int i = 0; i < 2 * length + 1; i++) {
    std::vector<int> line;
    for(int j = 0; j < 2 * length + 1; j++) {
      line.push_back(rand());
    }
    dists.push_back(line);
  }
  
  std::vector<std::vector<int>> rooms;
  for (int i = 0; i < length; i++) {
    std::vector<int> line;
    for (int j = 0; j < length; j++) {
      line.push_back(0);
    }
    rooms.push_back(line);
  }
  
  auto connect = [&](int a[2], int b[2]) {
    std::vector<std::vector<int>> dijk = dijkstra(dists, a, b);
    
    for (int i = 0; i < dijk.size(); i++) {
      rooms[dijk[i][0]][dijk[i][1]] = 1;
    }
    
  };
  

  int center[2] = {length/2-rand()%2, length/2-rand()%2};
  
  int upPlace[2] = {up,length-1};
  connect(center, upPlace);
  int rightPlace[2] = {length-1,right};
  connect(center, rightPlace);
  int downPlace[2] = {down,0};
  connect(center, downPlace);
  int leftPlace[2] = {0,left};
  connect(center, leftPlace);
  return rooms;
}
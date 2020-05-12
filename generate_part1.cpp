#include "stupid.h"

std::vector<std::vector<int>> generate_part1(std::vector<std::vector<int>> edges, int seed, int length) 
{
  std::vector<int> up = edges[0];
  std::vector<int> down = edges[1];
  std::vector<int> left = edges[2];
  std::vector<int> right = edges[3];
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
  for (int i = 0; i < up.size(); i++) {
    int upPlace[2] = {up[i],length-1};
    connect(center, upPlace);
  }  
  for (int i = 0; i < right.size(); i++) {
    int rightPlace[2] = {length-1,right[i]};
    connect(center, rightPlace);
  }  
  for (int i = 0; i < down.size(); i++) {
    int downPlace[2] = {down[i],0};
    connect(center, downPlace);
  }  
  for (int i = 0; i < left.size(); i++) {
    int leftPlace[2] = {0,left[i]};
    connect(center, leftPlace);
  }  
  return rooms;
}














#include "stupid.h"

int getDist(std::vector<std::vector<int>> dists, int a[2], int b[2]) {
  try {
    int ax = a[0] * 2;
    int ay = a[1] * 2;
    int bx = b[0] * 2;
    int by = b[1] * 2;
    return dists[(ax + bx)/2][(ay + by)/2];
  } catch(...) {
    std::cout << "getDist failed" << std::endl;
    return 0;
  }
}

std::vector<std::vector<int>> dijkstra(std::vector<std::vector<int>> dists, int start[2], int end[2]) {
  int length = (dists.size()-1)/2;
  struct node {
    bool isCompleted = false;
    bool isNeighbor = false;
    int prev[2] = {-1, -1};
    int dist_from_start = INT_MAX;
  };

  node nodes[length][length];
  std::vector<std::vector<int>> neighboring_nodes;
  


  int current_node[2] = {start[0], start[1]};
  nodes[start[0]][start[1]].dist_from_start = 0;
  auto nearest_neighbor = [&](std::vector<std::vector<int>> neighbors){
    int num = 0;
    std::vector<int> current_smallest = {neighbors[0][0], neighbors[0][1]};
    for (int i = 1; i < neighbors.size(); i++) {
      node neighbor = nodes[neighbors[i][0]][neighbors[i][1]];
      node smallest_node = nodes[current_smallest[0]][current_smallest[1]];
      if (neighbor.dist_from_start < smallest_node.dist_from_start) {
        current_smallest[0] = neighbors[i][0];
        current_smallest[1] = neighbors[i][1];
        num = i;
      }
    }
    current_smallest.push_back(num);
    return current_smallest;
  };
  
  auto isLegal = [&](int x, int y) {
    if (x < 0 || y < 0 || x >= length || y >= length) {
      return false;
    }
    if (nodes[x][y].isCompleted) {
      return false;
    }
    return true;
  };
  
  int lol = 0;
  while(current_node[0] != end[0] || current_node[1] != end[1]) 
  {
    int x = current_node[0];
    int y = current_node[1];
    
    if (isLegal(x + 1, y)) {
      if (
        nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x + 1, y}) < nodes[x + 1][y].dist_from_start
        ) {
        nodes[x + 1][y].dist_from_start = nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x + 1, y});
        nodes[x + 1][y].prev[0] = current_node[0];
        nodes[x + 1][y].prev[1] =  current_node[1];
      }
      if (!nodes[x + 1][y].isNeighbor) 
      {
        nodes[x + 1][y].isNeighbor = true;
        neighboring_nodes.push_back({x + 1,y});
      }
    }
    if (isLegal(x - 1, y)) {
      if (
        nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x - 1, y}) < nodes[x - 1][y].dist_from_start
        ) {
        nodes[x - 1][y].dist_from_start = nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x - 1, y});
        nodes[x - 1][y].prev[0] = current_node[0];
        nodes[x - 1][y].prev[1] =  current_node[1];
      }
      if (!nodes[x - 1][y].isNeighbor) 
      {
        nodes[x - 1][y].isNeighbor = true;
        neighboring_nodes.push_back({x -1, y});
      }
    }
    if (isLegal(x, y + 1)) {
      if (
        nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x, y + 1}) < nodes[x][y + 1].dist_from_start
        ) {
        nodes[x][y + 1].dist_from_start = nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x, y + 1});
        nodes[x][y + 1].prev[0] = current_node[0];
        nodes[x][y + 1].prev[1] =  current_node[1];
      }
      if (!nodes[x][y + 1].isNeighbor) 
      {
        nodes[x][y + 1].isNeighbor = true;
        neighboring_nodes.push_back({x,y + 1});
      }
    }
    if (isLegal(x, y - 1)) {
      if (
        nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x, y - 1}) < nodes[x][y - 1].dist_from_start
        ) {
        nodes[x][y - 1].dist_from_start = nodes[x][y].dist_from_start +
        getDist(dists, (int[]){x, y}, (int[]){x, y - 1});
        nodes[x][y - 1].prev[0] = current_node[0];
        nodes[x][y - 1].prev[1] =  current_node[1];
      }
      if (!nodes[x][y - 1].isNeighbor) 
      {
        nodes[x][y - 1].isNeighbor = true;
        neighboring_nodes.push_back({x,y - 1});
      }
    }
    
    nodes[x][y].isCompleted = true;
    std::vector<int> nearest = nearest_neighbor(neighboring_nodes);
    current_node[0] = nearest[0];
    current_node[1] = nearest[1];
    
    neighboring_nodes.erase(neighboring_nodes.begin() + nearest[2]);
  }
  
  std::vector<std::vector<int>> prev_list;
  std::vector<int> prev = {end[0], end[1]};
  prev_list.push_back(prev);
  
  while (prev[0] != start[0] || prev[1] != start[1]) {
    int error = prev[0];
    prev[0] = nodes[prev[0]][prev[1]].prev[0];

    prev[1] = nodes[error][prev[1]].prev[1];
    prev_list.push_back(prev);
    
  }
  
  return prev_list;
}
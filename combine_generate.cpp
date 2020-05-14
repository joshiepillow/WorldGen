#include "stupid.h"

std::vector<std::vector<std::vector<int>>> combine_generate(int x, int y, int seed) {
	//adjustable variables
	int length = 8;

	//code
	int finalSeed = getRoomSeed(x, y, seed);
  	std::vector<std::vector<int>> edges = getEdges(x, y, seed, length);
  	std::vector<std::vector<int>> rooms = generate_part1(edges, finalSeed, length);
  	rooms = generate_part2(rooms, finalSeed);
  	rooms = generate_part3(rooms);

  	std::cout << "\n";
  	for (int i = rooms.size()-1; i >= 0; i--) {
    	std::cout<<"\n";
    	for (int j = 0; j < rooms.size(); j++) {
    	  	std::cout<<rooms[j][i] << " ";
    	}
  	}
  	std::cout << std::endl;
  	return {rooms, edges};
}

bool check(int x, int y, std::vector<std::vector<int>> rooms, std::vector<std::vector<int>> edges) {
	std::vector up = edges[0];
	std::vector down = edges[1];
	std::vector left = edges[2];
	std::vector right = edges[3];

	if (0 <= x && x < rooms.size() &&  0 <= y && y < rooms[0].size() && rooms[x][y] == 1) return true;
	if (y == rooms[0].size()) {
		for (int i = 0; i < up.size(); i++) {
			if (x == up[i]) return true;
		}
		return false;
	}
	if (y == -1) {
		for (int i = 0; i < down.size(); i++) {
			if (x == down[i]) return true;
		}
		return false;
	}
	if (x == -1) {
		for (int i = 0; i < left.size(); i++) {
			if (y == left[i]) return true;
		}
		return false;
	}
	if (x == rooms.size()) {
		for (int i = 0; i < right.size(); i++) {
			if (y == right[i]) return true;
		}
		return false;
	}
	return false;
}












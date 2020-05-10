#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <limits.h>

std::vector<std::vector<int>> dijkstra(std::vector<std::vector<int>> dists, int start[2], int end[2]);
std::vector<std::vector<int>> generate_part1(int up, int down, int left, int right, int seed, int length);
std::vector<std::vector<int>> generate_part2(std::vector<std::vector<int>> input, int seed);
std::vector<std::vector<int>> generate_part3(std::vector<std::vector<int>> input);

int getRoomSeed(int x, int y, int seed);
std::vector<std::vector<int>> getEdges(int x, int y, int seed, int length);

sf::Texture draw(std::vector<std::vector<int>> rooms);
#include "stupid.h"


void doot(int x, int y, int seed) {
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
  std::cout<<std::endl;

  sf::RenderWindow window(sf::VideoMode(1024, 1024), "My window");
  sf::Texture t = load_room(rooms, edges);
  sf::Sprite s;
  s.setTexture(t);
  s.setScale(3, 3);
  window.clear(sf::Color(255, 255, 255));
  window.draw(s);
  window.display();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed) window.close();
    }
  }
}

int main() {
  int x = 0; 
  int y = 0;
  int seed = 0;

  doot(x, y, seed);
  char c = 'm';
  while(c != '\0') {
    std::cin >> c;
    if (c=='w') y++;
    else if (c=='a') x--;
    else if (c=='s') y--;
    else if (c=='d') x++;

    doot(x, y, seed);
  }
}
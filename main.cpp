#include "stupid.h"


void doot(int x, int y, int seed) {
  //adjustable variables
  int length = 8;

  //code
  int finalSeed = getRoomSeed(x, y, seed);
  std::vector<std::vector<int>> edges = getEdges(x, y, seed, length);
  std::vector<std::vector<int>> rooms = generate_part1(edges[0][0], edges[1][0], edges[2][0], edges[3][0], finalSeed, length);
  rooms = generate_part2(rooms, finalSeed);
  rooms = generate_part3(rooms);
  sf::Sprite sprite(draw(rooms));
  sf::RenderWindow window(sf::VideoMode(64 * rooms.size(), 64 * rooms.size()), "My window");
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
            
    }
    window.clear();
    // Draw the texture
    window.draw(sprite);
    // End the current frame and display its contents on screen
    window.display();
  }

  std::cout << "\n";
  for (int i = rooms.size()-1; i >= 0; i--) {
    std::cout<<"\n";
    for (int j = 0; j < rooms.size(); j++) {
      std::cout<<rooms[j][i] << " ";
    }
  }
  std::cout<<"\n"<<time(NULL)<<"\n";
}

int main() {
  int x = 0; 
  int y = 0;
  std::cout<<time(NULL);
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
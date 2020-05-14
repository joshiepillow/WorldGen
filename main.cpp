#include "stupid.h"

int main() {
  //adjustable variables
  int seed = 0;

  //code
  int worldx = 0;
  int worldy = 0;
  int x = 0;
  int y = 0;

  auto mod = [](int x, int y) {
    return (x % y + y) % y;
  };

  sf::RenderWindow window(sf::VideoMode(1024, 1024), "My window");
  std::vector load = combine_generate(worldx, worldy, seed);
  std::vector rooms = load[0];
  std::vector edges = load[1];
  sf::Texture section = load_section(rooms, edges);

  sf::Texture t = add(x, y, section);
  sf::Sprite map;
  map.setTexture(t);
  map.setScale(3, 3);
  window.clear(sf::Color(255, 255, 255));
  window.draw(map);
  window.display();

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)){
      if (event.type == sf::Event::Closed) window.close();
      if (event.type == sf::Event::KeyPressed)
      {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
          if(check(x, y+1, rooms, edges)) y++;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
          if(check(x-1, y, rooms, edges)) x--;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          if(check(x, y-1, rooms, edges)) y--;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
          if(check(x+1, y, rooms, edges)) x++;
        }

        if (mod(x, rooms.size()) != x) {
          if (x < 0) worldx--; else worldx++;
          x = mod(x, rooms.size());
          load = combine_generate(worldx, worldy, seed);
          rooms = load[0];
          edges = load[1];
          section = load_section(rooms, edges);
        } 
        if (mod(y, rooms.size()) != y) {
          if (y < 0) worldy--; else worldy++;
          y = mod(y, rooms.size());
          load = combine_generate(worldx, worldy, seed);
          rooms = load[0];
          edges = load[1];
          section = load_section(rooms, edges);
        }
        window.clear(sf::Color(255, 255, 255));
        sf::Texture t = add(x, y, section);
        map.setTexture(t);
        window.draw(map);
        window.display();
      }
    }
  }
}
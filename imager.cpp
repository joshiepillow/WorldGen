#include "stupid.h"
sf::Texture add(std::vector<std::vector<int>> rooms) {

}

sf::Texture load_room(std::vector<std::vector<int>> rooms, std::vector<std::vector<int>> sides) {
	
	sf::Texture a;
	a.loadFromFile("sprites/room.png");
	sf::Sprite room(a);

	sf::Texture b;
	b.loadFromFile("sprites/hallway hori.png");
	sf::Sprite hallway_hori(b);

	sf::Texture c;
	c.loadFromFile("sprites/hallway vert.png");
	sf::Sprite hallway_vert(c);
	hallway_vert.setOrigin(0, 16);
	
	sf::Texture d;
	d.loadFromFile("sprites/location cursor.png");
	sf::Sprite location_cursor(d);

	sf::Texture e;
	e.loadFromFile("sprites/arrow up.png");
	sf::Sprite arrow_up(e);

	sf::Texture f;
	f.loadFromFile("sprites/arrow down.png");
	sf::Sprite arrow_down(f);

	sf::Texture g;
	g.loadFromFile("sprites/arrow left.png");
	sf::Sprite arrow_left(g);

	sf::Texture h;
	h.loadFromFile("sprites/arrow right.png");
	sf::Sprite arrow_right(h);


	sf::RenderTexture texture;
	texture.create(rooms.size()*16 + 32, rooms[0].size()*16 + 32);
	texture.clear(sf::Color::White);
	
	for (int i = 0; i < rooms.size(); i++) {
		for (int j = 0; j < rooms[0].size(); j++) {
			if(rooms[i][j] == 1) {
				int x = 16 * i + 16;
				int y = 16 * rooms[0].size() - 16 * (j + 1) + 16;
				room.setPosition(x, y);
				texture.draw(room);
				if (i+1<rooms.size() && rooms[i+1][j] == 1) {
					hallway_hori.setPosition(x, y);
					texture.draw(hallway_hori);
				}
				if (j+1<rooms[0].size() && rooms[i][j+1] == 1) {
					hallway_vert.setPosition(x, y);
					texture.draw(hallway_vert);
				}
			}
		}
	}

	std::vector<int> up = sides[0];
	std::vector<int> down = sides[1];
	std::vector<int> left = sides[2];
	std::vector<int> right = sides[3];
	int err = 5;
	for (int i = 0; i < up.size(); i++) {
		std::cout<<up[i] << std::endl;
		arrow_up.setPosition(16 + up[i]*16, err);
		texture.draw(arrow_up);
	}
	for (int i = 0; i < down.size(); i++) {
		arrow_down.setPosition(16 + down[i]*16, 9 * 16 - err);
		texture.draw(arrow_down);
	}
	for (int i = 0; i < left.size(); i++) {
		arrow_left.setPosition(err, 16 * 8 - left[i]*16);
		texture.draw(arrow_left);
	}
	
	for (int i = 0; i < right.size(); i++) {
		arrow_right.setPosition(9 * 16 - err, 16 * 8 - right[i]*16);
		texture.draw(arrow_right);
	}

   	texture.display();


	return texture.getTexture();
}
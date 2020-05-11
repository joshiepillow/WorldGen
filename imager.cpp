#include "stupid.h"
sf::Texture draw(std::vector<std::vector<int>> rooms) {
	
	sf::Texture a;
	sf::Sprite room;
	if(!a.loadFromFile("sprites/room.png")) {
		std::cout<<"draw Errored";
	}
	
	room.setTexture(a);

	sf::Texture b;
	sf::Sprite hallway_hori;
	sf::Sprite hallway_vert;
	if(!b.loadFromFile("sprites/hallway.png")) {
		std::cout<<"draw Errored";
	}
	hallway_hori.setTexture(b);
	hallway_vert.setTexture(b);
	hallway_vert.setRotation(90);
	hallway_vert.setOrigin(16, 16);
	
	sf::Texture c;
	sf::Sprite location_cursor;
	if(!c.loadFromFile("sprites/location cursor.png")) {
		std::cout<<"draw Errored";
	}
	location_cursor.setTexture(c);

	sf::RenderTexture texture;
	texture.create(rooms.size()*16, rooms[0].size()*16);
	texture.clear(sf::Color::White);
	
	for (int i = 0; i < rooms.size(); i++) {
		for (int j = 0; j < rooms[0].size(); j++) {
			if(rooms[i][j] == 1) {
				int x = 16 * i;
				int y = 16 * rooms[0].size() - 16 * (j + 1);
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

	texture.draw(room);
   	texture.display();



	return texture.getTexture();
}
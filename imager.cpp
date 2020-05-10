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
	hallway_vert.setOrigin(0, 16);
	
	sf::Texture c;
	sf::Sprite location_cursor;
	if(!c.loadFromFile("sprites/location cursor.png")) {
		std::cout<<"draw Errored";
	}
	location_cursor.setTexture(c);

	sf::RenderTexture texture;
	texture.create(500, 500);

	/*for (int i = 0; i < rooms.size(); i++) {
		for (int j = 0; j < rooms[0].size(); j++) {
			if(rooms[i][j] == 1) {
				//room.setPosition(16 * i, 16 * j);
				//texture.draw(room);
			}	
		}
	}*/


// Create a new render-texture
//sf::RenderTexture texture;
//texture.create(500, 500);
	texture.clear(sf::Color::Red);
	texture.draw(room);
   	texture.display();








	sf::Texture fake(texture.getTexture());
	return fake;
}
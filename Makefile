.DEFAULT_GOAL := test	

test :
	g++ --std=c++17 dijkstra.cpp generate_part1.cpp generate_part2.cpp generate_part3.cpp getSeeds.cpp imager.cpp combine_generate.cpp -lsfml-graphics -lsfml-window -lsfml-system main.cpp

clean :
	-rm *.o $(objects) test
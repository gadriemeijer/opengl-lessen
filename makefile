compile: ./main.cpp
	g++ -c ./main.cpp
	g++ main.cpp -o glfw-app glad.c -ldl -lglfw -lGL

run:
	./glfw-app


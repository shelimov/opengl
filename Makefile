export C_INCLUDE_PATH=/usr/local/include
export CPLUS_INCLUDE_PATH=/usr/local/include

LIBS = -lstdc++ -lSDL2 -lGL -lGLEW
LIBS_PATHS = -L/System/Library/Frameworks/OpenGL.framework/Versions/Current/Libraries -L/usr/local/lib
OBJECT_FILES = main.o display.o shader.o

main: $(OBJECT_FILES)
	gcc $(OBJECT_FILES) -o main $(LIBS_PATHS) $(LIBS)

main.o: main.cpp
	gcc -c main.cpp -o main.o

display.o: display.cpp
	gcc -c display.cpp -o display.o

shader.o: ./shaders/shaderUtils.cpp
	gcc -c ./shaders/shaderUtils.cpp -o shader.o

clear:
	rm -f $(OBJECT_FILES) main

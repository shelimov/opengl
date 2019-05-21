export C_INCLUDE_PATH=/usr/local/include
export CPLUS_INCLUDE_PATH=/usr/local/include

LIBS = -lstdc++ -lGLFW -lGL -lGLEW
LIBS_PATHS = -L/System/Library/Frameworks/OpenGL.framework/Versions/Current/Libraries -L/usr/local/lib
OBJECT_FILES = main.o display.o shader.o

main: $(OBJECT_FILES)
	gcc $(OBJECT_FILES) -o main $(LIBS_PATHS) $(LIBS)

main.o: main.cpp main.h
	gcc -c main.cpp -o main.o

display.o: display.cpp display.h
	gcc -c display.cpp -o display.o

shader.o: shaders/shaderUtils.cpp shaders/shaderUtils.h
	gcc -c shaders/shaderUtils.cpp -o shader.o

clear:
	rm -f $(OBJECT_FILES) main

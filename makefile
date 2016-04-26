FILENAME=MovieList.cpp
FLAGS=-std=c++11 -Wall -o
EXENAME=MovieList

MOVIEOBJECT=MovieHandler.o
MOVIEHEADER=MovieHandler.h
MOVIECLASS=MovieHandler.cpp

main: $(MOVIEOBJECT)
	g++ $(FILENAME) $(FLAGS) $(EXENAME) $(MOVIEOBJECT)

$(MOVIEOBJECT): $(MOVIEHEADER) $(MOVIECLASS)
	g++ -c -std=c++11 -Wall $(MOVIECLASS)

clean:
	$(RM) 


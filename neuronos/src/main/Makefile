SOURCES= $(wildcard *.cpp)

OBJECTS= $(SOURCES:.cpp=.o)

OBJECTS_PATH=$(foreach obj, $(OBJECTS), $(objectDir)/$(obj))

all: $(OBJECTS)

%.o: %.cpp $(hearders)
	$(CC) -o $(objectDir)/$@ -c $< $(CFLAGS)

clean:
	rm $(OBJECTS_PATH);

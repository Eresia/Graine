CC=g++
CFLAGS=-Wall -g -std=c++11 -pthread -DDEBUG -g
EFLAGS=`pkg-config --libs allegro-5.0 allegro_main-5.0 allegro_image-5.0 allegro_font-5.0 allegro_ttf-5.0`

launcher=test.out

scriptDir=$(shell pwd)
objectDir=bin
srcDir=src

directories=$(shell find $(srcDir) -type d | sed '1d')

cpp=$(foreach dir, $(directories), $(wildcard $(dir)/*.cpp))

headers=$(foreach dir, $(directories), $(wildcard $(scriptDir)/$(dir)/*.hpp))

objects=$(foreach file, $(cpp:.cpp=.o), $(objectDir)/$(notdir $(file)))

all: $(launcher)

#all:
#	@echo $(scriptDir)/$(objectDir)

$(launcher): compilation
	$(CC) -o $(launcher) $(objects) $(EFLAGS)

compilation:
	@mkdir $(objectDir) -p
	@for dir in $(directories); do \
		if [ ! -e $$dir/Makefile ]; then \
				cp Makefile_type $$dir/Makefile; \
		fi; \
		make --no-print-directory -C $$dir objectDir="$(scriptDir)/$(objectDir)" headers="$(headers)" CC=$(CC) CFLAGS="$(CFLAGS)";	\
	done

clean_all: clean
	rm $(launcher)

clean:
	rm -R $(objectDir)

clean_error:
	@for dir in $(directories); do \
		rm $$dir/*.o; \
	done

clean_Makefile:
	@for dir in $(directories); do	\
		rm $$dir/Makefile;	\
	done

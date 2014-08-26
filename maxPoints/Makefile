
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
OBJS+=$(patsubst %.cc, %.o, $(wildcard *.cc))

all:$(OBJS)

%.o:%.cc
	g++ -g -O3 -o $@ $^ -std=c++0x -DDEBUG

clean:
	rm -rf $(OBJS)

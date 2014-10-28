
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
OBJS+=$(patsubst %.cc, %.o, $(wildcard *.cc))

all:$(OBJS)

%.o:%.cc
	g++ -O3 -o $@ $^ -g -DDEBUG -std=c++11

clean:
	rm -rf $(OBJS)


OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
OBJS+=$(patsubst %.cc, %.o, $(wildcard *.cc))

all:$(OBJS)

%.o:%.cc
	g++ -O3 -o $@ $^ -g -DDEBUG -std=c++0x

clean:
	rm -rf $(OBJS)

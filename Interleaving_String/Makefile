
OBJS=$(patsubst %.c, %.o, $(wildcard *.c))
OBJS+=$(patsubst %.cc, %.o, $(wildcard *.cc))

all:$(OBJS)

%.o:%.cc
	g++ -O3 -o $@ $^ -g -DNDEBUG

clean:
	rm -rf $(OBJS)

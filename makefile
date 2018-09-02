CXX = clang++
OBJS =  tests.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS)  -o testsymbol

clean:
	$(RM) main $(OBJS) core *~


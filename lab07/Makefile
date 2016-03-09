EXE = Lab7.out
OBJS = IntArray.o Lab7.o
CPPFLAGS = -ansi -Wall

# The variable CXX is the default C++ compiler, in this case it's g++
$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE)

.PHONY : clean
clean:
	-rm -f Lab7.o $(EXE)
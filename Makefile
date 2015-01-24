# Makefile for RLC GTL PLR changer

NAME = GTLplrChanger
SRCS = GTL_PLR_Changer.cpp

OBJS = $(SRCS:%.cpp=%.o)

CC = g++ -c
CFLAGS = -Wall

CLNK = g++ 
LFLAGS = -Wall 

# DOCTOOL = doxygen


$(NAME): $(OBJS)
	$(CLNK) $(LFLAGS) -o $@ $+
	# $(DOCTOOL) > /dev/null

%.o: %.cpp 
	$(CC) $(CFLAGS)  $<  

clean:
	rm -f *~ *.o 
	rm -f -R html latex
	rm -f deps.mk

depend:
	g++ -MM $(SRCS) > deps.mk

-include deps.mk


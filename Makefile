OBJECTS	= curr.o 
CC	= g++
TARGET	= curr


.SUFFIXES : .c .o

.c.o :
	$(CC) -std=c++17 -O2 -c -Wall $<

$(TARGET)	: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
	
clean :
	rm -rf $(TARGET) $(OBJECTS) core*

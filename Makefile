CC	= g++
OBJECTS	= curr.o 
TARGET	= curr


.SUFFIXES : .c .o

.c.o :
	$(CC) -std=c++17 -O2 -c -g -Wall $<

$(TARGET)	: $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)
	
clean :
	rm -rf $(TARGET) $(OBJECTS) core*

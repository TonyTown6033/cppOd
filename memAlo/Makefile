CC = g++
CFLAGS = -g -Wall -Werror 
SRCS = memAlo.cc
TARGET = alo
OUTFILE = memAlo.txt

all: $(SRCS) 
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) 

run: $(TARGET)
	./$(TARGET) < $(OUTFILE)

clean : $(TARGET)
	rm $(TARGET)

debug: $(TARGET)
	gdb -x gdb_commands.txt ./$(TARGET)

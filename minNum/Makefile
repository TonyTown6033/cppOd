
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -g
SRCS = minNum.cc
DATA = data.txt
OBJS = $(SRCS:.cc=.o)
TARGET = minNum

# 默认目标
all: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# 调试目标
debug: $(TARGET)
	gdb -x gdb_commands.txt ./$(TARGET)

# 清理规则
clean: 
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET) < $(DATA)


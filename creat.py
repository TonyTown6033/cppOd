import os

def create_project(project_name):
    # 创建项目文件夹
    project_dir = os.path.join(os.getcwd(), project_name)
    os.makedirs(project_dir)

    # 创建 Makefile 文件
    makefile_content = f'''
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -g
SRCS = {project_name}.cc
DATA = data.txt
OBJS = $(SRCS:.cc=.o)
TARGET = {project_name}

# 默认目标
all: $(SRCS)
\t$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# 调试目标
debug: $(TARGET)
\tgdb -x gdb_commands.txt ./$(TARGET)

# 清理规则
clean: 
\trm -f $(TARGET)

run: $(TARGET)
\t./$(TARGET) < $(DATA)

'''


    code_content = '''#include<iostream>
#include<string>
using namespace std;
int main(){
    string input1;
    string input2;

    while(true){
        getline(cin,input1);
        getline(cin,input2);

        cout << "hello python "<<endl;
        if (cin.eof() || cin.fail()) break;

    }

    return 0;
}
'''
    with open(os.path.join(project_dir, 'Makefile'), 'w') as f:
        f.write(makefile_content)

    # 创建项目代码文件
    with open(os.path.join(project_dir, f'{project_name}.cc'), 'w') as f:
        f.write(code_content)

    # 创建 data.txt 文件
    with open(os.path.join(project_dir, 'data.txt'), 'w') as f:
        pass

    # 创建 gdb_command.txt 文件
    with open(os.path.join(project_dir, 'gdb_commands.txt'), 'w') as f:
        pass

if __name__ == "__main__":
    project_name = input("请输入项目名：")
    create_project(project_name)

INC_DIR :=  ./
SRC_DIR = ./
#EXE_DIR := ./bin
CC := g++
CPPFLAGS := -std=c++11 -g -Wno-deprecated
LIBS :=  -lpthread
INC_FILE := $(addprefix -I, $(INC_DIR))
CPP_FILE :=  $(wildcard *.cc)
#OBJS_HPP :=$(wildcard  $(INC_DIR)/*.hpp) $(wildcard $(INC_DIR)/*.h)
TARGET := a.out
$(TARGET):$(CPP_FILE)
	$(CC) $(CPPFLAGS) -o $@ $(CPP_FILE) $(INC_FILE) $(LIBS)

clean:
	rm -rf $(TARGET)

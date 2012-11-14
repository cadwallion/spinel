BASEDIR = .
BUILD_DIR = ./build
TARGET := $(BUILD_DIR)/libspinel.a
CC = g++
ALL_CFLAGS = -g -Wall
OBJECT = $(patsubst %.cpp,%.o,$(wildcard $(BASEDIR)/src/*.cpp))
INCLUDES = -I$(BASEDIR)/src -I$(BASEDIR)/include -I$(BASEDIR)/lib
RM_F := rm -f

.PHONY : all
all : $(TARGET)

$(TARGET) : mruby $(OBJECT)
	$(AR) r $@ $(OBJECT) $(BASEDIR)/vendor/mruby/src/*.o $(BASEDIR)/vendor/mruby/mrblib/*.o

$(OBJECT) : %.o : %.cpp
	$(CC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@
	
.PHONY : mruby
mruby:
	$(MAKE) -C vendor/mruby

.PHONY : clean
clean :
	-$(RM_F) $(TARGET) $(OBJECT)
	-$(RM_F) $(OBJECT:.o=.d)
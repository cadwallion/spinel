BASEDIR = ..
BUILD_DIR = ../build
CC = g++
OBJECT = $(wildcard $(BASEDIR)/game/*.cpp)
INCLUDES = -I$(BASEDIR)/src -I$(BASEDIR)/include -L$(BUILD_DIR)
LIBS = -lspinel
CP_R := cp -r
RM_RF := rm -rf

.PHONY : all
all: 
	$(CC) $(OBJECT) $(INCLUDES) $(LIBS) -o $(BUILD_DIR)/game
	$(CP_R) $(BASEDIR)/game/scripts $(BUILD_DIR)
	$(CP_R) $(BASEDIR)/core $(BUILD_DIR)
	
.PHONY : clean
clean:
	-$(RM_RF) $(BUILD_DIR)/game
	-$(RM_RF) $(BUILD_DIR)/scripts
	-$(RM_RF) $(BUILD_DIR)/core
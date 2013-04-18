BASEDIR = .
BUILD_DIR = ./build
CC = g++
ALL_CFLAGS = -g -Wall
OBJECT = $(patsubst %.cpp,%.o,$(wildcard $(BASEDIR)/src/*.cpp))
INCLUDES = -I$(BASEDIR)/src -I$(BASEDIR)/include -I$(BASEDIR)/lib
RM_F := rm -f
ECHO := echo
MSG_BEGIN = @for line in
MSG_END = ; do echo "$$line"; done

.PHONY : all
all: engine game

.PHONY : engine
engine: $(BUILD_DIR)/libspinel.a

.PHONY : game
game: engine
	$(MAKE) -C game

$(BUILD_DIR)/libspinel.a : mruby $(OBJECT)
	$(AR) r $@ $(OBJECT) $(shell find $(BASEDIR)/vendor/mruby/build/host -type f -name '*.o')

$(OBJECT) : %.o : %.cpp
	$(CC) $(ALL_CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY : mruby
mruby:
	$(MAKE) -C vendor/mruby

.PHONY : clean
clean :
	-$(RM_F) $(TARGET) $(OBJECT)
	-$(RM_F) $(OBJECT:.o=.d)
	$(MAKE) -C game clean

distclean : clean
	$(MAKE) -C vendor/mruby clean

.PHONY : help
help:
	$(MSG_BEGIN) \
		"" \
		"	Spinel Makefile" \
		"" \
		"targets:" \
		"	all (default) - builds mruby, Spinel engine, and game demo" \
		"	engine - builds Spinel engine static library" \
		"	game - builds game demo using libspinel.a" \
		"	clean - clean Spinel engine and game artifacts and demo files" \
		"	distclean - clean mruby artifacts as well as Spinel artifacts/demo files" \
		$(MSG_END)
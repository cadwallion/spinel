# Spinel - Ruby-infused Game Engine

Spinel is a new free and open source game engine under development that utilizes [mruby](https://github.com/mruby/mruby/)
as its integral scripting layer. Under the hood is C/C++, however wherever possible the engine uses Ruby.

Included in the repo is the source of Spinel, as well as a demo application for testing the engine.

I want to stress that this is in **EARLY DEVELOPMENT**. What you see is the result of initial research
taken place during an Agora Games Hackathon in 24 hours.  Most of what you see will likely be rewritten,
but given the requirement of having a working demo in 24 hours, some temporary structures had to be put
in place.

## Installation

Spinel requires compiling mruby, and comes with mruby as a git submodule linked to working builds with Spinel.

```
git clone git://github.com/cadwallion/spinel.git
cd spinel
git submodule init && git submodule update
```

For compilation, spinel comes with an Xcode project.  For non-Xcode users, the project is compiled via make:

```
make [game|engine|mruby|all|distclean|help]
```

To build the game, either use the 'game' target in Xcode or run `make game`. If problems occur while compiling,
please run `make distclean` before running `make game`. Use `make help` for more information. Build output is
set to ./build/.

## Engine

The Engine is a static library containing core Engine configurations and the hooks for custom game development.
The primary components right now are Spinel::Engine and EngineSetup. Creating a game using Spinel requires
linking `libspinel.a` and including the `engine.h` header. See the code in `src/` for more information on how
to use Spinel in your own game.

## Game Demo

You'll find a demonstration of initializing an mruby VM within C++, loading source files into the VM, creation
of Ruby objects from C and inserting them into the VM, as well as Ruby-defined function calls from C. This
shows the capability of interoperability and the ability to maintain C/C++-level game constructs with Ruby-level
abstractions, as well as core class loading from both sides of the VM barrier. Note that script loading uses two
setup values in game/main.cpp: `script_diectory` and `core_directory`.  These are relative paths to the build path,
and the files will be copied to the build directory.

## Next Steps

Now that the hackathon is over, I'll begin ripping out the temporary constructs and being adding in the real
engine structure.  Some features on the top of the list:

* Game Loop Standardization
* Better structure of Scripting vs Core class loading
* Platform-specific Window Initialization Hooks
* Scene Manager Creation

## Contribution

Once I am further along in development I'll create a ROADMAP to help reflect where the project is going to make it
easier for contributions in line with where my head is taking this.  I am releasing the code as an effort to show
the progress to the public and use it as a talking piece as I find challenges with mruby/Ruby design along the
way.

That said, pull-requests with feature branches are welcome.

## Author

Created by [Andrew Nordman](https://github.com/cadwallion).  Announcement of project at RubyConf 2012, initial
development as part of [Agora Games](https://www.agoragames.com/) Hackathon X.

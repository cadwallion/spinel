# Spinel - Ruby-infused Game Engine

Spinel is a new free and open source game engine under development that utilizes [mruby](https://github.com/mruby/mruby/)
as its integral scripting layer. Under the hood is C/C++, however wherever possible the engine uses Ruby.

Included in the repo is the source of Spinel, as well as a demo application for testing the engine.

I want to stress that this is in *EARLY DEVELOPMENT*. What you see is the result of initial research
taken place during an Agora Games Hackathon in 24 hours.  Most of what you see will likely be rewritten,
but given the requirement of having a working demo in 24 hours, some temporary structures had to be put
in place.

This project uses a .xcodeproj which contains the two build targets of the game and the engine. The game
source is found in the game/ directory.

## Demo

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

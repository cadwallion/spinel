//
//  Created by Andrew Nordman on 11/9/12.
//  Copyright (c) 2012 Andrew Nordman. All rights reserved.
//
//
//  DEMO GAME IMPLEMENTATION
//
//  This is a quick demo of loading the Spinel Engine and starting the event loop. It loads
//  all core classes from the engine located in setup, and then loads any scripts. The premise
//  being that core will become packaged with the Engine and refactored to not be user-facing,
//  while the scripts directory will be the gateway to modding a game.
//
// This is far from complete, but serves as the jumping point for the engine from here on out.

#include <iostream>
#include "engine.h"

int main(int argc, const char * argv[])
{
  EngineSetup setup;
  setup.name = "Cad's Game";
  setup.script_directory = "scripts/";
  setup.core_directory = "core/";
  setup.game_class = "MyGame_Game";
  Spinel::Engine *engine = new Spinel::Engine(&setup);
  std::cout << "Loading Engine...\n";
  engine->Run();
  return 0;
}


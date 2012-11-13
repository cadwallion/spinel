//
//  Created by Andrew Nordman on 11/9/12.
//  Copyright (c) 2012 Andrew Nordman. All rights reserved.
//

#ifndef __spinel__engine__
#define __spinel__engine__

#include <iostream>
#include <mruby.h>
#include <mruby/proc.h>
#include <mruby/data.h>
#include <mruby/compile.h>
#include <mruby/variable.h>
#include <mruby/string.h>

struct EngineSetup {
  const char *name;
  const char *script_directory;
  const char *core_directory;
  const char *game_class;
  
  EngineSetup() {
    name = "Application";
    script_directory = "./script/";
    core_directory = "./core/";
    game_class = "Spinel_Game";
  }
};

namespace Spinel {
  class Engine {
  public:
    Engine(EngineSetup *s = NULL);
    ~Engine();
    void Run();
  private:
    EngineSetup *setup;
    mrb_state *mrb;
    mrbc_context *mrb_context;
    mrb_value game_object;
    
    void load_mrb();
    void load_mrb_file(const char*, const char*);
    void load_mrb_files_from_dir(const char*);
    void load_core_classes();
    void load_user_scripts();
    
    void load_game_object();
    void call_game_loop();
  };
}
#endif /* defined(__spinel__engine__) */

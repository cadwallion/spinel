//
//  Created by Andrew Nordman on 11/9/12.
//  Copyright (c) 2012 Andrew Nordman. All rights reserved.
//

#include "engine.h"
#include <iostream>
#include "unistd.h"
#include "dirent.h"
#include <string.h>

namespace Spinel {
  Engine::Engine(EngineSetup *s) {
    setup = new EngineSetup;
    
    if( s != NULL)
      memcpy( setup, s, sizeof(EngineSetup));
    
    load_mrb();
  }
  
  Engine::~Engine() {
    delete(setup);
    mrb_close(mrb);
    mrbc_context_free(mrb, mrb_context);
  }

  void Engine::Run() {
    load_game_object();
    for (int x = 0; x < 5; x++) {
      std::cout << "C++ RUN ITERATION #" << x << std::endl;
      mrb_funcall(mrb, game_object, "update", 0);
      sleep(1);
    }
  }
  
  void Engine::load_mrb() {
    mrb = mrb_open();
    // mrb_context: Debugger context
    mrb_context = mrbc_context_new(mrb);
    mrb_context->capture_errors = 0;
    mrb_context->dump_result = 0;
    mrb_context->no_exec = 0;
    
    load_core_classes();
    load_user_scripts();
  }
  
  void Engine::load_user_scripts() {
    load_mrb_files_from_dir(setup->script_directory);
  }
  
  void Engine::load_core_classes() {
    load_mrb_files_from_dir(setup->core_directory);
  }
  
  void Engine::load_mrb_files_from_dir(const char *directory) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(directory);
    
    if (dir != NULL) {
      while ((ent = readdir(dir)) != NULL) {
        if (strstr(ent->d_name, ".rb")) {
          load_mrb_file(directory, ent->d_name);
        }
      }
    }
  }
  
  void Engine::load_mrb_file(const char *file_path, const char *filename) {
    char path[1024];
    
    strcpy(path, file_path);
    strcat(path, filename);
    
    FILE *file;
    
    file = fopen((const char*)path, "r");
    mrb_load_file_cxt(mrb, file, mrb_context);
    std::cout << path << " loaded." << std::endl;
    fclose(file);
  }
  
  void Engine::load_game_object() {
    RClass *klass = mrb_class_get(mrb, setup->game_class);
    mrb_value argv[2];
    game_object = mrb_class_new_instance(mrb, 0, argv, klass);
    mrb_define_global_const(mrb, "GAME_OBJ", game_object);
  }
}
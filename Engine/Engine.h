#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <functional>

#include "Wrapper.h"


class Engine {
    std::unordered_map<std::string, const Wrapper*> commands;

public:
    void register_command(const Wrapper* wrapper, const std::string& name) {
        commands[name] = wrapper;
    }

    std::string execute(const std::string& command_name, const Wrapper::ArgMap& args);
};
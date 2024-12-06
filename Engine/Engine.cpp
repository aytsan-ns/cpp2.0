#include "Engine.h"


std::string Engine::execute(const std::string& command_name, const Wrapper::ArgMap& args) {
    auto it = commands.find(command_name);
    if (it != commands.end()) {
        return (*(it->second))(args);
    }
    throw std::runtime_error("Command not found: " + command_name);
}
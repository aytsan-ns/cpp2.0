#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <functional>

class Wrapper {
public:
    using ArgMap = std::unordered_map<std::string, std::string>;

    template <typename Object, typename Method> Wrapper(Object* obj, Method method, ArgMap default_args)
        : func([=](const ArgMap& args) -> std::string {
        ArgMap merged_args = default_args;
        for (const auto& [key, value] : args)
            merged_args[key] = value;

        return std::invoke(method, obj, merged_args);
            }) {}

    std::string operator()(const ArgMap& args) const {
        return func(args);
    }

private:
    std::function<std::string(const ArgMap&)> func;
};
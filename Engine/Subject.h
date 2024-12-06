#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <functional>
#include <filesystem>

#include "Engine.h"
#include "Wrapper.h"


class Subject {
public:

    std::string replace_words(const Wrapper::ArgMap& args);  // Замена слов в файле

    std::string find_phrase(const Wrapper::ArgMap& args);  // Поиск словосочетаний

    std::string capitalize_words(const Wrapper::ArgMap& args);  // Преобразование первых букв слов в заглавные

    std::string capitalize_sentences(const Wrapper::ArgMap& args);  // Преобразование первых букв предложений в заглавные

    std::string add_numbering(const Wrapper::ArgMap& args);  // Добавление нумерации предложений

private:

    std::string read_file(const std::string& file_path);  // Чтение содержимого файла

    void write_file(const std::string& file_path, const std::string& text);  // Запись содержимого в файл
};
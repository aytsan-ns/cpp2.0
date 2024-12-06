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

    std::string replace_words(const Wrapper::ArgMap& args);  // ������ ���� � �����

    std::string find_phrase(const Wrapper::ArgMap& args);  // ����� ��������������

    std::string capitalize_words(const Wrapper::ArgMap& args);  // �������������� ������ ���� ���� � ���������

    std::string capitalize_sentences(const Wrapper::ArgMap& args);  // �������������� ������ ���� ����������� � ���������

    std::string add_numbering(const Wrapper::ArgMap& args);  // ���������� ��������� �����������

private:

    std::string read_file(const std::string& file_path);  // ������ ����������� �����

    void write_file(const std::string& file_path, const std::string& text);  // ������ ����������� � ����
};
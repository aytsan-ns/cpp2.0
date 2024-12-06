#include <iostream>
#include <fstream>
#include <filesystem>

#include "Engine.h"
#include "Wrapper.h"
#include "Subject.h"



int main(int argc, char* argv[]) {
    if (argc < 3) { // необходимо минимум 3 аргумента: программа, путь к файлу, команда
        std::cerr << "Usage: " << argv[0] << " <file_path> <command> <args>..." << std::endl;
        return 1;
    }

    std::string file_path = argv[1];
    std::string command = argv[2];

    // существование файла
    if (!std::filesystem::exists(file_path)) {
        std::cerr << "Error: File not found: " << file_path << std::endl;
        return 1;
    }

    try {
        Subject subj;
        Engine engine;

        // регистраци€ команд
        Wrapper replace_wrapper(&subj, &Subject::replace_words, { {"file_path", file_path}, {"target", ""}, {"replacement", ""} });
        Wrapper find_wrapper(&subj, &Subject::find_phrase, { {"file_path", file_path}, {"phrase", ""} });
        Wrapper capitalize_words_wrapper(&subj, &Subject::capitalize_words, { {"file_path", file_path} });
        Wrapper capitalize_sentences_wrapper(&subj, &Subject::capitalize_sentences, { {"file_path", file_path} });
        Wrapper numbering_wrapper(&subj, &Subject::add_numbering, { {"file_path", file_path} });

        engine.register_command(&replace_wrapper, "replace");
        engine.register_command(&find_wrapper, "find");
        engine.register_command(&capitalize_words_wrapper, "capitalize_words");
        engine.register_command(&capitalize_sentences_wrapper, "capitalize_sentences");
        engine.register_command(&numbering_wrapper, "numbering");

        // аргументы команды
        Wrapper::ArgMap args = { {"file_path", file_path} };

        for (int i = 3; i < argc; i += 2) {
            if (i + 1 < argc) {
                args[argv[i]] = argv[i + 1]; // argv[i] Ч ключ, argv[i + 1] Ч значение
            }
            else {
                std::cerr << "Error: Argument '" << argv[i] << "' has no value" << std::endl;
                return 1;
            }
        }

        std::cout << engine.execute(command, args) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
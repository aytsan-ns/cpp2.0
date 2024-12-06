#include "Subject.h"

std::string Subject::replace_words(const Wrapper::ArgMap& args) {
    std::string text = read_file(args.at("file_path"));
    std::string target = args.at("target");
    std::string replacement = args.at("replacement");

    // Замена всех вхождений слова
    size_t pos = 0;
    while ((pos = text.find(target, pos)) != std::string::npos) {
        text.replace(pos, target.length(), replacement);
        pos += replacement.length();
    }

    write_file(args.at("file_path"), text);
    return "Words replaced successfully.";
}

std::string Subject::find_phrase(const Wrapper::ArgMap& args) {
    std::string text = read_file(args.at("file_path"));
    std::string phrase = args.at("phrase");
    return text.find(phrase) != std::string::npos ? "Phrase found." : "Phrase not found.";
}

std::string Subject::capitalize_words(const Wrapper::ArgMap& args) {
    std::string text = read_file(args.at("file_path"));
    bool capitalize = true;
    for (char& c : text) {
        if (capitalize && std::isalpha(c)) {
            c = std::toupper(c);
            capitalize = false;
        }
        if (std::isspace(c)) {
            capitalize = true;
        }
    }
    write_file(args.at("file_path"), text);
    return "Words capitalized successfully.";
}

std::string Subject::capitalize_sentences(const Wrapper::ArgMap& args) {
    std::string text = read_file(args.at("file_path"));
    bool capitalize = true;
    for (char& c : text) {
        if (capitalize && std::isalpha(c)) {
            c = std::toupper(c);
            capitalize = false;
        }
        if (c == '.' || c == '?' || c == '!') {
            capitalize = true;
        }
    }
    write_file(args.at("file_path"), text);
    return "Sentences capitalized successfully.";
}

std::string Subject::add_numbering(const Wrapper::ArgMap& args) {
    std::string text = read_file(args.at("file_path"));
    std::istringstream iss(text);
    std::ostringstream oss;

    std::string sentence;
    int number = 1;
    while (std::getline(iss, sentence, '.')) {
        if (!sentence.empty()) {
            oss << number++ << ". " << sentence << ".\n";
        }
    }

    write_file(args.at("file_path"), oss.str());
    return "Sentences numbered successfully.";
}

std::string Subject::read_file(const std::string& file_path) {
    if (!std::filesystem::exists(file_path)) {
        throw std::runtime_error("Error: File does not exist: " + file_path);
    }

    std::ifstream file_in(file_path);
    if (!file_in.is_open()) {
        throw std::runtime_error("Error: Could not open file: " + file_path);
    }
    std::ostringstream content;
    content << file_in.rdbuf();
    return content.str();
}

void Subject::write_file(const std::string& file_path, const std::string& text) {
    std::ofstream file_out(file_path);
    if (!file_out.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + file_path);
    }
    file_out << text;
}
#include "facebook.hpp"

Facebook::Facebook(const std::string& connections) {  ///reading in a file
  std::ifstream ifs{connections}; //take in file

  for (std::string line; std::getline(ifs, line); line = "") {
    std::vector<std::string> get_substr_vector = Breakln(line, ' ');
    int keep_first = stoi(get_substr_vector.at(0));
    adj_vect_.push_back(keep_first);
  }


std::vector<std::string> Facebook::Breakln(const std::string& str, char delimiter) {
    size_t last = 0;
    std::vector<std::string> substrs;
    for (size_t i = 0; i != str.length(); ++i) {
        if (str.at(i) == delimiter || str.at(i) == '\r') {
        std::string substr = str.substr(last, i - last);
        last = i + 1;
        substrs.push_back(substr);
        }
    }

    if (last != str.size()) {
        std::string substr = str.substr(last, str.length() - last);
        substrs.push_back(substr);
    }

    return substrs;
}
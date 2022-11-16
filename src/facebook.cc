#include "facebook.hpp"

Facebook::Facebook(const std::string &connections)
{                                 /// reading in a file
  std::ifstream ifs{connections}; // take in file

  for (std::string line; std::getline(ifs, line); line = "")
  {
    std::vector<int> get_substr_vector = GetSub(line, ' ');
    // int keep_first = stoi(get_substr_vector.at(0));
    adj_vect_.push_back(get_substr_vector);
  }
}

void Facebook::DisplayOut()
{
  for (int i = 0; i < adj_vect_.size(); i++)
  {
    for (int j = 0; j < adj_vect_[i].size(); j++)
      cout << adj_vect_[i][j] << " ";
    cout << '\n';
  }
}

std::vector<int> Facebook::GetSub(const std::string &str, char delimiter)
{
  size_t last = 0;
  std::vector<int> substrs;
  for (size_t i = 0; i != str.length(); ++i)
  {
    if (str.at(i) == delimiter || str.at(i) == '\r')
    {
      std::string substr = str.substr(last, i - last);
      last = i + 1;
      substrs.push_back(std::stoi(substr));
    }
  }

  if (last != str.size())
  {
    std::string substr = str.substr(last, str.length() - last);
    substrs.push_back(std::stoi(substr));
  }

  return substrs;
}

std::vector<std::vector<int>> Facebook::getAV()
{
  return adj_vect_;
}
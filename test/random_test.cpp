#include <iostream>
#include <map>
#include <random>

using namespace std;

int main() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::map<int, int> hist;
  std::uniform_int_distribution<int> dist(1, 6);

  cout << "rolling the dice..." << endl;

  for (int n = 0; n < 20000; ++n) {
    ++hist[dist(gen)+dist(gen)]; // note: demo only: the performance of many 
                      // implementations of random_device degrades sharply
                      // once the entropy pool is exhausted.  For practical
                      // use random_device is generally only used to seed 
                      // a PRNG such as mt19937
  }
  for (auto& p : hist) {
    std::cout << p.first << " : " << std::string(p.second/100, '*') << '\n';
  }
 
  for (auto& p : hist) {
    std::cout << p.first << " : " << p.second << '\n';
  }
 
}


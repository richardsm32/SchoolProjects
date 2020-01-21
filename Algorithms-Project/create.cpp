#include <random>
#include <string>
#include <fstream>
#include <iostream>

void createData(int npoints) {
  std::random_device rdm;
  std::uniform_int_distribution<int> d(-10000, 10000);
  std::ofstream file;
  std::string ptstring = std::to_string(npoints);
  std::string filename = "output" + ptstring + ".txt";
  file.open(filename);
  for(int i = 0; i < npoints; i++) {
    int x = d(rdm);
    int y = d(rdm);
    file << x << " " << y << "\n";
  }
  file.close();

}

int main() {
  int npoints;
  std::cout << "Please enter the amount of points you want: " << std::endl;
  std::cin >> npoints;
  createData(npoints);
  return 0;
}

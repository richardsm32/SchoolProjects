#include <chrono>
#include <climits>
#include <ctime>
#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>

class Point {
public:
  int xaxis;
  int yaxis;
};

std::vector<Point*> points;

bool loadData(std::string filename) {
  std::ifstream file(filename);
  bool fexists = false;
  if(!file.good()) {
    std::cout << "That file does not exist" << std::endl;
  } else {
    bool check = true;
    while (check == true) {
      Point* temppoint = new Point;
      int x, y;
      file >> x >> y;
      if (file.eof()) {
        check = false;
      } else {
      temppoint->xaxis = x;
      temppoint->yaxis = y;
      points.push_back(temppoint);
      }
    }
    fexists = true;
  }
  return fexists;
}

void bruteforce() {
  auto t1 = std::chrono::high_resolution_clock::now();
  double dmin = std::numeric_limits<double>::max();
  int p1, p2;
  int psize = points.size();
  for(int i = 0; i < psize; i++) {
    for(int j = i+1; j < psize; j++){
      int x1 = points[i]->xaxis;
      int x2 = points[j]->xaxis;
      int y1 = points[i]->yaxis;
      int y2 = points[j]->yaxis;
      double d =  sqrt((pow((x1-x2),2)) + (pow((y1-y2),2)));
      if (d < dmin) {
        dmin = d;
        p1 = i;
        p2 = j;
      }
    }
  }
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  int p1x, p1y, p2x, p2y;
  p1x = points[p1]->xaxis;
  p1y = points[p1]->yaxis;
  p2x = points[p2]->xaxis;
  p2y = points[p2]->yaxis;
  std::cout << "Point 1 is -> x: " << p1x << " y: " << p1y <<std::endl;
  std::cout << "Point 2 is -> x: " << p2x << " y: " << p2y <<std::endl;
  std::cout << "The closest distance is -> " << dmin <<std::endl;
  std::cout << "The duration of the calculation is " << duration << " microseconds."<<std::endl;

}

int main() {
  std::string filename;
  std::cout << "Which file would you like to use?" << std::endl;
  std:: cin >> filename;
  if(loadData(filename) == true) {
    bruteforce();
  }
  return 0;
}

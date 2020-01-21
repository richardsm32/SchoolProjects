#include <chrono>
#include <algorithm>
#include <limits>
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

bool xcomp(Point* a, Point* b) {
    return a->xaxis < b->xaxis;
}

bool ycomp(Point* a, Point* b) {
    return a->yaxis < b->yaxis;
}

std::pair<double,std::pair<Point*, Point*>> findD (int psize, std::vector<Point*> temppoints) {
  double dmin = std::numeric_limits<double>::max();
  int p1, p2;
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
  Point* point1 = temppoints[p1];
  Point* point2 = temppoints[p2];
  std::pair<Point*, Point*> pairpoint(point1, point2);
  std::pair<int, std::pair<Point*, Point*>> dpair(dmin, pairpoint);
  return dpair;
}

std::vector<Point*> copy (std::vector<Point*> p, int begin, int end) {
  std::vector<Point*> tempvec;
    for(int i = begin; i < end; i++) {
      tempvec.push_back(p[i]);
    }
  return tempvec;
}

std::pair<double, std::pair<Point*, Point*>> middlePair(double min, std::vector<Point*> temppoints, int mid) {
    double dmin = min;
    std::sort(temppoints.begin(), temppoints.end(), ycomp);
    int p1, p2;
    int size = temppoints.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i+1; j < size && (temppoints[j]->yaxis - temppoints[i]->yaxis) < dmin; ++j) {
            int x1 = temppoints[i]->xaxis;
            int x2 = temppoints[j]->xaxis;
            int y1 = temppoints[i]->yaxis;
            int y2 = temppoints[j]->yaxis;
            int d =  sqrt((pow((x1-x2),2)) + (pow((y1-y2),2)));
            if (d < dmin) {
                  dmin = d;
                  p1 = i;
                  p2 = j;
                }
        }
    }
    Point* point1 = temppoints[p1];
    Point* point2 = temppoints[p2];
    std::pair<Point*, Point*> pairpoint(point1, point2);
    std::pair<int, std::pair<Point*, Point*>> dpair(dmin, pairpoint);
    return dpair;
}

std::pair<double,std::pair<Point*, Point*>> closestPair(int numpoints, std::vector<Point*> temppoints) {
  double dmin = std::numeric_limits<double>::max();
  std::pair<double, std::pair<Point*, Point*>> dminPair;
  if(numpoints < 4) {
     return findD(numpoints, temppoints);
  } else {
    int c  = (numpoints/2);
    std::vector<Point*> leftpoints = copy(points, 0, c);
    std::vector<Point*> rightpoints = copy(points, c, temppoints.size());
    int leftnum = leftpoints.size();
    int rightnum = rightpoints.size();
    std::pair<double, std::pair<Point*, Point*>> pair1 = closestPair(leftnum, leftpoints);
    std::pair<double, std::pair<Point*, Point*>> pair2 = closestPair(rightnum, rightpoints);
    int d1 = pair1.first;
    if(d1 < dmin) {
        dminPair.first = pair1.first;
        dminPair.second.first = pair1.second.first;
        dminPair.second.second = pair1.second.second;
    } else {
      dminPair.first = pair2.first;
      dminPair.second.first = pair2.second.first;
      dminPair.second.second = pair2.second.second;
    }
    std::pair<double, std::pair<Point*, Point*>> midPair = middlePair(dmin, temppoints, c);
    int d2 = midPair.first;
    if (d2 < dmin) {
      dminPair.first = midPair.first;
      dminPair.second.first = midPair.second.first;
      dminPair.second.second = midPair.second.second;
    }
    return dminPair;
  }
}


void divideconquer() {
  auto t1 = std::chrono::high_resolution_clock::now();
  ////////////////////////////////////////////////////////////////////////////
  //                  divide and conquer code
  std::sort(points.begin(), points.end(), xcomp);
  int numpoints = points.size();
  std::vector<Point*> temppoints;
  temppoints = points;
  std::pair<double, std::pair<Point*, Point*>> closePair = closestPair(numpoints, temppoints);
  //
  ///////////////////////////////////////////////////////////////////////////
  auto t2 = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  int p1x, p1y, p2x, p2y;
  double d;
  d = closePair.first;
  Point* p1 = closePair.second.first;
  Point* p2 = closePair.second.second;
  p1x = p1->xaxis;
  p1y = p1->yaxis;
  p2x = p2->xaxis;
  p2y = p2->yaxis;
  std::cout << "Point 1 is -> x: " << p1x << " y: " << p1y <<std::endl;
  std::cout << "Point 2 is -> x: " << p2x << " y: " << p2y <<std::endl;
  std::cout << "The distance is -> " << d <<std::endl;
  std::cout << "The duration of the calculation is " << duration << " microseconds."<<std::endl;
}

int main() {
  std::string filename;
  std::cout << "Which file would you like to use?" << std::endl;
  std:: cin >> filename;
  if(loadData(filename) == true) {
    divideconquer();
  }
  return 0;
}

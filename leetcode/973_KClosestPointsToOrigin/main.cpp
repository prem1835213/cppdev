#include <queue>
#include <vector>
#include <iostream>
#include <cmath>

/*
    Given an array of points where points[i] = [x_i, y_i] represents a point on the X-Y plane
    and an integer k, return the k closest points to the origin [0, 0].

    The answer is guaranteed to be unique, except for the order that it is in.
*/

struct Point{
    int x;
    int y;
    float magnitude;
    Point() : x(0), y(0), magnitude(0){}
    Point(int x, int y){
        this->x = x;
        this->y = y;
        this->magnitude = std::sqrt(x*x + y*y);
    }

    friend bool const operator<(const Point& left, const Point& right){
        return left.magnitude < right.magnitude;
    }
};

std::vector<std::vector<int>> kClosestPoints(std::vector<std::vector<int>>& points, int k){
    int size = 0;
    std::priority_queue<Point> maxHeap;
    for (int i = 0; i < points.size(); i++){
        const Point p = Point(points[i][0], points[i][1]);
        if (size < k){
            maxHeap.push(p);
            size++;
        }
        else if (p < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(p);
        }
    }

    std::vector<std::vector<int>> kClosest;
    for (int i = 0; i < k; i++){
        const Point p = maxHeap.top();
        maxHeap.pop();
        std::vector<int> v = {p.x, p.y};
        kClosest.push_back(v);
    }

    return kClosest;
}

int main(){
    std::vector<std::vector<int>> points = {{1, 1}, {2, 2}, {1, 2}};
    int k = 2;
    std::vector<std::vector<int>> kClosest = kClosestPoints(points, k);
    for (int i = 0; i < k; i++){
        std::cout << kClosest[i][0] << ", " << kClosest[i][1] << std::endl;
    }
}
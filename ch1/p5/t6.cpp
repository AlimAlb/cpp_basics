#include <iostream>
#include <vector>
#include <algorithm>

struct Point
{
    int x;
    int y;
};

bool Compare(const Point& point1, const Point& point2){
    return (point1.x*point1.x + point1.y*point1.y) < (point2.x*point2.x + point2.y*point2.y);
}

int main(){
    size_t n;
    std::cin >> n;
    std::vector<Point> points;
    for (size_t i = 0; i != n; i++)
    {
        int x,y;
        scanf("%d %d", &x, &y);
        Point point;
        point.x = x;
        point.y = y;
        points.push_back(point);        
    }
    std::sort(points.begin(), points.end(), Compare);


    for (size_t i = 0; i != points.size(); i++)
    {
        std::cout << points[i].x << ' ' << points[i].y << '\n';
    }
}

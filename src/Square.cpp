#include "../include/Square.h"
#include <stdexcept>

namespace {

double dist2(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

bool isSquare(const Point& p1,const Point& p2, const Point& p3,const Point& p4) {
    double d = dist2(p1,p2);
    return d!=0 &&
           d==dist2(p2,p3) &&
           d==dist2(p3,p4) &&
           d==dist2(p4,p1) &&
           dist2(p1,p3)==dist2(p2,p4);
}

}

Square::Square(const Point& a,const Point& b, const Point& c,const Point& d) : Rectangle(a,b,c,d) {
    if (!isSquare(a,b,c,d))
        throw std::invalid_argument("Invalid square");
}

double Square::area() const {
    return dist2(p1,p2);
}

void Square::print(std::ostream& os) const {
    os << "Square: ("<<p1.x<<","<<p1.y<<"), (" <<p2.x<<","<<p2.y<<"), ("
       <<p3.x<<","<<p3.y<<"), (" <<p4.x<<","<<p4.y<<")";
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

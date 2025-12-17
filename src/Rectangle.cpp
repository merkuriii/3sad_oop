#include "../include/Rectangle.h"
#include <cmath>
#include <stdexcept>

namespace {

double dist2(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

double dot(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.x - b.x)
         + (b.y - a.y) * (c.y - b.y);
}

bool isRectangle(const Point& p1, const Point& p2,
                 const Point& p3, const Point& p4) {
    if (dist2(p1,p2)==0 || dist2(p2,p3)==0 ||
        dist2(p3,p4)==0 || dist2(p4,p1)==0)
        return false;

    if (dot(p1,p2,p3)!=0 || dot(p2,p3,p4)!=0 ||
        dot(p3,p4,p1)!=0 || dot(p4,p1,p2)!=0)
        return false;

    if (dist2(p1,p2)!=dist2(p3,p4)) return false;
    if (dist2(p2,p3)!=dist2(p4,p1)) return false;
    if (dist2(p1,p3)!=dist2(p2,p4)) return false;

    return true;
}

}

Rectangle::Rectangle(const Point& a,const Point& b, const Point& c,const Point& d)
    : p1(a),p2(b),p3(c),p4(d) {
    if (!isRectangle(p1,p2,p3,p4))
        throw std::invalid_argument("Invalid rectangle");
}

Point Rectangle::center() const {
    return {(p1.x+p2.x+p3.x+p4.x)/4.0,
            (p1.y+p2.y+p3.y+p4.y)/4.0};
}

double Rectangle::area() const {
    return std::sqrt(dist2(p1,p2)) * std::sqrt(dist2(p2,p3));
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: ("<<p1.x<<","<<p1.y<<"), (" <<p2.x<<","<<p2.y<<"), ("
       <<p3.x<<","<<p3.y<<"), (" <<p4.x<<","<<p4.y<<")";
}

void Rectangle::read(std::istream& is) {
    is >> p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
    if (!isRectangle(p1,p2,p3,p4))
        throw std::invalid_argument("Invalid rectangle input");
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(&other);
    return r && p1==r->p1 && p2==r->p2 && p3==r->p3 && p4==r->p4;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

Rectangle::Rectangle(const Rectangle& o): p1(o.p1),p2(o.p2),p3(o.p3),p4(o.p4) {}
Rectangle::Rectangle(Rectangle&& o) noexcept
    : p1(std::move(o.p1)),p2(std::move(o.p2)),
      p3(std::move(o.p3)),p4(std::move(o.p4)) {}

Rectangle& Rectangle::operator=(const Rectangle& o) {
    p1=o.p1; p2=o.p2; p3=o.p3; p4=o.p4; return *this;
}
Rectangle& Rectangle::operator=(Rectangle&& o) noexcept {
    p1=std::move(o.p1); p2=std::move(o.p2);
    p3=std::move(o.p3); p4=std::move(o.p4); return *this;
}

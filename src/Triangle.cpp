#include "../include/Triangle.h"
#include <cmath>
#include <stdexcept>

namespace {

double area2(const Point& a, const Point& b, const Point& c) {
    return a.x * (b.y - c.y)
         + b.x * (c.y - a.y)
         + c.x * (a.y - b.y);
}

bool isTriangle(const Point& p1, const Point& p2, const Point& p3) {
    if (p1 == p2 || p1 == p3 || p2 == p3)
        return false;
    return area2(p1, p2, p3) != 0;
}

}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3)
    : p1(p1), p2(p2), p3(p3) {
    if (!isTriangle(p1, p2, p3))
        throw std::invalid_argument("Invalid triangle");
}

Point Triangle::center() const {
    return {(p1.x + p2.x + p3.x) / 3.0,
            (p1.y + p2.y + p3.y) / 3.0};
}

double Triangle::area() const {
    return std::abs(area2(p1, p2, p3)) / 2.0;
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: (" << p1.x << "," << p1.y << "), ("
       << p2.x << "," << p2.y << "), ("
       << p3.x << "," << p3.y << ")";
}

void Triangle::read(std::istream& is) {
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    if (!isTriangle(p1, p2, p3))
        throw std::invalid_argument("Invalid triangle input");
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(&other);
    if (!t) return false;

    return ((p1 == t->p1 && p2 == t->p2 && p3 == t->p3) ||
            (p1 == t->p1 && p2 == t->p3 && p3 == t->p2) ||
            (p1 == t->p2 && p2 == t->p1 && p3 == t->p3) ||
            (p1 == t->p2 && p2 == t->p3 && p3 == t->p1) ||
            (p1 == t->p3 && p2 == t->p1 && p3 == t->p2) ||
            (p1 == t->p3 && p2 == t->p2 && p3 == t->p1));
}

std::unique_ptr<Figure> Triangle::clone() const {
    return std::make_unique<Triangle>(*this);
}

Triangle::Triangle(const Triangle& o) : p1(o.p1), p2(o.p2), p3(o.p3) {}
Triangle::Triangle(Triangle&& o) noexcept
    : p1(std::move(o.p1)), p2(std::move(o.p2)), p3(std::move(o.p3)) {}

Triangle& Triangle::operator=(const Triangle& o) {
    p1 = o.p1; p2 = o.p2; p3 = o.p3; return *this;
}
Triangle& Triangle::operator=(Triangle&& o) noexcept {
    p1 = std::move(o.p1);
    p2 = std::move(o.p2);
    p3 = std::move(o.p3);
    return *this;
}

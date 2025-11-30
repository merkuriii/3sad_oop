#include "../include/Triangle.h"
#include <cmath>
#include <sstream>

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) 
    : p1(p1), p2(p2), p3(p3) {}

Point Triangle::center() const {
    return Point((p1.x + p2.x + p3.x) / 3, (p1.y + p2.y + p3.y) / 3);
}

double Triangle::area() const {
    return std::abs((p1.x * (p2.y - p3.y) + p2.x*(p3.y - p1.y) + p3.x*(p1.y - p2.y)) / 2);
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: (" << p1.x << "," << p1.y << "), " << "(" 
       << p2.x << "," << p2.y << "), " << "(" << p3.x << "," << p3.y << ")";
}

void Triangle::read(std::istream& is) {
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* t = dynamic_cast<const Triangle*>(&other);
    if (!t) return false;

    // проверяем все комбинации вершин (треугольники могут быть одинаковыми при разном порядке)
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

Triangle::Triangle(const Triangle& other) :p1(other.p1), p2(other.p2), p3(other.p3) {}

Triangle::Triangle(Triangle&& other) noexcept 
    : p1(std::move(other.p1)), p2(std::move(other.p2)), p3(std::move(other.p3)) {}

Triangle& Triangle::operator=(const Triangle& other) {
    if (this != &other) {
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
    }
    return *this;
}

Triangle& Triangle::operator=(Triangle&& other) noexcept {
    if (this != &other) {
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
    }
    return *this;
}
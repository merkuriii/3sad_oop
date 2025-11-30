#include "../include/Square.h"
#include <cmath>
#include <algorithm>

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : p1(p1), p2(p2), p3(p3), p4(p4) {}

Point Square::center() const {
    return Point((p1.x + p2.x + p3.x + p4.x) / 4,
                 (p1.y + p2.y + p3.y + p4.y) / 4);
}

double Square::area() const {
    double side = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    return side * side;
}

void Square::print(std::ostream& os) const {
    os << "Square: (" << p1.x << "," << p1.y << "), "
       << "(" << p2.x << "," << p2.y << "), "
       << "(" << p3.x << "," << p3.y << "), "
       << "(" << p4.x << "," << p4.y << ")";
}

void Square::read(std::istream& is) {
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
}

bool Square::operator==(const Figure& other) const {
    const Square* s = dynamic_cast<const Square*>(&other);
    if (!s) return false;

    return p1 == s->p1 && p2 == s->p2 && p3 == s->p3 && p4 == s->p4;
}

std::unique_ptr<Figure> Square::clone() const {
    return std::make_unique<Square>(*this);
}

Square::Square(const Square& other) 
    : p1(other.p1), p2(other.p2), p3(other.p3), p4(other.p4) {}

Square::Square(Square&& other) noexcept
    : p1(std::move(other.p1)), p2(std::move(other.p2)), p3(std::move(other.p3)), p4(std::move(other.p4)) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
        p4 = other.p4;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if (this != &other) {
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
    }
    return *this;
}
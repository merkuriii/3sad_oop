#include "../include/Rectangle.h"
#include <cmath>

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : p1(p1), p2(p2), p3(p3), p4(p4) {}

Point Rectangle::center() const {
    return Point((p1.x + p2.x + p3.x + p4.x) / 4,
                 (p1.y + p2.y + p3.y + p4.y) / 4);
}

double Rectangle::area() const {
    double width = std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
    double height = std::sqrt(std::pow(p4.x - p1.x, 2) + std::pow(p4.y - p1.y, 2));
    return width * height;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: (" << p1.x << "," << p1.y << "), " << "(" 
       << p2.x << "," << p2.y << "), " << "(" << p3.x << "," 
       << p3.y << "), " << "(" << p4.x << "," << p4.y << ")";
}

void Rectangle::read(std::istream& is) {
    is >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* r = dynamic_cast<const Rectangle*>(&other);
    if (!r) return false;

    return p1 == r->p1 && p2 == r->p2 && p3 == r->p3 && p4 == r->p4;
}

std::unique_ptr<Figure> Rectangle::clone() const {
    return std::make_unique<Rectangle>(*this);
}

Rectangle::Rectangle(const Rectangle& other) :p1(other.p1), p2(other.p2), p3(other.p3), p4(other.p4) {}

Rectangle::Rectangle(Rectangle&& other) noexcept 
    : p1(std::move(other.p1)), p2(std::move(other.p2)), 
      p3(std::move(other.p3)), p4(std::move(other.p4)) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        p1 = other.p1;
        p2 = other.p2;
        p3 = other.p3;
        p4 = other.p4;
    }
    return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        p1 = std::move(other.p1);
        p2 = std::move(other.p2);
        p3 = std::move(other.p3);
        p4 = std::move(other.p4);
    }
    return *this;
}
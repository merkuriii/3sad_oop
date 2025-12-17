#pragma once
#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square() = default;
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    double area() const override;
    void print(std::ostream& os) const override;

    std::unique_ptr<Figure> clone() const override;
};
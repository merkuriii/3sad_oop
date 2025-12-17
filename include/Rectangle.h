#pragma once
#include "Figure.h"

class Rectangle : public Figure {
protected:
    Point p1, p2, p3, p4;

public:
    Rectangle() = default;
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    Point center() const override;
    double area() const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

    Rectangle(const Rectangle& other);
    Rectangle(Rectangle&& other) noexcept;

    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
};

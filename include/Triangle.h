#pragma once 
#include "Figure.h"

class Triangle : public Figure {
private:
    Point p1, p2, p3;

public:
    Triangle() {};
    Triangle(const Point& p1, const Point& p2, const Point& p3);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

    Triangle(const Triangle& other);
    Triangle(Triangle&& other) noexcept;
    Triangle& operator=(const Triangle& other);
    Triangle& operator=(Triangle&& other) noexcept;
};

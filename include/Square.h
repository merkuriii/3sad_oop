#pragma once 
#include "Figure.h"

class Square : public Figure {
private:
    Point p1, p2, p3, p4;

public:
    Square() {};
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

    bool operator==(const Figure& other) const override;
    std::unique_ptr<Figure> clone() const override;

    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
};
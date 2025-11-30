#pragma once 
#include <iostream>
#include <memory>

class Point {
public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class Figure {
public:
    virtual ~Figure() = default;

    virtual Point center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    virtual bool operator==(const Figure& other) const = 0;
    virtual std::unique_ptr<Figure> clone() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.print(os);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Figure& fig) {
        fig.read(is);
        return is;
    }

    explicit operator double() const {
        return area();
    }
};
#include <gtest/gtest.h>
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"

TEST(TriagleTest, AreaCalculation) {
    Triangle t(Point(0,0), Point(1,0), Point(0,1));
    EXPECT_DOUBLE_EQ(t.area(), 0.5);
}

TEST(TriagleTEST, CenterCalculation) {
    Triangle t(Point(0,0), Point(3,0), Point(0,3));
    Point center = t.center();
    EXPECT_DOUBLE_EQ(center.x, 1.0);
    EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST(SquareTest, AreaCalculation) {
    Square s(Point(0,0), Point(1,0), Point(1,1), Point(0,1));
    EXPECT_DOUBLE_EQ(s.area(), 1.0);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle r(Point(0,0), Point(2,0), Point(2,1), Point(0,1));
    EXPECT_DOUBLE_EQ(r.area(), 2.0);
}

TEST(FigureTest, DoubleConversion) {
    Triangle t(Point(0,0), Point(1,0), Point(0,1));
    double area = double(t);
    EXPECT_DOUBLE_EQ(area, 0.5);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
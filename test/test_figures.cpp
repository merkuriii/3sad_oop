#include <gtest/gtest.h>
#include <sstream>
#include <memory>
#include "../include/Figure.h"
#include "../include/Triangle.h"
#include "../include/Square.h"
#include "../include/Rectangle.h"

TEST(TriangleTest, AreaCalculation) {
    Triangle t({0,0}, {4,0}, {0,3});
    EXPECT_DOUBLE_EQ(t.area(), 6.0);
}

TEST(TriangleTest, CenterCalculation) {
    Triangle t({0,0}, {6,0}, {3,3});
    Point c = t.center();
    EXPECT_DOUBLE_EQ(c.x, 3.0);
    EXPECT_DOUBLE_EQ(c.y, 1.0);
}

TEST(TriangleTest, InvalidTriangle_CollinearPoints) {
    EXPECT_THROW(Triangle({0,0}, {1,0}, {2,0}), std::invalid_argument);
}

TEST(TriangleTest, InvalidTriangle_DuplicatePoints) {
    EXPECT_THROW(Triangle({0,0}, {1,1}, {0,0}), std::invalid_argument);
}

TEST(TriangleTest, Equality_SameOrder) {
    Triangle t1({0,0}, {1,0}, {0,1});
    Triangle t2({0,0}, {1,0}, {0,1});
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, Equality_DifferentOrder) {
    Triangle t1({0,0}, {1,0}, {0,1});
    Triangle t2({1,0}, {0,1}, {0,0});
    EXPECT_TRUE(t1 == t2);
}

TEST(TriangleTest, Equality_NotEqual) {
    Triangle t1({0,0}, {1,0}, {0,1});
    Triangle t2({0,0}, {2,0}, {0,2});
    EXPECT_FALSE(t1 == t2);
}

TEST(TriangleTest, Clone) {
    Triangle original({0,0}, {3,0}, {0,4});
    std::unique_ptr<Figure> cloned = original.clone();
    EXPECT_TRUE(*cloned == original);
    EXPECT_NE(cloned.get(), &original);
}

TEST(SquareTest, AreaCalculation) {
    Square s({0,0}, {0,5}, {5,5}, {5,0});
    EXPECT_DOUBLE_EQ(s.area(), 25.0);
}

TEST(SquareTest, CenterCalculation) {
    Square s({-1,-1}, {2,-1}, {2,2}, {-1,2});
    Point c = s.center();
    EXPECT_DOUBLE_EQ(c.x, 0.5);
    EXPECT_DOUBLE_EQ(c.y, 0.5);
}

TEST(SquareTest, InvalidSquare_NotSquare) {
    EXPECT_THROW(Square({0,0}, {0,4}, {3,4}, {3,0}), std::invalid_argument);
}

TEST(SquareTest, InvalidSquare_NotRectangle) {
    EXPECT_THROW(Square({0,0}, {1,1}, {2,0}, {0,1}), std::invalid_argument);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle r({0,0}, {5,0}, {5,3}, {0,3});
    EXPECT_DOUBLE_EQ(r.area(), 15.0);
}

TEST(RectangleTest, CenterCalculation) {
    Rectangle r({1,2}, {6,2}, {6,7}, {1,7});
    Point c = r.center();
    EXPECT_DOUBLE_EQ(c.x, 3.5);
    EXPECT_DOUBLE_EQ(c.y, 4.5);
}

TEST(RectangleTest, InvalidRectangle_NotPerpendicular) {
    EXPECT_THROW(Rectangle({0,0}, {4,0}, {5,3}, {1,3}), std::invalid_argument);
}

TEST(RectangleTest, InvalidRectangle_ZeroSide) {
    EXPECT_THROW(Rectangle({0,0}, {0,0}, {4,3}, {4,0}), std::invalid_argument);
}

TEST(FigureTest, Polymorphism) {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Triangle>(Point{0,0}, Point{2,0}, Point{1,3}));
    figures.push_back(std::make_unique<Rectangle>(Point{0,0}, Point{4,0}, Point{4,2}, Point{0,2}));
    figures.push_back(std::make_unique<Square>(Point{0,0}, Point{3,0}, Point{3,3}, Point{0,3}));

    double total_area = 0.0;
    for (const auto& fig : figures) {
        total_area += fig->area();
    }
    
    EXPECT_DOUBLE_EQ(total_area, 3.0 + 8.0 + 9.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
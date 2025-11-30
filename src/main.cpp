#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Figure.h"
#include "Triangle.h"
#include "Square.h"
#include "Rectangle.h"

class FigureArray {
private:
    std::vector<std::unique_ptr<Figure>> figures;

public:
    void addFigure(std::unique_ptr<Figure> fig) {
        figures.push_back(std::move(fig));
    }

    void removeFigure(int index) {
        if (index >= 0 && index < figures.size()) {
            figures.erase(figures.begin() + index);
        }
    }

    void printAll() const {
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
            std::cout << "Center: (" << figures[i]->center().x << ", " 
                      << figures[i]->center().y << ")" << std::endl;
            std::cout << "Area: " << double(*figures[i]) << std::endl;
            std::cout << "---" << std::endl;
        }
    }

    double totalArea() const {
        double total = 0;
        for (const auto& fig : figures) {
            total += double(*fig);
        }
        return total;
    }

    size_t size() const {
        return figures.size();
    }
};

void showMenu() {
    std::cout << "\n=== Figure Management System ===" << std::endl;
    std::cout << "1. Add Triangle" << std::endl;
    std::cout << "2. Add Square" << std::endl;
    std::cout << "3. Add Rectangle" << std::endl;
    std::cout << "4. Print All Figures" << std::endl;
    std::cout << "5. Show Total Area" << std::endl;
    std::cout << "6. Remove Figure" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Choose option: ";
}

int main() {
    FigureArray array;
    int choice;
    
    while (true) {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                auto triangle = std::make_unique<Triangle>();
                std::cout << "Enter triangle coordinates (x1 y1 x2 y2 x3 y3): ";
                std::cin >> *triangle;
                array.addFigure(std::move(triangle));
                break;
            }
            case 2: {
                auto square = std::make_unique<Square>();
                std::cout << "Enter square coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
                std::cin >> *square;
                array.addFigure(std::move(square));
                break;
            }
            case 3: {
                auto rectangle = std::make_unique<Rectangle>();
                std::cout << "Enter rectangle coordinates (x1 y1 x2 y2 x3 y3 x4 y4): ";
                std::cin >> *rectangle;
                array.addFigure(std::move(rectangle));
                break;
            }
            case 4:
                array.printAll();
                break;
            case 5:
                std::cout << "Total area: " << array.totalArea() << std::endl;
                break;
            case 6: {
                int index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                array.removeFigure(index);
                break;
            }
            case 7:
                return 0;
            default:
                std::cout << "Invalid option!" << std::endl;
        }
    }
    
    return 0;
}
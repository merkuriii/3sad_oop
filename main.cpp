#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "../include/Figure.h"
#include "../include/Rectangle.h"
#include "../include/Square.h"
#include "../include/Triangle.h"

int main() {
    std::vector<std::unique_ptr<Figure>> figures;

    try {
        figures.push_back(std::make_unique<Rectangle>(
            Point{0, 0}, Point{6, 0}, Point{6, 4}, Point{0, 4}));
        figures.push_back(std::make_unique<Square>(
            Point{0, 0}, Point{5, 0}, Point{5, 5}, Point{0, 5}));
        figures.push_back(std::make_unique<Triangle>(
            Point{0, 0}, Point{8, 0}, Point{4, 6}));
    } catch (const std::exception& e) {
        std::cerr << "Ошибка при создании начальных фигур: " << e.what() << '\n';
    }

    std::string command;
    while (true) {
        std::cout << "\n=== Список фигур (" << figures.size() << ") ===\n";
        double total_area = 0.0;
        for (size_t i = 0; i < figures.size(); ++i) {
            std::cout << i << ": ";
            figures[i]->print(std::cout);
            std::cout << " | площадь = " << figures[i]->area()
                      << " | центр = (" << figures[i]->center().x
                      << ", " << figures[i]->center().y << ")\n";
            total_area += figures[i]->area();
        }
        std::cout << "Общая площадь всех фигур: " << total_area << "\n\n";

        std::cout << "Команды:\n"
                  << "  add    — добавить новую фигуру\n"
                  << "  del    — удалить фигуру по индексу\n"
                  << "  exit   — выйти из программы\n"
                  << "Введите команду: ";
        std::cin >> command;

        if (command == "exit") {
            break;
        }

        if (command == "add") {
            std::cout << "Тип фигуры (rectangle / square / triangle): ";
            std::string type;
            std::cin >> type;

            try {
                if (type == "rectangle") {
                    std::cout << "Введите 8 координат (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    Rectangle r;
                    r.read(std::cin);
                    figures.push_back(r.clone());
                } else if (type == "square") {
                    std::cout << "Введите 8 координат (x1 y1 x2 y2 x3 y3 x4 y4): ";
                    Square s;
                    s.read(std::cin);
                    figures.push_back(s.clone());
                } else if (type == "triangle") {
                    std::cout << "Введите 6 координат (x1 y1 x2 y2 x3 y3): ";
                    Triangle t;
                    t.read(std::cin);
                    figures.push_back(t.clone());
                } else {
                    std::cout << "Неизвестный тип фигуры!\n";
                    continue;
                }
                std::cout << "Фигура успешно добавлена.\n";
            } catch (const std::invalid_argument& e) {
                std::cerr << "Ошибка: " << e.what() << " — фигура не добавлена.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        else if (command == "del") {
            std::cout << "Введите индекс фигуры для удаления: ";
            size_t index;
            if (std::cin >> index && index < figures.size()) {
                figures.erase(figures.begin() + index);
                std::cout << "Фигура с индексом " << index << " удалена.\n";
            } else {
                std::cout << "Неверный индекс!\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        else {
            std::cout << "Неизвестная команда.\n";
        }
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Программа завершена.\n";
    return 0;
}
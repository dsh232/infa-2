#include <iostream>
#include <math.h>

int intInput()		//проверка на ввод.
{
    int input;
    while (!(std::cin >> input) //соответсвие введенного значения типу переменной
        || std::cin.peek() != '\n')  //проверка на конец ввода
    {
        std::cin.clear();	//"лечим" поток. +состояние good
        while (std::cin.get() != '\n');
        std::cout << "Incorrect input. Enter integers without unnecessary characters. Repeat it again. " << std::endl;
    }
    return input;
}
char charInput()   // Корректный ввод на продолжить/остановить программу. Проверка на ввод.
{
    char input;
    while (!(std::cin >> input) || std::cin.peek() != '\n')
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Incorrect input. Enter 'Y' or 'N' without unnecessary characters. Repeat it again." << std::endl;
    }
    return input;
}

class Triangle {
private:
    int x1, y1, x2, y2, x3, y3; 
    bool is_valid_triangle() {
        double side1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
        double side2 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
        double side3 = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {
        if (!is_valid_triangle()) {
            throw std::invalid_argument("triangle with these coordinates does not exist. ");
        }
    }
     double getArea() {
        return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    }
};

// реализовать треугольник через класс
// проверка в конструкторе корректности введенных данных (треугольник или нет)
// метод возвращает площадь  треугольника


int main()
{
    bool is_need_next_run = false; //создание флага для повторного запуска программы
   
    while (!is_need_next_run) { //цикл для повторного использования программы
        int first_vertex_x, first_vertex_y, second_vertex_x, second_vertex_y, third_vertex_x, third_vertex_y, first_side, second_side, third_side;
        std::cout << "This program will help you find the area of a triangle.\n";

        std::cout << "Input x in first vertex: ";
        first_vertex_x = intInput();
        std::cout << "Input y in first vertex: ";
        first_vertex_y = intInput();

        std::cout << "Input x in second vertex: ";
        second_vertex_x = intInput();
        std::cout << "Input y in second vertex: ";
        second_vertex_y = intInput();

        std::cout << "Input x in third vertex: ";
        third_vertex_x = intInput();
        std::cout << "Input y in third vertex: ";
        third_vertex_y = intInput();

        try {
            Triangle triangle(first_vertex_x, first_vertex_y,
                second_vertex_x, second_vertex_y,
                third_vertex_x, third_vertex_y);
            double area = triangle.getArea();
            std::cout << "Result: " << area << std::endl;
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl; // Выводим сообщение об ошибке
        }

        bool is_need_processed = false;
        do {
            std::cout << "Continue? (Y/N):  ";
            char answer = charInput();
            if (answer == 'N') {
                std::cout << "Bye!" << std::endl;
                is_need_next_run = true;
                is_need_processed = true;
            }
            else if (answer == 'Y') {
                std::cout << "Here we go!" << std::endl;
                is_need_processed = true;
            }

        } while (!is_need_processed);
    }
    
}

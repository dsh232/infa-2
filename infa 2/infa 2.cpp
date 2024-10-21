#include <iostream>
#include <math.h>

int int_input()		//проверка на ввод.
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
char char_input()   // Корректный ввод на продолжить/остановить программу. Проверка на ввод.
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

double calculate_area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main()
{
    bool is_need_next_run = false; //создание флага для повторного запуска программы
    while (is_need_next_run == false) { //цикл для повторного использования программы
        int first_vertex_x, first_vertex_y, second_vertex_x, second_vertex_y, third_vertex_x, third_vertex_y, first_side, second_side, third_side;
        std::cout << "This program will help you find the area of a triangle.\n";

        std::cout << "Input x in first vertex: ";
        first_vertex_x = int_input();
        std::cout << "Input y in first vertex: ";
        first_vertex_y = int_input();

        std::cout << "Input x in second vertex: ";
        second_vertex_x = int_input();
        std::cout << "Input y in second vertex: ";
        second_vertex_y = int_input();

        std::cout << "Input x in third vertex: ";
        third_vertex_x = int_input();
        std::cout << "Input y in third vertex: ";
        third_vertex_y = int_input();

    
        double area = calculate_area(first_vertex_x, first_vertex_y,
            second_vertex_x, second_vertex_y,
            third_vertex_x, third_vertex_y);

        std::cout << "Result: " << area <<std::endl;

        bool is_need_processed = false;
        do {
            std::cout << "Continue? (Y/N):  ";
            char answer = char_input();
            if (answer == 'N') {
                std::cout << "Bye!" << std::endl;
                is_need_next_run = true;
                is_need_processed = true;
            }
            else if (answer == 'Y') {
                std::cout << "Here we go!" << std::endl;
                is_need_processed = true;
            }

        } while (is_need_processed == false);
    }
    
}

#include <iostream>
#include "Canvas.h"
#include <conio.h>

using namespace std;

// Функция для отображения меню
void menu() {
    cout << "Выберите фигуру:\n";
    cout << "1 - Точка\n";
    cout << "2 - Линия\n";
    cout << "3 - Прямоугольник\n";
    cout << "4 - Эллипс\n";
    cout << "5 - Многоугольник\n";
    cout << "0 - Вывести рисунок\n";
}


// Функция для добавления точки
void addPoint(Canvas& c) {
    int x, y, r, g, b;
    cout << "Введите координаты (x y): ";
    cin >> x >> y;
    cout << "Введите цвет (R G B): ";
    cin >> r >> g >> b;
    c.add(new Point(x, y, RGB(r, g, b)));
}

// Функция для добавления линии
void addLine(Canvas& c) {
    int x1, y1, x2, y2, r, g, b;
    cout << "Введите координаты начала и конца (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Введите цвет (R G B): ";
    cin >> r >> g >> b;
    c.add(new Line(x1, y1, x2, y2, RGB(r, g, b)));
}

// Функция для добавления прямоугольника
void addRectangle(Canvas& c) {
    int x1, y1, x2, y2, r, g, b, fr, fg, fb;
    bool filled;
    cout << "Введите координаты углов (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Заполненный? (1 - да, 0 - нет): ";
    cin >> filled;
    cout << "Введите цвет границы (R G B): ";
    cin >> r >> g >> b;
    cout << "Введите цвет заливки (R G B): ";
    cin >> fr >> fg >> fb;
    c.add(new RectangleShape(x1, y1, x2, y2, RGB(r, g, b), filled, RGB(fr, fg, fb)));
}

// Функция для добавления эллипса
void addEllipse(Canvas& c) {
    int x1, y1, x2, y2, r, g, b, fr, fg, fb;
    bool filled;
    cout << "Введите координаты ограничивающего прямоугольника (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;
    cout << "Заполненный? (1 - да, 0 - нет): ";
    cin >> filled;
    cout << "Введите цвет границы (R G B): ";
    cin >> r >> g >> b;
    cout << "Введите цвет заливки (R G B): ";
    cin >> fr >> fg >> fb;
    c.add(new EllipseShape(x1, y1, x2, y2, RGB(r, g, b), filled, RGB(fr, fg, fb)));
}

// Функция для добавления многоугольника
void addPolygon(Canvas& c) {
    int n, x, y, r, g, b, fr, fg, fb;
    bool filled;
    cout << "Введите количество вершин: ";
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++) {
        cout << "Введите координаты вершины " << i + 1 << " (x y): ";
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    cout << "Заполненный? (1 - да, 0 - нет): ";
    cin >> filled;
    cout << "Введите цвет границы (R G B): ";
    cin >> r >> g >> b;
    cout << "Введите цвет заливки (R G B): ";
    cin >> fr >> fg >> fb;
    c.add(new PolygonShape(points, RGB(r, g, b), filled, RGB(fr, fg, fb)));
}

int main() {
    //setlocale(LC_ALL, "RUS");
    Canvas c;
    int choice;
    while (true) {
        menu();
        cout << "Ваш выбор: ";
        cin >> choice;
        switch (choice) {
        case 0: 
            system("CLS");
            c.show(); 
            _getch();
            break;
        case 1: addPoint(c); break;
        case 2: addLine(c); break;
        case 3: addRectangle(c); break;
        case 4: addEllipse(c); break;
        case 5: addPolygon(c); break;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
    cout << "Нажмите любую клавишу для выхода...";
    cin.get();
    cin.get();
    return 0;
}
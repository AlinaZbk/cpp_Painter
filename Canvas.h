#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include <windows.h>
#include <vector>

using namespace std;

// Базовый класс Shape
class Shape {
public:
    virtual void show(HDC hdc) = 0; // Чисто виртуальный метод
    virtual ~Shape() {} // Виртуальный деструктор
};

// Класс Point (Точка)
class Point : public Shape {
public:
    int x, y;
    COLORREF color;

    Point(int x, int y, COLORREF c = RGB(255, 255, 255))
        : x(x), y(y), color(c) {}

    void show(HDC hdc) override {
        SetPixel(hdc, x, y, color);
    }
};

// Класс Line (Отрезок)
class Line : public Shape {
    Point start, end;
    COLORREF color;
public:
    Line(int x1, int y1, int x2, int y2, COLORREF c)
        : start(x1, y1, c), end(x2, y2, c), color(c) {}

    void show(HDC hdc) override {
        HPEN pen = CreatePen(PS_SOLID, 1, color);
        SelectObject(hdc, pen);
        MoveToEx(hdc, start.x, start.y, NULL);
        LineTo(hdc, end.x, end.y);
        DeleteObject(pen);
    }
};

// Класс Rectangle (Прямоугольник)
class RectangleShape : public Shape {
    Point top_left, bottom_right;
    COLORREF color, fill_color;
    bool filled;
public:
    RectangleShape(int x1, int y1, int x2, int y2, COLORREF c, bool fill = false, COLORREF fc = RGB(0, 0, 0))
        : top_left(x1, y1, c), bottom_right(x2, y2, c), color(c), fill_color(fc), filled(fill) {}

    void show(HDC hdc) override {
        HPEN pen = CreatePen(PS_SOLID, 1, color);
        HBRUSH brush = filled ? CreateSolidBrush(fill_color) : (HBRUSH)GetStockObject(NULL_BRUSH);

        SelectObject(hdc, pen);
        SelectObject(hdc, brush);
        Rectangle(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);

        DeleteObject(pen);
        if (filled) DeleteObject(brush);
    }
};

// Класс EllipseShape (Эллипс)
class EllipseShape : public Shape {
    Point top_left, bottom_right;
    COLORREF color, fill_color;
    bool filled;
public:
    EllipseShape(int x1, int y1, int x2, int y2, COLORREF c, bool fill = false, COLORREF fc = RGB(0, 0, 0))
        : top_left(x1, y1, c), bottom_right(x2, y2, c), color(c), fill_color(fc), filled(fill) {}

    void show(HDC hdc) override {
        HPEN pen = CreatePen(PS_SOLID, 1, color);
        HBRUSH brush = filled ? CreateSolidBrush(fill_color) : (HBRUSH)GetStockObject(NULL_BRUSH);

        SelectObject(hdc, pen);
        SelectObject(hdc, brush);
        ::Ellipse(hdc, top_left.x, top_left.y, bottom_right.x, bottom_right.y);

        DeleteObject(pen);
        if (filled) DeleteObject(brush);
    }
};

// Класс PolygonShape (Многоугольник)
class PolygonShape : public Shape {
    vector<Point> points;
    COLORREF color, fill_color;
    bool filled;
public:
    PolygonShape(vector<Point> pts, COLORREF c, bool fill = false, COLORREF fc = RGB(0, 0, 0))
        : points(pts), color(c), fill_color(fc), filled(fill) {}

    void show(HDC hdc) override {
        HPEN pen = CreatePen(PS_SOLID, 1, color);
        HBRUSH brush = filled ? CreateSolidBrush(fill_color) : (HBRUSH)GetStockObject(NULL_BRUSH);
        SelectObject(hdc, pen);
        SelectObject(hdc, brush);

        POINT* pts = new POINT[points.size()];
        for (size_t i = 0; i < points.size(); i++) {
            pts[i] = { points[i].x, points[i].y };
        }
        Polygon(hdc, pts, points.size());

        delete[] pts;
        DeleteObject(pen);
        if (filled) DeleteObject(brush);
    }
};

// Класс Canvas (Холст)
class Canvas {
    vector<Shape*> shapes;
    HWND hWnd;
    HDC hdc;
public:
    Canvas() {
        hWnd = GetConsoleWindow();
        hdc = GetDC(hWnd);
    }

    ~Canvas() {
        for (Shape* s : shapes)
            delete s;
        shapes.clear();
        ReleaseDC(hWnd, hdc);
    }

    void add(Shape* s) {
        shapes.push_back(s);
    }

    void clear() {
        for (Shape* s : shapes)
            delete s;
        shapes.clear();
    }

    void show() {
        for (Shape* s : shapes)
            s->show(hdc);
    }
};

#endif // CANVAS_H
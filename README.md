
Canvas Drawing Application

### Описание
Программа предоставляет простой инструмент для рисования различных графических примитивов в консольном окне Windows с использованием GDI (windows.h).  
Позволяет пользователю добавлять фигуры, управлять их параметрами и отображать их на экране.

### Файлы проекта
- Canvas.h — заголовочный файл, содержащий классы фигур и холста.
- Canvas.cpp — подключает Canvas.h (файл нужен для компиляции, но не содержит реализаций).
- main.cpp — основной файл программы, реализует меню для взаимодействия с пользователем.

### Функционал
#### Меню
Программа предоставляет консольное меню, позволяющее:
- Выбрать фигуру для добавления.
- Указать параметры фигуры (координаты, цвет, заливку).
- Отобразить все добавленные фигуры.
  
### Доступные фигуры
#### 1. Точка (Point)
   - Параметры:
     - Координаты (x, y)
     - Цвет (R, G, B)
   - Отображение: вызывается SetPixel(hdc, x, y, color)

#### 2. Линия (Line)
   - Параметры:
     - Координаты начала (x1, y1)
     - Координаты конца (x2, y2)
     - Цвет (R, G, B)
   - Отображение: вызывается MoveToEx → LineTo

#### 3. Прямоугольник (RectangleShape)
   - Параметры:
     - Координаты двух противоположных углов (x1, y1, x2, y2)
     - Цвет границы (R, G, B)
     - Флаг заполнения (true/false)
     - Цвет заливки (R, G, B)
   - Отображение: вызывается Rectangle(), используется CreateSolidBrush для заливки

#### 4. Эллипс (EllipseShape)
   - Параметры:
     - Координаты ограничивающего прямоугольника (x1, y1, x2, y2)
     - Цвет границы (R, G, B)
     - Флаг заполнения (true/false)
     - Цвет заливки (R, G, B)
   - Отображение: вызывается Ellipse(), используется CreateSolidBrush для заливки

#### 5. Многоугольник (PolygonShape)
   - Параметры:
     - Количество вершин n
     - Координаты вершин (x, y)
     - Цвет границы (R, G, B)
     - Флаг заполнения (true/false)
     - Цвет заливки (R, G, B)
   - Отображение: вызывается Polygon(), используется CreateSolidBrush для заливки
     
### Требования
- ОС Windows (используется windows.h)
- Компилятор с поддержкой C++ (например, g++)
- Поддержка GDI (Windows API для работы с графикой)

### Установка и запуск
1. Склонируйте репозиторий:
   git clone https://github.com/AlinaZbk/cpp_Painter.git,
   cd cpp_Painter
2. Скомпилируйте программу:
g++ main.cpp Canvas.cpp -o canvas_app -lgdi32
3. Запустите приложение:
./canvas_app

### Автор
Alina Zubko https://github.com/AlinaZbk

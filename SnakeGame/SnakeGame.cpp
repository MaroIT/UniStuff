#include <iostream>
#include <ncurses.h>

const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 20;

class Snake {
private:
    struct Point {
        int x;
        int y;
    };

    enum Direction { UP, DOWN, LEFT, RIGHT };

    int length;
    Direction direction;
    Point head;
    Point* body;

public:
    Snake() {
        length = 1;
        direction = RIGHT;
        head.x = BOARD_WIDTH / 2;
        head.y = BOARD_HEIGHT / 2;
        body = new Point[BOARD_WIDTH * BOARD_HEIGHT];
        body[0] = head;
    }

    ~Snake() {
        delete[] body;
    }

    void move() {
        Point nextHead = head;
        switch (direction) {
        case UP:
            nextHead.y--;
            break;
        case DOWN:
            nextHead.y++;
            break;
        case LEFT:
            nextHead.x--;
            break;
        case RIGHT:
            nextHead.x++;
            break;
        }

        for (int i = length - 1; i > 0; i--) {
            body[i] = body[i - 1];
        }

        body[0] = nextHead;
        head = nextHead;
    }

    void changeDirection(char key) {
        switch (key) {
        case 'w':
            if (direction != DOWN)
                direction = UP;
            break;
        case 's':
            if (direction != UP)
                direction = DOWN;
            break;
        case 'a':
            if (direction != RIGHT)
                direction = LEFT;
            break;
        case 'd':
            if (direction != LEFT)
                direction = RIGHT;
            break;
        }
    }

    bool collidedWithSelf() {
        for (int i = 1; i < length; i++) {
            if (head.x == body[i].x && head.y == body[i].y)
                return true;
        }
        return false;
    }

    bool collidedWithWall() {
        return (head.x < 0 || head.x >= BOARD_WIDTH || head.y < 0 || head.y >= BOARD_HEIGHT);
    }

    void draw() {
        clear();  // Wyczyść ekran
        for (int y = 0; y < BOARD_HEIGHT; y++) {
            for (int x = 0; x < BOARD_WIDTH; x++) {
                if (x == head.x && y == head.y) {
                    addch('O');  // Rysuj głowę węża
                }
                else {
                    bool isBodyPart = false;
                    for (int i = 0; i < length; i++) {
                        if (body[i].x == x && body[i].y == y) {
                            addch('*');  // Rysuj część ciała węża
                            isBodyPart = true;
                            break;
                        }
                    }
                    if (!isBodyPart) {
                        addch(' ');  // Rysuj puste pole
                    }
                }
            }
            addch('\n');
        }
        refresh();  // Odśwież ekran
    }
};

int main() {
    Snake snake;

    initscr();  // Inicjalizuj ncurses
    noecho();  // Wyłącz echo wprowadzanych znaków
    keypad(stdscr, TRUE);  // Włącz obsługę klawiatury
    nodelay(stdscr, TRUE);  // Ustaw oczekiwanie na wprowadzenie znaku jako nieblokujące

    while (true) {
        int key = getch();  // Pobierz naciśnięty klawisz
        if (key != ERR) {  // Sprawdź, czy został naciśnięty klawisz
            snake.changeDirection(key);  // Zmień kierunek węża na podstawie naciśniętego klawisza
        }

        snake.move();

        if (snake.collidedWithSelf() || snake.collidedWithWall()) {
            endwin();  // Zakończ tryb ncurses
            std::cout << "Game Over!" << std::endl;
            break;
        }

        snake.draw();

        napms(100);  // Poczekaj 100 milisekund
    }

    return 0;
}

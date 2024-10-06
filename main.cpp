#include <iostream>
#include <sstream>
#include <vector>

// Define the size of the board
const int BOARD_WIDTH = 200;
const int BOARD_HEIGHT = 30;
// Struct to define the board
struct Board {
    std::vector<std::vector<char> > grid;
    Board() : grid(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' ')) {}
    void print() {
        for (auto& row : grid) {
            for (char c : row) {
                std::cout << c;
            }
            std::cout << "\n";
        }
    }

    void clear() {
        grid.assign(BOARD_HEIGHT, std::vector<char>(BOARD_WIDTH, ' '));
    }

    void drawTriangle(int x, int y, int height) {
        if (height <= 0) return; // Ensure the triangle height is positive and sensible
        for (int i = 0; i < height; ++i) {
            int leftMost = x - i; // Calculate the starting position
            int rightMost = x + i; // Calculate the ending position
            int posY = y + i; // Calculate the vertical position
            // Draw only the edges/border of the triangle
            if (posY < BOARD_HEIGHT) {
                if (leftMost >= 0 && leftMost < BOARD_WIDTH) // Check bounds for left
                    grid[posY][leftMost] = '*';
                if (rightMost >= 0 && rightMost < BOARD_WIDTH && leftMost != rightMost)
                    // Check bounds for right most position
                        grid[posY][rightMost] = '*';
            }
        }
        // Draw the base of the triangle separately
        for (int j = 0; j < 2 * height - 1; ++j) {
            int baseX = x - height + 1 + j;
            int baseY = y + height - 1;
            if (baseX >= 0 && baseX < BOARD_WIDTH && baseY < BOARD_HEIGHT) // Check
                grid[baseY][baseX] = '*';
        }
    }

    void drawSquare(int x, int y, int width, int height) {
        if (width <= 0 || height <= 0) return;

        for (int j = 0; j < width; ++j) {
            if (y >= 0 && y < BOARD_HEIGHT) {
                if (x + j >= 0 && x + j < BOARD_WIDTH)
                    grid[y][x + j] = '*';
                if (y + height - 1 < BOARD_HEIGHT) {
                    if (x + j >= 0 && x + j < BOARD_WIDTH)
                        grid[y + height - 1][x + j] = '*';
                }
            }
        }

        for (int i = 1; i < height - 1; ++i) {
            if (x >= 0 && x < BOARD_WIDTH) {
                if (y + i >= 0 && y + i < BOARD_HEIGHT)
                    grid[y + i][x] = '*';
                if (x + width - 1 >= 0 && x + width - 1 < BOARD_WIDTH) {
                    if (y + i >= 0 && y + i < BOARD_HEIGHT)
                        grid[y + i][x + width - 1] = '*';
                }
            }
        }
    }

    void drawCircle(int centerX, int centerY, int radius) {
        int x = radius;
        int y = 0;
        int radiusError = 1 - radius;

        while (x >= y) {
            drawBorders(centerX, centerY, x, y);
            y++;
            if (radiusError < 0) {
                radiusError += 2 * y + 1;
            } else {
                x--;
                radiusError += 2 * (y - x + 1);
            }
        }
    }

    void drawBorders(int centerX, int centerY, int x, int y) {
        if (centerX + x < BOARD_WIDTH && centerY + y < BOARD_HEIGHT)
            grid[centerY + y][centerX + x] = '*';
        if (centerX - x >= 0 && centerY + y < BOARD_HEIGHT)
            grid[centerY + y][centerX - x] = '*';
        if (centerX + x < BOARD_WIDTH && centerY - y >= 0)
            grid[centerY - y][centerX + x] = '*';
        if (centerX - x >= 0 && centerY - y >= 0)
            grid[centerY - y][centerX - x] = '*';
        if (centerY + x < BOARD_HEIGHT && centerX + y < BOARD_WIDTH)
            grid[centerY + x][centerX + y] = '*';
        if (centerY + x < BOARD_HEIGHT && centerX - y >= 0)
            grid[centerY + x][centerX - y] = '*';
        if (centerY - x >= 0 && centerX + y < BOARD_WIDTH)
            grid[centerY - x][centerX + y] = '*';
        if (centerY - x >= 0 && centerX - y >= 0)
            grid[centerY - x][centerX - y] = '*';
    }

    void drawLine(int startX, int startY, int height, double angle) {
        double radians = angle * M_PI / 180.0;

        for (int i = 0; i <= height; ++i) {
            int posX = static_cast<int>(startX + i * cos(radians));
            int posY = static_cast<int>(startY + i * sin(radians));

            if (posX >= 0 && posX < BOARD_WIDTH && posY >= 0 && posY < BOARD_HEIGHT) {
                grid[posY][posX] = '*';
            }
        }
    }

};

int main() {
    Board board;
    std::string command;

    std::cout << "Enter commands:\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "draw") {
            std::string shape;
            iss >> shape;

            if (shape == "triangle") {
                int x, y, height;
                iss >> x >> y >> height;
                board.drawTriangle(x, y, height);
            } else if (shape == "square") {
                int x, y, width, height;
                iss >> x >> y >> width >> height;
                board.drawSquare(x, y, width, height);
            } else if (shape == "circle") {
                int x, y, radius;
                iss >> x >> y >> radius;
                board.drawCircle(x, y, radius);
            } else if (shape == "line") {
                int x, y, length;
                double angle;
                iss >> x >> y >> length >> angle;
                board.drawLine(x, y, length, angle);
            } else {
                std::cout << "Unknown shape. Use triangle, square, circle, or line.\n";
            }
        } else if (cmd == "print") {
            board.print();
        } else if (cmd == "clear") {
            board.clear();
        } else if (cmd == "exit") {
            break;
        } else {
            std::cout << "Unknown command. Use 'draw', 'print', 'clear', or 'exit'.\n";
        }
    }

    return 0;
}
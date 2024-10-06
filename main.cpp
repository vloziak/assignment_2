#include <iostream>
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

};

int main() {
    Board board;
    board.drawTriangle(10, 1, 5);
    board.drawSquare(10,20,10,5);
    board.drawCircle(20,20,10);
    board.print();
    return 0;
}
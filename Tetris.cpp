#include "Tetris.hpp"

void TetrominosManager::refactorTetromino(TetrominoType type, Tetromino &tetro) {
    switch (type) {

//      0 1 2 3
        case I:
            tetro.type = I;
            tetro.state.init();
            tetro.points[0].x = 3;
            tetro.points[0].y = 0;
            tetro.points[1].x = 4;
            tetro.points[1].y = 0;
            tetro.points[2].x = 5;
            tetro.points[2].y = 0;
            tetro.points[3].x = 6;
            tetro.points[3].y = 0;
            break;

//      0
//      1 2 3
        case J:
            tetro.type = J;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 0;
            tetro.points[1].x = 4;
            tetro.points[1].y = 1;
            tetro.points[2].x = 5;
            tetro.points[2].y = 1;
            tetro.points[3].x = 6;
            tetro.points[3].y = 1;
            break;

//          3
//      0 1 2
        case L:
            tetro.type = L;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 1;
            tetro.points[1].x = 5;
            tetro.points[1].y = 1;
            tetro.points[2].x = 6;
            tetro.points[2].y = 0;
            tetro.points[3].x = 6;
            tetro.points[3].y = 1;
            break;

//      0 2
//      1 3
        case O:
            tetro.type = O;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 0;
            tetro.points[1].x = 4;
            tetro.points[1].y = 1;
            tetro.points[2].x = 5;
            tetro.points[2].y = 0;
            tetro.points[3].x = 5;
            tetro.points[3].y = 1;
            break;

//        2 3
//      0 1
        case S:
            tetro.type = S;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 1;
            tetro.points[1].x = 5;
            tetro.points[1].y = 1;
            tetro.points[2].x = 5;
            tetro.points[2].y = 0;
            tetro.points[3].x = 6;
            tetro.points[3].y = 0;
            break;

//        2
//      0 1 3

        case T:
            tetro.type = T;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 1;
            tetro.points[1].x = 5;
            tetro.points[1].y = 1;
            tetro.points[2].x = 5;
            tetro.points[2].y = 0;
            tetro.points[3].x = 6;
            tetro.points[3].y = 1;
            break;

//      0 1
//        2 3
        case Z:
            tetro.type = Z;
            tetro.state.init();
            tetro.points[0].x = 4;
            tetro.points[0].y = 0;
            tetro.points[1].x = 5;
            tetro.points[1].y = 0;
            tetro.points[2].x = 5;
            tetro.points[2].y = 1;
            tetro.points[3].x = 6;
            tetro.points[3].y = 1;
            break;
    }
}

void TetrominosManager::checkClockWiseWallKick(Tetromino &tetro, Tetris &table) {
    switch (tetro.type) {
        case I:
        case J:
        case L:
        case O:
        case S:
        case T:
        case Z:
            return;
    }
}

void TetrominosManager::rotateClockWiseTetromino(Tetromino &tetro) {
    switch (tetro.type) {
        case I:
        case J:
        case L:
        case O:
        case S:
        case T:
        case Z:
            return;
    }
    ++tetro.state;
}

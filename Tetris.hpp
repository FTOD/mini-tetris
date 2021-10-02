#ifndef MINI_TETRIS_TETRIS_HPP
#define MINI_TETRIS_TETRIS_HPP

#define TABLE_WIDTH 10
#define TABLE_HEIGHT 20

struct TetrominoState{
    TetrominoState():state(ZERO){};
    enum State {
        ZERO = 0,
        RIGHT = 1,
        TWO = 2,
        LEFT = 3,
    } state;
    inline void toNext(){
        if (state == LEFT)
            state = ZERO;
        else
            state = static_cast<State>(state + 1);
    }
    inline void toPrev(){
        if (state == ZERO)
            state = LEFT;
        else
            state = static_cast<State>(state - 1);
    }
    inline void init(){
        state = ZERO;
    }
    inline TetrominoState& operator++(){toNext(); return *this;};
    inline TetrominoState& operator--(){toPrev(); return *this;};

};

enum TetrominoType{
    NO_TYPE,
    I,
    J,
    L,
    O,
    S,
    T,
    Z,
};



struct Point{
    inline void moveRight(){
        ++x;
    }
    inline void moveLeft(){
        --x;
    }
    unsigned x;
    unsigned y;
};


struct Tetromino{
    Point points[4];
    TetrominoState state;
    TetrominoType type;
};

struct Tetris {
    TetrominoType table[TABLE_WIDTH][TABLE_HEIGHT];
    Tetromino current_tetromino;
};
class TetrominosManager{
public:
    inline static void moveRight(Tetromino& tetro, Tetris& table){
        //check if it can actually move
        for (auto& point: tetro.points){
            //if i
            if (point.x >= TABLE_WIDTH-1)
                return;
            if (table.table[point.x + 1][point.y]!=NO_TYPE)
                return;
        }
        for (auto & point : tetro.points)
            point.moveRight();
    }

    inline static void moveLeft(Tetromino& tetro, Tetris& table) {
        //check if it can actually move
        for (auto& point: tetro.points){
            //if i
            if (point.x <= 0)
                return;
            if (table.table[point.x - 1][point.y]!=NO_TYPE)
                return;
        }

        for (auto & point : tetro.points)
            point.moveLeft();
    }


    /**
     * This function refoctor a tetro.
     * It re-initialize the tetro and places it at the initial place (depending on the type de the tetro),
     * with its init state (state 0).
     * @param type  the type of the new tetro
     * @param tetro  the tetro to be refactored
     */
    static void refactorTetromino(TetrominoType type,Tetromino& tetro);

    /**
     * check if we can turn the  tetromino
     * @param tetro
     * @param table
     */
    static void checkClockWiseWallKick(Tetromino& tetro, Tetris& table);

    /**
     * turn the tetromino, update the position of each pixel of the tetromino
     * @param tetro
     */
    static void rotateClockWiseTetromino(Tetromino& tetro);

};



#endif //MINI_TETRIS_TETRIS_HPP

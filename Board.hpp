#pragma once
#include "Direction.hpp"
#include <string>
#include <unordered_map>

namespace ariel {
        class Board{
            std::unordered_map<uint, std::unordered_map<uint, char>> board;
            uint smallestCol;
            uint smallestRow;
            uint biggestCol;
            uint biggestRow;
            public  : 
            Board();
            ~Board(){};
            std::string read(uint row, uint  col, Direction direction, uint length);
            void post(uint row,uint col, Direction direction, const std::string str);
            void show();
        };
 }
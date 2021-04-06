#include "Board.hpp"
#include <stdexcept>
#include <iostream>
#include <climits>
using namespace std;


namespace ariel {
    //constructor 
       Board::Board(){
        std::unordered_map<uint, std::unordered_map<uint, char>> board;
        smallestCol=UINT_MAX;
        smallestRow=UINT_MAX;
        biggestCol=0;
        biggestRow=0;
       }
       //post a message in the board.you chose the row,col,direction and your string you want to publich. 
        void Board::post(uint row, uint col, Direction direction, string str){
        //if the length of the string is 0 nothing happend.
        if (str.empty()){
        return;
        }
        //check if the string the user want to publish resize the board(if the  upper left corner of the messageBoard is smaller then 
        //what we have until now).if so update it.
        uint i=0;
        if (row<smallestRow){
            smallestRow=row;
        }
        if (col<smallestCol){
            smallestCol=col;
        }
        // if direction parallel to x-axis. 
        if(direction==Direction::Horizontal){
            while(i<str.size()){//put the string in the board after 
                board[row][col+i]=str.at(i);
                i++;
         }
         //check and resize the lower right corner of the messageBoard if the board grow. 
         if (row>biggestRow){
            biggestRow=row;
        }
        if (col+str.length()>biggestCol){
            biggestCol=col+str.length();
        }
     }
     // if direction parallel to y-axis. 
      if (direction==Direction::Vertical){
        while(i<str.size()){//put the string in the board 
           board[row+i][col]=str.at(i);
         i++;
        } 
         //check and resize the lower right corner of the messageBoard if the board grow. 
         if (row+str.length()>biggestRow){
            biggestRow=row+str.length();
        }
        if (col>biggestCol){
            biggestCol=col;
        }
     }
    }

    string Board::read(uint rows, uint cols, Direction direction, uint length){
        string str;
        uint i=0;
         // if direction parallel to x-axis.
        if (direction==Direction::Horizontal){
            while(i<length){
                try {//when we read from map if the key key doesn't exist when use 'at' it throw out_of_range excetion.
                   str+=board.at(rows).at(cols+i);
                   } 
                catch(const out_of_range & e) {
                    str += '_';    
                } 
                i++; 
            }
        }
        // if direction parallel to y-axis. 
        if  (direction==Direction::Vertical){
            while(i<length){
                 // unordered_map::at throws an out-of-range if this specific key doesn't exist.the catch will print insted '_'
                try {
                   str+=board.at(rows+i).at(cols);
                   } 
                catch(const out_of_range & e) {
                    str += '_';    
                } 
                i++; 
            }
        }
        return str;
    }
    void Board::show(){
        for(uint i=smallestRow;i<=biggestRow&&i<=UINT_MAX;i++){
            for(uint j=smallestCol;j<=biggestCol&&j<=UINT_MAX;j++){
                // unordered_map::at throws an out-of-range if this specific key doesn't exist.the catch will print insted '_'
                try {
                    cout << board.at(i).at(j);
                    } 
                catch(const out_of_range & e){
                    cout << '_';    
                }
            }
            cout<<endl;
        }
    }
}
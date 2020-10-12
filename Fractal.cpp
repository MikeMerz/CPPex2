#include <iostream>
#include "Fractal.h"
#include <cmath>

//
// Created by mikemerzl on 03/01/2020.
//
/**
 * Constuctor
 * @param size dim
 */
SierpinskiCarpet::SierpinskiCarpet (int size) : Fractal (size)
{
    board = std::vector<std::vector<char>> ((int) pow (3 , size) ,
                                            std::vector<char> ((int) pow (3 , size) ,
                                                               ' '));
}

/**
 * output the board vector
 */
void Fractal::draw ()
{
    for (auto & i:board)
    {
        for (char c:i)
        {
            std::cout << c;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * create the board vector according to the cur fractal
 * @param i starting row index
 * @param j starting col index
 * @param dim amount of shapes to create
 */
void SierpinskiCarpet::drawFractal (int i , int j , int dim)
{
    if (dim > 0)
    {
        // left col top left corner
        drawFractal (i , j , dim - 1);
        //left col mid position
        drawFractal (i + ((int) pow (3 , dim - 1)) , j , dim - 1);
        //left col left top corner
        drawFractal (i + (2 * (int) pow (3 , dim - 1)) , j , dim - 1);
        //mid col lower position
        drawFractal (i + 2 * ((int) pow (3 , dim - 1)) , j + (((int) pow (3 , dim - 1))) ,
                     dim - 1) ;
        // mid col top position
        drawFractal (i , j + ((int) pow (3 , dim - 1)) , dim - 1);
        //rightmost lower corner
        drawFractal (i + 2 * ((int) pow (3 , dim - 1)) , j + (2 * ((int) pow (3 , dim - 1))) ,
                     dim - 1);
        //right col mid position
        drawFractal (i + ((int) pow (3 , dim - 1)) , j + (2 * ((int) pow (3 , dim - 1))) ,
                     dim - 1);
        //right top corner we ignore the mid col mid position due to definition of the cur fractal
        drawFractal (i , j + (2 * ((int) pow (3 , dim - 1))) , dim - 1);
    }
    else
    {
        board[i][j] = '#';
    }
}

/**
 * Constructor
 * @param size amount of shapes to create
 */
SierpinskiTriangle::SierpinskiTriangle (int size) : Fractal (size)
{
    board = std::vector<std::vector<char>> ((int) pow (2 , size) ,
                                            std::vector<char> ((int) pow (2 , size) ,
                                                               ' ')) ;
}

/**
 * create the board vector according to the cur fractal
 * @param i starting row index
 * @param j starting col index
 * @param dim amount of shapes to create
 */
void SierpinskiTriangle::drawFractal (int i , int j , int dim)
{
    if (dim > 0)
    {
        //left top corner
        drawFractal (i , j , dim - 1);
        //left col mid position
        drawFractal (i + ((int) pow (2 , dim - 1)) , j , dim - 1) ;
        //right col top right corner
        drawFractal (i , j + ((int) pow (2 , dim - 1)) , dim - 1) ;
    }
    else
    {
        board[i][j] = '#';
    }
}

/**
 * Constructor
 * @param size amount of shapes to create
 */
Vicsekfractal::Vicsekfractal (int size) : Fractal (size)
{
    board = std::vector<std::vector<char>> ((int) pow (3 , size) ,
                                            std::vector<char> ((int) pow (3 , size) ,
                                                               ' ')) ;
}

/**
 * create the board vector according to the cur fractal
 * @param i starting row index
 * @param j starting col index
 * @param dim amount of shapes to create
 */
void Vicsekfractal::drawFractal (int i , int j , int dim)
{
    if (dim > 0)
    {
        //left col top corner
        drawFractal (i , j , dim - 1) ;
        //right col top corner
        drawFractal (i , j + (2 * (int) pow (3 , dim - 1)) , dim - 1) ;
        //mid col mid row
        drawFractal (i + ((int) pow (3 , dim - 1)) , j + ((int) pow (3 , dim - 1)) ,
                     dim - 1) ;
        //left col lower position
        drawFractal (i + (2 * (int) pow (3 , dim - 1)) , j , dim - 1) ;
        //right col lower corner
        drawFractal (i + (2 * (int) pow (3 , dim - 1)) , j + (2 * (int) pow (3 , dim - 1)) ,
                     dim - 1) ;
    }
    else
    {
        board[i][j] = '#' ;
    }
}




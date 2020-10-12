//
// Created by mikemerzl on 03/01/2020.
//

#ifndef EX2_FRACTAL_H
#define EX2_FRACTAL_H


#include <vector>
#include <string>
#include <bits/unique_ptr.h>
#include "cmath"

/**
 * Fractal super-class
 */
class Fractal
{
public:
    /**
     *  constructor
     * @param size dim of object
     */
    Fractal (int size) : size (size)
    {};

    /**
     * Create Board
     * @param i starting row index
     * @param j starting col index
     * @param dim amount of shapes to create
     */
    virtual void drawFractal (int i , int j , int dim) = 0;

    /**
     * Output the board
     */
    virtual void draw ();

    /**
     * def destructor
     */
    virtual ~Fractal () = default;

protected:
    int size;
    std::vector<std::vector<char>> board;
};

/**
 * SierpinskiCarpet type Faractal
 */
class SierpinskiCarpet : public Fractal
{
public:
    /**
    *  constructor
    * @param size dim of object
    */
    SierpinskiCarpet (int size);

    /**
     * Output the board
     */
    void drawFractal (int i , int j , int dim) override;
};

/**
 * SierpinskiTriangle type Faractal
 */
class SierpinskiTriangle : public Fractal
{
public:
    /**
    *  constructor
    * @param size dim of object
    */
    SierpinskiTriangle (int size);

    /**
    * Output the board
    */
    void drawFractal (int i , int j , int dim) override;

};

/**
 * Vicsekfractal type Faractal
 */
class Vicsekfractal : public Fractal
{
public:
    /**
    *  constructor
    * @param size dim of object
    */
    Vicsekfractal (int size);

    /**
    * Output the board
    */
    void drawFractal (int i , int j , int dim) override;


};

/**
 * Factory to create correct pointer
 */
class FractalFactory
{
public:
    /**
     * Create pointer of the cur Fractal
     * @param num type
     * @param size amount of shapes
     * @return pointer to correct type
     */
    std::unique_ptr<Fractal> createFractal (int num , int size)
    {
        if (num == 1)
        {
            return std::make_unique<SierpinskiCarpet> (size);
        }
        if (num == 2)
        {
            return std::make_unique<SierpinskiTriangle> (size);
        }
        else
        {
            return std::make_unique<Vicsekfractal> (size);
        }
    }
};

#endif //EX2_FRACTAL_H

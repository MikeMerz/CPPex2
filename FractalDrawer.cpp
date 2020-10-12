#include <iostream>
#include "Fractal.h"
#include <boost/filesystem.hpp>
#include <boost/tokenizer.hpp>
//-------------------------------- define-------------------
#define MIN_FRACTAL_TYPE 1
#define MAX_FRACTAL_TYPE 3
#define MAX_DIM_SIZE 6
#define MIN_DIM_SIZE 1
#define ALLOWED_LEANGTH 3
#define EXPECTED_ARGUMENT_AMOUNT 2
//------------------------------typedef------------------
typedef boost::tokenizer<boost::char_separator<char>> Tok;
//-----------------------functions----------------------
/**
 * Function to outprint the error exit and close the file
 * @param in current stream
 */
void handleFailure (boost::filesystem::ifstream & in);

int main (int argc , char *argv[])
{
    if (argc != EXPECTED_ARGUMENT_AMOUNT)
    {
        std::cerr << "Usage: FractalDrawer <file path>" << std::endl;
        exit (EXIT_FAILURE);
    }
    boost::filesystem::path p (argv[1]);
    //checks if file exists and with correct filename ending
    if (! boost::filesystem::exists (p))
    {
        std::cerr << "Invalid input" << std::endl;
        exit (EXIT_FAILURE);
    }
    boost::filesystem::ifstream in (p);
    if (p.filename ().string ().find_last_of (".cvs") == std::string::npos)
    {
        std::cerr << "Invalid input" << std::endl;
        exit (EXIT_FAILURE);
    }
    boost::char_separator<char> sep {","};
    FractalFactory factory;
    std::string line;
    getline (in , line);
    Tok tok {line , sep};
    std::vector<std::unique_ptr<Fractal>> vec;
    while (in.good ())
    {
        // check if valid,2 col means we have 1 , and they have the same index
        if (line.find_first_of (',') != line.find_last_of (','))
        {
            handleFailure (in);
        }
        if (line.size () != ALLOWED_LEANGTH) // checks if the line in the correct length
        {
            handleFailure (in);
        }
        for (auto const & t:tok)
        {
            if (! isdigit (t[0]))
            {
                handleFailure (in);
            }
        }
        int type = std::stoi (*tok.begin ()); // convert first to a number and check if valid
        if (type < MIN_FRACTAL_TYPE || type > MAX_FRACTAL_TYPE)
        {
            handleFailure (in);
        }
        int dims = std::stoi (
                (*(++ tok.begin ()))); // convert second to a number and check if valid
        if (dims > MAX_DIM_SIZE || dims < MIN_DIM_SIZE)
        {
            handleFailure (in);
        }
        vec.push_back (factory.createFractal (type , dims));
        vec.back ()->drawFractal (0 , 0 , dims);
        getline (in , line);
    }//end of file
    //reverse the vector
    std::reverse (vec.begin () , vec.end ()) ;
    for (auto const & i:vec)
    {
        i->draw ();
    }
    return 0;
}

/**
 * Function to outprint the error exit and close the file
 * @param in current stream
 */
void handleFailure (boost::filesystem::ifstream & in)
{
    std::cerr << "Invalid input" << std::endl;
    in.close ();
    exit (EXIT_FAILURE);
}

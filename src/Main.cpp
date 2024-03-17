#include<iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <cstring>
#include "VisitorCount.h"

using namespace std;

/**
 * @brief The main function takes input visitor data file as command line parameter.
 *        This function perse the visitor arrival & deperture data and store sorted order
 *        using two multiset data structure. This function call FindMaxVisitors() method
 *        of CVisitorCount class to find the maximum visitor count and time period of the 
 *        maximum visitor count
 * 
 * @param argc This parameter is used to count number of command line arguments 
 * @param argv This parameter is used to pass command line parameters to the program
 * @return int main() function return 0 on SUCCESS and return - 1 on FAILURE
 */

int main(int argc, char* argv[])
{
    //check if a input filename is passed, argc should be 2 for correct execution of the program
    if( argc != 2 )
    {
        cerr << "Invalid Command Line\nUsage: " << argv[0] << " Missing Input File\n" ;
        return -1;
    }
    
    //Check if input file is a text file (.txt) or not
    if(!strstr(argv[1], ".txt"))
    {
      cerr << "Input File is not a Text File (.txt)";
      return -1;
    }

    // storing input file name from first argument from command line
    string input_file_name(argv[1]); 
    ifstream input_file_stream(input_file_name);

    // check if the inpt file open sucessfully
    if(!input_file_stream.is_open())
    {
      cerr<<"Unable to Open File: "<<argv[1]<<endl;
      return -1;
    }
    
    // multiset to store arrival and departure time from the input file
    multiset<string> arrival_data_set;
    multiset<string> departure_data_set;
    string line;
    string arrival_time;
    string departure_time;

    // parsing input file line by line seperated by comma
    while(getline(input_file_stream,line)) {
     
     stringstream string_stream(line);
     getline(string_stream, arrival_time, ',');
     getline(string_stream, departure_time, ',');

     // storing each arrival time & departure time in two multisets, so that during
     // insertion time arrival & deperture time data set will be in sorted order
     arrival_data_set.insert(arrival_time);  
     departure_data_set.insert(departure_time);
    }

    // create VisitorCount Class object to call FindMaxVisitors() method
    CVisitorCount CVisitorCountObj;
    //Calling FindMaxVisitors() method and passing arrival data set & deperture data set 
    CVisitorCountObj.FindMaxVisitors(arrival_data_set, departure_data_set);

    return 0;
}

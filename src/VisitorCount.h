#ifndef VISITORCOUNT_H
#define VISITORCOUNT_H

#include <iostream>
#include<set>

using namespace std;

/**
 * @brief This Class provide public method FindMaxVisitors() to find maximum number of visitors
 *        and time durations, based on visitor arrival and departure data as input file
 * 
 */
class CVisitorCount {

public:

// Public method to find maximum number of visitors
// and time durations, based on visitor arrival and departure data as input file
void FindMaxVisitors(multiset<string>const& arrival, multiset<string> const& departure);

};

#endif
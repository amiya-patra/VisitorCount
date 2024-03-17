#include<iostream>
#include <fstream>
#include <sstream>
#include <set>
#include<vector>
#include "VisitorCount.h"

using namespace std;


/**
 * @brief  FindMaxVisitors() function find time duration when maximum number of visitor present in the
 * museum. It also find and display maximum number of visitors on standard output   
 * 
 * @param arrival This parameter pass the sorted arrival data set stored in multiset from the input file 
 * @param departure This parameter pass the sorted departure data set stored in multiset from the input file
 * 
 * @retval This fnction doesnot return any value. It display result on standard output
 */


// Method to find the time when the maximum number of visitor present in the museum
void CVisitorCount :: FindMaxVisitors(multiset<string> const& arrival, multiset<string>const& departure)      
{
    int visitor_cnt = 0;      // keep track of the total number of visitors at any time in museum
    int max_visitor_cnt = 0;  // keep track of the maximum number of visitors in the museum
    string max_start_tm = "";    // keep track of the start time when there are maximum visitors
    string max_end_tm = "";     // keep track of the end time when there are maximum visitors
   
    multiset<string>::iterator iter_arrival = arrival.begin(), iter_departure = departure.begin();
   
    while (iter_arrival != arrival.end() && iter_departure != departure.end() ) {
    
        if(*iter_arrival <= *iter_departure)
        {
            //Increasing visitor_cnt by 1 when arrival time is less than departure time 
            visitor_cnt++;
           // update the maximum count of visitors 
           //when visitor count is greater than max count
            if (visitor_cnt > max_visitor_cnt)
            {
                max_visitor_cnt = visitor_cnt;
                //storing current arrival time as start time when visitor count is max
                max_start_tm = *iter_arrival;  
                //storing current departure time as end time when visitor count is max
                max_end_tm  = *iter_departure;
            }
            // increment index of arrival set
            iter_arrival++;
        }
        else //Decrease visitor_cnt by 1 when arrival time is greater than departure time 
        {
           visitor_cnt--;
            // increment index of departure set to process the next departure time
           iter_departure++;
        }
    
   }
   
      // print the result to standard output in the form
      // <start time>-<end time>;<number of visitors>
      cout<<max_start_tm<<"-"<<max_end_tm<<";"<<max_visitor_cnt;
     
} 




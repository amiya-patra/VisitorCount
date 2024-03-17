Algorithm of Finding the time period and maximum number of visitors
===================================================================

1. Read input text file as command line argument, where every line is the entering and leaving time
values of one visitor separated with commas.

2. Perse comma sepearated arrival and deparature time from input file.

3. Store arrival, deparature time into two seperate multiset data structure as arrival & deparature time 
   can be dupicate. 
   Note: While inserting the arrival and departure data into multiset data structure, the data gets sorted 
   in O(logN) time in ascending order. 

 4. visitor_cnt, max_visitor_cnt, max_start_tm & max_end_tm flags are used to keep track visitors count at   
    given time, maximum visitor, start time and end time respectively. 

 5. Process all events (arrival & departure) in sorted order stored in multiset data stucture in the following 
    way:
    a. If the next event is arrival, increase the number of visitor by 1 and update the maximum visitor count found so far, if the current visitor count is more. Also Move the pointer of multiset container by 1. 
    Update max_start_tm value with current time data from arrival multiset and max_end_tm with current
    time value from departure multiset.

    b. If the next event is a departure, decrease the visitor count by 1. Also Move the pointer of multiset container by 1.

    Note: When comparing two events time, The event with less or equal than other time event is treated
          as arrival time. The time which is greater treated as departure time.
          example: In case of  10:30 and 11:25. arrival event will be 10:30 and departure 11:25

6. When all the time data of arrival multiset are compared then
    a. max_visitor_cnt print the maximum visitor count
    b. max_start_tm print start time when maximum visitor count
    c. max_end_tm print the end time when maximum visitor count


Time Complexity & Space Complexity Analysis:
===========================================

A. Inserting the arrival & departure data from input file to multiset takes O(logN) time 
   as data stores in Binary serach tree.
   As we are comparing sorted arrival time with sorted departure time we will have maximum 
   2N comparison. where N is the number of arrival data and another N will be number of 
   departure data. So the over all time Complexity is O(N).

B. As we are using two multisets for storing the arrival & departure time 
   the space complexity will be O(N), where N is the  number of arrival or departure data.


   Note: As per given input file visitors.txt the answer:
    Maximum Visitor Count: 17
    Start time : 11:10
    End time : 11:10
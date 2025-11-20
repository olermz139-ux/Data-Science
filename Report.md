# Project 2 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project)

  *The class on this project is the readings of a wind turbine. The attributes of each object are: sample ID number, date, 
time, the active power output of the turbine, wind speed, theoretical power output, and wind direction. Hence each object 
  describes the conditions at which measurements were taken for a wind turbine. The data is sorted out by date and time. All 
  the measurements taken correspond to January, so they are sorted out by day 1-31  and then the time of day from 0:00 to 
  23:59.*

* The time complexities of each method in the Stack and Queue classes
  
  *POP: O(1) constant*
  
   *PUSH: O(1) constant*
  
   *SEARCH: O(N) linear*
  
   *PRINT: O(N) linear*

   *ENQUEUE: O(1) constant*
  
   *DEQUEUE: O(1) constant*
  
   *SEARCH: O(N) linear*
  
   *PRINT: O(N) linear*
   
  
* Justify your use of pointers in the Queue (i.e. the direction of the arrows between the Nodes) as it relates to the complexity of the enqueue and dequeue methods
  
 *The Queue keeps track of the front and the back as new nodes are added to the back but delete nodes are taken from the front FIFO the nodes are set to point at the element following from front to back. This makes the algorithm more efficient cause when using the method enqueue there is only a need to change the back pointer to the new item and the previous back to point to the new item. The same can be said of the dequeue method which only updates the front of the queue. Meaning there is no need to change all the pointers when an element is added or deleted.*  
  
* An explanation of when and why the 10 objects in the main function changed their order
  
 *The elements of the 10 objects change order when they are changed from the stack structure into the queue structure 
 because the elements are added at different places. Using the stack class elements are added at the top, hence they are i 
 reverse order of the vector indexing, and the queue adds elements to the end and therefore the order is the same as the 
 vector indexing.*


**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

# Project 5 Report

Answer the following prompts directly in this file:
* Information about your dataset. You will be assigned a different grader for this project.
 
The class on this project is the information of a wind turbine on a given day. The attributes of each object are: sample ID number, date, time, the active power output of the turbine, wind speed, theoretical power output, and wind direction. Hence each object describes the conditions at which measurements were taken for a wind turbine. The data is sorted out by the unique identifier, sample ID.
 
* Create graphs for the number of collisions for inserting your dataset into all 20 hash tables.
  * Clearly label the graph titles and axes.
  * Set up the graph in a way that makes the most sense to you. Here are some options I have seen before:
    * Using a line graph to track the *individual* collision counts as each insertion is made. High-valued blips happen in open addressing when rehashes occur.
    * Using a line graph to track the *cumulative* collision count as each insertion is made. Vertical jumps happen in open addressing when rehashes occur.
    * Using a line graph to track the *average* number of collisions per insertion, where each hash table has one value and you can see the trends as the initial table size grows.

![LP1](imagesP5/LP_M1.png)
![LP2](imagesP5/LP_M2.png)
![LPtable1](imagesP5/LPtable_M1.png)
![LPtable2](imagesP5/LPtable_M2.png)

![QP1](imagesP5/QP_M1.png)
![QP2](imagesP5/QP_M2.png)
![QPtable1](imagesP5/QPtable_M1.png)
![QPtable2](imagesP5/QPtable_M2.png)

![SC1](imagesP5/SC_M1.png)
![SC2](imagesP5/SC_M2.png)

* Using the graphs, analyze why the collision counts are different for the different size hash tables. Use what you know about your keys and the hash tables to justify why the collision counts make sense.

It is observable from the graphs made for all methods: separate chaining, linear probing, and quadratic probing, regardless of the method used to get the key, that as the table size increases the number of collisions decreases. It is important to recall that the last step of the hash function is to mod by the table size, hence by increasing the table size we decrease the number of collisions because the index changes as we mod by a different number. This is the same principle behind rehashing after the table is mostly filled there are more chances that the new value-added collides with one already in the table. Therefore, the table size is doubled and upgraded to the nearest prime. 
For this particular data set, increasing the capacity of the table by twice the vector size proved to be the most effective as there was no need for rehashing after this. 

* Determine which global function works best as the key for your dataset objects based on the collision counts.

Method one for obtaining the key used only the unique identifier, whereas method two used the unique identifier plus the theoretical power output of the turbine. The theoretical power output was chosen because it had more sample variability. A turbine's theoretical power depends on multiple elements, whereas wind direction and actual wind power are more constant. Moreover, the actual wind power can currently be zero. 
Comparing the three elements we can see that adding the theoretical power (Method 2) to get a key decreased the number of collisions in all three cases. This is because the sample IDs are consecutive numbers from 1-3816. Hashing two continuous values with only one digit of difference increases the likelihood of keys hashing into the same value i.e. a collision; by adding a random number, in this case, the theoretical power output, to the sample ID value we decrease the probability of two keys colliding.

* Draw conclusions about which hash collision detection method works best on your dataset (separate chaining or open addressing).

Between the two methods of open addressing, Linear Probing and Quadratic Probing, the second proved to be more efficient which is what we expected. Quadratic Probing is a more efficient method because there is no need to go index by index to find a vector after a collision occurs but it also helps with the spread of the elements added. Nonetheless, for this particular data set, separate chaining is the method with fewer collisions and with a logarithmic trend through all five different table sizes.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

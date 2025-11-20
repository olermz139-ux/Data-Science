# Project 4 Report

Answer the following prompts directly in this file:
* Information about your dataset (you will be assigned a different grader for this project).
  
The class on this project is the information of a wind turbine on a given day. The attributes of each object are: sample ID number, date, time, the active power output of the turbine, wind speed, theoretical power output, and wind direction. Hence each object describes the conditions at which measurements were taken for a wind turbine. The data was originally sorted out by the unique identifier, sample ID, but for the purposes of this project and because the operators are overloaded using the sample ID the CSV file is sorted  by the column wind direction. This made the objects be in a shuffled order when added into the vector.
  
* Analyze the data. Graph the number of reads and writes for each sorting algorithm and look at how the number of reads and writes grows when the size of the data set grows. Compare and contrast the different sorting algorithms and draw conclusions about which sorting algorithms are more efficient. Discuss complexities and their effects.

![table](images/table.png)

![bubble](images/bubble.png)

![merge](images/merge.png)

![insertion](images/insertion.png)

![heap](images/heap.png)

![selection](images/selection.png)

For the analysis of the sorting algorithms to sort the vector of objects type Turbine, it is important to note that a stability discussion is not necessary because the unique identifier is used to overload the operators, and the unique identifier can't be repeated. The time complexities are listed in the table; among the sorting algorithms that have quadratic time complexities, bubble sort is the least efficient. This is because the vector is fully read to compare items and swap if necessary so it requires more reads and writes than any other sorting algorithm with said complexity. Furthermore, selection sort requires less writes. The writes increase linearly as the size of the vector increases. Among the algorithms with quadratic complexity, selection sort is the best. Not only because it requires less writes, but because as seen by the linear trend in the graphs it is the one that is closer to being linear as the R-alue is closer to 1. Yet, the most efficient algorithm is merge sort, because of the splitting method when increasing the number of items it will not require significantly more passes. If the vector is doubled it will need to split and do the merges one more time before returning the original size vector. 

* Look at the output from the stabilityTest function and answer the following questions:
  * How are the names sorted by default?
  * How is the output from the two stable sorting algorithms different from the two unstable ones? Be specific in your answer, and use what you know about how each sorting algorithm works to justify your observations.

The default ordering of the name is alphabetic order but only taking into account the first name. 

                                  People (Default ordering)
                                  
                                        First     Last
                                        
                                        Alex      White
                                        
                                        Blake     Black
                                        
                                        Jamie     Brown
                                        
                                        Jordan    Black
                                        
                                        Kelsey    Brown
                                        
                                        Nicky     White
                                        
                                        Red       White
                                        
                                        Robin     White
                                        
                                        Sam       Black
                                        
                                        Skylar    Brown
                                        

For stable algorithms, the order is:

Bubble Sort (Reads: 75, Writes: 45) and Insertion Sort (Reads: 39, Writes: 24) and Merge Sort (Reads: 87, Writes: 61)  

                                        First     Last
                                        
                                        Blake     Black
                                        
                                        Jordan    Black
                                        
                                        Sam       Black
                                        
                                        Jamie     Brown
                                        
                                        Kelsey    Brown
                                        
                                        Skylar    Brown
                                        
                                        Alex      White
                                        
                                        Nicky     White
                                        
                                        Red       White
                                        
                                        Robin     White
                                        
For the unstable sorting algorithms, the order is:

      Heap Sort (Reads: 198, Writes: 88)                  Selection Sort(Reads: 41, Writes: 27)
      
      First     Last                                                 First     Last
      
      Jordan    Black                                                Blake     Black
      
      Sam       Black                                                Jordan    Black
      
      Blake     Black                                                Sam       Black
      
      Jamie     Brown                                                Kelsey    Brown
      
      Kelsey    Brown                                                Jamie     Brown
      
      Skylar    Brown                                                Skylar    Brown
      
      Red       White                                                Red       White
      
      Nicky     White                                                Robin     White
      
      Robin     White                                                Alex      White
      
      Alex      White                                                Nicky     White


All of the sorting algorithms, sort the list of names by last name. Nevertheless, it can be observed that for the stable algorithms (bubble, insertion, and merge  sort) the relative order of the names is kept as they appear in the default ordering of the list. For the last name Black in the default order, the first name order is Blake, Jordan, and Sam, which is the same order they have after sorting by last name. This behavior can be observed for the two other last names. On the other hand, it can be observed that the output for the unstable algorithms (heap, and selection sort) of the first name as per the default ordering is not the same. In fact, for  heap sort the first names of the last name Black and White are different, and for the last names of Brown and White, the first names are different in selection sort. 

The explanation above clearly expresses the meaning of stability in a sorting algorithm; by definition, stability is used to describe whether or not duplicate values are swapped during sorting. Because the relative order of first names is kept the three stable sorting algorithms have the same output, and because heap and selection sort are unstable sorting algorithms they have a different output. Moreover, heap and selection sort have two different outputs because the sorting method is different. 

* Answers to the following questions: 
  * If you need to sort a contacts list on a mobile app, which sorting algorithm(s) would you use and why? 
  * What about if you need to sort a database of 20 million client files that are stored in a datacenter in the cloud?
 
To sort a list of contacts, I would choose quick sort because it is both stable and the time complexity is Nlog(N). Nevertheless, quick sort for bigger size vectors can increase the time complexity to quadratic so merge sort would be a more efficient choice.

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

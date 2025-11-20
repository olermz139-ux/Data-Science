# Project 3 Report

Answer the following questions directly in this file:
* You will have a different grader again, so make sure your report includes information about your dataset.
  
  *The class on this project is the readings of a wind turbine. The attributes of each object are: sample ID number, date, 
  time, the active power output of the turbine, wind speed, theoretical power output, and wind direction. Hence each object 
  describes the conditions at which measurements were taken for a wind turbine. The data is sorted out by date and time. All 
  the measurements taken correspond to January, so they are sorted out by day 1-31 and then the time of day from 0:00 to 
  23:59.*
  
* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
  
  *The most prominent difference can be observed in the binary search tree because nothing is balancing the tree. 
  Meaning that when digits are inserted in order, the tree is built diagonally with the new value always added as a right 
  child. That makes the depth search for each value equal to its value. Conversely, it is observable that the depth search 
  value decreases significantly if the values are added randomly because it balances the structure tree.*

  *On the other hand, the AVL tree depth values for both cases are very similar. This behavior is expected due to the fact 
  that the AVL tree balances its structure when a value is added, and so there is not an observable difference depth 
  search for values.*

  *Finally, the splay tree has a mixed behavior between the BST and the AVL tree. The values of the random insertion depths     present values that are smaller and have less variability than the values from the in-order insertion. The splay tree 
   like AVL readjusts itself to have values recently added to become more accessible, but if the values are added in order      then even with the rotations the tree will still have the slanted property that the binary search tree has.*
  
* How do the depths of each custom-data-type tree compare to each other?
  
  *The sample ID is the attribute that is used as a unique identifier. The sample ID is an integer that denotes the 
  measurement taken at a certain date, and time and with specific power outputs. The sample ID starts at 1 and increases as 
  with a step of 1 as more data is recorded for the sample. Therefore the behaviour for the tree depth values mimics the 
  integer trial from 1-100. That is to say that the best depth values will be for the AVL tree as it balances better than 
  the other tree algorithms.*
  
* Why do the depths of the second custom-data-type Splay Tree make sense?
  
  *The values make sense because once the value is found in the tree is found and the depth value is recorded, the value is
  splayed meaning that the value is changed to the root, and hence once the value is looked up for again the depth will 
  always be zero cause it will remain at the root until a new value is looked for.*
  
* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
  * Your graphs should have clear labels for both x and y axes.
  * Save your graph files in the graphs folder.
  * You do not need to graph the depths of the integer type trees or the Splay Tree that finds each object 5 times in a row, but you can if you feel it helps you analyze the data.
  * An example graph spreadsheet and an example graph image have been included in the starter code.
  * Here is how you include an image in your Report.md file:
![BST](graphs/BST.png)
![AVLTree](graphs/AVLTree.png)
![SplayTree](graphs/SplayTree.png)
![SplayTreeZoom](graphs/SplayTreeZoom.png)
* Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.
  
*The type of graph chosen for analysis is a scattered plot made with Excel. In the case of the splay tree a second plot is added to provide more clarity to the values being graphed; to achieve that 5 values were taken out from the original data set. It is known that the complexities for each of the trees: BST, AVL, and Splay respectively O(N), O(log(N)), and O(log(N)). From the plot, it can be observed that the worst scenario is shown for the BST where we can see a linear trend because the nodes only have a right child. For the AVL tree and the Splay Tree Zoom plot we can see that there are more values of depth are repeated, this is due to the fact that the trees are more balanced structurally because, through each addition of a node, the tree rebalances itself.* 
*Nevertheless, it is important to notice that the depth values of the splay tree are smaller than the values of the AVL, and they almost look like they are inverted. Because the splay function makes a rotation to the root of a value recently added it becomes quicker to search for items because the next value inserted is larger than the previous values and hence is added closer to the root cause the insertion still follows the rules of the Binary Search Tree. Furthermore, with the splay tree plot, we can observe that for the first few values, the depth search is not as good, and then it stabilizes due to splaying.*

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

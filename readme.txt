/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Hanuman Sai Chanukya Srinivas Chilamkuri
Hours to complete assignment: 8

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/

The assignment is about to print the solar system by building a command-line argument which reads the particular file. I accomplished to 
display the solar system in SFML window on the background which i have chosen. Planets are arranged in an order depending on planets.txt 
file.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/

In this assignment I used a little bit of stack data structure while saving object to the vector which is used to display the position of 
planets. 

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/

1. celestial body object is drawable and SFML while loop uses window.draw(obj). In this code I used "i" in the place of "obj". 
Implementation loads univese from stdin. Body class is overloaded by using ">>" to read in a row from universe file. It supports arbitrary 
number of body objects per universe file. We can change arbitrary universe size and given SFML window size by changing parameters declared 
in main.cpp file.

2. Makefile is included with "all" and "clean" functions. "all" function is building NBody and all the dependencies are correct in  
makefile. screenshot of my output is included with the name "screenshot.png" in the attached file.

3. In the "main.cpp" file I loaded my image into texture, texture into sprite and then set the position of backgroung image. For every 
planet named in this code, same type of process is done. When the vector is working then to overload the stream input operator ">>" symbol 
is used and read in the universe file to set up planets in a row.

4. I used a simple and cool backgroung image to display planets on it. I used an image containing of tiny stars in it. I used a backgroung 
image named "universe.jpg".

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/

I didn't receive any help from the classmates or anyone else.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/

No serious problem is encountered while i am writing the code.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
 
I added a background image named "universe.jpg" to the planets. It displays when the code is compiled with "./NBody < planets.txt".

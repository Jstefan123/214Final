# Final Project: Traffic Sign Recognition
##### Contributors: Aric Landy, John Landy, John Stefan

### Introduction
This project uses linear algebra and simple but effective machine learning concepts in order to recognize traffic signs. 

### Key Concepts
Using the span of several images for each sign, our project calculates the minimum error of projection onto the span of each different image in the database, and thus predicts the road sign. 

### Optimization Opportuninties
Added functionality of this project could work in basic machine learning conepts by adding images to the database as they are categorized. This would allow the program to grow more accurate as it takes in more input.

Edge detection could also be used with signs containing numbers (speed limit, interstate, etc.) to further optimize. This kind of technology could be used in autonomous vehicles to determine the speed limit, the number of the interstate, and more.

Implementation of least squares to further optimize the error calculation could allow the project to gain accuracy. This topic is currently being looked into.

###### Text File Format
Our program works by reading in only one text file manually. While the number of text files is actually very large due to the large database of our program, we can accomplish this by formatting our text file to efficiently find the other text files. For each sign, our text file reads in the name, the number of corresponding text files that should go into the database (three times the number of images for red, blue, and green channels respectively), and each of those files below. Our program can read input efficiently using fstream objects to fill the database quickly.

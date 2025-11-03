# COP3530 - Project 2: Comparing Hash Tables
By Kaiden Bartrum, Liam Gale, and Jeremiah Hidayat

# Development Documentation
## Movie Struct
Movie structs that hold the alphanumeric id, the title, the year created, and the list of genres. This is the data being 
inputted into the Hash table. 

## Parser Documentation
The parser reads all the datapoints from the IMDB title TSV and returns a vector of movie structs. 

## Hash Table Template 
This is the template that you should edit to implement the different hash tables. I made a template to ensure the 
implementations are similar in functionality and function calling to make the rest of the implementation streamlined.

How I set it up is that there is an abstract base class in the [hashTemplate](./include/hashTemplate.h) file.

see the [mock hash table](./include/mockHash.h) for the syntax and an example implementation of the template. 
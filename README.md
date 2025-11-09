# COP3530 - Project 2: Comparing Hash Tables with IMDb
By Kaiden Bartrum, Liam Gale, and Jeremiah Hidayat

A C++ project that benchmarks two different hash table implementations — **Separate Chaining** and **Open Addressing** — using IMDb movie data.  
Built as part of a data structures and algorithms coursework project.

## Features

- Compare performance between:
    - **Separate Chaining Hash Table**
    - **Open Addressing Hash Table**
- Support for:
    - Insertion of IMDb movie records (Key:value = Title:Genres)
    - Search and removal operations
    - Load factor tracking
    - Automatic rehashing and resizing
- CLI-based interaction

## Dependencies

- C++17 or later
- CMake 3.30+
- CLion (recommended)
- IMDb Dataset – [title.basics.tsv.gz](https://datasets.imdbws.com/title.basics.tsv.gz)
## Setup 

**We used CLion to make and run this project so we advise to open the project from version control before following the instructions.**

### Steps to run the project
- Open the project in CLion by opening from version control.
- go to Run > Edit Configurations > HashTableCLI >> Working Directory > ```\set to your project directory\```
- To get the database file for IMDb, visit this [link](https://datasets.imdbws.com/title.basics.tsv.gz).
- Extract the file and put the `title.basics.tsv` file in the [data directory](data).

if you are getting this error when trying to insert from the file:
```Error: Cannot open file data/title.basics.tsv```
Make sure that the default workspace is set correctly for the makefile to read this file: 
- go to Run > Edit Configurations > HashTableCLI >> Working Directory > ```\set to your project directory\```


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

## Setup 

To get the database file for IMDb, visit this [link](https://datasets.imdbws.com/title.basics.tsv.gz).
Extract the file and put the `title.basics.tsv` file in the [data directory](data).

Make sure that the default workspace is set correctly for the makefile to read this file: 

in Clion: Run > Edit Configurations > Working Directory > set to your project root.
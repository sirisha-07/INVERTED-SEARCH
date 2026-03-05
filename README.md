# Inverted-Search

A C-based implementation of an Inverted Index that enables efficient word-based searching across multiple text files.

# Overview

This project builds an inverted index from input text files.  
An inverted index maps words to the files in which they appear, allowing fast search operations without repeatedly scanning entire files.

# Features

- Create an index from multiple text files
- Search for words across indexed files
- Displays file names where the word appears
- Uses hashing and linked lists for storage
- Dynamic memory management

# How It Works

1. The program reads input text files.
2. Words are extracted and stored in a hash table.
3. Each word node maintains a list of files in which it appears.
4. When a search query is entered, the program retrieves results directly from the index.

# Tools
- Language: C, File I/O
- Data Structure: Hash Table, Doubly Linked List

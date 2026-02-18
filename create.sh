#!/bin/bash

# Check if two arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <file-path> <problem-name> <link-to-problem>"
    exit 1
fi

# Get the file path and problem name from the arguments
FILE_PATH="$1"
PROBLEM_NAME="$2"
PROBLEM_LINK="$3"

# Create the directory if it doesn't exist
DIR_PATH=$(dirname "$FILE_PATH")
mkdir -p "$DIR_PATH/"

# Get the current date
CURRENT_DATE=$(date '+%B %d, %Y')

# Add the current date and problem name as a comment and create the .cpp file
{
    echo "// Created on $CURRENT_DATE by Adriano"
    echo "// Problem: $PROBLEM_NAME"
    echo "// Link: $PROBLEM_LINK"
} > "$FILE_PATH"

cp template/Makefile $FILE_PATH/..
cd $FILE_PATH 

# Notify the user
echo "File created at: $FILE_PATH"

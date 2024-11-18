#!/bin/bash

# Check if a filename is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <source_file.c>"
    exit 1
fi

# Compile the provided C++ file
gcc "$1" -o temp_exec

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    ./temp_exec
    
    # Remove the temporary executable after running
    rm ./temp_exec
else
    echo "Compilation failed."
fi

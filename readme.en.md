# C Data Structure

**언어 선택 / Language Selection:**

- [🇰🇷 한국어 (Korean)](readme.md)
- [🇺🇸 English](readme.en.md)
  
This repository contains basic data structures implemented in C language. It is designed to help for me to understand the fundamentals of data structures by implementing and practicing how they work.

## Implemented Data Structures

1. **Singly Linked List**
   - A singly linked list is a data structure where each node contains data and a pointer to the next node.
   - [Singly Linked List Code](https://github.com/limJhyeok/c-data-structure/blob/main/app/singly_linked_list.c)
   
2. **Doubly Linked List**
   - A doubly linked list is a data structure where each node contains data, a pointer to the next node, and a pointer to the previous node.
   - [Doubly Linked List Code](https://github.com/limJhyeok/c-data-structure/blob/main/app/doubly_linked_list.c)
   
3. **Stack**
   - A stack is a LIFO (Last In, First Out) data structure where the last inserted element is the first to be removed.
   - [Stack Code](https://github.com/limJhyeok/c-data-structure/blob/main/app/stack.c)
   
4. **Queue**
   - A queue is a FIFO (First In, First Out) data structure where the first inserted element is the first to be removed.
   - [Queue Code](https://github.com/limJhyeok/c-data-structure/blob/main/app/queue.c)
   
5. **Binary Tree**
   - A binary tree is a tree structure where each node has up to two child nodes.
   - [Binary Tree Code](https://github.com/limJhyeok/c-data-structure/blob/main/app/binary_tree.c)

## Usage

### Start the container and access the bash shell
```bash
docker-compose up -d
docker-compose exec c-app /bin/bash
```

### Run the source file inside the container
```bash
./scripts/execute.sh {source_file}.c

# Example
# ./scripts/execute.sh singly_linked_list.c
```

### Setting up C/C++ extension
1. Install the C/C++ extension in VS Code.
2. Install `gcc` and `g++`.
```bash
sudo apt-get install -y gcc
sudo apt-get install -y g++
```
3. Configure `.vscode/c_cpp_properties.json`.

### Auto Formatter (Style: Google)
1. Install `clang-format` and `pre-commit`.
```bash
sudo apt install -y clang-format 
pip install pre-commit
```

2. Set up `pre-commit`.
```bash
pre-commit install
```

### Stop the container
```bash
docker-compose down
```

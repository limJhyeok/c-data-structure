# C Data Structure

이 리포지토리는 C언어를 사용하여 구현한 기본적인 자료구조들을 포함하고 있습니다. 자료구조에 대한 기본적인 이해를 돕기 위해 각 자료구조를 구현하고, 그 동작 방식을 실습할 수 있도록 작성되었습니다.

## 구현된 자료구조

1. **Singly Linked List**
   - 싱글 링크드 리스트는 각 노드가 데이터와 다음 노드를 가리키는 포인터를 가지는 자료구조입니다.
   - [Singly Linked List 코드](https://github.com/limJhyeok/c-data-structure/blob/main/app/singly_linked_list.c)
   
2. **Doubly Linked List**
   - 더블 링크드 리스트는 각 노드가 데이터, 다음 노드, 이전 노드를 가리키는 포인터를 가지는 자료구조입니다.
   - [Doubly Linked List 코드](https://github.com/limJhyeok/c-data-structure/blob/main/app/doubly_linked_list.c)
   
3. **Stack**
   - 스택은 LIFO(Last In, First Out) 방식으로 동작하는 자료구조로, 마지막에 삽입된 항목이 가장 먼저 삭제됩니다.
   - [Stack 코드](https://github.com/limJhyeok/c-data-structure/blob/main/app/stack.c)
   
4. **Queue**
   - 큐는 FIFO(First In, First Out) 방식으로 동작하는 자료구조로, 먼저 삽입된 항목이 가장 먼저 삭제됩니다.
   - [Queue 코드](https://github.com/limJhyeok/c-data-structure/blob/main/app/queue.c)
   
5. **Binary Tree**
   - 이진 트리는 각 노드가 두 개의 자식 노드를 가지는 트리 형태의 자료구조입니다.
   - [Binary Tree 코드](https://github.com/limJhyeok/c-data-structure/blob/main/app/binary_tree.c)

## 사용법

### container 구동 및 bash 진입
```bash
docker-compose up -d
docker-compose exec c-app /bin/bash
```

### 구동된 container 안에서 결과 확인
```bash
./scripts/execute.sh {source_file}.c

# 예시
# ./scripts/execute.sh singly_linked_list.c.c
```

### c/c++ extention
1. vscode에서 c/c++ extention 설치
2. gcc/g++ 설치
```bash
sudo apt-get install -y gcc
sudo apt-get install -y g++
```
3. .vscode/c_pp_properites.json 설정


### 자동 포매터(style: google)
1. clang-format, pre-commit 설치
```bash
sudo apt install -y clang-format 
pip install pre-commit
```

2. pre-commit 설치
```bash
pre-commit install
```
### 컨테이너 종료
```bash
docker-compose down
```

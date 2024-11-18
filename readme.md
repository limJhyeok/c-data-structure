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
# ./scripts/execute.sh hello_world.c
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
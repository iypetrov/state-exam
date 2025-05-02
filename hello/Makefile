build:
	@g++ main.cpp -o bin/main

run:
	@./bin/main

valgrind:
	@docker build -t cpp-valgrind .
	@docker run --rm cpp-valgrind

bin/lox: $(wildcard src/*.c src/*.h)
	mkdir -p bin
	clang -Wall -Werror -Wextra -Wpedantic $< -o bin/lox

clean:
	rm -rf bin

.PHONY: clean

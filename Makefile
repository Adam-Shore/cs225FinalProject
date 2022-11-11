CXX=clang++-10
INCLUDES=-Iincludes/
CXX_FLAGS=-std=c++20 -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec

bin/exec: src/driver.cc src/facebook.cc
	${CXX} ${CXX_FLAGS} $^ -o $@



.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf bin/*
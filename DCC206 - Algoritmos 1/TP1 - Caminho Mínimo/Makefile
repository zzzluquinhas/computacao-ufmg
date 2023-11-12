# Makefile

# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS := $(wildcard *.cc)

# Object files
OBJS := $(SRCS:.cc=.o)

# Target executable
TARGET := tp01

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run:
	./$(TARGET)

test_cases_dir := test_cases

eval: all
	@echo "Running tests..."
	@passed=0; failed=0; \
	failures=""; \
	for input_file in $(test_cases_dir)/inputs/*; do \
		output_file="$(test_cases_dir)/outputs/$$(basename $$input_file .txt).sol"; \
		if ! ./$(TARGET) < "$$input_file" | diff -q - "$$output_file" > /dev/null; then \
			echo "Test case $$input_file failed"; \
			failures="$$failures $$input_file"; \
			failed=$$((failed + 1)); \
		else \
			passed=$$((passed + 1)); \
		fi; \
	done; \
	echo "Passed: $$passed"; \
	echo "Failed: $$failed"; \
	if [ $$failed -ne 0 ]; then \
		echo "Failed tests:"; \
		for f in $$failures; do \
			echo $$f; \
		done; \
	else \
		echo "Congratulations! All tests passed."; \
	fi
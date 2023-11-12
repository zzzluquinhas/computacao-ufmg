# Makefile

# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall #-DDEBUG

# Source files
SRCS := $(wildcard *.cc)

# Object files
OBJS := $(SRCS:.cc=.o)

# Target executable
TARGET := tp03

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

test_cases_dir := test_cases

eval: all
	@echo "Running tests..."
	@passed=0; failed=0; \
	failures=""; \
	for input_file in $(test_cases_dir)/inputs/*; do \
		output_file="$(test_cases_dir)/outputs/$$(basename $$input_file .txt).sol"; \
		if ! ( ./$(TARGET) < "$$input_file" | diff -y --suppress-common-lines - "$$output_file" > /dev/null ); then \
			echo "Test case $$input_file failed"; \
			failures="$$failures $$input_file"; \
			failed=$$((failed + 1)); \
			echo "Differences for test case $$input_file:"; \
			tmp_student_output="$$(mktemp)"; \
			./$(TARGET) < "$$input_file" > "$$tmp_student_output"; \
			awk '{print NR ":" $$0}' "$$tmp_student_output" > "$$tmp_student_output.numbered"; \
			awk '{print NR ":" $$0}' "$$output_file" > "$$output_file.numbered"; \
			diff -y --suppress-common-lines "$$tmp_student_output.numbered" "$$output_file.numbered"; \
			rm "$$tmp_student_output" "$$tmp_student_output.numbered" "$$output_file.numbered"; \
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

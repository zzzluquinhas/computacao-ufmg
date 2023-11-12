# Makefile

# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS := $(wildcard *.cc)

# Object files
OBJS := $(SRCS:.cc=.o)

# Target executable
TARGET := tp02

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

eval: $(TARGET)
	@echo "Evaluating results for the exact algorithm (accounting only the exact algorithm result):"
	@for input_file in test_cases/inputs/*.txt; do \
		output=$$(./$(TARGET) < $$input_file); \
		expected=$$(cat test_cases/outputs/$$(basename $$input_file .txt).sol); \
		if [ "$${output#*Exato: }" != "$$expected" ]; then \
			echo "Test case $$(basename $$input_file) failed"; \
			echo "Expected: $$expected"; \
			echo "Actual:   $${output#*Exato: }"; \
		else \
			echo "Test case $$(basename $$input_file) passed"; \
		fi \
	done

eval_greedy: $(TARGET)
	@echo "Evaluating results for the greedy algorithm"
	@total_diff=0; total_tests=0; \
	for input_file in test_cases/inputs/*.txt; do \
		exact_result=$$(cat test_cases/outputs/$$(basename $$input_file .txt).sol); \
		greedy_output=$$(./$(TARGET) < $$input_file | sed -n 's/Guloso: //p'); \
		diff=$$(echo "scale=4; 100*($$greedy_output/$$exact_result)" | bc); \
		total_diff=$$(echo "$$total_diff + $$diff" | bc); \
		total_tests=$$(expr $$total_tests + 1); \
		echo "Test case $$(basename $$input_file) - $$diff% of optimal solution"; \
	done; \
	avg_diff=$$(echo "scale=4; $$total_diff / $$total_tests" | bc); \
	echo "Average proximity from optimal: $$avg_diff%"
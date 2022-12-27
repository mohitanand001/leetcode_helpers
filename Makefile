runtest:
	@echo "running tests"
	g++ sorting_using_comparators.cpp test_sorting.cpp -o main.out && ./main.out

runtest:
	@echo "running tests"
	g++ sorting/sorting_using_comparators.cpp tests/test_sorting.cpp -o main.out && ./main.out

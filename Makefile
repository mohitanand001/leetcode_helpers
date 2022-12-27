runtest:
	@echo "running tests"
	g++ sorting/sorting_for_testing.cpp tests/test_sorting.cpp -o main.out && ./main.out

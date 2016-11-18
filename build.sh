mkdir bin scriptname >/dev/null 2>&1
g++ -std=c++11 main.cpp createFilters.cpp featureExtractor.cpp filter.cpp -o bin/test

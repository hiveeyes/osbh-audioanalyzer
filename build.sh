mkdir bin scriptname >/dev/null 2>&1

GPP=g++

# Check for modern compiler
GPP_49=g++-mp-4.9
if [ ! -z $(which $GPP_49) ]; then
    GPP=$(which $GPP_49)
fi

$GPP -std=c++11 main.cpp createFilters.cpp featureExtractor.cpp filter.cpp classifier.cpp -o bin/test

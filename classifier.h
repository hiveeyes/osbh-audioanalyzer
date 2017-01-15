#include <iostream>
#include <sstream>
#include <vector>
#include "states.h"
using namespace std;

//Classifier class. Classifies energy vector

class Classifier {
	

    //Decision Tree
    vector<vector<float>> decisionTree;

  public:
    Classifier (string s);
    void parse (string s);
	string classify (std::vector<float> energy);

};
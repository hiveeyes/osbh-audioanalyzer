#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Classifier class. Classifies energy vector

class Classifier {
	

    //Decision Tree
    vector<vector<float>> decisionTree;

  public:
    Classifier (string s);
    void parse (string s);
	int classify (std::vector<float> energy);

};
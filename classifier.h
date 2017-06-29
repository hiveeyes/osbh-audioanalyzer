#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Classifier class. Classifies energy vector

class Classifier {
	
	//Classifier type
	int classifierType;

    //Decision Tree
    vector<vector<float>> decisionTree;

    //Linear regression
    vector<vector<float>> linearComb;

  public:
    Classifier (string type, string s);
    void tree_parse (string s);
    void logistic_parse (string s);
	int classify (std::vector<float> energy);

};
#include "classifier.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Constructor. parse() does the rest
Classifier::Classifier (string s){
		this->parse(s);
}

	
/*String parser based on this idea:
Label		49 Hz		121 Hz		4		1		3
Feature		1st			2nd			State	State	State
Compare 	-55.079437	-36.502423	-		-		-
If <=		column 3	column 4	-		-		-
Else		column 2	column 5	-		-		-

Would translate to

“f0,-55.079437,2,1\n
f1,-36.502423,3,4\n
s4\n
s1\n
s3”

We use a float vectors, so each line would be:
0.0/1.0 if feature/state  -> (feature) number of feature, value to compare, vector to go to if<=, vector to go to if >=
						  -> (state) number of state

*/
void Classifier::parse (string s)
{
	std::stringstream lineStream(s);
	string line;
	vector<float> node;

	//Divide by lines
	while(getline(lineStream, line))
	{
		//Check first letter. If feature, push a 0 and the feature number
		if(line.at(0) == 'f')
		{
			node.push_back(0.0);
			//node.push_back(stof(line.substr(1,line.find(',')-1)));
			node.push_back((float)atof(line.substr(1,line.find(',')-1).data()));

			//Push the rest from the first comma
			std::stringstream tokenStream(line.substr(line.find(',')-1));
			string token;

			while(getline(tokenStream, token, ','))
			{
    			node.push_back((float)atof(token.data()));
			}

		}
		//If state, push a 1 and the state number
		else if(line.at(0)=='s')
		{
			node.push_back(1.0);
			node.push_back((float)atof(line.substr(1).data()));
		}
		else{
			cout<<"Error with classifier input string\n";
			break;
		}
    	decisionTree.push_back(node);
    	node.clear();
	}
}

/*Classify method. Follow brunches until we get a state to return.
Again:
0.0/1.0 if feature/state  -> (feature) number of feature, value to compare, vector to go to if<=, vector to go to if >=
						  -> (state) number of state
*/

string Classifier::classify(vector<float> energy)
{
	int node=0;
	while (true)
	{
		if(decisionTree[node][0]==1)
		{
			return states[(int)decisionTree[node][1]];
		}
		else if(energy[(int)decisionTree[node][1]] <= decisionTree[node][2]){
			node=(int)decisionTree[node][3];
		}
		else{
			node=(int)decisionTree[node][4];
		}

	}

}
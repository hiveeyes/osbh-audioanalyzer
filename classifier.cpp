#include "classifier.h"
#include <cmath>

//Constructor. parse() does the rest
Classifier::Classifier (string type, string s){
		if (type.compare("decision_tree")==0)
		{
			this->tree_parse(s);
			this->classifierType=0;
		}
		else if (type.compare("logistic")==0)
		{
			this->logistic_parse(s);
			this->classifierType=1;
		}
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
void Classifier::tree_parse (string s)
{
	//std::stringstream lineStream(s);
	string line;
	int linePosition;


	vector<float> node;

	//Divide by lines
	while((linePosition=s.find('\n'))!=-1)
	//while(getline(lineStream, line))
	{
		line=s.substr(0, linePosition+1);
		//Check first letter. If feature, push a 0 and the feature number
		if(line.at(0) == 'f')
		{
			//Push 0 for feature
			node.push_back(0.0);
			//node.push_back(stof(line.substr(1,line.find(',')-1)));

			//Push feature number
			node.push_back((float)atof(line.substr(1,line.find(',')-1).data()));

			//Push the rest from the first comma
			//std::stringstream tokenStream(line.substr(line.find(',')-1));
			string token;
			string values=line.substr(line.find(',')+1);
			values=line.substr(line.find(',')+1);
			int commaPosition;

			while((commaPosition=values.find(','))!=-1 || (commaPosition=values.find('\n'))!=-1)
			//while(getline(tokenStream, token, ','))
			{
				token=values.substr(0, commaPosition);
    			node.push_back((float)atof(token.data()));
    			values=values.substr(commaPosition+1);
			}
			

		}
		//If state, push a 1 and the state number
		else if(line.at(0)=='s')
		{
			node.push_back(1.0);
			node.push_back((float)atof(line.substr(1).data()));
		}
		else{
		//	cout<<"Error with classifier input string\n";
			break;
		}
    	decisionTree.push_back(node);
    	s=s.substr(linePosition+1);
    	node.clear();
	}
}

/*String parser based on this idea:
Label		OffSet     49 Hz		121 Hz		...

*/
void Classifier::logistic_parse (string s)
{
	//std::stringstream lineStream(s);
	string line;
	int linePosition;


	vector<float> node;

	//Divide by lines
	while((linePosition=s.find('\n'))!=-1)
	//while(getline(lineStream, line))
	{
		line=s.substr(0, linePosition+1);
		//Check first letter. Must be an s
		if(line.at(0) == 's')
		{
			//Push the state number
			node.push_back((float)atof(line.substr(1).data()));

			//Push the rest from the first comma
			//std::stringstream tokenStream(line.substr(line.find(',')-1));
			string token;
			string values=line.substr(line.find(',')+1);
			values=line.substr(line.find(',')+1);
			int commaPosition;

			while((commaPosition=values.find(','))!=-1 || (commaPosition=values.find('\n'))!=-1)
			//while(getline(tokenStream, token, ','))
			{
				token=values.substr(0, commaPosition);
    			node.push_back((float)atof(token.data()));
    			values=values.substr(commaPosition+1);
			}
			

		}
		else{
		//	cout<<"Error with classifier input string\n";
			break;
		}
    	linearComb.push_back(node);
    	s=s.substr(linePosition+1);
    	node.clear();
	}
}

/*Classify method. Follow brunches until we get a state to return.
Again:
0.0/1.0 if feature/state  -> (feature) number of feature, value to compare, vector to go to if<=, vector to go to if >=
						  -> (state) number of state
*/

int Classifier::classify(vector<float> energy)
{
	int node=0;
	switch (classifierType){

		//Decision tree
		case 0:
			while (true)
			{
				if(decisionTree[node][0]==1)
				{
					return (int)decisionTree[node][1];
				}
				else if(energy[(int)decisionTree[node][1]] <= decisionTree[node][2]){
					
					node=(int)decisionTree[node][3];

				}
				else{
					
					node=(int)decisionTree[node][4];
				}
			}
			break;

		//Regression
		case 1:

			vector<float> pred;
			vector<float> instanceFs;

			float maxF=-1000000;
			float max=-1000000;
			float current;
			float predSum;

			for(int i=0; i<linearComb.size(); i++)
			{
				instanceFs.push_back(0);
			}

			for (int i=1; i<linearComb[0].size(); i++)
			{
				predSum=0;
				for(int j=0; j<linearComb.size(); j++)
				{
					if(i>1)
					{
						pred.push_back(linearComb[j][i]*energy[i-2]);
					}
					else{
						pred.push_back(linearComb[j][1]);
					}
					predSum+=pred[j];
				}
				predSum/=linearComb.size();

				for(int j=0; j<linearComb.size(); j++)
				{
					instanceFs[j]+=(pred[j]-predSum) * (linearComb.size()-1) / linearComb.size();
				}
				pred.clear();

			}

			for(int i=0; i<instanceFs.size(); i++)
			{
				if (instanceFs[i] > maxF)
				{
					maxF=instanceFs[i];
				}
			}

			for(int i=0; i<instanceFs.size(); i++)
			{
				instanceFs[i]=exp(instanceFs[i] - maxF);
				//cout << instanceFs[i];
				//cout << "\n";
				if (instanceFs[i] > max){
					max=instanceFs[i];
					node=linearComb[i][0];
				}
			}


			return node;

			break;
	}

}
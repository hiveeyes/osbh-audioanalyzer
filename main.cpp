#include "createFilters.h"
#include "featureExtractor.h"
#include "classifier.h"
#include <fstream>
#include <vector>
#include <array>
#include "states.h"
using namespace std;
//parameters
#include "params.h"

/** Performs majority voting on stored beehive states
*/
int majorityVoting(vector<int> states)
{
	//Count all states
	std::array<int,11> count={0,0,0,0,0,0,0,0,0,0,0};
	for( int i = 0; i < states.size(); i++ )
	{	
		count[states[i]]++;
	}

	//Determine most repeated state
	int indexWinner = 1;
	for( int i = 1; i < count.size(); i++ )
	{
		if( count[i] > count[indexWinner] )
		{
			indexWinner = i;
		}
	}
	return indexWinner;
}

int main()
{
	
	//create filters
	//vector<Filter> filters=createFilters("../resources/coeffs_2205.txt");
	vector<Filter> filters=createFilters();

	//create feature extractor (params in h file)
	FeatureExtractor fex(filters, samplingRate, windowLength);
	

	//create classifier
	//Classifier c("f1,21.636442,1,5\nf0,0.087535,2,3\nf1,0.755093,3,4\ns1\ns4\ns3\n");
	//Classifier c("f1,0.220705,1,4\nf6,0.028664,2,3\ns1\ns4\ns3\n");
	//Classifier c("decision_tree","f1,0.288374,1,2\nf0,0.000407,13,3\nf0,0.001604,12,4\nf2,0.00659,5,6\nf1,0.329603,12,11\nf3,0.004466,7,11\nf6,0.005685,11,8\nf6,0.002256,9,14\nf3,0.007542,14,10\nf2.00121,14,11\nf1,0.140948,11,13\ns1\ns3\ns4\ns10\n");
	Classifier c("logistic","s1,2.31,2.06,-1.54,0,-10.94,0,0,0,41.89,68.97,-234.25\ns4,-12.87,0,-49.83,16.51,13.82,30.29,10.31,-28.68,47.44,-35.04,35.57\ns9,-1.01,1.21,3.39,-0.59,9.05,12.87,-1.57,1.7,-65.35,7.84,6.12\ns10,0.01,0,3.85,7.48,4.89,-90.57,59.4,-11.76,-12.67,-35.84,22.85\n");


	//Output: Energy vector time series
	vector < vector < float > > energy;
	vector < int > DetectedStates;
	vector <float> energy_local;
	
	//Read test data file line by line for testing. This should be changed to sample gathering from Particle ADC
	
	ifstream data ("../resources/6300/Collapsed_long.dat");
	if(data.is_open ())
	{	
		//Input: x		
		float x;
		while (data >> x)
		{
			//Update feature extractor
			fex.update(x);
			
			//If feature extractor is ready
			if(fex.isReady()){
				energy_local=fex.getEnergy();
				DetectedStates.push_back(c.classify(energy_local));
				fex.clearEnergy();
				energy.push_back(energy_local);

				//If we get to 5 classifications, perform majority voting and output state
				if(DetectedStates.size()==5){
					cout<<states[majorityVoting(DetectedStates)];
					cout<<"\n";
					DetectedStates.clear();
				}
			}
		}
	}
	data.close();
	
	//Write results to file
	ofstream outputFile;
	outputFile.open ("energy_bands.dat");
		
	for (int i = 0; i < energy.size(); i++)
	{
		for (int j = 0; j < energy[i].size(); j++)
		{
			outputFile << energy[i][j] << " ";
		}
		outputFile << "\n";
	}
	
	outputFile.close();
	
}

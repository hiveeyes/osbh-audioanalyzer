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

int main(int argc, char* argv[])
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
	//Classifier c("logistic","s1,2.31,2.06,-1.54,0,-10.94,0,0,0,41.89,68.97,-234.25\ns4,-12.87,0,-49.83,16.51,13.82,30.29,10.31,-28.68,47.44,-35.04,35.57\ns9,-1.01,1.21,3.39,-0.59,9.05,12.87,-1.57,1.7,-65.35,7.84,6.12\ns10,0.01,0,3.85,7.48,4.89,-90.57,59.4,-11.76,-12.67,-35.84,22.85\n");
	//Classifier c("logistic","s1,4.56,6.72,-1.4,0,-16.99,4.3,-25.24,2.66,-0.42,-3.55,0,2.03,4.12,-86.34\ns4,2.81,20.98,-44.45,-41.42,-9.35,7.4,-6.79,-2.33,9.99,2.82,39.19,-22.24,-32.2,-5.18\ns9,-3.08,7.54,0.58,0.22,2.21,10.46,0.11,0,0,37.67,0,-87.75,51.6,35.5\ns10,-0.22,-5.22,1.99,4.89,2.61,-0.6,8.53,-38.19,11.24,-1.44,-3.07,13.77,-9.1,8.36\n");
	//Classifier c("logistic","s1,4.33,5.83,-1.67,0.71,-16.01,4.78,-22.29,2.7,-2.16,-3.82,0,6.25,3.24,-68.25\ns4,2.18,22.36,-42.23,-49.79,-9.23,7.7,-4.23,-1.81,8.2,-0.92,44.42,-23.25,-17.86,-4.84\ns9,-3.89,7.46,0.46,1.6,2.42,10.7,3.19,-0.75,0-0.447,32.02,0,-71.82,45.99,42.46\ns10,-0.77,-5.66,1.6,5.91,2.54,-0.64,12.86,-45.25,13.77,-1.71,-1.85,13.35,-8,14.18\n");
	Classifier c("logistic","s1,3.03,4.21,-2,-0.54,0,-10.97,1.20,-5.76,0,4.15,-1.74,16.44,-35.67,-23.88\ns4,2.4,15,-33.46,-44.64,-2.5,1.91,-3.92,6.02,5.17,-14.3,35.72,-23.05,-22.39,6.87\ns9,-3.13,4.4,3.08,0.98,3.94,5.19,3.96,5.47,4.8,7.46,0.79,-44.22,24.39,41.2\ns10,3.88,-32.09,-0.18,1.81,-5.46,7.85,-8.62,-9.82,-1.14,-9.11,-5.44,2.34,9.25,-26.03\n");



	//Output: Energy vector time series
	vector < vector < float > > energy;
	vector < int > DetectedStates;
	vector <float> energy_local;

	//Read data file line by line. This should be changed to sample gathering from Particle ADC
	std::string filename = argv[1];
    cout << "Opening file " << filename << "\n";
    ifstream data (filename);

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

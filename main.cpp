#include "createFilters.h"
#include "featureExtractor.h"
#include "classifier.h"
#include <fstream>
#include <vector>
using namespace std;
//parameters
#include "params.h"

int main()
{
	
	//create filters
	//vector<Filter> filters=createFilters("../resources/coeffs_2205.txt");
	vector<Filter> filters=createFilters();

	//create feature extractor (params in h file)
	FeatureExtractor fex(filters, samplingRate, windowLength);
	

	//create classifier
	Classifier c("f1,21.636442,1,5\nf0,0.087535,2,3\nf1,0.755093,3,4\ns1\ns4\ns3\n");

	//Output: Energy vector time series
	vector < vector < float > > energy;
	vector < vector < string > > states;
	vector <float> energy_local;
	
	//Read test data file line by line for testing. This should be changed to sample gathering from Particle ADC
	
	ifstream data ("../resources/Active.dat");
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
				cout<<c.classify(energy_local);
				cout<<"\n";
				fex.clearEnergy();
				energy.push_back(energy_local);
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

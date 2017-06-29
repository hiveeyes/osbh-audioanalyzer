#include <iostream>
#include <vector>
#include "filter.h"
using namespace std;

//feature Extractor class. Computes energy for each stored filter

class FeatureExtractor {
	
	//Filters
	std::vector<Filter> filters;
	
    //window length in samples
    int windowSamples;
	
	//updated sample count
    int sampleCount;
	
	//Frequency band energy
	std::vector<float> energy;

	//Energy value for normalization
	float totalEnergy;

	//ready flag
	bool ready;

  public:
    FeatureExtractor (std::vector<Filter> &filters,  float samplingRate, float windowLength);
	FeatureExtractor (std::vector<Filter> &filters,  int windowSamples);
	void update(float value);
    bool isReady();
	std::vector<float> getEnergy();
	float getTotalEnergy();
	void clearEnergy();

};


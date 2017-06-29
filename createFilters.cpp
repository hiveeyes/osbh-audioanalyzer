#include "createFilters.h"
//Creates filters without reading from file. Hardcoded

vector <Filter> createFilters()
{
	//Filter vector
	vector <Filter> filters;
 
	//Float vectors for storing coefficients
	vector<vector<float>> coeffs;
 
	//Filter
	Filter f(coeffs,0);
 
	vector<float> sos(6);
 
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.984834e+00,  9.873643e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 6.469432e-03);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.978322e+00,  9.829424e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 8.564669e-03);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.968288e+00,  9.768331e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.162385e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.952814e+00,  9.685842e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.585273e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.888722e+00,  9.423521e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.891657e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.870536e+00,  9.362512e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 3.197003e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.823490e+00,  9.220812e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 3.904069e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.666155e+00,  8.845031e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 5.776395e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.454950e+00,  8.457071e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 7.714661e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.109470e+00,  7.950290e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.025104e-01);
	filters.push_back(f);
	coeffs.clear();
	
	return filters;
}





//Loads and parses coefficients file, creating filters from it

vector <Filter> createFilters(string coeffsFileName)
{
	//Read and parse coefficients file	
	ifstream coeffsText (coeffsFileName.c_str());
	string line;
	
	//Filter vector
	vector <Filter> filters;

	//Float vectors for storing coefficients	
	vector<vector<float> > coeffs;

	//Second order section
	vector<float> sos;

	//Gain
	float g;

	//flag for storing gain or coefficients alternatively
	int marker=0;
	
	if(coeffsText.is_open ())
	{
		while ( getline (coeffsText,line) )
		{
			//Check that line is not a comment or space
			if(line[0]!='#' &&  line[0]!=' ')
			{
				stringstream ss(line);
				//Fill coefficient vector until the end of the line
				while (!ss.fail())
				{
					float f;
					ss >> f;
					if (!ss.fail())
					{
						//Gain						}
						if(marker==0){
							g=f;
							marker=1;
						}
						//Coefficients
						else{
							sos.push_back(f);
						}
					}
					else
					{
						continue;
					}
				}
				//Add sos to filter coeffs
				if(sos.size()==6){
					coeffs.push_back(sos);
					sos.clear();
				}
			}
			else
			{
				//Create filter and add to list
				if(coeffs.size()>0){
					Filter f (coeffs, g);
					filters.push_back(f);
					coeffs.clear();
				}
				marker=0;
			}
		}
	}
	coeffsText.close();
	return filters;
}

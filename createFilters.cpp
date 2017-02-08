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
 
	sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.962087e+00,  9.825848e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.968876e+00,  9.854361e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.245098e-04);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.831753e+00,  9.583182e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.862277e+00,  9.626915e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 7.780287e-04);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, 1.414961e-01, 8.322749e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.963557e-01,  8.327025e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.415032e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00,  1.659577e-01,  8.084948e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, 5.401055e-01, 8.156620e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.785500e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00,  7.553471e-01,  7.612362e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, 1.154765e+00, 7.939698e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.517611e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00,  9.520854e-01,  7.399303e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, 1.349033e+00, 7.899214e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.824794e-02);
	filters.push_back(f);
	coeffs.clear();
	
	sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00,  1.124670e+00,  7.151349e-01};
	coeffs.push_back(sos);
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, 1.515845e+00, 7.904018e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 3.145326e-02);
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

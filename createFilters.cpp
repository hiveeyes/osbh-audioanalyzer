#include "createFilters.h"
//Creates filters without reading from file. Hardcoded

vector <Filter> createFilters()
{
		//Filter vector
	vector <Filter> filters;

	//Float vectors for storing coefficients	
	vector<vector<float> > coeffs;

	//1st second order section
	vector<float> sos(6);
	sos={(float)1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, -1.984084e+00, 9.886387e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00, -2.000000e+00, 1.000000e+00, 1.000000e+00, -1.990548e+00, 9.953167e-01};
	coeffs.push_back(sos);
	//1st filter
	Filter f (coeffs, 2.930094e-05);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00, 2.000000e+00, 9.999997e-01, 1.000000e+00, -1.946510e+00, 9.787749e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-1.955860e+00,9.813309e-01};
	coeffs.push_back(sos);
	//2nd filter
	f=Filter(coeffs, 2.016789e-04);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00,2.000000e+00,9.999997e-01,1.000000e+00,-1.298059e+00,9.084855e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-1.426870e+00,9.163276e-01};
	coeffs.push_back(sos);
	//3rd filter
	f=Filter(coeffs, 3.845109e-03);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00,2.000000e+00,9.999997e-01,1.000000e+00,-1.127357e+00,8.970964e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-1.285726e+00,9.051855e-01};
	coeffs.push_back(sos);
	//4th filter
	f=Filter(coeffs, 4.900544e-03);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00,2.000000e+00,9.999997e-01,1.000000e+00,-7.999985e-01,8.778063e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-1.011989e+00,8.855665e-01};
	coeffs.push_back(sos);
	//5th filter
	f=Filter(coeffs, 7.028156e-03);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00,2.000000e+00,9.999997e-01,1.000000e+00,-6.669801e-01,8.706456e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-8.994795e-01,8.779843e-01};
	coeffs.push_back(sos);
	//6th filter
	f=Filter(coeffs, 7.935346e-03);
	filters.push_back(f);
	coeffs.clear();

	//1st second order section
	sos={1.000000e+00,2.000000e+00,9.999997e-01,1.000000e+00,-5.311512e-01,8.636423e-01};
	coeffs.push_back(sos);
	//2nd
	sos={1.000000e+00,-2.000000e+00,1.000000e+00,1.000000e+00,-7.837712e-01,8.703682e-01};
	coeffs.push_back(sos);
	//7th filter
	f=Filter(coeffs, 8.890164e-03);
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

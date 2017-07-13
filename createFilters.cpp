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

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.988192e+00,  9.898294e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 5.581749e-03);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.980926e+00,  9.846599e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 7.670585e-03);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.975628e+00,  9.812284e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 9.517449e-03);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.963954e+00,  9.744001e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.287313e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.952814e+00,  9.685842e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.585273e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.937975e+00,  9.616016e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 1.929711e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.916886e+00,  9.527626e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.368217e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.888722e+00,  9.423521e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.891657e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.793798e+00,  9.140404e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 4.298210e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.758468e+00,  9.051555e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 4.747219e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.716855e+00,  8.954499e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 5.230716e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00, -1.539156e+00,  8.601357e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 6.993926e-02);
	filters.push_back(f);
	coeffs.clear();

	sos={(float)1.000000e+00,  0.000000e+00, -1.000000e+00,  1.000000e+00,  1.077900e+00,  5.427943e-01};
	coeffs.push_back(sos);
	f=Filter(coeffs, 2.286031e-01);
	filters.push_back(f);
	coeffs.clear();

	return filters;
}


// The filter coefficients before the update "Added new filters and logistic regression classifier"
// See also https://github.com/opensourcebeehives/MachineLearning-Local/commit/a40de504
vector <Filter> createFiltersV1()
{
    //Filter vector
    vector <Filter> filters;

    //Float vectors for storing coefficients
    vector<vector<float>> coeffs;

    //Filter
    Filter f(coeffs,0);

    vector<float> sos(6);

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.970870e+00,  9.733939e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -2.013306e+00,  1.015805e+00};
    coeffs.push_back(sos);
    f=Filter(coeffs, 1.616452e-05);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.968947e+00,  9.851466e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.974635e+00,  9.868454e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 1.101340e-04);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.622646e+00,  9.346536e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.692574e+00,  9.410388e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 1.933591e-03);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.528841e+00,  9.262438e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.616117e+00,  9.332066e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 2.472735e-03);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.344025e+00,  9.117649e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.464692e+00,  9.194961e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 3.566587e-03);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.266786e+00,  9.063119e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.401085e+00,  9.142184e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 4.035773e-03);
    filters.push_back(f);
    coeffs.clear();

    sos={(float)1.000000e+00,  2.000000e+00,  9.999997e-01,  1.000000e+00, -1.186478e+00,  9.009157e-01};
    coeffs.push_back(sos);
    sos={(float)1.000000e+00, -2.000000e+00,  1.000000e+00,  1.000000e+00, -1.334720e+00,  9.089479e-01};
    coeffs.push_back(sos);
    f=Filter(coeffs, 4.531140e-03);
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

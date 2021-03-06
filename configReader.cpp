#include "configReader.h"

#ifdef __ROOT__
ClassImp(ConfigReader)
#endif

ConfigReader::ConfigReader()
{
    mCommentString = "#";
    mSectionString = "%";
}

ConfigReader::ConfigReader(string fileName)
{
    mCommentString = "#";
    mSectionString = "%";
    readFile(fileName);
}

void ConfigReader::readFile(string fileName)
{
    ifstream configFile(fileName.c_str());
    string line;
    string sectionName = "default";

    while (getline(configFile, line)) {
        if( line.find(mCommentString, 0) == 0) { continue; }
        if( line.find(mSectionString, 0) == 0 ) {
            sectionName = line.substr(1, line.length());
            continue;
        }

        int firstSpace = line.find(" ", 0);
        if(firstSpace >=1) {
            string key = line.substr(0, firstSpace);
            string value = line.substr(firstSpace + 1, line.length() - 1);

            options[sectionName][key] = value;
        }
    } //end while
}
vector<string> ConfigReader::getV(string key, string section, string delim )
{
    string valString = get(key, section);
    vector<string> valVector;
    int delimPosition = valString.find(delim, 0);

    while( delimPosition >= 0 )
    {
        valVector.push_back( valString.substr(0, delimPosition) );
        valString = valString.substr( delimPosition + 1, valString.length() - 1 );
        delimPosition = valString.find(delim, 0);
    }

    // Get last item
    valVector.push_back(valString); 

    return valVector;
}

vector<int> ConfigReader::getVI(string key, string section, string delim)
{
    vector<string> stringVector = getV(key, section, delim);
    vector<int> intVector;

    for(unsigned i = 0; i <= (stringVector.size() - 1); i++)
    {
        int element = atoi( stringVector.at(i).c_str() );
        intVector.push_back(element);
    }

    return intVector;
}

vector<float> ConfigReader::getVF(string key, string section, string delim)
{
    vector<string> stringVector = getV(key, section, delim);
    vector<float> floatVector;

    for(unsigned i = 0; i <= (stringVector.size() - 1); i++)
    {
        float element = atof( stringVector.at(i).c_str() );
        floatVector.push_back(element);
    }

    return floatVector;
}

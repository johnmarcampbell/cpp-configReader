#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

#ifdef __ROOT__
#include "TObject.h"
#endif

class ConfigReader
{
    public:
        ConfigReader();
        ConfigReader(string fileName);
        virtual ~ConfigReader(){};

        void readFile(string fileName);

        // Some quick get-methods
        string get(string key, string section = "default")
            { return options[section][key]; }
        int getI(string key, string section = "default")
            { return atoi( get(key, section).c_str() ); }
        float getF(string key, string section = "default")
            { return atof( get(key, section).c_str() ); }

        // Get the string, turn it into a vector of values
        vector<string> getV(string key, string section = "default",
                            string delim = " ");
        vector<int> getVI(string key, string section = "default",
                            string delim = " ");
        vector<float> getVF(string key, string section = "default",
                            string delim = " ");
        void set(string key, string value, string section = "default")
            { options[section][key] = value; }

        void setCommentString(string s) { mCommentString = s; }
        void setSectionString(string s) { mSectionString = s; }

        string mCommentString;
        string mSectionString;

    private:
        map<string, map<string, string> > options;

        #ifdef __ROOT__
        ClassDef(ConfigReader,1)
        #endif
};

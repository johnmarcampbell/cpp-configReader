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
        string get(string key, string section = "default")
            { return options[section][key]; }
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

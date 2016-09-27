#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class ConfigReader
{
    public:
        ConfigReader(){};
        ConfigReader(string fileName)
            { readFile(fileName); }
        ~ConfigReader(){};

        void readFile(string fileName);
        string get(string key, string section = "default")
            { return options[section][key]; }
        void set(string key, string value, string section = "default")
            { options[section][key] = value; }

    private:
        map<string, map<string, string> > options;

};

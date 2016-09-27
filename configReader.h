#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class ConfigReader
{
    public:
        ConfigReader();
        // ConfigReader(string filename);
        ~ConfigReader();

        void readFile(string fileName);
        string get(string key, string section = "default")
            { return options[section][key]; }

    private:
        map<string, map<string, string> > options;

};

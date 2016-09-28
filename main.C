#include "configReader.cpp"
int main(int argc, char** argv)
{
    // Default filename
    string fileName = "sample.config";
    if(argc >= 2) { fileName = argv[1]; }

    ConfigReader cr(fileName);

    cout << cr.get("key1") << endl;
    cout << cr.get("betaKey1", "beta") << endl;
    cout << cr.get("alphaKey1", "alpha") << endl;

    return 0;
}

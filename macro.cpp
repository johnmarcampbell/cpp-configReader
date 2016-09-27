#include "configReader.cpp"
int main()
{
    ConfigReader cr;
    cr.readFile("sample.config");
    cout << cr.get("key1") << endl;
    return 0;

}

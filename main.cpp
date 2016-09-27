#include "configReader.cpp"
int main()
{
    // ConfigReader cr("sample.config");
    ConfigReader cr;
    cr.setSectionString("@");
    cr.readFile("sample.config");

    cr.set("parameter1", "value1");
    cout << cr.get("key1") << endl;
    cout << cr.get("b2", "beta") << endl;
    return 0;

}

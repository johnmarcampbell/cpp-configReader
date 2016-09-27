#include "configReader.cpp"
int main()
{
    ConfigReader cr("sample.config");
    // cr.readFile("sample.config");

    cr.set("parameter1", "value1");
    cout << cr.get("key1") << endl;
    cout << cr.get("parameter1") << endl;
    return 0;

}

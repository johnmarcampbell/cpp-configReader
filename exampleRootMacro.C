exampleRootMacro()
{
    gSystem->Load("configReader");


    string fileName = "sample.config";
    ConfigReader cr(fileName);

    cout << cr.get("key1") << endl;
    cout << cr.get("betaKey1", "beta") << endl;
    cout << cr.get("alphaKey1", "alpha") << endl;
}

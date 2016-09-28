exampleRootMacro()
{
    gSystem->Load("ConfigReader");


    string fileName = "sample.config";
    ConfigReader cr(fileName);

    cout << cr.get("key1") << endl;
    cout << cr.get("betaKey1", "beta") << endl;
    vector<string> alphas = cr.getV("alphaKey1", "alpha") ;

    for(unsigned i = 0; i <= (alphas.size() - 1); i++)
    {
        cout << alphas.at(i) << endl;
    }



}

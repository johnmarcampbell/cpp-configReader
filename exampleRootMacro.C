exampleRootMacro(string fileName = "sample.config")
{
    gSystem->Load("ConfigReader");

    ConfigReader cr(fileName);

    // Get some values
    string aValue = cr.get("key1");
    string anotherValue = cr.get("key2");
    float pi = cr.getF("pi", "floats"); // from the "floats" section

    // Read a vector of ints
    vector<int> fibonacci = cr.getVI("fibonacci", "ints");
    for(unsigned i = 0; i <= (fibonacci.size() - 1); i++)
    {
        cout << "Fib #" << i << ": " << fibonacci.at(i) << endl;
    } 

    // Read a vector of floats
    vector<float> manyFloats = cr.getVF("manyFloats", "floats");

    for(unsigned i = 0; i <= (manyFloats.size() - 1); i++)
    {
        cout << "Float #" << i << ": " << manyFloats.at(i) << endl;
    } 

}

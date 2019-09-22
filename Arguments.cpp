//Author:   Colby Ackerman
//Class:    Program Translations (CS4280)
//Assign:   Project 0
//Date:     September 22, 2019

#include "Arguments.hpp"

Arguments::Arguments() : cliInput(""), infileName(""), fileContents("") {}

bool Arguments::handleArguments(int argc, char* argv[]) {
    bool success = false;

    //Handle either simulate keyboard input or file redirection.
    if(argc == 1) {
        handleFileRedirOrKeyboardSim();
        tokenize(cliInput);
        outputState = REDIRECTED;
        success = true;
    }

    //Otherwise need to load a file.
    else {
        //Get the file name.
        if(!parseArgs(argc, argv)) {
            std::cerr << "Error: Function: parseArgs(int, char**)" << std::endl;
            return false;
        }

        //Read entire file contents into fileString.
        if(!readFromFile(cliInput)) {
            std::cerr << "Error: Function: readFromFile(std::string)" << std::endl;
            return false;
        }
        
        tokenize(fileContents);
        outputState = FILE_READ;
        success = true;
    }

    return success;
}

bool Arguments::parseArgs(int argc, char* argv[]) {
    if(argc > 2){
        std::cerr << "Error: Too many arguments." << std::endl;
        return false;
    }

    /* 
    This is the case in which the user has passed the name of a file without
    the file extension appended to the end of it. 
    */
    else if(argc == 2) {
        //Retrieve the file name from the argument list.
        cliInput = std::string(argv[1]);
        
        //Save the name of the file without extension.
        infileName = cliInput;

        //Find the last occurence of '.' 
        std::string::size_type pos = cliInput.find_last_of(".");

        /*
        If the position is not the end of the string, append the .fs19 ext.
        This also handles the case where a filename contains other periods.
        */
        if(pos != std::string::npos) {            
            std::string extension = cliInput.substr(pos + 1);
            if(extension != "fs19") {
                cliInput.append(".fs19");
            }
        }
        else {
            cliInput.append(".fs19");
        }

        //DEBUG
        //std::cout << cliInput << std::endl;
        
        return true;
    }
    else {
        handleFileRedirOrKeyboardSim();
        return true;
    }

    return false;
}

void Arguments::handleFileRedirOrKeyboardSim() {
    /*
    Read entire cin buffer. Also handles simulated keyboard input.
    press "Enter" then "Ctrl + d" to end keyboard input.
    */
    char c = 0;
    while(std::cin.get(c)) {
        cliInput.push_back(c);
    }

    //DEBUG
    //std::cout << cliInput;

    //Clear the std::cin buffer.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    return;
}

void Arguments::tokenize(std::string str) {  
    //Parse the cliInput string for tokens and push into tokens vector.
    std::stringstream ss(str);
    std::string token;
    while(ss >> token) {
        tokens.push_back(token);
    }


    //DEBUG
    /* std::cout << "TOKENS:\n";
    if(tokens.empty()) {
        std::cout << "-NO TOKENS-" << std::endl;
        return;
    }
    for(int i = 0; i < tokens.size(); ++i) {
        std::cout << "\"" << tokens[i] << "\"\n";
    } */
}

bool Arguments::readFromFile(const std::string path) {
    std::fstream inFile(path.c_str(), std::ios_base::in);

    if(!inFile.good()) {
        inFile.close();
        return false;
    }

    char c = 0;
    while(inFile.get(c)) {
        fileContents.push_back(c);
    }

    inFile.close();

    return true;
}
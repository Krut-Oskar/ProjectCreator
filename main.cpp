#include <iostream>
#include <fstream>
#include <stdio.h>



using namespace std;
int CreateFile(string fileName, string filePath ,string data){
    string fullPath;
    fullPath.append(filePath);
    fullPath.append("/");
    fullPath.append(fileName);
    

    ofstream outfile;
    outfile.open(fullPath);
    if(!outfile){
        cout<<"File Created...FAILED"<< endl;
        return 0;
    }
    else{
        cout <<"File created...OK "<< endl;
        cout<<"File Path: "<< filePath<< " File Name: " << fileName << endl;
        outfile<<data<< endl;
        outfile.close();
        return 1;
    }
    
}
int CreateDirectory(string dirName, string dirPath){
    string fullPath = "mkdir ";
    fullPath.append(dirPath);
    fullPath.append("/");
    fullPath.append(dirName);
    const char* path = fullPath.c_str();
    

    int dirCreated = system(path);
    if (dirCreated == -1)
    {
        return 0;
        
    }
    else{
        return 1;
    }
}

int main(){
    string dirName;
    string dirPath;
    string fileName;
    string data;
    cout<<"Name of directory: ";
    getline(cin, dirName);
    cout<<"Enter path for directory: ";
    getline(cin, dirPath);
    cout<<"Enter file name: ";
    getline(cin, fileName);
    cout << "Write to your file: ";
    getline(cin, data);

    fileName.append(".txt");
    string fullPath = dirPath;
    fullPath.append("/");
    fullPath.append(dirName);
    

    

    if(CreateDirectory(dirName, dirPath)){
        cout<<"Directory Created...OK" << endl;
        CreateFile(fileName, fullPath, data);
    }
    else{
        cout<<"Directory Created...FAIL"<< endl;
    }
    
    return 0;

}
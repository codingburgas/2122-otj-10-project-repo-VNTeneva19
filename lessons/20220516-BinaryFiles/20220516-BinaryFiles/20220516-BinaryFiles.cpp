#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#pragma pack(1)
struct User
{
    int id;
    bool isEnabled;
};

int main()
{
    // cout << __cplusplus << endl;
    
    // fopen("file.bin", "r")
    // fclose
    // fread
    // fwrite
    // fseek

    cout << sizeof(User) << endl;

    fstream file("file1.bin", ios::in | ios::out | ios::app | ios::binary);

    int a = 65;
    int arr[] = { 65, 66, 67 };
    User u1{ 65, true };
    vector<User> users{
        { 65, true }
        { 66, false }
        { 67, true }
    };

    if (file.is_open())
    {
        // file.write((char*) &a, sizeof(a));
        // file.write((char*) arr, sizeof(arr));
        // file.write((char*) &u1, sizeof(u1));
        file.write((char*) users.data(), users.size() * sizeof(User));



        file.close();
    }
}


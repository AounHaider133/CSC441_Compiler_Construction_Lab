#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

const int BUFFER_SIZE = 4096;

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isDigit(char c)
{
    return c >= '0' && c <= '9';
}

void processBuffer(const vector<char> &buffer, int size)
{
    char lex[20];
    int li = 0;
    int state = 0;

    for (int i = 0; i < size; ++i)
    {
        switch (state)
        {
        case 0:
            if (buffer[i] == '/')
            {
                state = 1;
            }
            break;
        case 1:
            if (buffer[i] == '*')
            {
                state = 2;
                li = 0;
            }
            else
            {
                state = 0;
            }
            break;
        case 2:
            if (buffer[i] == '*')
            {
                state = 3;
            }
            else
            {
                lex[li++] = buffer[i];
            }
            break;
        case 3:
            if (buffer[i] == '/')
            {
                lex[li] = '\0';
                cout << "Comment: " << lex << endl;
                state = 0;
            }
            else
            {
                lex[li++] = '*';
                lex[li++] = buffer[i];
                state = 2;
            }
            break;
        }
    }
}


int main()
{
    ifstream file("double_buffer.cpp", ios::binary);

    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    vector<char> buffer1(BUFFER_SIZE);
    vector<char> buffer2(BUFFER_SIZE);

    bool useBuffer1 = true;

    while (!file.eof())
    {
        // Read data into the appropriate buffer
        if (useBuffer1)
        {
            file.read(buffer1.data(), BUFFER_SIZE);
            processBuffer(vector<char>(buffer1.begin(), buffer1.begin() + file.gcount()),file.gcount());
        }
        else
        {
            file.read(buffer2.data(), BUFFER_SIZE);
            processBuffer(vector<char>(buffer2.begin(), buffer2.begin() + file.gcount()),file.gcount());
        }

        // Toggle the buffer flag
        useBuffer1 = !useBuffer1;
    }

    // Close the file
    file.close();

    return 0;
}


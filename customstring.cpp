#include "customstring.h"

#include <QMessageBox>

// The * 2 is just assurance for memory allocations. Somehow, it is not enough.
// Reopening the same page a number of times, it randomly crashes despite
// having the same content/same length of characters.
// Adding more memory seems to have solved the problem.

CustomString::CustomString()
{
    // Size limit of a CustomString is 2000
    customString = (char *) calloc(2000, sizeof(char));
}

CustomString::CustomString(char *string)
{
    strcpy(this->customString, string);
    trimAll();
}

CustomString::CustomString(QString string)
{
    QByteArray charArray = string.toUtf8();
    this->customString = (char *) calloc(charArray.size() * 2, sizeof(char));
    strcpy(this->customString, charArray.data());

    customStringSize = strlen(customString);
    trimAll();
}

char *CustomString::getCustomString() const
{
    return customString;
}

void CustomString::trimEnd()
{
    while (customString[customStringSize - 1] == '\n' || customString[customStringSize - 1] == '\r' || customString[customStringSize - 1] == ' ') {
        customString[customStringSize - 1] = '\0';
        customStringSize--;
    }
}

void CustomString::trimFront()
{
    while (customString[0] == '\n' || customString[0] == '\r' || customString[0] == ' ') {
        strcpy(customString, customString + 1);
    }
}

void CustomString::trimAll()
{
    this->trimFront();
    this->trimEnd();
}

int CustomString::getLineCount()
{
    int lineBreakCount = 0;
    // Count How Many Lines
    for (int i = 0; i < customStringSize; i++) {
        if (customString[i] == '\n') lineBreakCount++;
    }

    return lineBreakCount + 1;
}

void CustomString::appendText(const char *text)
{
    strcat(customString, text);
}

void CustomString::appendText(int text)
{
    int digitCount = digitCounter(text);
    char *temp = (char *) calloc(digitCount * 2, sizeof(char));
    sprintf(temp, "%d", text);
    strcat(customString, temp);
    customStringSize = strlen(customString);
}

void CustomString::appendText(long text)
{
    int digitCount = digitCounter(text);
    char *temp = (char *) calloc(digitCount * 2, sizeof(char));
    sprintf(temp, "%ld", text);
    strcat(customString, temp);
    customStringSize = strlen(customString);
}

void CustomString::appendText(float text)
{
    char *temp = (char *) calloc(50, sizeof(char));
    sprintf(temp, "%f", text);
    strcat(customString, temp);
    customStringSize = strlen(customString);
}

void CustomString::appendText(double text)
{
    char *temp = (char *) calloc(50, sizeof(char));
    sprintf(temp, "%lf", text);
    strcat(customString, temp);
    customStringSize = strlen(customString);
}

void CustomString::appendChar(char text)
{
    char *temp = (char *) calloc(1, sizeof(char));
    sprintf(temp, "%c", text);
    strcat(customString, temp);
    customStringSize = strlen(customString);
}

char ***CustomString::get3DArray(const char delimiter)
{
    int userCount = this->getLineCount();

    // Creates Outermost Layer (Username and Password)
    char ***Array3D = (char ***) malloc(2 * sizeof(char **));

    // Creates 2nd Outermost Layer (Depends On Number Of Accounts)
    Array3D[0] = (char **) malloc(userCount * sizeof(char *));
    Array3D[1] = (char **) malloc(userCount * sizeof(char *));

    //Creates 3rd Layer (Contains Strings)
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < userCount; j++) {
            Array3D[i][j] = (char *) malloc(userCount * sizeof(char));
        }
    }

    //Actual String Proccessing
    char *tempString = (char *) calloc(20, sizeof(char));
    int accountCounter = 0;
    int tempStringPosition = 0;
    for (int i = 0; i < customStringSize; i++) {
        if (customString[i] == delimiter) {
            strcpy(Array3D[0][accountCounter], tempString);
            tempString = (char *) calloc(20, sizeof(char));
            tempStringPosition = 0;
        } else if (customString[i] == '\n') {
            strcpy(Array3D[1][accountCounter], tempString);
            tempString = (char *) calloc(20, sizeof(char));
            tempStringPosition = 0;
            accountCounter++;
        } else if (customString[i] == '\r') {
            // Skip
        } else {
            tempString[tempStringPosition] = customString[i];
            tempStringPosition++;
        }
    }

    // Since the string was trimmed, the final tempString would not be added to the array
    // So here is the additional code
    strcpy(Array3D[1][accountCounter], tempString);

    return Array3D;
}

int CustomString::compare(const char *string)
{
    return stricmp(customString, string);
}

int CustomString::digitCounter(int number)
{
    int digitCount = 1;
    while (number >= 10) {
        number /= 10;
        digitCount++;
    }

    return digitCount;
}

int CustomString::getCustomStringSize() const
{
    return customStringSize;
}

char CustomString::charAt(int index)
{
    return customString[index];
}


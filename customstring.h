#ifndef CUSTOMSTRING_H
#define CUSTOMSTRING_H

#include <QString>

class CustomString {
    public:
        CustomString();
        CustomString(char *string);
        CustomString(QString string);
        char *getCustomString() const;
        void trimEnd();
        void trimFront();
        void trimAll();
        int getLineCount();
        void appendText(const char *text);
        void appendText(int text);
        void appendText(long text);
        void appendText(float text);
        void appendText(double text);
        void appendChar(char text);
        char ***get3DArray(const char delimiter);
        int compare(const char *string);
        int getCustomStringSize() const;
        char charAt(int index);

private:
        int digitCounter(int number);
        char *customString;
        int customStringSize;
};

#endif // CUSTOMSTRING_H

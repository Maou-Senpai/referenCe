//Header Files
#include "pagearrays.h"

// Initializes dictionaries
PageArrays::PageArrays()
{
    // Empty For This Page
}

// FUNCTION NAME: showPage()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// Creates the elements of the page

void PageArrays::showPage()
{
    addHeader("Arrays");
    addParagraph("Arrays are used to store a bunch of items with same data type into a list.");

    addParagraphTitle("1D Array");
    addParagraph("To declare a 1D array, append [] after the variable name during declaration. To initialize, use {}.");
    addExampleByFile("1D Array Sample Code", ":/cpp/content/array1D.cpp");
    sample1Simulation();

    addParagraphTitle("2D Array");
    addParagraph("To declare a 2D array, append [][] after the variable name during declaration.");
    addExampleByFile("2D Array Sample Code", ":/cpp/content/array2D.cpp");
    sample2Simulation();

//    addParagraphTitle("More Examples");
//    addParagraph("Fibonacci Sequence, Calculating the first 20 numbers of the Fibonacci Sequence");
//    addExampleByFile("1D Array sample code", ":/cpp/content/arrayNumerical1d.cpp");
//    sample3Simulation();

    addParagraphTitle("More Examples");
    addParagraph("Calculating the sum of a 2D array");
    addExampleByFile("2D Array Sample Code", ":/cpp/content/arrayNumerical2d.cpp");
    sample4Simulation();

    addParagraphTitle("More Examples");
    addParagraph("Finding the smallest number in each column");
    addExampleByFile("2D Array sample code", ":/cpp/content/arrayNumerical5.cpp");
    sample5Simulation();

    addParagraphTitle("More Examples");
    addParagraph("Finding the largest number in each column");
    addExampleByFile("2D Array Sample Code", ":/cpp/content/arrayNumerical6.cpp");
    sample6Simulation();
}

// FUNCTION NAME: getDictionaries(std::vector<std::vector<dictionary *> *> *)
//
// PARAMETERS: std::vector<std::vector<dictionary *> *> *
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// Creates the elements of the page
// To be used for the search function
// This will be called by the mainwindow

void PageArrays::getDictionaries(std::vector<std::vector<dictionary *> *> *)
{
    // Empty For This Page
}

// FUNCTION NAME: sample1Simulation()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This is a sample simulation of the first sample code
// Modified to make it work in Qt

void PageArrays::sample1Simulation()
{
    CustomString *tempString = new CustomString;

    char Array[11] = {'P','R','O','G','R','A','M','M','I','N','G'};

    int i;

    for (i = 0; i <= 10; i++)
    {
        tempString->appendChar(Array[i]);

    }
    tempString->appendText("\n");

    for (i = 0; i <= 10; i++)
    {
        tempString->appendText("\n");
        tempString->appendChar(Array[i]);
    }

    addExample("Output", tempString->getCustomString());
}

// FUNCTION NAME: sample2Simulation()
//
// PARAMETERS: None
//
// RETURN VALUE: None
//
// CALLS TO: mainwindow.ui
//
// CALLED FROM: none
//
// METHOD:
//
// This is a sample simulation of the second sample code
// Modified to make it work in Qt

void PageArrays::sample2Simulation()
{
    CustomString *tempString = new CustomString;

    int TwoDArray[5][5] = { {2, 4, 6, 8, 10},
                            {1, 3, 5, 7, 9},
                            {12, 14, 16, 18, 20},
                            {11, 13, 15, 17, 19},
                            {22, 24, 26, 28, 30}
                         };
    int i;
    int j;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (!(i == 0 && j == 0)) tempString->appendText("\n");
            tempString->appendText(TwoDArray[i][j]);
            tempString->appendText("\t Value in i = ");
            tempString->appendText(i);
            tempString->appendText(", j = ");
            tempString->appendText(j);
        }
    }

    addExample("Output", tempString->getCustomString());
}

void PageArrays::sample3Simulation()
{
    CustomString *tempString = new CustomString;

    int fibonacci[20];

    fibonacci[0] = 0;
    fibonacci[1] = 1;

    for (int i = 2; i < 20; i++)
    {
        fibonacci [i] = fibonacci[i-2] + fibonacci [i-1];
        for (i = 0; i < 20; i++)
        {
            tempString->appendText("\t");
            tempString->appendText("\n\t Value = ");
            tempString->appendText(fibonacci[i]);

            tempString->appendText("\t\t\t Fibonacci ");
            tempString->appendText("[");
            tempString->appendText(i);
            tempString->appendText("]");
        }
    }
    addExample("Output", tempString->getCustomString());
}

void PageArrays::sample4Simulation()
{
    CustomString *tempString = new CustomString;

    int a[2][3] = { {15, 25, 35}, {45, 55, 65} };
    int b[2][3] = { {12, 22, 32}, {55, 25, 85} };
    int rows, columns, Sum[2][3];

    for(rows = 0; rows < 2; rows++)
     {
      for(columns = 0; columns < 3;columns++)
       {
        Sum[rows][columns] = a[rows][columns] + b[rows][columns];
       }
     }
    tempString->appendText("\n The first array is:   {15, 25, 35}, {45, 55, 65} \n ");
    tempString->appendText("\n The second array are: {12, 22, 32}, {55, 25, 85} \n ");
    tempString->appendText("\n The Sum of the two arrays is:  \n \n");

    for(rows = 0; rows < 2; rows++)
     {
        tempString->appendText("\n");
      for(columns = 0; columns < 3; columns++)
       {
        tempString->appendText(Sum[rows][columns]);
        tempString->appendText(" , ");
       }
     }

    addExample("Output", tempString->getCustomString());

}

void PageArrays::sample5Simulation()
{
    CustomString *tempString = new CustomString;

    int i, j, A[3][5] = {{50, 120, 30, 150, 80}, {140, 70, 110, 90, 100}, {30, 20, 0, 60, 40}};
    int smallest;

    tempString->appendText("\n The first row is:        {50, 120,  35, 150, 80} \n ");
    tempString->appendText("\n The second row are: {140, 70, 110, 90, 100} \n ");
    tempString->appendText("\n The third row are:    {30,  20,  0,  60, 40} \n ");
    tempString->appendText(" \n");
    for(i = 0; i <= 4; i = i + 1)
    {
        smallest = A[0][i];
        for(j = 1; j <= 2; j = j + 1)
            if(A[j][i] < smallest)
            smallest = A[j][i];
        tempString->appendText("\n The smallest in column ");
        tempString->appendText(i);
        tempString->appendText(" is: ");
        tempString->appendText(smallest);
        tempString->appendText("\n");

            }

    addExample("Output", tempString->getCustomString());

}

void PageArrays::sample6Simulation()
{
    CustomString *tempString = new CustomString;

    int i, j, A[3][5] = {{50, 120, 30, 150, 80}, {140, 70, 110, 90, 100}, {30, 20, 0, 60, 40}};

    int largest;


    tempString->appendText("\n The first row is:        {50, 120,  35, 150, 80} \n ");
    tempString->appendText("\n The second row are: {140, 70, 110, 90, 100} \n ");
    tempString->appendText("\n The third row are:    {30,  20,  0,  60, 40} \n ");
    tempString->appendText(" \n");

    for(i = 0; i <= 4; i = i + 1)
        {
        largest = A[0][i];
        for(j = 1; j <= 2; j = j + 1)
            if(A[j][i] > largest)
            largest = A[j][i];
        tempString->appendText("\n The largest in column ");
        tempString->appendText(i);
        tempString->appendText(" is: ");
        tempString->appendText(largest);
        tempString->appendText("\n");
        }
    addExample("Output", tempString->getCustomString());

}

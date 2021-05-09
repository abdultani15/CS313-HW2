//***********************************************************
// Author: D.S. Malik
//
// Program: Postfix Calculator  
// This program evaluates postfix expressions.
//***********************************************************

#include <iostream>  
#include <iomanip>
#include <fstream>
#include "mystack.h"

using namespace std;

void evaluateExpression(ifstream& inpF, ofstream& outF,   //Function that evaluates expression
    stackType<double>& stack,
    char& ch, bool& isExpOk);
void evaluateOpr(ofstream& out, stackType<double>& stack,  //Function that evaluates operators
    char& ch, bool& isExpOk);
void discardExp(ifstream& in, ofstream& out, char& ch);    //Function that discards the expression
void printResult(ofstream& outF, stackType<double>& stack, //function that prints the results
    bool isExpOk);

int main()
{
    bool expressionOk;  //Delcare expressionOK variable
    char ch;            //Declare char ch variable
    stackType<double> stack(100); Creates a stack of size 100 that are type double
        ifstream infile; //Creates ifstream to read the file
    ofstream outfile; //Creates ofstream to write the answer

    infile.open("RpnData.txt"); //opens the "RpnData.txt" to read

    if (!infile) //if the file canot be opened, the program exits
    {
        cout << "Cannot open the input file. " //prints message
            << "Program terminates!" << endl; //prints message
        return 1; //ends program
    }

    outfile.open("RpnOutput.txt"); //opens text file to write data to

    outfile << fixed << showpoint; // sets the floating point value
    outfile << setprecision(2); //sets precision to round to two decimal points

    infile >> ch; //read the first char from file
    while (infile) //while loop to continue reading infile until it ends
    {
        stack.initializeStack(); //initializes the stack
        expressionOk = true; //sets expressionOK to true
        outfile << ch; //write the char

        evaluateExpression(infile, outfile, stack, ch, //calls the evaluateExpression function
            expressionOk);
        printResult(outfile, stack, expressionOk);     //calss the printResult function
        infile >> ch; //begin processing the next expression
    } //end while 

    infile.close(); //closes the infile
    outfile.close(); //closes the outfile

    return 0; //End of program

} //end main


void evaluateExpression(ifstream& inpF, ofstream& outF, stackType<double>& stack, char& ch, bool& isExpOk)
{
    double num; //Declares num variable

    while (ch != '=') //while ch is not '='
    {
        switch (ch) //switches the char
        {
        case '#': //if char is a number
            inpF >> num;  //Reads from input file and puts it in num
            outF << num << " "; //Writes data into output file
            if (!stack.isFullStack()) //If stack is not full
                stack.push(num); //push num into the stack
            else //else if stack is full
            {
                cout << "Stack overflow. "            //prints msg
                    << "Program terminates!" << endl; //prints msg
                exit(0);  //terminate the program
            }

            break; //break to exit switch case loop
        default: //case if ch is not a number
            evaluateOpr(outF, stack, ch, isExpOk); //calls evaluateOpr function
        }//end switch

        if (isExpOk) //if no error
        {
            inpF >> ch; //Reads next char from input file and puts it into ch
            outF << ch; //Writes ch data into the output file

            if (ch != '#') //if ch does not equal a number
                outF << " "; //out a space to output file
        }
        else // else if there is an error
            discardExp(inpF, outF, ch); //Calls the discardExp to discard the expression
    } //end while (!= '=')
} //end evaluateExpression


void evaluateOpr(ofstream& out, stackType<double>& stack,
    char& ch, bool& isExpOk)
{
    double op1, op2; //Declare op1 and op2 as double

    if (stack.isEmptyStack()) //If stack is empty
    {
        out << " (Not enough operands)"; //writes to output file
        isExpOk = false; //sets isExpOk to false since the expression is not ok
    }
    else //Else the stack is not empty
    {
        op2 = stack.top(); // sets op2 to the top of the stack
        stack.pop(); // removes the top element

        if (stack.isEmptyStack()) //If stack is empty
        {
            out << " (Not enough operands)"; //writes to output file
            isExpOk = false; //sets IsExpOk to false since the expression is not ok
        }
        else //else if stack isn't empty
        {
            op1 = stack.top(); //sets op1 to the top of the stack
            stack.pop(); //removes the top element

            switch (ch) //switch case statement that takes ch
            {
            case '+': //If it is addition
                stack.push(op1 + op2); //pushes the value of op1 + op2 to the top of the stack
                break;  //break to exit switch case loop
            case '-': //if it is subtraction
                stack.push(op1 - op2); //pushes the value of op1 - op2 to the top of the stack
                break; //break to exit switch case loop
            case '*': //if it is multiplication
                stack.push(op1 * op2); //pushes the value of op1*op2 to the top of the stack
                break; //break to exit switch case loop
            case '/': //if it is division
                if (op2 != 0) //checks to make sure op2 does not equal 0 
                    stack.push(op1 / op2); //pushes op1 / op2 to the top of the stack
                else //else if op2 is 0
                {
                    out << " (Division by 0)"; //prints msg
                    isExpOk = false; //set isExpOk to false
                }
                break; //break to exit switch case loop
            default: //default case if non of the other cases applied
                out << " (Illegal operator)"; //prints msg
                isExpOk = false; //sets isExpOk to false
            }//end switch
        } //end else
    } //end else
} //end evaluateOpr

//discardExp function
void discardExp(ifstream& in, ofstream& out, char& ch)
{
    while (ch != '=') //while ch is not '='
    {
        in.get(ch); //get new ch from inpute file
        out << ch; //writes ch to output file
    }
} //end discardExp
//printResult function
void printResult(ofstream& outF, stackType<double>& stack,
    bool isExpOk)
{
    double result; //declare result variable as a double

    if (isExpOk) //if no error, print the result
    {
        if (!stack.isEmptyStack()) //if stack is not empty 
        {
            result = stack.top(); //result to set to top of stack
            stack.pop(); //removes the top element

            if (stack.isEmptyStack()) //if stack is empty
                outF << result << endl; //write result to output file 
            else //if stack isn't empty
                outF << " (Error: Too many operands)" << endl; //writes msg to output file
        } //end if
        else //else if stack is empty
            outF << " (Error in the expression)" << endl; //writes msg to output file
    }
    else //else there are error
        outF << " (Error in the expression)" << endl; //writes msg to outpute file

    outF << "_________________________________" //writes msg to output file
        << endl << endl; //two end lines 
} //end printResult
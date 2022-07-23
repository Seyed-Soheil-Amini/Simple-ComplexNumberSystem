// Author : Seyed Mohammad Soheil Amini
// Date : 1400/10/07
// System of Complex
#include <iostream>
#include <math.h>

#define MAX_NUM_COMPLEX 100

using namespace std;
enum COMMAND
{
    PRINT_COMPLEX,
    GET_COMP_MAGNITUDE,
    ADD_COMPLEX,
    SUB_COMPLEX,
    MUL_COMPLEX,
    MAX_COMPLEX,
    ADD_COMP_LIST,
    EXIT
};

struct COMPLEX
{
    float real_part;
    float img_part;
    float magnitude;
};
//this function shows the main menu
COMMAND mian_menu();
/**
 * this function reads the parameters of per complex
 * @return red complex is returned
 */
COMPLEX readComplex();
/**
 * this function print parts of per complex 
 * @param comp parts of this complex is printed
 */
void printComplex(COMPLEX comp);
/**
 * this function calculates the magnitude of complex 
 * @param comp the magnitude of this complex is calculated
 * @return magnitude of complex
 */
float getCompMagnitude(COMPLEX comp);
/**
 * this function calculates sumation of two complexes 
 * @param comp1 fisrt complex
 * @param comp2 second complex
 * @return sumation of two complexs
 */
COMPLEX addComplexes(COMPLEX comp1, COMPLEX comp2);
/**
 * this function calculates subtraction of two complexes 
 * @param comp1 fisrt complex
 * @param comp2 second complex
 * @return subtraction of two complex
 */
COMPLEX subComplexes(COMPLEX comp1, COMPLEX comp2);
/**
 * this function calculates multiplication of two complexes 
 * @param comp1 fisrt complex
 * @param comp2 second complex
 * @return multiplication of two complexes
 */
COMPLEX mulComplexes(COMPLEX comp1, COMPLEX comp2);
/**
 * this function gets the list of complex and return the complex 
 * with the largest magintude
 * @param comp list of complex
 * @param num the number of complexes
 * @return the largets complex
 */
COMPLEX maxComplex(COMPLEX comp[], int num);
/**
 * this function gives magnitude to per complex in list
 * (because list of complexes is a array ,so we dont need to retrun) 
 * @param complexes the list of complexes that have not magnitude
 * @param num the number of complexes
 */
void giveMagnitudeToComplexes(COMPLEX comp[], int num);
/**
 * this function read the real and img part of per complex in list  
 * (because list of complexes is a array ,so we dont need to retrun) 
 * @param comp the list of complexes
 * @param num the number of complexes
 */
void readcomplexes(COMPLEX comp[], int num);
/**
 * this function gets a list of complex and returns the sumation of them as a complex 
 * @param comp list of complexes
 * @param num the number of complexes
 * @return sumation of list of complexes as a complex
 */
COMPLEX addComplexlist(COMPLEX comp[], int num);

int main()
{
    COMPLEX complex[MAX_NUM_COMPLEX], comp1, comp2;
    int num;
    while (1)
    {
        system("cls");
        int command = mian_menu();
        switch (command)
        {
        case COMMAND::PRINT_COMPLEX:
            comp1 = readComplex();
            printComplex(comp1);
            break;
        case COMMAND::GET_COMP_MAGNITUDE:
            comp1 = readComplex();
            cout << "\t"
                 << "The magnitude : " << getCompMagnitude(comp1) << endl;
            break;
        case COMMAND::ADD_COMPLEX:
            comp1 = readComplex();
            comp2 = readComplex();
            printComplex(addComplexes(comp1, comp2));
            break;
        case COMMAND::SUB_COMPLEX:
            comp1 = readComplex();
            comp2 = readComplex();
            printComplex(subComplexes(comp1, comp2));
            break;
        case COMMAND::MUL_COMPLEX:
            comp1 = readComplex();
            comp2 = readComplex();
            printComplex(mulComplexes(comp1, comp2));
            break;
        case COMMAND::MAX_COMPLEX:
            cout << "\tEnter the number of complexes : ";
            cin >> num;
            readcomplexes(complex, num);
            giveMagnitudeToComplexes(complex, num);
            printComplex(maxComplex(complex, num));
            break;
        case COMMAND::ADD_COMP_LIST:
            cout << "\tEnter the number of complexes : ";
            cin >> num;
            readcomplexes(complex, num);
            printComplex(addComplexlist(complex, num));
            break;
        case COMMAND::EXIT:
            return 0;
        default:
            cout << "\tYour command is incorrect!";
            break;
        }
        system("pause");
    }
    return 0;
}
//------------------------------------------------
COMMAND mian_menu()
{
    int command;
    cout << "Enter your command : \n"
         << "\t1-Print a complex\n"
         << "\t2-Get a complex magnitude\n"
         << "\t3-Sum two complexes\n"
         << "\t4-Sub two complexes\n"
         << "\t5-Mul two complexes\n"
         << "\t6-Max magnitude in list of complexes\n"
         << "\t7-Sum list of complexes\n"
         << "\t8-Exit\n"
         << "\t==>";
    cin >> command;
    switch (command)
    {
    case 1:
        return COMMAND::PRINT_COMPLEX;
    case 2:
        return COMMAND::GET_COMP_MAGNITUDE;
    case 3:
        return COMMAND::ADD_COMPLEX;
    case 4:
        return COMMAND::SUB_COMPLEX;
    case 5:
        return COMMAND::MUL_COMPLEX;
    case 6:
        return COMMAND::MAX_COMPLEX;
    case 7:
        return COMMAND::ADD_COMP_LIST;
    default:
        return COMMAND::EXIT;
    }
}
//------------------------------------------------
COMPLEX readComplex()
{
    COMPLEX comp;
    cout << "\tEnter real part : ";
    cin >> comp.real_part;
    cout << "\tEnter img part : ";
    cin >> comp.img_part;
    return comp;
}
//------------------------------------------------
void printComplex(COMPLEX comp)
{
    if (comp.real_part == 0 && comp.img_part == 0)
        cout << "\tThe complex : " << 0 << endl;
    else if (comp.real_part == 0)
        cout << "\tThe complex : " << comp.img_part << "i" << endl;
    else if (comp.img_part == 0)
        cout << "\tThe complex : " << comp.real_part << endl;
    else if (comp.img_part > 0)
        cout << "\tThe complex : " << comp.real_part << "+" << comp.img_part << "i" << endl;
    else
        cout << "\tThe complex : " << comp.real_part << comp.img_part << "i" << endl;
}
//------------------------------------------------
float getCompMagnitude(COMPLEX comp)
{
    return sqrt(pow(comp.real_part, 2) + pow(comp.img_part, 2));
}
//------------------------------------------------
COMPLEX addComplexes(COMPLEX comp1, COMPLEX comp2)
{
    COMPLEX sumComp;
    sumComp.real_part = comp1.real_part + comp2.real_part;
    sumComp.img_part = comp1.img_part + comp2.img_part;
    return sumComp;
}
//------------------------------------------------
COMPLEX subComplexes(COMPLEX comp1, COMPLEX comp2)
{
    COMPLEX subComp;
    subComp.real_part = comp1.real_part - comp2.real_part;
    subComp.img_part = comp1.img_part - comp2.img_part;
    return subComp;
}
//------------------------------------------------
COMPLEX mulComplexes(COMPLEX comp1, COMPLEX comp2)
{
    COMPLEX mulComp;
    mulComp.real_part = (comp1.real_part * comp2.real_part) - (comp1.img_part * comp2.img_part);
    mulComp.img_part = (comp1.img_part * comp2.real_part) + (comp1.real_part * comp2.img_part);
    return mulComp;
}
//------------------------------------------------
void readcomplexes(COMPLEX comp[], int num)
{
    for (int i = 0; i < num; i++)
        comp[i] = readComplex();
}
//------------------------------------------------
void giveMagnitudeToComplexes(COMPLEX comp[], int num)
{
    for (int i = 0; i < num; i++)
        comp[i].magnitude = getCompMagnitude(comp[i]);
}
//------------------------------------------------
COMPLEX maxComplex(COMPLEX comp[], int num)
{
    COMPLEX maxComp = comp[0];
    float maxMagnitude = comp[0].magnitude;
    for (int i = 1; i < num; i++)
    {
        if (comp[i].magnitude > maxMagnitude)
        {
            maxMagnitude = comp[i].magnitude;
            maxComp = comp[i];
        }
    }
    return maxComp;
}
//------------------------------------------------
COMPLEX addComplexlist(COMPLEX comp[], int num)
{
    COMPLEX sumComp;
    sumComp.real_part = 0.0;
    sumComp.img_part = 0.0;
    for (int i = 0; i < num; i++)
    {
        sumComp.real_part += comp[i].real_part;
        sumComp.img_part += comp[i].img_part;
    }
    return sumComp;
}
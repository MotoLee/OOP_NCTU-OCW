// lab1-1.h
namespace Complex{
	
	const double pi = 3.1416;
	
    typedef struct{
        double real;
        double image;
    } Cplex;
        
    // declaration
    void ReadTextFile(char * argv_1, Cplex & c1, Cplex & c2);
    Cplex ComplexOperation(Cplex &a, Cplex &b, char op);
    void PrintComplex(char * argv_2, Cplex * results);
}

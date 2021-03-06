#include "postfix.hh"
#include "context.hh"
#include "binary_operation.hh"
#include "unary_operation.hh"


#include <iostream>
using namespace std;


int main() {
	Context context;
	
	context.op_add(new PlusOperation()).op_add(new MinusOperation()).op_add(new MulOperation()).op_add(new DivOperation()).op_add(new NegateOperation())
	.op_add(new SqOperation()).op_add(new DupOperation());
	

	Postfix postfix(context, cin);
	
	try {
		postfix.run();
	} catch(BinaryOperationError ex) {
		cout << "BINARY ERROR!" << endl;
	} catch(UnaryOperationError ex) {
		cout << "UNARY ERROR!" << endl;
	} catch(DivError ex) {
		cout << "ZERO DEVISOR!" << endl;
	}

	return 0;
}

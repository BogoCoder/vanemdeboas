#include <iostream>
#include "vEB.hpp"
using namespace std;

int main() {

	proto_vEB proto(16);

	cout << "\nINSERTING... " << endl;
	proto.insert(2);
	proto.insert(3);
	proto.insert(4);
	proto.insert(5);
	proto.insert(6);
	proto.insert(7);
	proto.insert(14);
	proto.insert(15);

	cout << "\nMEMBER: " << proto.member(6) << endl;

	cout << "\nMIN: " << proto.min() << endl;

	cout << "\nSUCC: " << proto.succ(14) << endl;
	
	proto.remove(2);
	proto.remove(15);
	
	cout << "\nMEMBER: " << proto.member(7) << endl;
	
	cout << "\nMIN: " << proto.min() << endl;
	
	cout << "\nMAX: " << proto.succ(14) << endl;
	
	return 0;
}

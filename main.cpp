#include <iostream>
#include "vEB.hpp"
using namespace std;

int main() {

	proto_vEB proto;
	proto(16);

	vEB lol;
	cout << "MEMBER: " << lol.member(proto, 4) << endl;

	return 0;
}
#include <iostream>
#include "date.h"

using namespace std;

int main(){
	Date date1(1,1,1);
	date1.modifierDate(2,2,2);
	int mois=date1.getMois();
	cout<<mois; 
	return 0;
}
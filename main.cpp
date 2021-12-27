#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	const int FLAT_RATE = 50;
	const float COST_MILE_PER_RATE_1 = 5.5;
	const float COST_MILE_PER_RATE_2 = 4.0;
	const float COST_MILE_PER_RATE_3 = 2.5;

	const int RATE_DISTANCE_MAX_1 = 100;
	const int RATE_DISTANCE_MAX_2 = 500;
		
	cout << "Each shipment incurs a fixed cost of \x9C and the pric eper ";
	cout << "mile is calculated according to the ruls below:\n";
	cout << "\tEach of the first 100 miles cost \x9C 5.50\n";
	cout << "Over 100 miles and up to and including 500 miles: \x9C 4.00 per ";
	cout << "miles. \n";
	cout << "ztOver 500 miles: \x9C 2.50 per miles. \n\n";



	int distance;
	cout << "Please enter distance to ship the parcel over (in whole miles) ";
	cin >> distance;

	if (distance <= 0)
		cout << "Invalid distance entered\n\n";
	else {
		float cost = FLAT_RATE;
		if (distance <= RATE_DISTANCE_MAX_1) //less than the first distance band(100)
			cost += distance * COST_MILE_PER_RATE_1;
		else {
			cost += RATE_DISTANCE_MAX_1 * COST_MILE_PER_RATE_1;
			if (distance <= RATE_DISTANCE_MAX_2) //betwen first and second dist band (100-500)
				cost += (distance - RATE_DISTANCE_MAX_2);
			else { //greater than the second distance band
				cost += (RATE_DISTANCE_MAX_1 - RATE_DISTANCE_MAX_1) * COST_MILE_PER_RATE_2;
				cost += (distance - RATE_DISTANCE_MAX_2) * COST_MILE_PER_RATE_3;
			}
		}
		cout << "Cost of shipping is: \x9C" << fixed << setprecision(2) << cost << "\n\n";
	}
	system("Pause");
	return 0;
}

//Zero Trace Programmed by Joel Serfoss
#include <iostream>
#include <list>
#include <vector>
using namespace std;
vector<int> loadpayload() {
	vector<int> payload;
	int value;
	int size;
	cout << "How many mission critical values are being entered?" << endl;
	cin >> size;
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << "Enter value " << i + 1 << ": " << endl;
		cin >> value;
		payload.push_back(value);
	}
	cout << endl;
	return payload;
}
template <typename T>
void display(const T& container) {
	cout << "Payload Data Stream: " << endl;
	for (auto it = container.begin(); it != container.end(); it++) {
		cout << *it;
		if (next(it) != container.end())
			cout << "->";
	}
	cout << endl;
}
int main() {
	cout << "========================================" << endl;
	cout << "=== ZeroTrace // Black Ops Terminal ===" << endl;
	cout << "========================================" << endl;
    cout << endl;

	
	bool missionActive = true;
	vector<int> payload;
	while (missionActive) {
		cout << "Would you like to start the mission? (y/n)" << endl;
		char start;
		cin >> start;
		if (start == 'y' || start == 'Y') {
			cout << "Mission started." << endl;
			cout << endl;
			payload = loadpayload();
			cout << "Vector:" << endl;
			display(payload);
			cout << endl;
			cout << "Extracting payload......." << endl;
			cout << endl;
			list<int> extractedPayLoad(payload.begin(), payload.end());
			cout << "Extracted list from vector:" << endl;
			display(extractedPayLoad);
			cout << endl;
			cout << "Paylod successfully extracted. No trace found." << endl;
		}
		else if (start == 'n' || start == 'N') {
			cout << "Mission aborted!" << endl;
			missionActive = false;
		}
		else
			cout << "Invalid input. Please try again." << endl;
	}
	return 0;

}
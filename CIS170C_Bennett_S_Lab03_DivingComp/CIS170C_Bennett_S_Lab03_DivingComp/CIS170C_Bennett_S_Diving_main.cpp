/* Name: Steven Bennett
	Date: March 21, 2013
	Assignment: Week 3 Lab 3 Diving Competition */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main ()
{
	//variable declarations
	double finalScore = 0.0;
	int numberOfDivers = 0;
	
	//output report heading
	cout << "Report to the media." << endl;
	cout << "Event: Diving Competition\n" << endl;

	//initialize and begin loop allowing user option of processing more divers
	char processDiver = 'y';
	while (processDiver == 'y' || processDiver == 'Y')
	{
		cout << "----------------------------------------------------" << endl;
		cout << "\nEnter diver's name: ";
		string diverName;
		getline(cin, diverName);
		cout << "Enter diver's city: ";
		string diverCity;
		getline(cin, diverCity);

		//initialize highestScore, lowestScore, and totalScore
		double highScore = 0.0;
		double lowScore = 11.0;
		double totalScore = 0.0;

		//use do...while loop to process the scores of 5 judges
		int count = 0;
		do
		{
			cout << "Enter score of judge #" << count + 1 << ": ";
			double judgeScore = 0.0;
			cin >> judgeScore;
			while (judgeScore < 0 || judgeScore > 10)
			{
				cout << "Invalid Score! Enter score between 0 to 10." << endl;
				cout << "Enter sore of judge #" << count + 1 << ": ";
				cin >> judgeScore;
			}
			
			//total up judgeScore and determine highestScore and lowestScore
			totalScore += judgeScore;
			if (judgeScore > highScore)
				highScore = judgeScore;
			if (judgeScore < lowScore)
				lowScore = judgeScore;

			//increment counter
			count++;
		} while (count < 5);

		//prompt user to input degree of difficulty and validate input
		cout << "Enter degree of difficulty (1.00 to 1.67): ";
		double degreeOfDifficulty = 0.0;
		cin >> degreeOfDifficulty;
		while (degreeOfDifficulty < 1.00 || degreeOfDifficulty > 1.67)
		{
			cout << "Invalid Input!" << endl;
			cout << "Enter degree of difficulty (1.00 to 1.67): ";
			cin >> degreeOfDifficulty;
		}

		//calculate diver's overallScore
		double overallScore = 0.0;
		totalScore -= highScore;
		totalScore -= lowScore;
		overallScore = (totalScore / 3) * degreeOfDifficulty;

		//display diver's information and overallScore
		cout << "\nDiver: " << diverName << endl;
		cout << "City: " << diverCity << endl;
		cout << setprecision(2) << fixed;
		cout << "Overall Score: " << overallScore << endl;

		//add diver's overallScore to finalScore and increment numberOfDivers
		finalScore += overallScore;
		numberOfDivers++;

		//prompt user to process another diver
		cout << "\n\nWould you like to process another diver (Y/N)?";
		cin >> processDiver; //take a look at this during debugging. May need to validate input.
		cin.ignore();//Check this
	}

	//calculate averageScoreAllDivers. Display numberOfDivers and averageScoreAllDivers.
	cout << "----------------------------------------------------" << endl;
	cout << "\n\t\tEVENT SUMMARY\t\t\n" << endl;
	double averageScoreAllDivers = 0.0;
	averageScoreAllDivers = finalScore / numberOfDivers;
	cout << setprecision(2) << fixed;
	cout << "Number of divers: " << numberOfDivers << endl;
	cout << "Average score of all divers: " << averageScoreAllDivers << endl;

	return 0;
}
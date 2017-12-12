// C++ Lab 8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
//create a program that is a game that races two planes measured in km/hour 
//the program will us one function to be called in the main fucntion 

//speed is a little off

void planeFunc(int time, float accel, float &dist, float &speed)
{
	//calculate the formulas for speed and distance
	speed = time * accel / 2;
	dist = 0.5 * time * time * accel;
}

int _tmain(int argc, _TCHAR* argv[]) 
{
	//Generate the random numbers 
	srand(time(0));
	float accel1 = rand() % 25 + 5;
	float accel2 = rand() % 25 + 5;

	//establish the variables that will be used within the program and the boolean value 
	float dist1, dist2, speed1, speed2;
	int time = 0;
	bool flying = true;

	 //create the table to diaply the time distance and speed 
	cout << setw(5) << "Time"
		<< setw(10) << "Dist one " << setw(10) << "Speed 1"
		<< setw(10) << "Dist two " << setw(10) << "Speed 2" << endl;
	cout << setprecision(2) << fixed << right;

	//creat a loop that will call the functons and calculate the two 
	while (flying)
	{
		//calculate the distances for both planes
		dist1 = time * time * accel1 * 0.5 / 1000;
		dist2 = time * time * accel2 * 0.5 / 1000;

		//calculate the speed for both planes
		speed1 = time * accel1 * 3.6;
		speed2 = time * accel2 * 3.6;

		//call the funtions
		planeFunc(time, accel1, dist1, speed1);
		planeFunc(time, accel2, dist2, speed2);

		//align the distance and speed values within the table
		cout << setw(5) << time
			<< setw(10) << (dist1 / 1000) << setw(10) << (speed1)
			<< setw(10) << (dist2 / 1000) << setw(10) << (speed2) << endl;

		if (time >= 20)
		{
			flying = false;
		}
		time++;
	}
	system("pause");
	return 0;
}


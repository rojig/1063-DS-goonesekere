/**
* @Homework: Homework-3
* @Author: Rojitha Goonesekere
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 28 02 2017
*/

/**
* @FunctionName: Print
* @Description: 
*     Changed the existing function to see if the loop was full and print if it is
* @Params:
*    Index, isFull
* @Returns:
*    NONE
*/
void Prin

	//If loop full print the results
	void Print(){
		int Index = Front;
		bool isFull = Full();

		while (Index != Rear || isFull){
			cout << Q[Index] << " ";
			Index = ((Index + 1) % (ArraySize));
			isFull = false;
		}
		cout << endl;
	}

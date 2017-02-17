/*
Program-2
Rojitha Goonesekere
The program has image manipulation functions within
a class called ImageManip
1063 Data Structures
Spring 2017
February 17, 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

class ImageManip {
private:
	rgb** image;
	int width;
	int height;
	ifstream ifile;
	ofstream ofile;
	string ifile_name;
	string ofile_name;

	void readFile() {
		ifile.open(ifile_name);
		if (!ifile) {
			cout << "Error no information to be read in" << endl;
		}
		else {
			ifile >> width >> height;

			image = new rgb*[height];

			for (int i = 0; i < height; i++) {
				image[i] = new rgb[width];
			}
			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					ifile >> image[i][j].r >> image[i][j].g >> image[i][j].b;
				}
			}
		}
		ifile.close();
	}

	void writeFile() {
		ofile.open(ofile_name);
		ofile << width << " " << height << endl;
		for (int i = 0; i<height; i++) {
			for (int j = 0; j<width; j++) {
				ofile << image[i][j].r << " " << image[i][j].g << " " << image[i][j].b << " ";
			}
			ofile << endl;
		}
		ofile.close();
	}

public:
	ImageManip() {
	}
	/*
	Function name: flipVert
	Description: loops through the array and flips the image vertically
	Parameters:
	string input - the file you are reading from
	string output - the file you are writing into
	Returns: void
	*/
	void flipVert(string output, string input) {
		ifile_name = input;
		ofile_name = input;
		readFile();
		for (int i = 0; i < height / 2; i++) {
			for (int j = 0; j < width; j++) {
				rgb initialRow, finalRow; //initial refers to location of row 
				initialRow = image[i][j]; //before being moved and final refers to
				finalRow = image[height - 1 - i][j]; //location of row after being moved
				image[i][j] = finalRow;
				image[height - 1 - i][j] = initialRow;
			}
		}
		writeFile();
	}
	/*
	Function name: flipHorz
	Description: loops through the 2D array and flips the image  
        horizontally
	Parameters:
	string input - the file you are reading from
	string output - the file you are writing into
	Returns: void
	*/
	void flipHorz(string input, string output) {
		ifile_name = input;
		ofile_name = input;
		readFile();
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width / 2; j++) {
				rgb initialCol, finalCol;//initial refers to location of column
				initialCol = image[i][j];//before being moved and final refers to
				finalCol = image[i][width - 1 - j];//location of column after being moved
				image[i][j] = finalCol;
				image[i][width - 1 - j] = initialCol;
			}
		}
		writeFile();
	}
	/*
	Function name: greyScale
	Description: Loops through and uses a function to make the rgb values grey scale
	Parameters:
	string input – the file you are reading from
	string output - the file you are writing to
	Returns: void
	*/
	void grayScale(string input, string output) {
		ifile_name = input;
		ofile_name = output;
		readFile();
		int grayColor;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				grayColor = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
				image[i][j].r = grayColor;
				image[i][j].g = grayColor;
				image[i][j].b = grayColor;
			}

		}
		writeFile();
	}
	~ImageManip() {

	}
};

int main() {
	ImageManip imageInfo;

	imageInfo.grayScale("bot1.txt", "bot2.txt");
	imageInfo.flipHorz("bot1.txt", "bot2.txt");
	imageInfo.flipVert("bot1.txt", "bot2.txt");


	system("pause");
	return 0;
}


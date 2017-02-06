/*
Program-1
Rojitha Goonesekere
This program flips an image vertically and horizontally and then 
converts the image into grey scale
1063 Data Structures
Spring 2017
January 5, 2017
*/

include<iostream>
include<fstream>
include<math.h>

using namespace std;

struct rgb {
	int r;
	int g;
	int b;
};

/*
Function name: flipVert
Description: This function will loop through the 2D array and changes or flips
each row so that the image will be flipped vertically
Parameters:
rgb** image - rgb values will be held in this 2D array
int width - columns of the array
int height - rows of the array
Returns: void
*/
void flipVert(rgb** image, int width, int height) {
	for (int i = 0; i < height / 2; i++) {
		for (int j = 0; j < width; j++) {
			rgb initialRow, finalRow; //initial refers to location of row 
			initialRow = image[i][j]; //before being moved and final refers to
			finalRow = image[height - 1 - i][j]; //location of row after being moved
			image[i][j] = finalRow;
			image[height - 1 - i][j] = initialRow;
		}
	}

}
/*
Function name: flipHorz
Description: This function will loop through the 2D array and change up
each column the opposite way so that the image will be flipped horizontally
Parameters:
rgb** image - rgb values will be held in this 2D array
int width - columns of the array
int height - rows of the array
Returns: void
*/
void flipHorz(rgb** image, int width, int height) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width / 2; j++) {
			rgb initialCol, finalCol;//initial refers to location of column
			initialCol = image[i][j];//before being moved and final refers to
			finalCol = image[i][width - 1 - j];//location of column after being moved
			image[i][j] = finalCol;
			image[i][width - 1 - j] = initialCol;
		}
	}

}
/*
Function name: greyScale
Description: Loops through a 2D array and turns every RGB value into its grayscale 
equivalent.
Parameters:
rgb** image - rgb values will be held in this 2D array
int width - columns of the array
int height - rows of the array
Returns: void
*/
void grayScale(rgb** image, int width, int height) {
	int grayColor;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			grayColor = (image[i][j].r + image[i][j].g + image[i][j].b) / 3;
			image[i][j].r = grayColor;
			image[i][j].g = grayColor;
			image[i][j].b = grayColor;
		}

	}

}


int main() {
	ifstream ifile;
	ofstream ofile;
	ifile.open("bot.txt");
	ofile.open("bot2.txt");

	int width;
	int height;

	rgb **imgArray;

	ifile >> width >> height;

	imgArray = new rgb*[height];

	for (int i = 0; i<height; i++) {
		imgArray[i] = new rgb[width];
	}

	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ifile >> imgArray[i][j].r >> imgArray[i][j].g >> imgArray[i][j].b;
		}
	}

	flipVert(imgArray, width, height);
	flipHorz(imgArray, width, height);
	grayScale(imgArray, width, height);

	ofile << width << " " << height << endl;
	for (int i = 0; i<height; i++) {
		for (int j = 0; j<width; j++) {
			ofile << imgArray[i][j].r << " " << imgArray[i][j].g << " " << imgArray[i][j].b << " ";
		}
		ofile << endl;
	}



	return 0;
}

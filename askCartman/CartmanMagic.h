// Header file
#include "DarkGDK.h"
#include <iostream>
#include<string.h>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;


// Answer class ///////////////////////////////////////////////////////////////////////////////////////////
class Answer
{
private:
	char* CartmansAnswer; 
	char* userQuestion;
	char* dataFile;

public:
	Answer(char* newAnswer);
	void getAnswer();
	char* returnAnswer();
	
	

};
/**************IMAGE CLASS *****************/////////////////////////////////////////////////////////////
class ImageClass
{
private:
	int imageNum;
	char* imageFileName;

public:
	ImageClass(char* imageFile, int imageNumber);
	~ImageClass();
	void loadImages();
	void pasteImages(int,int);
	
	
};
/**************AUDIO CLASS *****************//////////////////////////////////////////////////////////////
class AudioClass
{
private:
	int audioNum;
	int audioVol;
	char* audioFileName;

public:
	AudioClass(char* audioFile, int audioNumber, int volume);
	void loadSound();
	void loadMusic();
	void playSound();
	void playMusic();
	void loopMusic();
};
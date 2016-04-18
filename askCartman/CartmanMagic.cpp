// cpp file for classes definitions
#include "CartmanMagic.h"



///////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************ANSWER CLASS***************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////

// Answer Constructor #1
Answer::Answer(char* newAnswer)
{
	CartmansAnswer = newAnswer;		
}


// This function displays answer.
void Answer::getAnswer()
{	
	dbCenterText(dbScreenWidth()/2, 460, CartmansAnswer);
}
char* Answer::returnAnswer()
{
	return CartmansAnswer;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************IMAGE CLASS***************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////

ImageClass::ImageClass(char* imageFile, int imageNumber)
{
	imageFileName = imageFile;
	imageNum = imageNumber;
}
ImageClass::~ImageClass(){}
void ImageClass::loadImages()
{
	dbLoadImage(imageFileName, imageNum);
}
void ImageClass::pasteImages(int x, int y)
{
	dbPasteImage(imageNum, x, y);
}


///////////////////////////////////////////////////////////////////////////////////////////////////////
/**************************************AUDIO CLASS***************************************************/
///////////////////////////////////////////////////////////////////////////////////////////////////////

AudioClass::AudioClass(char *audioFile, int audioNumber, int volume)
{
	audioFileName = audioFile;
	audioNum = audioNumber;
	audioVol = volume;
}
void AudioClass::loadMusic()
{
	dbLoadMusic(audioFileName, audioNum);
	dbSetMusicVolume(audioNum, audioVol);
}
void AudioClass::loadSound()
{
	dbLoadSound(audioFileName, audioNum);
	dbSetSoundVolume(audioNum, audioVol);
}
void AudioClass::playMusic()
{
	dbPlayMusic(audioNum);
}
void AudioClass::playSound()
{
	dbPlaySound(audioNum);
}
void AudioClass::loopMusic()
{
	dbLoopMusic(audioNum);
}
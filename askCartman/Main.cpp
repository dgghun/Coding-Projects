// started 4-8-13
// finished 5-8-13
#include "CartmanMagic.h"
#include <ctime>
using namespace std;

// GLOBAL Variables 
int cartmanX = -50; // x coordinate for cartman image
int cartmanY = 0;	// y coordinate for cartman image
int blink = 100;	// variable to make cartman blink
double loading = 10;
const int voiceVolume = 92;

// Variable for Diskette image
int diskImage = 201;

// program info function
void programInfo();

//// DarkGDK Start
void DarkGDK()
{
	dbLoadImage("images\\Z_illusion.png", diskImage);
	programInfo();


	//// AUDIO CLASS	
	AudioClass audioAnswers[] =
	{
		AudioClass("audio\\audioAnswer_0.wav", 1, voiceVolume),	//	0
		AudioClass("audio\\audioAnswer_1.wav", 2, voiceVolume),	//	1
		AudioClass("audio\\audioAnswer_2.wav", 3, voiceVolume),	//	2
		AudioClass("audio\\audioAnswer_3.wav", 4, voiceVolume),	//	3
		AudioClass("audio\\audioAnswer_4.wav", 5, voiceVolume),	//	4
		AudioClass("audio\\audioAnswer_5.wav", 6, voiceVolume),	//	5
		AudioClass("audio\\audioAnswer_6.wav", 7, voiceVolume),	//	6
		AudioClass("audio\\audioAnswer_7.wav", 8, voiceVolume),	//	7
		AudioClass("audio\\audioAnswer_8.wav", 9, voiceVolume),	//	8
		AudioClass("audio\\audioAnswer_9.wav", 10, voiceVolume),	//	9
		AudioClass("audio\\audioAnswer_10.wav", 11, voiceVolume),	//	10
		AudioClass("audio\\audioAnswer_11.wav", 12, voiceVolume),	//	11
		AudioClass("audio\\audioAnswer_12.wav", 13, voiceVolume),	//	12
		AudioClass("audio\\audioAnswer_13.wav", 14, voiceVolume),	//	13
		AudioClass("audio\\audioAnswer_14.wav", 15, voiceVolume),	//	14
		AudioClass("audio\\audioAnswer_15.wav", 16, voiceVolume),	//	15
		AudioClass("audio\\audioAnswer_16.wav", 17, voiceVolume),	//	16
		AudioClass("audio\\audioAnswer_17.wav", 18, voiceVolume),	//	17
		AudioClass("audio\\audioAnswer_18.wav", 19, voiceVolume),	//	18
		AudioClass("audio\\audioAnswer_19.wav", 20, voiceVolume)	//	19
	};
	for (int i = 0; i <= 19; i++)
	{
		audioAnswers[i].loadSound();
	}

	AudioClass gameLogoMusic("audio\\gameLogoMusic.mp3", 21, 60); // Game logo music
	gameLogoMusic.loadMusic();

	AudioClass gameSong("audio\\gameSong.mp3", 22, 30); // Main game song
	gameSong.loadMusic();

	AudioClass handClap("audio\\handClap.wav", 23, 80); // Audience clap
	handClap.loadSound();

	AudioClass introduceCartman("audio\\introduceCartman.wav", 24, 95); // Announcer for cartman
	introduceCartman.loadSound();

	AudioClass cartmanSounds[] =
	{
		AudioClass("audio\\respectMy.wav", 25, 100),		//	0
		AudioClass("audio\\askMe.wav", 26, 100),			//	1
		AudioClass("audio\\LetsSee.wav", 27, 100),			//	2
		AudioClass("audio\\noMoreQuestions.wav", 28, 100),	//	3
		AudioClass("audio\\closeThe.wav", 29, 100),		//	4
	};
	for (int i = 0; i <= 4; i++)
	{
		cartmanSounds[i].loadSound();
	}

	AudioClass kenny[] =
	{
		AudioClass("audio\\kenny_1.wav", 30, 99),
		AudioClass("audio\\kenny_2.wav", 31, 99)
	};
	for (int i = 0; i <= 1; i++)
	{
		kenny[i].loadSound();
	}

	AudioClass handClapLong("audio\\handClapLong.wav", 32, 85); // audience clapping long time
	handClapLong.loadSound();

	AudioClass drumRoll("audio\\drumRoll.wav", 33, 90); // drummer roll
	drumRoll.loadSound();

	AudioClass crowd("audio\\crowd.wav", 34, 90); // crowd talking
	crowd.loadSound();
	programInfo();

	//// IMAGE CLASS
	ImageClass cartmanBody[] =
	{
		ImageClass("images\\DefaultCartman.jpg", 1),
		ImageClass("images\\DefaultCartmanBlink.jpg", 2),
		ImageClass("images\\DefaultCartmanMad.jpg", 3),
		ImageClass("images\\DefaultCartmanMadSmile.jpg", 4),
		ImageClass("images\\DefaultCartmanSmile.jpg", 5),
		ImageClass("images\\DefaultCartmanThinking.jpg", 6),
		ImageClass("images\\DefaultCartmanWorried.jpg", 7),
	};
	for (int i = 0; i <= 6; i++)
	{
		cartmanBody[i].loadImages();
	}
	programInfo();

	ImageClass cartmanTalking[] =
	{
		ImageClass("images\\talking_0.jpg", 8),
		ImageClass("images\\talking_1.jpg", 9),
		ImageClass("images\\talking_2.jpg", 10),
		ImageClass("images\\talking_3.jpg", 11),
		ImageClass("images\\talking_4.jpg", 12),
		ImageClass("images\\talking_5.jpg", 13),
		ImageClass("images\\talking_6.jpg", 14),
		ImageClass("images\\talking_7.jpg", 15),
		ImageClass("images\\talking_8.jpg", 16),
		ImageClass("images\\talking_9.jpg", 17),
		ImageClass("images\\talking_10.jpg", 18),
		ImageClass("images\\talking_11.jpg", 19)
	};
	for (int i = 0; i <= 11; i++)
	{
		cartmanTalking[i].loadImages();
	}
	programInfo();

	ImageClass cartmanMadTalking[] =
	{
		ImageClass("images\\MadTalking_0.jpg", 20),
		ImageClass("images\\MadTalking_1.jpg", 21),
		ImageClass("images\\MadTalking_2.jpg", 22),
		ImageClass("images\\ArmUpMadTalking_3.jpg", 23),
		ImageClass("images\\ArmUpMadTalking_4.jpg", 24),
		ImageClass("images\\MadTalking_5.jpg", 25),
		ImageClass("images\\MadTalking_6.jpg", 26),
		ImageClass("images\\MadTalking_7.jpg", 27),
		ImageClass("images\\MadTalking_8.jpg", 28),
		ImageClass("images\\MadTalking_9.jpg", 29),
		ImageClass("images\\MadTalking_10.jpg", 30)
	};
	for (int i = 0; i <= 10; i++)
	{
		cartmanMadTalking[i].loadImages();
	}
	programInfo();

	ImageClass cartmanArmUpMadTalking[] =
	{
		ImageClass("images\\ArmUpMadTalking_0.jpg", 31),
		ImageClass("images\\ArmUpMadTalking_1.jpg", 32),
		ImageClass("images\\ArmUpMadTalking_2.jpg", 33),
		ImageClass("images\\ArmUpMadTalking_3.jpg", 34),
		ImageClass("images\\ArmUpMadTalking_4.jpg", 35),
		ImageClass("images\\ArmUpMadTalking_5.jpg", 36),
		ImageClass("images\\ArmUpMadTalking_6.jpg", 37),
		ImageClass("images\\ArmUpMadTalking_7.jpg", 38),
		ImageClass("images\\ArmUpMadTalking_8.jpg", 39),
		ImageClass("images\\ArmUpMadTalking_9.jpg", 40),
		ImageClass("images\\ArmUpMadTalking_10.jpg", 41),
		ImageClass("images\\ArmUpMadTalking_11.jpg", 42)
	};
	for (int i = 0; i <= 11; i++)
	{
		cartmanArmUpMadTalking[i].loadImages();
	}
	programInfo();

	// Images for lights on curtain
	ImageClass lightsIntro[] =
	{
		ImageClass("images\\intro_2.jpg", 43), // 0
		ImageClass("images\\intro_3.jpg", 44), // 1
		ImageClass("images\\intro_4.jpg", 45), // 2
		ImageClass("images\\intro_5.jpg", 46), // 3
		ImageClass("images\\intro_6.jpg", 47), // 4
		ImageClass("images\\intro_7.jpg", 48), // 5
		ImageClass("images\\intro_8.jpg", 49), // 6
		ImageClass("images\\intro_9.jpg", 50), // 7
		ImageClass("images\\intro_10.jpg", 51), // 8
		ImageClass("images\\intro_11.jpg", 52), // 9
		ImageClass("images\\intro_12.jpg", 53), // 10
		ImageClass("images\\intro_13.jpg", 54), // 11
		ImageClass("images\\intro_14.jpg", 55), // 12
		ImageClass("images\\intro_15.jpg", 56), // 13
		ImageClass("images\\intro_16.jpg", 57), // 14
		ImageClass("images\\intro_17.jpg", 58), // 15
		ImageClass("images\\intro_18.jpg", 59), // 16
		ImageClass("images\\intro_19.jpg", 60)  // 17
	};
	for (int i = 0; i <= 17; i++)
	{
		lightsIntro[i].loadImages();
	}
	programInfo();

	// Images for curtain movement
	ImageClass introCurtain[] =
	{
		ImageClass("images\\introCurtain.jpg", 61), // 0 = Closed curtains
		ImageClass("images\\introCurtain_2.jpg", 62), // 1
		ImageClass("images\\introCurtain_3.jpg", 63), // 2
		ImageClass("images\\introCurtain_4.jpg", 64), // 3
		ImageClass("images\\introCurtain_5.jpg", 65), // 4
		ImageClass("images\\introCurtain_6.jpg", 66), // 5
		ImageClass("images\\introCurtain_7.jpg", 67), // 6
		ImageClass("images\\introCurtain_8.jpg", 68)  // 7
	};
	for (int i = 0; i <= 7; i++)
	{
		introCurtain[i].loadImages();
	}
	programInfo();

	//// Images for cartman running in scene
	ImageClass cartmanEntrance[] =
	{
		ImageClass("images\\entrance_0.jpg", 69), // 0
		ImageClass("images\\entrance_1.jpg", 70), // 1
		ImageClass("images\\entrance_2.jpg", 71), // 2
		ImageClass("images\\entrance_3.jpg", 72), // 3
		ImageClass("images\\entrance_4.jpg", 73), // 4
		ImageClass("images\\entrance_5.jpg", 74), // 5
		ImageClass("images\\entrance_6.jpg", 75), // 6
		ImageClass("images\\entrance_7.jpg", 76), // 7
		ImageClass("images\\entrance_8.jpg", 77), // 8
		ImageClass("images\\entrance_9.jpg", 78), // 9
		ImageClass("images\\entrance_10.jpg", 79), // 10
		ImageClass("images\\entrance_11.jpg", 80), // 11
		ImageClass("images\\entrance_12.jpg", 81), // 12
		ImageClass("images\\entrance_13.jpg", 82), // 13
		ImageClass("images\\entrance_14.jpg", 83), // 14
		ImageClass("images\\entrance_15.jpg", 84), // 15
		ImageClass("images\\entrance_16.jpg", 85), // 16
		ImageClass("images\\entrance_17.jpg", 86), // 17
		ImageClass("images\\entrance_18.jpg", 87), // 18
		ImageClass("images\\entrance_19.jpg", 88)  // 19
	};
	for (int i = 0; i <= 19; i++)
	{
		cartmanEntrance[i].loadImages();
	}
	programInfo();

	//// Images for outro
	ImageClass outro[] =
	{
		ImageClass("images\\outro_1.jpg", 89),	//	0
		ImageClass("images\\outro_2.jpg", 90),	//	1
		ImageClass("images\\outro_3.jpg", 91),	//	2
		ImageClass("images\\outro_4.jpg", 92),	//	3
		ImageClass("images\\outro_5.jpg", 93),	//	4
		ImageClass("images\\outro_6.jpg", 94),	//	5
		ImageClass("images\\outro_7.jpg", 95),	//	6
		ImageClass("images\\outro_8.jpg", 96),	//	7
		ImageClass("images\\outro_9.jpg", 97),	//	8
		ImageClass("images\\outro_10.jpg", 98),	//	9
		ImageClass("images\\outro_11.jpg", 99),	//	10
		ImageClass("images\\outro_12.jpg", 101),	//	11
		ImageClass("images\\outro_13.jpg", 102),	//	12
		ImageClass("images\\outro_14.jpg", 103),	//	13
		ImageClass("images\\outro_15.jpg", 104),	//	14
		ImageClass("images\\outro_16.jpg", 105),	//	15
		ImageClass("images\\outro_17.jpg", 106),	//	16
		ImageClass("images\\outro_18.jpg", 107),	//	17
		ImageClass("images\\outro_19.jpg", 108),	//	18
		ImageClass("images\\outro_20.jpg", 109),	//	19
		ImageClass("images\\outro_21.jpg", 110),	//	20
		ImageClass("images\\outro_22.jpg", 111),	//	21
		ImageClass("images\\outro_23.jpg", 112),	//	22
		ImageClass("images\\outro_24.jpg", 113),	//	23
		ImageClass("images\\outro_25.jpg", 114),	//	24
		ImageClass("images\\outro_26.jpg", 115),	//	25
		ImageClass("images\\outro_27.jpg", 116),	//	26
		ImageClass("images\\outro_28.jpg", 117),	//	27
		ImageClass("images\\outro_29.jpg", 118),	//	28
		ImageClass("images\\outro_30.jpg", 119),	//	29
		ImageClass("images\\outro_31.jpg", 120),	//	30
		ImageClass("images\\outro_32.jpg", 121),	//	31
		ImageClass("images\\outro_33.jpg", 122),	//	32
		ImageClass("images\\outro_34.jpg", 123),	//	33
		ImageClass("images\\outro_35.jpg", 124),	//	34
		ImageClass("images\\outro_36.jpg", 125),	//	35
		ImageClass("images\\outro_37.jpg", 126),	//	36
		ImageClass("images\\outro_38.jpg", 127)		//	37
	};
	for (int i = 0; i <= 37; i++)
	{
		outro[i].loadImages();
	}
	programInfo();

	// Stage background
	ImageClass stage("images\\cartmanStage.jpg", 128);
	stage.loadImages();

	//// Game intro Logo
	int gameLogo = 129;
	dbLoadImage("images\\askCartmanLOGO.jpg", gameLogo);


	//// ANSWER CLASS
	Answer AllAnswers[] =
	{
		Answer(" Holy guacamole, it is possibly certain. "),//0
		Answer(" Well, it is decidedly so. "),	//1				
		Answer(" The great Cartman says without a doubt. "),//2
		Answer(" You're in luck, my awesome powers say most definitely. "),//3
		Answer(" You may rely on it but I surely wouldn't. "),//4
		Answer(" As I see it and it would be wise to listen to the great Cartman,...yes "),//5
		Answer(" Let's say probably. "),//6
		Answer(" The powerful Cartman says your outlook is good.  "),//7
		Answer(" Yes, but please ask a more intelligent question next time. "),//8
		Answer(" All the signs point to yes and you're welcome. "),//9
		Answer(" It's a little hazy, try again later when you bring me some KFC. "),//10
		Answer(" Ask again later I have better things to do then answer such questions. "),//11
		Answer(" I've decided not to tell you now. Good day. "),//12
		Answer(" Sorry I cannot predict that question ask a better one. "),//13
		Answer(" Ok we both know the answer to that question so stop being sick! "),//14
		Answer(" I personally wouldn't count on it. "),//15
		Answer(" My reply is no. Get over it. "),//16
		Answer(" My highly evolved powers tell me the answer is no. "),//17
		Answer(" Ha! You really think I would answer that question! "),//18
		Answer(" I think you have stumped me on that one. Next question please. "),//19
	};

	// In/Output files //
	dbDeleteFile("QuestionData.txt");// Deletes In/Output file to start fresh. 
	ofstream Q_AFile; // initialize a In/Output file
	Q_AFile.open("QuestionData.txt");// Open file to write questions and answers
	Q_AFile << " ANSWERS TO QUESTIONS " << endl; // output file header
	Q_AFile << endl; // new line 
	int QNum = 1; // For In/Output file to know what question number was asked. 

	int rndNum; // initialize random num variable for question, image, audio and output file.
	dbRandomize(time(0)); // Seed Random timer with system clock
	bool playing = true; // Check if still playing


	//// When everything is done loading press key
	dbCLS();
	dbWait(100);
	dbSetImageColorKey(0, 0, 0); // Set color to be transparent.
	dbCenterText(dbScreenWidth() / 2, dbScreenHeight() / 2, "Press any key.");
	dbWaitKey();// Everything is done loading
	dbCLS();

	//////////////////////////////////////////////////////////////////
	/******************* PROGRAM BEGIN*******************************/
	//////////////////////////////////////////////////////////////////

	////// GameLogo fade in
	dbCLS();
	gameLogoMusic.playMusic();
	dbWait(800);
	DWORD white = dbRGB(255, 255, 255);
	dbCLS(white);
	dbSprite(gameLogo, cartmanX + 22, cartmanY, gameLogo);
	dbSetSprite(gameLogo, 1, 1);
	dbSetSpriteAlpha(gameLogo, 0);
	for (int i = 0; i <= 255; i++)
	{
		dbSetSpriteAlpha(gameLogo, i);
		dbWait(16);
	}
	dbWait(3000);
	dbDeleteSprite(gameLogo);
	dbCLS();
	dbWait(2000);

	//// Lights on Curtain
	gameSong.loopMusic();// game song starts and loops
	crowd.playSound();
	introCurtain[0].pasteImages(cartmanX, cartmanY);
	for (int i = 0; i <= 17; i++)
	{
		lightsIntro[i].pasteImages(cartmanX, cartmanY);
		dbWait(90);
	}
	introduceCartman.playSound(); // " Ladies and gentlemen!"
	for (int times = 0; times < 2; times++) // Loop lights
	{
		for (int i = 6; i <= 17; i++)
		{

			lightsIntro[i].pasteImages(cartmanX, cartmanY);
			dbWait(90);
		}
	}
	handClap.playSound();
	for (int i = 5; i >= 0; i--) // Lights leave
	{
		lightsIntro[i].pasteImages(cartmanX, cartmanY);
		dbWait(90);
	}
	introCurtain[0].pasteImages(cartmanX, cartmanY);

	///// Open Curtains
	for (int i = 0; i <= 6; i++)
	{
		introCurtain[i].pasteImages(cartmanX, cartmanY);
		dbWait(100);
	}
	stage.pasteImages(cartmanX, cartmanY);

	//// Cartman entrance
	for (int i = 0; i <= 19; i++)
	{
		cartmanEntrance[i].pasteImages(cartmanX, cartmanY);
		dbWait(100);
	}
	cartmanBody[4].pasteImages(cartmanX, cartmanY);
	dbWait(1000);
	cartmanBody[2].pasteImages(cartmanX, cartmanY);
	dbWait(500);
	cartmanSounds[0].playSound(); // play cartman
	for (int times = 0; times <= 2; times++)// " I am the great Cartman!"
	{
		for (int i = 0; i <= 8; i++)
		{
			cartmanArmUpMadTalking[i].pasteImages(cartmanX, cartmanY);
			dbCenterText(dbScreenWidth() / 2, 460, "I am the great Cartman, respect my authoritah!");
			dbWait(80);
		}
	}
	cartmanArmUpMadTalking[11].pasteImages(cartmanX, cartmanY);
	dbCenterText(dbScreenWidth() / 2, 460, "I am the great Cartman, respect my authoritah!");
	dbWait(700);
	cartmanBody[0].pasteImages(cartmanX, cartmanY);
	dbWait(300);
	cartmanSounds[1].playSound(); // play cartman
	for (int times = 0; times <= 2; times++)// talking
	{
		for (int i = 0; i <= 8; i++)
		{
			cartmanTalking[i].pasteImages(cartmanX, cartmanY);
			dbCenterText(dbScreenWidth() / 2, 460, "Ask me a Yes or No question and I will tell you the answer.");
			dbWait(80);
		}
	}


	//// GAME LOOP <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
	while (LoopGDK() && playing)
	{
		rndNum = dbRND(19); // set variable for random number
		// Random blink
		if (blink == 200)
		{
			cartmanBody[1].pasteImages(cartmanX, cartmanY);
			dbCenterText(dbScreenWidth() / 2, 460, "Ask a Yes or No question? (press spacebar), to exit press (shiftkey)");
			dbWait(100);
			cartmanBody[0].pasteImages(cartmanX, cartmanY);
			blink = dbRND(100);
		}

		cartmanBody[0].pasteImages(cartmanX, cartmanY); // paste default cartman
		dbCenterText(dbScreenWidth() / 2, 460, "Ask a Yes or No question? (press spacebar), to exit press (shiftkey)");

		// User asks question and gets anwswer
		if (dbSpaceKey())
		{
			// Pre answer
			cartmanSounds[2].playSound();
			for (int i = 0; i <= 11; i++)
			{
				cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				dbCenterText(dbScreenWidth() / 2, 460, " Let's see what my powers say. ");
				dbWait(83);
			}

			cartmanBody[0].pasteImages(cartmanX, cartmanY);
			dbWait(500);
			drumRoll.playSound(); // play drum roll
			cartmanBody[5].pasteImages(cartmanX, cartmanY);
			dbWait(1700);
			cartmanBody[6].pasteImages(cartmanX, cartmanY);
			dbWait(1500);

			dbCLS();
			cartmanBody[0].pasteImages(cartmanX, cartmanY);
			AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question

			// Which images to paste randomly
			switch (rndNum)
			{
			case 0: // "Holy guacamole, it is possibly certain"
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);



					}
					cartmanBody[0].pasteImages(cartmanX, cartmanY);
					AllAnswers[rndNum].getAnswer();
					dbWait(100);
				}
				cartmanBody[4].pasteImages(cartmanX, cartmanY);// Happy face.
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 1: // " Well, it is decidedly so. "
				audioAnswers[rndNum].playSound();
				for (int i = 4; i <= 6; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(100);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(200);
				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(90);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}

				cartmanBody[4].pasteImages(cartmanX, cartmanY); // Happy face
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 2: // " The great Cartman says without a doubt. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 3: // " You're in luck, my awesome powers say most definitely. " 
				audioAnswers[rndNum].playSound();
				for (int i = 0; i <= 6; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(100);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(100);
				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(80);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);

				}
				for (int i = 0; i <= 9; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(80);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);

				}

				cartmanBody[4].pasteImages(cartmanX, cartmanY); // Happy face
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 4: // " You may rely on it but I surely wouldn't. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(82);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 5: // " As i see it and it would be wise to listen to the great Cartman,...yes "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 3; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(70);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(500);
				cartmanTalking[3].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(300);
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 6: // 	" Let's say probably "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 1; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(81);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 7: // " The powerful Cartman says your outlook is good.  "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(81);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[4].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 8: // " Yes, but please ask a more intelligent question next time. " 
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 3; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 9: // " All the signs point to yes and you're welcome. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 10: // " It's a little hazy, try again later when you bring me some KFC. "
				audioAnswers[rndNum].playSound();
				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(79);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(100);
				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(81);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 11: // " Ask again later I have better things to do then answer such questions. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 3; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(66);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}

				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 12: // " I've decided not to tell you now. Good day. "
				audioAnswers[rndNum].playSound();

				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(90);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(200);
				for (int i = 0; i <= 2; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(80);
					cartmanMadTalking[i].pasteImages(cartmanX, cartmanY);
				}
				AllAnswers[rndNum].getAnswer();
				dbWait(200);
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 13: // " Sorry I cannot predict that question ask a better one. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times <= 2; times++)
				{
					for (int i = 0; i <= 6; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(65);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(200);
				for (int i = 0; i <= 8; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(80);
					cartmanMadTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 14: // " Ok we both know the answer to that question so stop being sick! "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 3; times++)// how times to go through animation
				{
					for (int i = 0; i <= 10; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(75);
						cartmanMadTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 15: // " I personally wouldn't count on it. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 1; times++)// how times to go through animation
				{
					for (int i = 0; i <= 11; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(87);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 16: // " My reply is no. Get over it. "
				audioAnswers[rndNum].playSound();

				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(90);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				dbWait(5);
				for (int i = 0; i <= 4; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(80);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 17: // " My highly evolved powers tell me the answer is no. "
				audioAnswers[rndNum].playSound();
				for (int times = 0; times < 3; times++)// how times to go through animation
				{
					for (int i = 0; i <= 8; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);
						cartmanTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}

				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 18: // " Ha! You really think I would answer that question! "
				audioAnswers[rndNum].playSound();
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(80);
				cartmanMadTalking[6].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(300);
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(100);

				for (int times = 0; times < 2; times++)// how times to go through animation
				{
					for (int i = 0; i <= 9; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(80);
						cartmanMadTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}

				cartmanBody[2].pasteImages(cartmanX, cartmanY); // Happy face
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;
			case 19: // " I think you have stumped me on that one. Next question please. "
				audioAnswers[rndNum].playSound();
				for (int i = 0; i <= 11; i++) // goes through talking animation
				{
					AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
					dbWait(90);
					cartmanTalking[i].pasteImages(cartmanX, cartmanY);
				}
				cartmanBody[0].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(300);
				for (int times = 0; times < 1; times++)// how times to go through animation
				{
					for (int i = 0; i <= 8; i++) // goes through talking animation
					{
						AllAnswers[rndNum].getAnswer(); // displays cartmans answer to question
						dbWait(90);
						cartmanMadTalking[i].pasteImages(cartmanX, cartmanY);
					}

				}
				cartmanBody[2].pasteImages(cartmanX, cartmanY);
				AllAnswers[rndNum].getAnswer();
				dbWait(1000);
				break;

			}// END OF SWITCH

			dbCLS();
			cartmanBody[0].pasteImages(cartmanX, cartmanY);

			// Write answer to user question In/Output file.
			Q_AFile << " QUESTION # " << QNum << endl;
			Q_AFile << " ANSWER:\n " << AllAnswers[rndNum].returnAnswer() << endl;
			Q_AFile << endl;
			QNum++; // Increments question number asked.

		}

		blink++; // increment the blink counter
		playing = true; // keeps game going
		if (dbShiftKey()){ playing = false; } // Check if user still wants to play

		dbSync();
	}

	Q_AFile.close();// Close In/Output file.
	dbCLS();

	/////// OUTRO 
	cartmanSounds[3].playSound();  // play cartman
	for (int times = 0; times <= 2; times++)
	{
		for (int i = 0; i <= 8; i++)
		{
			cartmanTalking[i].pasteImages(cartmanX, cartmanY);
			dbCenterText(dbScreenWidth() / 2, 460, "No more questions, thank you and good night!");
			dbWait(75);
		}
	}
	handClapLong.playSound(); // play audience hand clap
	outro[0].pasteImages(cartmanX, cartmanY);
	dbWait(2000);
	outro[1].pasteImages(cartmanX, cartmanY);
	dbWait(1500);
	outro[2].pasteImages(cartmanX, cartmanY);
	dbWait(1000);
	outro[3].pasteImages(cartmanX, cartmanY);
	dbWait(1000);
	cartmanSounds[4].playSound(); // play cartman
	for (int i = 4; i <= 14; i++)
	{
		outro[i].pasteImages(cartmanX, cartmanY);
		dbCenterText(dbScreenWidth() / 2, 460, "Close the curtains Kenny!");
		dbWait(100);
	}
	outro[15].pasteImages(cartmanX, cartmanY);
	dbCenterText(dbScreenWidth() / 2, 460, "Close the curtains Kenny!");
	dbWait(1500);
	kenny[0].playSound(); // play kenny
	for (int i = 16; i <= 23; i++)
	{
		outro[i].pasteImages(cartmanX, cartmanY), dbWait(100);
	}
	dbWait(100);
	for (int i = 24; i <= 37; i++)
	{
		outro[i].pasteImages(cartmanX, cartmanY), dbWait(100);
	}
	dbWait(1000);
	kenny[1].playSound(); // play kenny
	dbSetTextFont("stencil");
	dbSetTextSize(80);
	dbCenterText(dbScreenWidth() / 2, dbScreenHeight() / 2 - 50, "GAME OVER");
	dbWait(4000);

} //<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ DarkGDK END


// Funtion

void programInfo()
{
	// Program descrpition/ credits

	int x = dbScreenWidth() / 2 - 15;
	if (loading > 90){ x -= 4; }
	dbCLS();
	dbSetTextFont("times new roman bold");
	dbSetTextSize(20);
	dbCenterText(dbScreenWidth() / 2, 100, "CIS 116, C++ Programming II, Craftonhills college, Project II");
	dbCenterText(dbScreenWidth() / 2, 125, "Written by: David Garcia, Spring 2013");
	dbCenterText(dbScreenWidth() / 2, 150, "This program is a game of asking a Yes or No question");
	dbCenterText(dbScreenWidth() / 2, 175, "and getting a ridiculous answer.");
	dbCenterText(dbScreenWidth() / 2, 200, "Enjoy :)");
	dbPasteImage(diskImage, 222, 250);
	dbSetTextSize(18);
	dbSetCursor(x, dbScreenHeight() / 2 + 90);
	dbPrint(loading);
	loading += 10;
	if (loading > 100){ dbSetTextSize(20); }
	dbWait(1);

}









//========================================================================================================
//
//	Arquivo: GeometryCorners.cpp
//
//	Descrição:	controi geometria dos cantos
//
//========================================================================================================

#include "GeometryCorners.h"

//========================================================================================================
//	COLOR PIECE
//========================================================================================================
void CCornerComponent::CornerColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.238086, 0.800234, -0.077359));
	pieceData.push_back(UT_Vector3(0.459684, 0.800234, 0.083641));
	pieceData.push_back(UT_Vector3(0.544327, 0.800234, -0.176862));
	pieceData.push_back(UT_Vector3(0.322729, 0.800234, -0.337862));
	pieceData.push_back(UT_Vector3(0.459684, 0.778454, 0.083641));
	pieceData.push_back(UT_Vector3(0.238086, 0.778454, -0.077359));
	pieceData.push_back(UT_Vector3(0.322729, 0.778454, -0.337862));
	pieceData.push_back(UT_Vector3(0.544327, 0.778454, -0.176862));
	pieceData.push_back(UT_Vector3(0.255814, 0.800234, -0.064479));
	pieceData.push_back(UT_Vector3(0.441956, 0.800234, 0.070761));
	pieceData.push_back(UT_Vector3(0.526599, 0.800234, -0.189742));
	pieceData.push_back(UT_Vector3(0.340457, 0.800234, -0.324982));
	pieceData.push_back(UT_Vector3(0.255814, 0.778454, -0.064479));
	pieceData.push_back(UT_Vector3(0.441956, 0.778454, 0.070761));
	pieceData.push_back(UT_Vector3(0.526599, 0.778454, -0.189742));
	pieceData.push_back(UT_Vector3(0.340457, 0.778454, -0.324982));
	pieceData.push_back(UT_Vector3(0.466455, 0.800234, 0.062801));
	pieceData.push_back(UT_Vector3(0.537556, 0.800234, -0.156022));
	pieceData.push_back(UT_Vector3(0.315958, 0.800234, -0.317022));
	pieceData.push_back(UT_Vector3(0.244858, 0.800234, -0.098199));
	pieceData.push_back(UT_Vector3(0.315958, 0.778454, -0.317022));
	pieceData.push_back(UT_Vector3(0.244858, 0.778454, -0.098199));
	pieceData.push_back(UT_Vector3(0.466455, 0.778454, 0.062801));
	pieceData.push_back(UT_Vector3(0.537556, 0.778454, -0.156022));
	pieceData.push_back(UT_Vector3(0.448727, 0.800234, 0.049921));
	pieceData.push_back(UT_Vector3(0.519828, 0.800234, -0.168902));
	pieceData.push_back(UT_Vector3(0.333686, 0.800234, -0.304142));
	pieceData.push_back(UT_Vector3(0.262586, 0.800234, -0.085319));
	
	int faces[84] = { 26, 27, 28, 25,
		9, 13, 14, 10,
		19, 21, 22, 20,
		11, 15, 16, 12,
		17, 23, 24, 18,
		18, 26, 25, 17,
		20, 28, 27, 19,
		1, 6, 13, 9,
		5, 2, 10, 14,
		3, 8, 15, 11,
		7, 4, 12, 16,
		11, 12, 27, 26,
		9, 10, 25, 28,
		4, 7, 21, 19,
		6, 1, 20, 22,
		2, 5, 23, 17,
		8, 3, 18, 24,
		3, 11, 26, 18,
		10, 2, 17, 25,
		1, 9, 28, 20,
		12, 4, 19, 27 };

	for (int i = 0; i < 84; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 1
//========================================================================================================
void CCornerComponent::Corner_Yellow_Blue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.354438, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(0.028355, 0.789344, 0.487841));
	pieceData.push_back(UT_Vector3(0.455203, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(0.129120, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(0.362499, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(0.447141, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(0.036416, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(0.121059, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(0.455203, 0.511962, 0.626534));
	pieceData.push_back(UT_Vector3(0.363200, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(0.129120, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(0.037117, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(0.463965, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(0.555968, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(0.229885, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(0.137882, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(0.463264, 0.511962, 0.601724));
	pieceData.push_back(UT_Vector3(0.371261, 0.765224, 0.475092));
	pieceData.push_back(UT_Vector3(0.455904, 0.765224, 0.214589));
	pieceData.push_back(UT_Vector3(0.547907, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(0.045178, 0.765224, 0.475092));
	pieceData.push_back(UT_Vector3(0.137181, 0.511962, 0.601723));
	pieceData.push_back(UT_Vector3(0.221824, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(0.129821, 0.765224, 0.214589));
	pieceData.push_back(UT_Vector3(0.220811, 0.536941, 0.303921));
	pieceData.push_back(UT_Vector3(0.212750, 0.536941, 0.328730));
	pieceData.push_back(UT_Vector3(0.128107, 0.536941, 0.589234));
	pieceData.push_back(UT_Vector3(0.120046, 0.536941, 0.614043));
	pieceData.push_back(UT_Vector3(0.446129, 0.536941, 0.614044));
	pieceData.push_back(UT_Vector3(0.454190, 0.536941, 0.589234));
	pieceData.push_back(UT_Vector3(0.538832, 0.536941, 0.328730));
	pieceData.push_back(UT_Vector3(0.546894, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(0.054442, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(0.328351, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(0.155207, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(0.429116, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(0.336412, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(0.062503, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(0.147146, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(0.421055, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(0.063204, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(0.337113, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(0.429116, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(0.155207, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(0.255972, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(0.529881, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(0.437878, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(0.163969, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(0.146133, 0.536941, 0.614043));
	pieceData.push_back(UT_Vector3(0.420042, 0.536941, 0.614044));
	pieceData.push_back(UT_Vector3(0.246898, 0.536941, 0.303921));
	pieceData.push_back(UT_Vector3(0.520807, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(0.163268, 0.511962, 0.601723));
	pieceData.push_back(UT_Vector3(0.437178, 0.511962, 0.601724));
	pieceData.push_back(UT_Vector3(0.521820, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(0.247911, 0.511962, 0.341220));
	
	int faces[216] = {	30, 31, 20, 17,
						50, 43, 44, 49,
						39, 40, 37, 38,
						21, 27, 26, 24,
						51, 52, 47, 48,
						29, 30, 17, 9,
						32, 31, 19, 13,
						35, 36, 40, 39,
						34, 33, 38, 37,
						12, 28, 27, 21,
						15, 25, 26, 23,
						5, 6, 19, 18,
						34, 42, 41, 33,
						24, 8, 7, 21,
						36, 35, 48, 47,
						1, 5, 18, 10,
						6, 3, 13, 19,
						21, 7, 2, 12,
						16, 4, 8, 24,
						18, 19, 31, 30,
						42, 50, 49, 41,
						27, 22, 23, 26,
						45, 46, 52, 51,
						10, 18, 30, 29,
						14, 20, 31, 32,
						28, 11, 22, 27,
						25, 16, 24, 26,
						56, 53, 54, 55,
						43, 54, 53, 44,
						45, 56, 55, 46,
						29, 9, 43, 50,
						11, 28, 49, 44,
						40, 6, 5, 37,
						38, 7, 8, 39,
						52, 32, 13, 47,
						48, 16, 25, 51,
						36, 3, 6, 40,
						39, 8, 4, 35,
						33, 2, 7, 38,
						37, 5, 1, 34,
						1, 10, 42, 34,
						12, 2, 33, 41,
						35, 4, 16, 48,
						47, 13, 3, 36,
						10, 29, 50, 42,
						28, 12, 41, 49,
						46, 14, 32, 52,
						51, 25, 15, 45,
						23, 22, 53, 56,
						17, 20, 55, 54,
						9, 17, 54, 43,
						22, 11, 44, 53,
						15, 23, 56, 45,
						20, 14, 46, 55 };
	
	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 2
//========================================================================================================
void CCornerComponent::Corner_Yellow_Blue_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();
 	pieceData.push_back(UT_Vector3(-0.354438, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(-0.455203, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(-0.028355, 0.789344, 0.487841));
	pieceData.push_back(UT_Vector3(-0.129120, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(-0.328351, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(-0.054442, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(-0.429116, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(-0.155207, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(-0.455203, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(-0.363200, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(-0.555968, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.463965, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(-0.037117, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(-0.129120, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(-0.229885, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.137882, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(-0.429117, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(-0.337114, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(-0.063204, 0.765224, 0.499902));
	pieceData.push_back(UT_Vector3(-0.155207, 0.511962, 0.626533));
	pieceData.push_back(UT_Vector3(-0.437878, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(-0.529881, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.255972, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.163969, 0.765224, 0.189779));
	pieceData.push_back(UT_Vector3(-0.220811, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(-0.246898, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(-0.520807, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(-0.546894, 0.536941, 0.303920));
	pieceData.push_back(UT_Vector3(-0.446129, 0.536941, 0.614044));
	pieceData.push_back(UT_Vector3(-0.420042, 0.536941, 0.614044));
	pieceData.push_back(UT_Vector3(-0.146133, 0.536941, 0.614043));
	pieceData.push_back(UT_Vector3(-0.120046, 0.536941, 0.614043));
	pieceData.push_back(UT_Vector3(-0.447141, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(-0.362499, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(-0.121059, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(-0.036416, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(-0.336413, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(-0.421055, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(-0.147146, 0.789344, 0.202528));
	pieceData.push_back(UT_Vector3(-0.062503, 0.789344, 0.463032));
	pieceData.push_back(UT_Vector3(-0.455904, 0.765224, 0.214589));
	pieceData.push_back(UT_Vector3(-0.371261, 0.765224, 0.475092));
	pieceData.push_back(UT_Vector3(-0.463264, 0.511962, 0.601724));
	pieceData.push_back(UT_Vector3(-0.547907, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(-0.221824, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(-0.137181, 0.511962, 0.601723));
	pieceData.push_back(UT_Vector3(-0.045178, 0.765224, 0.475092));
	pieceData.push_back(UT_Vector3(-0.129821, 0.765224, 0.214589));
	pieceData.push_back(UT_Vector3(-0.538832, 0.536941, 0.328730));
	pieceData.push_back(UT_Vector3(-0.454190, 0.536941, 0.589234));
	pieceData.push_back(UT_Vector3(-0.212750, 0.536941, 0.328730));
	pieceData.push_back(UT_Vector3(-0.128107, 0.536941, 0.589233));
	pieceData.push_back(UT_Vector3(-0.521820, 0.511962, 0.341220));
	pieceData.push_back(UT_Vector3(-0.437178, 0.511962, 0.601723));
	pieceData.push_back(UT_Vector3(-0.163268, 0.511962, 0.601723));
	pieceData.push_back(UT_Vector3(-0.247911, 0.511962, 0.341220));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 3
//========================================================================================================
void CCornerComponent::Corner_Yellow_Purple_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.57349, 0.78934, -0.186339));
	pieceData.push_back(UT_Vector3(-0.30968, 0.78934, -0.378005));
	pieceData.push_back(UT_Vector3(-0.47272, 0.78934, 0.123784));
	pieceData.push_back(UT_Vector3(-0.20892, 0.78934, -0.067882));
	pieceData.push_back(UT_Vector3(-0.56543, 0.78934, -0.161529));
	pieceData.push_back(UT_Vector3(-0.48078, 0.78934, 0.098974));
	pieceData.push_back(UT_Vector3(-0.30162, 0.78934, -0.353196));
	pieceData.push_back(UT_Vector3(-0.21698, 0.78934, -0.092692));
	pieceData.push_back(UT_Vector3(-0.73653, 0.51196, -0.239315));
	pieceData.push_back(UT_Vector3(-0.58767, 0.76522, -0.190946));
	pieceData.push_back(UT_Vector3(-0.47272, 0.51196, -0.430981));
	pieceData.push_back(UT_Vector3(-0.32386, 0.76522, -0.382612));
	pieceData.push_back(UT_Vector3(-0.48690, 0.76522, 0.119178));
	pieceData.push_back(UT_Vector3(-0.63576, 0.51196, 0.070809));
	pieceData.push_back(UT_Vector3(-0.37196, 0.51196, -0.120858));
	pieceData.push_back(UT_Vector3(-0.22309, 0.76522, -0.072489));
	pieceData.push_back(UT_Vector3(-0.72847, 0.51196, -0.214505));
	pieceData.push_back(UT_Vector3(-0.57960, 0.76522, -0.166136));
	pieceData.push_back(UT_Vector3(-0.49496, 0.76522, 0.094368));
	pieceData.push_back(UT_Vector3(-0.64383, 0.51196, 0.045999));
	pieceData.push_back(UT_Vector3(-0.31580, 0.76522, -0.357802));
	pieceData.push_back(UT_Vector3(-0.46466, 0.51196, -0.406171));
	pieceData.push_back(UT_Vector3(-0.38002, 0.51196, -0.145668));
	pieceData.push_back(UT_Vector3(-0.23115, 0.76522, -0.097299));
	pieceData.push_back(UT_Vector3(-0.35728, 0.53694, -0.116087));
	pieceData.push_back(UT_Vector3(-0.36534, 0.53694, -0.140897));
	pieceData.push_back(UT_Vector3(-0.44998, 0.53694, -0.401400));
	pieceData.push_back(UT_Vector3(-0.45804, 0.53694, -0.426210));
	pieceData.push_back(UT_Vector3(-0.72185, 0.53694, -0.234544));
	pieceData.push_back(UT_Vector3(-0.71379, 0.53694, -0.209734));
	pieceData.push_back(UT_Vector3(-0.62914, 0.53694, 0.050769));
	pieceData.push_back(UT_Vector3(-0.62108, 0.53694, 0.075579));
	pieceData.push_back(UT_Vector3(-0.33079, 0.78934, -0.362672));
	pieceData.push_back(UT_Vector3(-0.55238, 0.78934, -0.201672));
	pieceData.push_back(UT_Vector3(-0.23002, 0.78934, -0.052549));
	pieceData.push_back(UT_Vector3(-0.45162, 0.78934, 0.108451));
	pieceData.push_back(UT_Vector3(-0.54432, 0.78934, -0.176863));
	pieceData.push_back(UT_Vector3(-0.32272, 0.78934, -0.337862));
	pieceData.push_back(UT_Vector3(-0.23808, 0.78934, -0.077359));
	pieceData.push_back(UT_Vector3(-0.45968, 0.78934, 0.083641));
	pieceData.push_back(UT_Vector3(-0.34496, 0.76522, -0.367279));
	pieceData.push_back(UT_Vector3(-0.56656, 0.76522, -0.206279));
	pieceData.push_back(UT_Vector3(-0.71543, 0.51196, -0.254648));
	pieceData.push_back(UT_Vector3(-0.49383, 0.51196, -0.415647));
	pieceData.push_back(UT_Vector3(-0.39306, 0.51196, -0.105525));
	pieceData.push_back(UT_Vector3(-0.61466, 0.51196, 0.055475));
	pieceData.push_back(UT_Vector3(-0.46580, 0.76522, 0.103844));
	pieceData.push_back(UT_Vector3(-0.24420, 0.76522, -0.057156));
	pieceData.push_back(UT_Vector3(-0.47914, 0.53694, -0.410877));
	pieceData.push_back(UT_Vector3(-0.70074, 0.53694, -0.249877));
	pieceData.push_back(UT_Vector3(-0.37838, 0.53694, -0.100754));
	pieceData.push_back(UT_Vector3(-0.59998, 0.53694, 0.060246));
	pieceData.push_back(UT_Vector3(-0.48577, 0.51196, -0.390838));
	pieceData.push_back(UT_Vector3(-0.70736, 0.51196, -0.229838));
	pieceData.push_back(UT_Vector3(-0.62272, 0.51196, 0.030666));
	pieceData.push_back(UT_Vector3(-0.40112, 0.51196, -0.130334));

	int faces[216] = {	30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55};

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 4
//========================================================================================================
void CCornerComponent::Corner_Yellow_Purple_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.000000, 0.789344, -0.603006));
	pieceData.push_back(UT_Vector3(0.263806, 0.789344, -0.411339));
	pieceData.push_back(UT_Vector3(-0.263806, 0.789344, -0.411339));
	pieceData.push_back(UT_Vector3(0.000000, 0.789344, -0.219672));
	pieceData.push_back(UT_Vector3(-0.021104, 0.789344, -0.587673));
	pieceData.push_back(UT_Vector3(-0.242702, 0.789344, -0.426672));
	pieceData.push_back(UT_Vector3(0.242702, 0.789344, -0.396005));
	pieceData.push_back(UT_Vector3(0.021105, 0.789344, -0.235006));
	pieceData.push_back(UT_Vector3(0.000000, 0.511962, -0.774438));
	pieceData.push_back(UT_Vector3(0.000000, 0.765224, -0.617913));
	pieceData.push_back(UT_Vector3(0.263806, 0.511962, -0.582771));
	pieceData.push_back(UT_Vector3(0.263806, 0.765224, -0.426246));
	pieceData.push_back(UT_Vector3(-0.263806, 0.765224, -0.426246));
	pieceData.push_back(UT_Vector3(-0.263806, 0.511962, -0.582771));
	pieceData.push_back(UT_Vector3(0.000000, 0.511962, -0.391104));
	pieceData.push_back(UT_Vector3(0.000000, 0.765224, -0.234579));
	pieceData.push_back(UT_Vector3(-0.021104, 0.511962, -0.759104));
	pieceData.push_back(UT_Vector3(-0.021104, 0.765224, -0.602580));
	pieceData.push_back(UT_Vector3(-0.242702, 0.765224, -0.441579));
	pieceData.push_back(UT_Vector3(-0.242702, 0.511962, -0.598104));
	pieceData.push_back(UT_Vector3(0.242702, 0.765224, -0.410913));
	pieceData.push_back(UT_Vector3(0.242702, 0.511962, -0.567437));
	pieceData.push_back(UT_Vector3(0.021105, 0.511962, -0.406438));
	pieceData.push_back(UT_Vector3(0.021104, 0.765224, -0.249913));
	pieceData.push_back(UT_Vector3(0.000000, 0.536941, -0.375666));
	pieceData.push_back(UT_Vector3(0.021105, 0.536941, -0.391000));
	pieceData.push_back(UT_Vector3(0.242702, 0.536941, -0.552000));
	pieceData.push_back(UT_Vector3(0.263806, 0.536941, -0.567333));
	pieceData.push_back(UT_Vector3(0.000000, 0.536941, -0.759000));
	pieceData.push_back(UT_Vector3(-0.021104, 0.536941, -0.743667));
	pieceData.push_back(UT_Vector3(-0.242702, 0.536941, -0.582666));
	pieceData.push_back(UT_Vector3(-0.263806, 0.536941, -0.567333));
	pieceData.push_back(UT_Vector3(0.242702, 0.789344, -0.426672));
	pieceData.push_back(UT_Vector3(0.021105, 0.789344, -0.587673));
	pieceData.push_back(UT_Vector3(-0.021104, 0.789344, -0.235006));
	pieceData.push_back(UT_Vector3(-0.242702, 0.789344, -0.396005));
	pieceData.push_back(UT_Vector3(0.000000, 0.789344, -0.572339));
	pieceData.push_back(UT_Vector3(0.221597, 0.789344, -0.411339));
	pieceData.push_back(UT_Vector3(-0.000000, 0.789344, -0.250339));
	pieceData.push_back(UT_Vector3(-0.221597, 0.789344, -0.411339));
	pieceData.push_back(UT_Vector3(0.242702, 0.765224, -0.441579));
	pieceData.push_back(UT_Vector3(0.021105, 0.765224, -0.602580));
	pieceData.push_back(UT_Vector3(0.021105, 0.511962, -0.759104));
	pieceData.push_back(UT_Vector3(0.242702, 0.511962, -0.598104));
	pieceData.push_back(UT_Vector3(-0.021104, 0.511962, -0.406438));
	pieceData.push_back(UT_Vector3(-0.242702, 0.511962, -0.567437));
	pieceData.push_back(UT_Vector3(-0.242702, 0.765224, -0.410913));
	pieceData.push_back(UT_Vector3(-0.021104, 0.765224, -0.249913));
	pieceData.push_back(UT_Vector3(0.242702, 0.536941, -0.582666));
	pieceData.push_back(UT_Vector3(0.021105, 0.536941, -0.743667));
	pieceData.push_back(UT_Vector3(-0.021104, 0.536941, -0.391000));
	pieceData.push_back(UT_Vector3(-0.242702, 0.536941, -0.551999));
	pieceData.push_back(UT_Vector3(0.221597, 0.511962, -0.582771));
	pieceData.push_back(UT_Vector3(0.000000, 0.511962, -0.743771));
	pieceData.push_back(UT_Vector3(-0.221597, 0.511962, -0.582771));
	pieceData.push_back(UT_Vector3(0.000000, 0.511962, -0.421771));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55};

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 5
//========================================================================================================
void CCornerComponent::Corner_Yellow_Green_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.573493, 0.789344, -0.186339));
	pieceData.push_back(UT_Vector3(0.472727, 0.789344, 0.123784));
	pieceData.push_back(UT_Vector3(0.309686, 0.789344, -0.378005));
	pieceData.push_back(UT_Vector3(0.208921, 0.789344, -0.067882));
	pieceData.push_back(UT_Vector3(0.552388, 0.789344, -0.201672));
	pieceData.push_back(UT_Vector3(0.330790, 0.789344, -0.362672));
	pieceData.push_back(UT_Vector3(0.451622, 0.789344, 0.108451));
	pieceData.push_back(UT_Vector3(0.230025, 0.789344, -0.052549));
	pieceData.push_back(UT_Vector3(0.736534, 0.511962, -0.239314));
	pieceData.push_back(UT_Vector3(0.587670, 0.765224, -0.190946));
	pieceData.push_back(UT_Vector3(0.635768, 0.511962, 0.070809));
	pieceData.push_back(UT_Vector3(0.486905, 0.765224, 0.119178));
	pieceData.push_back(UT_Vector3(0.323863, 0.765224, -0.382612));
	pieceData.push_back(UT_Vector3(0.472727, 0.511962, -0.430981));
	pieceData.push_back(UT_Vector3(0.371962, 0.511962, -0.120858));
	pieceData.push_back(UT_Vector3(0.223098, 0.765224, -0.072489));
	pieceData.push_back(UT_Vector3(0.715430, 0.511962, -0.254648));
	pieceData.push_back(UT_Vector3(0.566566, 0.765224, -0.206279));
	pieceData.push_back(UT_Vector3(0.344968, 0.765224, -0.367279));
	pieceData.push_back(UT_Vector3(0.493832, 0.511962, -0.415647));
	pieceData.push_back(UT_Vector3(0.465800, 0.765224, 0.103844));
	pieceData.push_back(UT_Vector3(0.614664, 0.511962, 0.055475));
	pieceData.push_back(UT_Vector3(0.393067, 0.511962, -0.105524));
	pieceData.push_back(UT_Vector3(0.244203, 0.765224, -0.057156));
	pieceData.push_back(UT_Vector3(0.357280, 0.536941, -0.116087));
	pieceData.push_back(UT_Vector3(0.378385, 0.536941, -0.100754));
	pieceData.push_back(UT_Vector3(0.599982, 0.536941, 0.060246));
	pieceData.push_back(UT_Vector3(0.621086, 0.536941, 0.075579));
	pieceData.push_back(UT_Vector3(0.721852, 0.536941, -0.234544));
	pieceData.push_back(UT_Vector3(0.700747, 0.536941, -0.249877));
	pieceData.push_back(UT_Vector3(0.479150, 0.536941, -0.410877));
	pieceData.push_back(UT_Vector3(0.458045, 0.536941, -0.426210));
	pieceData.push_back(UT_Vector3(0.480788, 0.789344, 0.098974));
	pieceData.push_back(UT_Vector3(0.565432, 0.789344, -0.161529));
	pieceData.push_back(UT_Vector3(0.216982, 0.789344, -0.092692));
	pieceData.push_back(UT_Vector3(0.301625, 0.789344, -0.353196));
	pieceData.push_back(UT_Vector3(0.544327, 0.789344, -0.176862));
	pieceData.push_back(UT_Vector3(0.459684, 0.789344, 0.083641));
	pieceData.push_back(UT_Vector3(0.238086, 0.789344, -0.077359));
	pieceData.push_back(UT_Vector3(0.322729, 0.789344, -0.337862));
	pieceData.push_back(UT_Vector3(0.494966, 0.765224, 0.094368));
	pieceData.push_back(UT_Vector3(0.579609, 0.765224, -0.166136));
	pieceData.push_back(UT_Vector3(0.728473, 0.511962, -0.214505));
	pieceData.push_back(UT_Vector3(0.643830, 0.511962, 0.045999));
	pieceData.push_back(UT_Vector3(0.380023, 0.511962, -0.145668));
	pieceData.push_back(UT_Vector3(0.464666, 0.511962, -0.406171));
	pieceData.push_back(UT_Vector3(0.315802, 0.765224, -0.357802));
	pieceData.push_back(UT_Vector3(0.231159, 0.765224, -0.097299));
	pieceData.push_back(UT_Vector3(0.629147, 0.536941, 0.050769));
	pieceData.push_back(UT_Vector3(0.713791, 0.536941, -0.209734));
	pieceData.push_back(UT_Vector3(0.365341, 0.536941, -0.140897));
	pieceData.push_back(UT_Vector3(0.449984, 0.536941, -0.401400));
	pieceData.push_back(UT_Vector3(0.622725, 0.511962, 0.030666));
	pieceData.push_back(UT_Vector3(0.707368, 0.511962, -0.229838));
	pieceData.push_back(UT_Vector3(0.485771, 0.511962, -0.390838));
	pieceData.push_back(UT_Vector3(0.401128, 0.511962, -0.130334));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };


	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 6
//========================================================================================================
void CCornerComponent::Corner_LightGreen_DarkGreen_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.573493, -0.789344, 0.186339));
	pieceData.push_back(UT_Vector3(0.472727, -0.789344, -0.123784));
	pieceData.push_back(UT_Vector3(0.309686, -0.789344, 0.378005));
	pieceData.push_back(UT_Vector3(0.208921, -0.789344, 0.067882));
	pieceData.push_back(UT_Vector3(0.552388, -0.789344, 0.201672));
	pieceData.push_back(UT_Vector3(0.330790, -0.789344, 0.362672));
	pieceData.push_back(UT_Vector3(0.451622, -0.789344, -0.108451));
	pieceData.push_back(UT_Vector3(0.230025, -0.789344, 0.052549));
	pieceData.push_back(UT_Vector3(0.736534, -0.511962, 0.239314));
	pieceData.push_back(UT_Vector3(0.587670, -0.765224, 0.190946));
	pieceData.push_back(UT_Vector3(0.635768, -0.511962, -0.070809));
	pieceData.push_back(UT_Vector3(0.486904, -0.765224, -0.119178));
	pieceData.push_back(UT_Vector3(0.323863, -0.765224, 0.382612));
	pieceData.push_back(UT_Vector3(0.472727, -0.511962, 0.430981));
	pieceData.push_back(UT_Vector3(0.371962, -0.511962, 0.120858));
	pieceData.push_back(UT_Vector3(0.223098, -0.765224, 0.072489));
	pieceData.push_back(UT_Vector3(0.715430, -0.511962, 0.254648));
	pieceData.push_back(UT_Vector3(0.566566, -0.765224, 0.206279));
	pieceData.push_back(UT_Vector3(0.344968, -0.765224, 0.367279));
	pieceData.push_back(UT_Vector3(0.493832, -0.511962, 0.415647));
	pieceData.push_back(UT_Vector3(0.465800, -0.765224, -0.103844));
	pieceData.push_back(UT_Vector3(0.614664, -0.511962, -0.055476));
	pieceData.push_back(UT_Vector3(0.393067, -0.511962, 0.105524));
	pieceData.push_back(UT_Vector3(0.244203, -0.765224, 0.057156));
	pieceData.push_back(UT_Vector3(0.357280, -0.536941, 0.116087));
	pieceData.push_back(UT_Vector3(0.378384, -0.536941, 0.100754));
	pieceData.push_back(UT_Vector3(0.599982, -0.536941, -0.060246));
	pieceData.push_back(UT_Vector3(0.621086, -0.536941, -0.075579));
	pieceData.push_back(UT_Vector3(0.721852, -0.536941, 0.234544));
	pieceData.push_back(UT_Vector3(0.700747, -0.536941, 0.249877));
	pieceData.push_back(UT_Vector3(0.479150, -0.536941, 0.410877));
	pieceData.push_back(UT_Vector3(0.458045, -0.536941, 0.426210));
	pieceData.push_back(UT_Vector3(0.480788, -0.789344, -0.098974));
	pieceData.push_back(UT_Vector3(0.565431, -0.789344, 0.161529));
	pieceData.push_back(UT_Vector3(0.216982, -0.789344, 0.092692));
	pieceData.push_back(UT_Vector3(0.301625, -0.789344, 0.353196));
	pieceData.push_back(UT_Vector3(0.544327, -0.789344, 0.176862));
	pieceData.push_back(UT_Vector3(0.459684, -0.789344, -0.083641));
	pieceData.push_back(UT_Vector3(0.238086, -0.789344, 0.077359));
	pieceData.push_back(UT_Vector3(0.322729, -0.789344, 0.337862));
	pieceData.push_back(UT_Vector3(0.494966, -0.765224, -0.094368));
	pieceData.push_back(UT_Vector3(0.579609, -0.765224, 0.166136));
	pieceData.push_back(UT_Vector3(0.728473, -0.511962, 0.214504));
	pieceData.push_back(UT_Vector3(0.643830, -0.511962, -0.045999));
	pieceData.push_back(UT_Vector3(0.380023, -0.511962, 0.145668));
	pieceData.push_back(UT_Vector3(0.464666, -0.511962, 0.406171));
	pieceData.push_back(UT_Vector3(0.315802, -0.765224, 0.357802));
	pieceData.push_back(UT_Vector3(0.231159, -0.765224, 0.097299));
	pieceData.push_back(UT_Vector3(0.629147, -0.536941, -0.050770));
	pieceData.push_back(UT_Vector3(0.713791, -0.536941, 0.209734));
	pieceData.push_back(UT_Vector3(0.365341, -0.536941, 0.140897));
	pieceData.push_back(UT_Vector3(0.449984, -0.536941, 0.401400));
	pieceData.push_back(UT_Vector3(0.622725, -0.511962, -0.030666));
	pieceData.push_back(UT_Vector3(0.707368, -0.511962, 0.229838));
	pieceData.push_back(UT_Vector3(0.485771, -0.511962, 0.390838));
	pieceData.push_back(UT_Vector3(0.401128, -0.511962, 0.130334));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 7
//========================================================================================================
void CCornerComponent::Corner_LightGreen_Red_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.354438, -0.789344, -0.487842));
	pieceData.push_back(UT_Vector3(0.028355, -0.789344, -0.487841));
	pieceData.push_back(UT_Vector3(0.455203, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(0.129120, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(0.362499, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.447141, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(0.036416, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.121059, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(0.455203, -0.511962, -0.626534));
	pieceData.push_back(UT_Vector3(0.363200, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(0.129120, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.037117, -0.765224, -0.499901));
	pieceData.push_back(UT_Vector3(0.463965, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.555968, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.229885, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.137882, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.463264, -0.511962, -0.601724));
	pieceData.push_back(UT_Vector3(0.371261, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(0.455904, -0.765224, -0.214589));
	pieceData.push_back(UT_Vector3(0.547907, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(0.045178, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(0.137181, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(0.221824, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(0.129821, -0.765224, -0.214588));
	pieceData.push_back(UT_Vector3(0.220811, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(0.212750, -0.536941, -0.328730));
	pieceData.push_back(UT_Vector3(0.128107, -0.536941, -0.589234));
	pieceData.push_back(UT_Vector3(0.120046, -0.536941, -0.614043));
	pieceData.push_back(UT_Vector3(0.446129, -0.536941, -0.614044));
	pieceData.push_back(UT_Vector3(0.454190, -0.536941, -0.589234));
	pieceData.push_back(UT_Vector3(0.538832, -0.536941, -0.328730));
	pieceData.push_back(UT_Vector3(0.546894, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(0.054442, -0.789344, -0.487841));
	pieceData.push_back(UT_Vector3(0.328351, -0.789344, -0.487842));
	pieceData.push_back(UT_Vector3(0.155207, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(0.429116, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(0.336412, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.062503, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.147145, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(0.421055, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(0.063204, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(0.337113, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(0.429116, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.155207, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.255972, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.529881, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.437878, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.163969, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.146132, -0.536941, -0.614043));
	pieceData.push_back(UT_Vector3(0.420042, -0.536941, -0.614044));
	pieceData.push_back(UT_Vector3(0.246898, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(0.520807, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(0.163268, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(0.437177, -0.511962, -0.601724));
	pieceData.push_back(UT_Vector3(0.521820, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(0.247911, -0.511962, -0.341220));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 8
//========================================================================================================
void CCornerComponent::Corner_LightGreen_Pink_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.354438, -0.789344, -0.487842));
	pieceData.push_back(UT_Vector3(-0.455203, -0.789344, -0.177718));
	pieceData.push_back(UT_Vector3(-0.028355, -0.789344, -0.487841));
	pieceData.push_back(UT_Vector3(-0.129120, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(-0.328351, -0.789344, -0.487842));
	pieceData.push_back(UT_Vector3(-0.054442, -0.789344, -0.487841));
	pieceData.push_back(UT_Vector3(-0.429116, -0.789344, -0.177718));
	pieceData.push_back(UT_Vector3(-0.155207, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(-0.455203, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(-0.363200, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(-0.555968, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(-0.463965, -0.765224, -0.189778));
	pieceData.push_back(UT_Vector3(-0.037117, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(-0.129120, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(-0.229885, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(-0.137882, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(-0.429117, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(-0.337114, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(-0.063204, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(-0.155207, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(-0.437878, -0.765224, -0.189778));
	pieceData.push_back(UT_Vector3(-0.529881, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(-0.255972, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(-0.163969, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(-0.220811, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(-0.246898, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(-0.520807, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(-0.546894, -0.536941, -0.303920));
	pieceData.push_back(UT_Vector3(-0.446129, -0.536941, -0.614044));
	pieceData.push_back(UT_Vector3(-0.420043, -0.536941, -0.614044));
	pieceData.push_back(UT_Vector3(-0.146133, -0.536941, -0.614043));
	pieceData.push_back(UT_Vector3(-0.120046, -0.536941, -0.614043));
	pieceData.push_back(UT_Vector3(-0.447141, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(-0.362499, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(-0.121059, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(-0.036416, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(-0.336413, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(-0.421055, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(-0.147145, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(-0.062503, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(-0.455904, -0.765224, -0.214588));
	pieceData.push_back(UT_Vector3(-0.371261, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(-0.463265, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.547907, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.221824, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.137181, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.045178, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(-0.129821, -0.765224, -0.214588));
	pieceData.push_back(UT_Vector3(-0.538832, -0.536941, -0.328730));
	pieceData.push_back(UT_Vector3(-0.454190, -0.536941, -0.589234));
	pieceData.push_back(UT_Vector3(-0.212750, -0.536941, -0.328730));
	pieceData.push_back(UT_Vector3(-0.128107, -0.536941, -0.589233));
	pieceData.push_back(UT_Vector3(-0.521820, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.437178, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.163268, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.247911, -0.511962, -0.341220));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 9
//========================================================================================================
void CCornerComponent::Corner_LightGreen_Gray_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.573493, -0.789344, 0.186339));
	pieceData.push_back(UT_Vector3(-0.309686, -0.789344, 0.378005));
	pieceData.push_back(UT_Vector3(-0.472727, -0.789344, -0.123784));
	pieceData.push_back(UT_Vector3(-0.208921, -0.789344, 0.067882));
	pieceData.push_back(UT_Vector3(-0.565431, -0.789344, 0.161529));
	pieceData.push_back(UT_Vector3(-0.480788, -0.789344, -0.098974));
	pieceData.push_back(UT_Vector3(-0.301624, -0.789344, 0.353195));
	pieceData.push_back(UT_Vector3(-0.216982, -0.789344, 0.092692));
	pieceData.push_back(UT_Vector3(-0.736534, -0.511962, 0.239314));
	pieceData.push_back(UT_Vector3(-0.587670, -0.765224, 0.190946));
	pieceData.push_back(UT_Vector3(-0.472727, -0.511962, 0.430981));
	pieceData.push_back(UT_Vector3(-0.323863, -0.765224, 0.382612));
	pieceData.push_back(UT_Vector3(-0.486904, -0.765224, -0.119178));
	pieceData.push_back(UT_Vector3(-0.635768, -0.511962, -0.070809));
	pieceData.push_back(UT_Vector3(-0.371962, -0.511962, 0.120858));
	pieceData.push_back(UT_Vector3(-0.223098, -0.765224, 0.072489));
	pieceData.push_back(UT_Vector3(-0.728473, -0.511962, 0.214505));
	pieceData.push_back(UT_Vector3(-0.579609, -0.765224, 0.166136));
	pieceData.push_back(UT_Vector3(-0.494966, -0.765224, -0.094368));
	pieceData.push_back(UT_Vector3(-0.643830, -0.511962, -0.045999));
	pieceData.push_back(UT_Vector3(-0.315802, -0.765224, 0.357802));
	pieceData.push_back(UT_Vector3(-0.464666, -0.511962, 0.406171));
	pieceData.push_back(UT_Vector3(-0.380023, -0.511962, 0.145668));
	pieceData.push_back(UT_Vector3(-0.231159, -0.765224, 0.097299));
	pieceData.push_back(UT_Vector3(-0.357280, -0.536941, 0.116087));
	pieceData.push_back(UT_Vector3(-0.365341, -0.536941, 0.140897));
	pieceData.push_back(UT_Vector3(-0.449984, -0.536941, 0.401400));
	pieceData.push_back(UT_Vector3(-0.458045, -0.536941, 0.426210));
	pieceData.push_back(UT_Vector3(-0.721852, -0.536941, 0.234544));
	pieceData.push_back(UT_Vector3(-0.713791, -0.536941, 0.209734));
	pieceData.push_back(UT_Vector3(-0.629147, -0.536941, -0.050770));
	pieceData.push_back(UT_Vector3(-0.621086, -0.536941, -0.075579));
	pieceData.push_back(UT_Vector3(-0.330790, -0.789344, 0.362672));
	pieceData.push_back(UT_Vector3(-0.552388, -0.789344, 0.201672));
	pieceData.push_back(UT_Vector3(-0.230025, -0.789344, 0.052549));
	pieceData.push_back(UT_Vector3(-0.451622, -0.789344, -0.108451));
	pieceData.push_back(UT_Vector3(-0.544327, -0.789344, 0.176862));
	pieceData.push_back(UT_Vector3(-0.322729, -0.789344, 0.337862));
	pieceData.push_back(UT_Vector3(-0.238086, -0.789344, 0.077359));
	pieceData.push_back(UT_Vector3(-0.459684, -0.789344, -0.083641));
	pieceData.push_back(UT_Vector3(-0.344968, -0.765224, 0.367279));
	pieceData.push_back(UT_Vector3(-0.566566, -0.765224, 0.206279));
	pieceData.push_back(UT_Vector3(-0.715430, -0.511962, 0.254648));
	pieceData.push_back(UT_Vector3(-0.493832, -0.511962, 0.415647));
	pieceData.push_back(UT_Vector3(-0.393067, -0.511962, 0.105524));
	pieceData.push_back(UT_Vector3(-0.614664, -0.511962, -0.055476));
	pieceData.push_back(UT_Vector3(-0.465800, -0.765224, -0.103844));
	pieceData.push_back(UT_Vector3(-0.244203, -0.765224, 0.057156));
	pieceData.push_back(UT_Vector3(-0.479149, -0.536941, 0.410877));
	pieceData.push_back(UT_Vector3(-0.700747, -0.536941, 0.249877));
	pieceData.push_back(UT_Vector3(-0.378384, -0.536941, 0.100754));
	pieceData.push_back(UT_Vector3(-0.599982, -0.536941, -0.060246));
	pieceData.push_back(UT_Vector3(-0.485770, -0.511962, 0.390838));
	pieceData.push_back(UT_Vector3(-0.707368, -0.511962, 0.229838));
	pieceData.push_back(UT_Vector3(-0.622725, -0.511962, -0.030666));
	pieceData.push_back(UT_Vector3(-0.401128, -0.511962, 0.130334));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 10
//========================================================================================================
void CCornerComponent::Corner_LightGreen_LightBlue_DarkGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.000000, -0.789344, 0.603006));
	pieceData.push_back(UT_Vector3(0.263806, -0.789344, 0.411339));
	pieceData.push_back(UT_Vector3(-0.263806, -0.789344, 0.411339));
	pieceData.push_back(UT_Vector3(0.000000, -0.789344, 0.219672));
	pieceData.push_back(UT_Vector3(-0.021104, -0.789344, 0.587672));
	pieceData.push_back(UT_Vector3(-0.242702, -0.789344, 0.426672));
	pieceData.push_back(UT_Vector3(0.242702, -0.789344, 0.396005));
	pieceData.push_back(UT_Vector3(0.021105, -0.789344, 0.235005));
	pieceData.push_back(UT_Vector3(0.000000, -0.511962, 0.774438));
	pieceData.push_back(UT_Vector3(0.000000, -0.765224, 0.617913));
	pieceData.push_back(UT_Vector3(0.263806, -0.511962, 0.582770));
	pieceData.push_back(UT_Vector3(0.263806, -0.765224, 0.426246));
	pieceData.push_back(UT_Vector3(-0.263806, -0.765224, 0.426246));
	pieceData.push_back(UT_Vector3(-0.263806, -0.511962, 0.582771));
	pieceData.push_back(UT_Vector3(0.000000, -0.511962, 0.391104));
	pieceData.push_back(UT_Vector3(0.000000, -0.765224, 0.234579));
	pieceData.push_back(UT_Vector3(-0.021104, -0.511962, 0.759104));
	pieceData.push_back(UT_Vector3(-0.021104, -0.765224, 0.602580));
	pieceData.push_back(UT_Vector3(-0.242702, -0.765224, 0.441579));
	pieceData.push_back(UT_Vector3(-0.242702, -0.511962, 0.598104));
	pieceData.push_back(UT_Vector3(0.242702, -0.765224, 0.410912));
	pieceData.push_back(UT_Vector3(0.242702, -0.511962, 0.567437));
	pieceData.push_back(UT_Vector3(0.021105, -0.511962, 0.406437));
	pieceData.push_back(UT_Vector3(0.021105, -0.765224, 0.249913));
	pieceData.push_back(UT_Vector3(0.000000, -0.536941, 0.375666));
	pieceData.push_back(UT_Vector3(0.021105, -0.536941, 0.391000));
	pieceData.push_back(UT_Vector3(0.242702, -0.536941, 0.551999));
	pieceData.push_back(UT_Vector3(0.263806, -0.536941, 0.567333));
	pieceData.push_back(UT_Vector3(0.000000, -0.536941, 0.759000));
	pieceData.push_back(UT_Vector3(-0.021104, -0.536941, 0.743667));
	pieceData.push_back(UT_Vector3(-0.242702, -0.536941, 0.582666));
	pieceData.push_back(UT_Vector3(-0.263806, -0.536941, 0.567333));
	pieceData.push_back(UT_Vector3(0.242702, -0.789344, 0.426672));
	pieceData.push_back(UT_Vector3(0.021105, -0.789344, 0.587672));
	pieceData.push_back(UT_Vector3(-0.021104, -0.789344, 0.235006));
	pieceData.push_back(UT_Vector3(-0.242702, -0.789344, 0.396005));
	pieceData.push_back(UT_Vector3(0.000000, -0.789344, 0.572339));
	pieceData.push_back(UT_Vector3(0.221597, -0.789344, 0.411339));
	pieceData.push_back(UT_Vector3(0.000000, -0.789344, 0.250339));
	pieceData.push_back(UT_Vector3(-0.221597, -0.789344, 0.411339));
	pieceData.push_back(UT_Vector3(0.242702, -0.765224, 0.441579));
	pieceData.push_back(UT_Vector3(0.021105, -0.765224, 0.602580));
	pieceData.push_back(UT_Vector3(0.021105, -0.511962, 0.759104));
	pieceData.push_back(UT_Vector3(0.242702, -0.511962, 0.598104));
	pieceData.push_back(UT_Vector3(-0.021104, -0.511962, 0.406437));
	pieceData.push_back(UT_Vector3(-0.242702, -0.511962, 0.567437));
	pieceData.push_back(UT_Vector3(-0.242702, -0.765224, 0.410913));
	pieceData.push_back(UT_Vector3(-0.021104, -0.765224, 0.249913));
	pieceData.push_back(UT_Vector3(0.242702, -0.536941, 0.582666));
	pieceData.push_back(UT_Vector3(0.021105, -0.536941, 0.743667));
	pieceData.push_back(UT_Vector3(-0.021104, -0.536941, 0.391000));
	pieceData.push_back(UT_Vector3(-0.242702, -0.536941, 0.552000));
	pieceData.push_back(UT_Vector3(0.221598, -0.511962, 0.582771));
	pieceData.push_back(UT_Vector3(0.000000, -0.511962, 0.743771));
	pieceData.push_back(UT_Vector3(-0.221597, -0.511962, 0.582771));
	pieceData.push_back(UT_Vector3(0.000000, -0.511962, 0.421771));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 11
//========================================================================================================
void CCornerComponent::Corner_Purple_DarkGreen_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)	
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.573492, 0.186340, 0.789344));
	pieceData.push_back(UT_Vector3(0.309686, 0.014908, 0.875060));
	pieceData.push_back(UT_Vector3(0.736533, 0.014908, 0.564937));
	pieceData.push_back(UT_Vector3(0.472727, -0.156524, 0.650653));
	pieceData.push_back(UT_Vector3(0.586536, 0.172626, 0.771392));
	pieceData.push_back(UT_Vector3(0.723490, 0.028622, 0.582889));
	pieceData.push_back(UT_Vector3(0.322729, 0.001193, 0.857107));
	pieceData.push_back(UT_Vector3(0.459684, -0.142809, 0.668605));
	pieceData.push_back(UT_Vector3(0.472727, 0.463722, 0.650653));
	pieceData.push_back(UT_Vector3(0.564730, 0.210460, 0.777284));
	pieceData.push_back(UT_Vector3(0.208921, 0.292290, 0.736369));
	pieceData.push_back(UT_Vector3(0.300924, 0.039028, 0.863000));
	pieceData.push_back(UT_Vector3(0.727771, 0.039028, 0.552877));
	pieceData.push_back(UT_Vector3(0.635769, 0.292290, 0.426246));
	pieceData.push_back(UT_Vector3(0.371962, 0.120858, 0.511962));
	pieceData.push_back(UT_Vector3(0.463965, -0.132404, 0.638593));
	pieceData.push_back(UT_Vector3(0.485771, 0.450008, 0.632701));
	pieceData.push_back(UT_Vector3(0.577773, 0.196746, 0.759331));
	pieceData.push_back(UT_Vector3(0.714728, 0.052743, 0.570829));
	pieceData.push_back(UT_Vector3(0.622725, 0.306005, 0.444198));
	pieceData.push_back(UT_Vector3(0.313967, 0.025314, 0.845047));
	pieceData.push_back(UT_Vector3(0.221964, 0.278575, 0.718416));
	pieceData.push_back(UT_Vector3(0.358919, 0.134573, 0.529915));
	pieceData.push_back(UT_Vector3(0.450922, -0.118689, 0.656545));
	pieceData.push_back(UT_Vector3(0.381036, 0.095879, 0.524451));
	pieceData.push_back(UT_Vector3(0.367993, 0.109594, 0.542404));
	pieceData.push_back(UT_Vector3(0.231038, 0.253597, 0.730906));
	pieceData.push_back(UT_Vector3(0.217995, 0.267311, 0.748858));
	pieceData.push_back(UT_Vector3(0.481802, 0.438744, 0.663143));
	pieceData.push_back(UT_Vector3(0.494845, 0.425029, 0.645190));
	pieceData.push_back(UT_Vector3(0.631799, 0.281026, 0.456688));
	pieceData.push_back(UT_Vector3(0.644843, 0.267311, 0.438735));
	pieceData.push_back(UT_Vector3(0.330790, 0.028622, 0.868203));
	pieceData.push_back(UT_Vector3(0.552388, 0.172626, 0.796201));
	pieceData.push_back(UT_Vector3(0.493832, -0.142809, 0.643796));
	pieceData.push_back(UT_Vector3(0.715429, 0.001193, 0.571794));
	pieceData.push_back(UT_Vector3(0.565431, 0.158911, 0.778249));
	pieceData.push_back(UT_Vector3(0.343834, 0.014908, 0.850250));
	pieceData.push_back(UT_Vector3(0.480788, -0.129095, 0.661748));
	pieceData.push_back(UT_Vector3(0.702386, 0.014908, 0.589747));
	pieceData.push_back(UT_Vector3(0.322028, 0.052743, 0.856143));
	pieceData.push_back(UT_Vector3(0.543626, 0.196746, 0.784141));
	pieceData.push_back(UT_Vector3(0.451623, 0.450008, 0.657510));
	pieceData.push_back(UT_Vector3(0.230026, 0.306005, 0.729512));
	pieceData.push_back(UT_Vector3(0.393067, 0.134573, 0.505105));
	pieceData.push_back(UT_Vector3(0.614664, 0.278575, 0.433103));
	pieceData.push_back(UT_Vector3(0.706667, 0.025313, 0.559734));
	pieceData.push_back(UT_Vector3(0.485070, -0.118689, 0.631736));
	pieceData.push_back(UT_Vector3(0.239100, 0.281026, 0.742001));
	pieceData.push_back(UT_Vector3(0.460697, 0.425029, 0.670000));
	pieceData.push_back(UT_Vector3(0.402141, 0.109594, 0.517594));
	pieceData.push_back(UT_Vector3(0.623738, 0.253597, 0.445593));
	pieceData.push_back(UT_Vector3(0.243069, 0.292290, 0.711559));
	pieceData.push_back(UT_Vector3(0.464666, 0.436293, 0.639558));
	pieceData.push_back(UT_Vector3(0.601621, 0.292290, 0.451056));
	pieceData.push_back(UT_Vector3(0.380024, 0.148287, 0.523057));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 12
//========================================================================================================
void CCornerComponent::Corner_Gray_Orange_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.573492, 0.186340, 0.789344));
	pieceData.push_back(UT_Vector3(-0.736533, 0.014908, 0.564937));
	pieceData.push_back(UT_Vector3(-0.309686, 0.014908, 0.875060));
	pieceData.push_back(UT_Vector3(-0.472727, -0.156524, 0.650653));
	pieceData.push_back(UT_Vector3(-0.552387, 0.172626, 0.796202));
	pieceData.push_back(UT_Vector3(-0.330790, 0.028622, 0.868203));
	pieceData.push_back(UT_Vector3(-0.715429, 0.001193, 0.571794));
	pieceData.push_back(UT_Vector3(-0.493831, -0.142809, 0.643796));
	pieceData.push_back(UT_Vector3(-0.472727, 0.463722, 0.650653));
	pieceData.push_back(UT_Vector3(-0.564730, 0.210460, 0.777284));
	pieceData.push_back(UT_Vector3(-0.635768, 0.292290, 0.426246));
	pieceData.push_back(UT_Vector3(-0.727771, 0.039028, 0.552877));
	pieceData.push_back(UT_Vector3(-0.300923, 0.039028, 0.863000));
	pieceData.push_back(UT_Vector3(-0.208921, 0.292290, 0.736369));
	pieceData.push_back(UT_Vector3(-0.371962, 0.120858, 0.511962));
	pieceData.push_back(UT_Vector3(-0.463965, -0.132404, 0.638593));
	pieceData.push_back(UT_Vector3(-0.451623, 0.450008, 0.657511));
	pieceData.push_back(UT_Vector3(-0.543625, 0.196746, 0.784141));
	pieceData.push_back(UT_Vector3(-0.322028, 0.052743, 0.856143));
	pieceData.push_back(UT_Vector3(-0.230025, 0.306005, 0.729512));
	pieceData.push_back(UT_Vector3(-0.706667, 0.025314, 0.559734));
	pieceData.push_back(UT_Vector3(-0.614664, 0.278575, 0.433103));
	pieceData.push_back(UT_Vector3(-0.393067, 0.134573, 0.505105));
	pieceData.push_back(UT_Vector3(-0.485069, -0.118689, 0.631736));
	pieceData.push_back(UT_Vector3(-0.381036, 0.095879, 0.524451));
	pieceData.push_back(UT_Vector3(-0.402141, 0.109594, 0.517594));
	pieceData.push_back(UT_Vector3(-0.623738, 0.253597, 0.445593));
	pieceData.push_back(UT_Vector3(-0.644842, 0.267311, 0.438736));
	pieceData.push_back(UT_Vector3(-0.481801, 0.438744, 0.663143));
	pieceData.push_back(UT_Vector3(-0.460697, 0.425029, 0.670000));
	pieceData.push_back(UT_Vector3(-0.239099, 0.281026, 0.742001));
	pieceData.push_back(UT_Vector3(-0.217995, 0.267311, 0.748858));
	pieceData.push_back(UT_Vector3(-0.723490, 0.028622, 0.582890));
	pieceData.push_back(UT_Vector3(-0.586535, 0.172626, 0.771392));
	pieceData.push_back(UT_Vector3(-0.459684, -0.142809, 0.668606));
	pieceData.push_back(UT_Vector3(-0.322729, 0.001193, 0.857107));
	pieceData.push_back(UT_Vector3(-0.565431, 0.158911, 0.778249));
	pieceData.push_back(UT_Vector3(-0.702385, 0.014908, 0.589747));
	pieceData.push_back(UT_Vector3(-0.480788, -0.129095, 0.661748));
	pieceData.push_back(UT_Vector3(-0.343833, 0.014908, 0.850250));
	pieceData.push_back(UT_Vector3(-0.714728, 0.052743, 0.570830));
	pieceData.push_back(UT_Vector3(-0.577773, 0.196746, 0.759332));
	pieceData.push_back(UT_Vector3(-0.485770, 0.450008, 0.632701));
	pieceData.push_back(UT_Vector3(-0.622725, 0.306005, 0.444199));
	pieceData.push_back(UT_Vector3(-0.358919, 0.134573, 0.529915));
	pieceData.push_back(UT_Vector3(-0.221964, 0.278575, 0.718416));
	pieceData.push_back(UT_Vector3(-0.313967, 0.025313, 0.845047));
	pieceData.push_back(UT_Vector3(-0.450922, -0.118689, 0.656546));
	pieceData.push_back(UT_Vector3(-0.631799, 0.281026, 0.456688));
	pieceData.push_back(UT_Vector3(-0.494845, 0.425029, 0.645190));
	pieceData.push_back(UT_Vector3(-0.367993, 0.109594, 0.542404));
	pieceData.push_back(UT_Vector3(-0.231038, 0.253597, 0.730906));
	pieceData.push_back(UT_Vector3(-0.601621, 0.292290, 0.451056));
	pieceData.push_back(UT_Vector3(-0.464666, 0.436293, 0.639558));
	pieceData.push_back(UT_Vector3(-0.243069, 0.292290, 0.711559));
	pieceData.push_back(UT_Vector3(-0.380023, 0.148287, 0.523057));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 13
//========================================================================================================
void CCornerComponent::Corner_Pink_LightGreen_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.927930, 0.186340, -0.301503));
	pieceData.push_back(UT_Vector3(-0.764888, 0.014908, -0.525910));
	pieceData.push_back(UT_Vector3(-0.927930, 0.014908, -0.024120));
	pieceData.push_back(UT_Vector3(-0.764888, -0.156524, -0.248527));
	pieceData.push_back(UT_Vector3(-0.927930, 0.172626, -0.279312));
	pieceData.push_back(UT_Vector3(-0.927930, 0.028622, -0.046311));
	pieceData.push_back(UT_Vector3(-0.764888, 0.001193, -0.503719));
	pieceData.push_back(UT_Vector3(-0.764888, -0.142809, -0.270718));
	pieceData.push_back(UT_Vector3(-0.764889, 0.463722, -0.248527));
	pieceData.push_back(UT_Vector3(-0.913752, 0.210460, -0.296896));
	pieceData.push_back(UT_Vector3(-0.601847, 0.292290, -0.472934));
	pieceData.push_back(UT_Vector3(-0.750711, 0.039028, -0.521303));
	pieceData.push_back(UT_Vector3(-0.913752, 0.039028, -0.019514));
	pieceData.push_back(UT_Vector3(-0.764889, 0.292290, 0.028855));
	pieceData.push_back(UT_Vector3(-0.601848, 0.120858, -0.195552));
	pieceData.push_back(UT_Vector3(-0.750711, -0.132404, -0.243921));
	pieceData.push_back(UT_Vector3(-0.764889, 0.450008, -0.226337));
	pieceData.push_back(UT_Vector3(-0.913752, 0.196746, -0.274705));
	pieceData.push_back(UT_Vector3(-0.913752, 0.052743, -0.041704));
	pieceData.push_back(UT_Vector3(-0.764889, 0.306005, 0.006664));
	pieceData.push_back(UT_Vector3(-0.750711, 0.025314, -0.499112));
	pieceData.push_back(UT_Vector3(-0.601847, 0.278575, -0.450744));
	pieceData.push_back(UT_Vector3(-0.601848, 0.134573, -0.217743));
	pieceData.push_back(UT_Vector3(-0.750711, -0.118689, -0.266111));
	pieceData.push_back(UT_Vector3(-0.616530, 0.095879, -0.200323));
	pieceData.push_back(UT_Vector3(-0.616530, 0.109594, -0.222513));
	pieceData.push_back(UT_Vector3(-0.616530, 0.253597, -0.455514));
	pieceData.push_back(UT_Vector3(-0.616530, 0.267311, -0.477705));
	pieceData.push_back(UT_Vector3(-0.779571, 0.438744, -0.253298));
	pieceData.push_back(UT_Vector3(-0.779571, 0.425029, -0.231107));
	pieceData.push_back(UT_Vector3(-0.779571, 0.281026, 0.001894));
	pieceData.push_back(UT_Vector3(-0.779571, 0.267311, 0.024085));
	pieceData.push_back(UT_Vector3(-0.777932, 0.028622, -0.507957));
	pieceData.push_back(UT_Vector3(-0.914886, 0.172626, -0.319455));
	pieceData.push_back(UT_Vector3(-0.777932, -0.142809, -0.230575));
	pieceData.push_back(UT_Vector3(-0.914886, 0.001193, -0.042073));
	pieceData.push_back(UT_Vector3(-0.914886, 0.158911, -0.297265));
	pieceData.push_back(UT_Vector3(-0.777932, 0.014908, -0.485766));
	pieceData.push_back(UT_Vector3(-0.777932, -0.129095, -0.252765));
	pieceData.push_back(UT_Vector3(-0.914886, 0.014908, -0.064263));
	pieceData.push_back(UT_Vector3(-0.763754, 0.052743, -0.503350));
	pieceData.push_back(UT_Vector3(-0.900709, 0.196746, -0.314849));
	pieceData.push_back(UT_Vector3(-0.751845, 0.450008, -0.266480));
	pieceData.push_back(UT_Vector3(-0.614891, 0.306005, -0.454982));
	pieceData.push_back(UT_Vector3(-0.614891, 0.134573, -0.177600));
	pieceData.push_back(UT_Vector3(-0.751845, 0.278575, 0.010903));
	pieceData.push_back(UT_Vector3(-0.900709, 0.025313, -0.037466));
	pieceData.push_back(UT_Vector3(-0.763754, -0.118689, -0.225968));
	pieceData.push_back(UT_Vector3(-0.629573, 0.281026, -0.459752));
	pieceData.push_back(UT_Vector3(-0.766528, 0.425029, -0.271250));
	pieceData.push_back(UT_Vector3(-0.629573, 0.109594, -0.182370));
	pieceData.push_back(UT_Vector3(-0.766528, 0.253597, 0.006132));
	pieceData.push_back(UT_Vector3(-0.614891, 0.292290, -0.432791));
	pieceData.push_back(UT_Vector3(-0.751845, 0.436293, -0.244289));
	pieceData.push_back(UT_Vector3(-0.751845, 0.292290, -0.011288));
	pieceData.push_back(UT_Vector3(-0.614891, 0.148287, -0.199790));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 14
//========================================================================================================
void CCornerComponent::Corner_Red_Blue_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.000000, 0.186340, -0.975683));
	pieceData.push_back(UT_Vector3(0.263806, 0.014908, -0.889967));
	pieceData.push_back(UT_Vector3(-0.263806, 0.014908, -0.889967));
	pieceData.push_back(UT_Vector3(-0.000000, -0.156524, -0.804251));
	pieceData.push_back(UT_Vector3(-0.021105, 0.172626, -0.968826));
	pieceData.push_back(UT_Vector3(-0.242702, 0.028622, -0.896824));
	pieceData.push_back(UT_Vector3(0.242702, 0.001193, -0.883110));
	pieceData.push_back(UT_Vector3(0.021104, -0.142809, -0.811109));
	pieceData.push_back(UT_Vector3(-0.000000, 0.463722, -0.804252));
	pieceData.push_back(UT_Vector3(-0.000000, 0.210460, -0.960776));
	pieceData.push_back(UT_Vector3(0.263806, 0.292290, -0.718536));
	pieceData.push_back(UT_Vector3(0.263806, 0.039028, -0.875060));
	pieceData.push_back(UT_Vector3(-0.263806, 0.039028, -0.875060));
	pieceData.push_back(UT_Vector3(-0.263806, 0.292290, -0.718536));
	pieceData.push_back(UT_Vector3(-0.000000, 0.120858, -0.632820));
	pieceData.push_back(UT_Vector3(-0.000000, -0.132404, -0.789344));
	pieceData.push_back(UT_Vector3(-0.021105, 0.450008, -0.797394));
	pieceData.push_back(UT_Vector3(-0.021105, 0.196746, -0.953919));
	pieceData.push_back(UT_Vector3(-0.242702, 0.052743, -0.881917));
	pieceData.push_back(UT_Vector3(-0.242702, 0.306005, -0.725393));
	pieceData.push_back(UT_Vector3(0.242702, 0.025314, -0.868203));
	pieceData.push_back(UT_Vector3(0.242702, 0.278575, -0.711678));
	pieceData.push_back(UT_Vector3(0.021104, 0.134573, -0.639677));
	pieceData.push_back(UT_Vector3(0.021104, -0.118689, -0.796201));
	pieceData.push_back(UT_Vector3(-0.000000, 0.095879, -0.648258));
	pieceData.push_back(UT_Vector3(0.021105, 0.109594, -0.655115));
	pieceData.push_back(UT_Vector3(0.242702, 0.253597, -0.727116));
	pieceData.push_back(UT_Vector3(0.263806, 0.267311, -0.733973));
	pieceData.push_back(UT_Vector3(-0.000000, 0.438744, -0.819690));
	pieceData.push_back(UT_Vector3(-0.021105, 0.425029, -0.812832));
	pieceData.push_back(UT_Vector3(-0.242702, 0.281026, -0.740831));
	pieceData.push_back(UT_Vector3(-0.263806, 0.267311, -0.733973));
	pieceData.push_back(UT_Vector3(0.242702, 0.028622, -0.896824));
	pieceData.push_back(UT_Vector3(0.021104, 0.172626, -0.968826));
	pieceData.push_back(UT_Vector3(-0.021105, -0.142809, -0.811109));
	pieceData.push_back(UT_Vector3(-0.242702, 0.001193, -0.883110));
	pieceData.push_back(UT_Vector3(-0.000000, 0.158911, -0.961968));
	pieceData.push_back(UT_Vector3(0.221597, 0.014908, -0.889967));
	pieceData.push_back(UT_Vector3(-0.000000, -0.129095, -0.817966));
	pieceData.push_back(UT_Vector3(-0.221597, 0.014908, -0.889967));
	pieceData.push_back(UT_Vector3(0.242702, 0.052743, -0.881917));
	pieceData.push_back(UT_Vector3(0.021104, 0.196746, -0.953919));
	pieceData.push_back(UT_Vector3(0.021104, 0.450008, -0.797394));
	pieceData.push_back(UT_Vector3(0.242702, 0.306005, -0.725393));
	pieceData.push_back(UT_Vector3(-0.021105, 0.134573, -0.639677));
	pieceData.push_back(UT_Vector3(-0.242702, 0.278575, -0.711678));
	pieceData.push_back(UT_Vector3(-0.242702, 0.025313, -0.868203));
	pieceData.push_back(UT_Vector3(-0.021105, -0.118689, -0.796201));
	pieceData.push_back(UT_Vector3(0.242702, 0.281026, -0.740831));
	pieceData.push_back(UT_Vector3(0.021104, 0.425029, -0.812832));
	pieceData.push_back(UT_Vector3(-0.021105, 0.109594, -0.655115));
	pieceData.push_back(UT_Vector3(-0.242702, 0.253597, -0.727116));
	pieceData.push_back(UT_Vector3(0.221597, 0.292290, -0.718536));
	pieceData.push_back(UT_Vector3(-0.000000, 0.436293, -0.790537));
	pieceData.push_back(UT_Vector3(-0.221597, 0.292290, -0.718536));
	pieceData.push_back(UT_Vector3(-0.000000, 0.148287, -0.646534));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 15
//========================================================================================================
void CCornerComponent::Corner_DarkGreen_White_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.927930, 0.186340, -0.301503));
	pieceData.push_back(UT_Vector3(0.927930, 0.014908, -0.024120));
	pieceData.push_back(UT_Vector3(0.764888, 0.014908, -0.525910));
	pieceData.push_back(UT_Vector3(0.764888, -0.156524, -0.248527));
	pieceData.push_back(UT_Vector3(0.914886, 0.172626, -0.319455));
	pieceData.push_back(UT_Vector3(0.777931, 0.028622, -0.507957));
	pieceData.push_back(UT_Vector3(0.914886, 0.001193, -0.042073));
	pieceData.push_back(UT_Vector3(0.777932, -0.142809, -0.230575));
	pieceData.push_back(UT_Vector3(0.764889, 0.463722, -0.248528));
	pieceData.push_back(UT_Vector3(0.913752, 0.210460, -0.296896));
	pieceData.push_back(UT_Vector3(0.764889, 0.292290, 0.028855));
	pieceData.push_back(UT_Vector3(0.913752, 0.039028, -0.019514));
	pieceData.push_back(UT_Vector3(0.750711, 0.039028, -0.521303));
	pieceData.push_back(UT_Vector3(0.601847, 0.292290, -0.472935));
	pieceData.push_back(UT_Vector3(0.601847, 0.120858, -0.195552));
	pieceData.push_back(UT_Vector3(0.750711, -0.132404, -0.243921));
	pieceData.push_back(UT_Vector3(0.751845, 0.450008, -0.266480));
	pieceData.push_back(UT_Vector3(0.900709, 0.196746, -0.314849));
	pieceData.push_back(UT_Vector3(0.763754, 0.052743, -0.503351));
	pieceData.push_back(UT_Vector3(0.614891, 0.306005, -0.454982));
	pieceData.push_back(UT_Vector3(0.900709, 0.025314, -0.037466));
	pieceData.push_back(UT_Vector3(0.751845, 0.278575, 0.010902));
	pieceData.push_back(UT_Vector3(0.614891, 0.134573, -0.177600));
	pieceData.push_back(UT_Vector3(0.763754, -0.118689, -0.225968));
	pieceData.push_back(UT_Vector3(0.616530, 0.095879, -0.200323));
	pieceData.push_back(UT_Vector3(0.629573, 0.109594, -0.182370));
	pieceData.push_back(UT_Vector3(0.766528, 0.253597, 0.006132));
	pieceData.push_back(UT_Vector3(0.779571, 0.267311, 0.024084));
	pieceData.push_back(UT_Vector3(0.779571, 0.438744, -0.253298));
	pieceData.push_back(UT_Vector3(0.766528, 0.425029, -0.271251));
	pieceData.push_back(UT_Vector3(0.629573, 0.281026, -0.459753));
	pieceData.push_back(UT_Vector3(0.616529, 0.267311, -0.477705));
	pieceData.push_back(UT_Vector3(0.927930, 0.028622, -0.046311));
	pieceData.push_back(UT_Vector3(0.927930, 0.172626, -0.279312));
	pieceData.push_back(UT_Vector3(0.764888, -0.142809, -0.270718));
	pieceData.push_back(UT_Vector3(0.764888, 0.001193, -0.503719));
	pieceData.push_back(UT_Vector3(0.914886, 0.158911, -0.297265));
	pieceData.push_back(UT_Vector3(0.914886, 0.014908, -0.064264));
	pieceData.push_back(UT_Vector3(0.777932, -0.129095, -0.252765));
	pieceData.push_back(UT_Vector3(0.777932, 0.014908, -0.485767));
	pieceData.push_back(UT_Vector3(0.913752, 0.052743, -0.041704));
	pieceData.push_back(UT_Vector3(0.913752, 0.196746, -0.274706));
	pieceData.push_back(UT_Vector3(0.764889, 0.450008, -0.226337));
	pieceData.push_back(UT_Vector3(0.764889, 0.306005, 0.006664));
	pieceData.push_back(UT_Vector3(0.601847, 0.134573, -0.217743));
	pieceData.push_back(UT_Vector3(0.601847, 0.278575, -0.450744));
	pieceData.push_back(UT_Vector3(0.750711, 0.025313, -0.499113));
	pieceData.push_back(UT_Vector3(0.750711, -0.118689, -0.266111));
	pieceData.push_back(UT_Vector3(0.779571, 0.281026, 0.001894));
	pieceData.push_back(UT_Vector3(0.779571, 0.425029, -0.231108));
	pieceData.push_back(UT_Vector3(0.616530, 0.109594, -0.222513));
	pieceData.push_back(UT_Vector3(0.616529, 0.253597, -0.455514));
	pieceData.push_back(UT_Vector3(0.751845, 0.292290, -0.011288));
	pieceData.push_back(UT_Vector3(0.751845, 0.436293, -0.244290));
	pieceData.push_back(UT_Vector3(0.614891, 0.292290, -0.432791));
	pieceData.push_back(UT_Vector3(0.614891, 0.148287, -0.199790));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 16
//========================================================================================================
void CCornerComponent::Corner_DarkGreen_Purple_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.000001, -0.186340, 0.975683));
	pieceData.push_back(UT_Vector3(0.263807, -0.014908, 0.889967));
	pieceData.push_back(UT_Vector3(-0.263806, -0.014908, 0.889967));
	pieceData.push_back(UT_Vector3(0.000000, 0.156524, 0.804251));
	pieceData.push_back(UT_Vector3(-0.021104, -0.172626, 0.968826));
	pieceData.push_back(UT_Vector3(-0.242701, -0.028623, 0.896824));
	pieceData.push_back(UT_Vector3(0.242702, -0.001193, 0.883110));
	pieceData.push_back(UT_Vector3(0.021105, 0.142809, 0.811109));
	pieceData.push_back(UT_Vector3(0.000001, -0.463723, 0.804252));
	pieceData.push_back(UT_Vector3(0.000001, -0.210461, 0.960776));
	pieceData.push_back(UT_Vector3(0.263807, -0.292290, 0.718535));
	pieceData.push_back(UT_Vector3(0.263807, -0.039028, 0.875060));
	pieceData.push_back(UT_Vector3(-0.263806, -0.039028, 0.875060));
	pieceData.push_back(UT_Vector3(-0.263806, -0.292290, 0.718536));
	pieceData.push_back(UT_Vector3(0.000000, -0.120858, 0.632820));
	pieceData.push_back(UT_Vector3(0.000000, 0.132404, 0.789344));
	pieceData.push_back(UT_Vector3(-0.021104, -0.450008, 0.797394));
	pieceData.push_back(UT_Vector3(-0.021104, -0.196746, 0.953919));
	pieceData.push_back(UT_Vector3(-0.242701, -0.052743, 0.881917));
	pieceData.push_back(UT_Vector3(-0.242701, -0.306005, 0.725393));
	pieceData.push_back(UT_Vector3(0.242702, -0.025313, 0.868203));
	pieceData.push_back(UT_Vector3(0.242702, -0.278575, 0.711678));
	pieceData.push_back(UT_Vector3(0.021105, -0.134573, 0.639677));
	pieceData.push_back(UT_Vector3(0.021105, 0.118689, 0.796201));
	pieceData.push_back(UT_Vector3(0.000000, -0.095879, 0.648258));
	pieceData.push_back(UT_Vector3(0.021105, -0.109594, 0.655115));
	pieceData.push_back(UT_Vector3(0.242702, -0.253597, 0.727116));
	pieceData.push_back(UT_Vector3(0.263807, -0.267311, 0.733973));
	pieceData.push_back(UT_Vector3(0.000001, -0.438744, 0.819689));
	pieceData.push_back(UT_Vector3(-0.021104, -0.425029, 0.812832));
	pieceData.push_back(UT_Vector3(-0.242701, -0.281026, 0.740831));
	pieceData.push_back(UT_Vector3(-0.263806, -0.267311, 0.733974));
	pieceData.push_back(UT_Vector3(0.242702, -0.028622, 0.896824));
	pieceData.push_back(UT_Vector3(0.021105, -0.172626, 0.968826));
	pieceData.push_back(UT_Vector3(-0.021104, 0.142809, 0.811109));
	pieceData.push_back(UT_Vector3(-0.242701, -0.001193, 0.883110));
	pieceData.push_back(UT_Vector3(0.000001, -0.158911, 0.961969));
	pieceData.push_back(UT_Vector3(0.221598, -0.014908, 0.889967));
	pieceData.push_back(UT_Vector3(0.000000, 0.129095, 0.817966));
	pieceData.push_back(UT_Vector3(-0.221597, -0.014908, 0.889967));
	pieceData.push_back(UT_Vector3(0.242702, -0.052743, 0.881917));
	pieceData.push_back(UT_Vector3(0.021105, -0.196746, 0.953919));
	pieceData.push_back(UT_Vector3(0.021105, -0.450008, 0.797394));
	pieceData.push_back(UT_Vector3(0.242702, -0.306005, 0.725393));
	pieceData.push_back(UT_Vector3(-0.021104, -0.134573, 0.639677));
	pieceData.push_back(UT_Vector3(-0.242701, -0.278576, 0.711678));
	pieceData.push_back(UT_Vector3(-0.242701, -0.025314, 0.868203));
	pieceData.push_back(UT_Vector3(-0.021104, 0.118689, 0.796202));
	pieceData.push_back(UT_Vector3(0.242702, -0.281026, 0.740830));
	pieceData.push_back(UT_Vector3(0.021105, -0.425029, 0.812832));
	pieceData.push_back(UT_Vector3(-0.021104, -0.109594, 0.655115));
	pieceData.push_back(UT_Vector3(-0.242701, -0.253597, 0.727116));
	pieceData.push_back(UT_Vector3(0.221598, -0.292290, 0.718535));
	pieceData.push_back(UT_Vector3(0.000001, -0.436293, 0.790537));
	pieceData.push_back(UT_Vector3(-0.221597, -0.292290, 0.718536));
	pieceData.push_back(UT_Vector3(0.000000, -0.148287, 0.646534));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 17
//========================================================================================================
void CCornerComponent::Corner_LightBlue_Orange_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.927929, -0.186340, 0.301504));
	pieceData.push_back(UT_Vector3(-0.764887, -0.014908, 0.525911));
	pieceData.push_back(UT_Vector3(-0.927930, -0.014908, 0.024122));
	pieceData.push_back(UT_Vector3(-0.764888, 0.156524, 0.248529));
	pieceData.push_back(UT_Vector3(-0.927929, -0.172626, 0.279314));
	pieceData.push_back(UT_Vector3(-0.927929, -0.028623, 0.046312));
	pieceData.push_back(UT_Vector3(-0.764887, -0.001193, 0.503720));
	pieceData.push_back(UT_Vector3(-0.764888, 0.142809, 0.270719));
	pieceData.push_back(UT_Vector3(-0.764888, -0.463723, 0.248529));
	pieceData.push_back(UT_Vector3(-0.913752, -0.210461, 0.296898));
	pieceData.push_back(UT_Vector3(-0.601846, -0.292290, 0.472936));
	pieceData.push_back(UT_Vector3(-0.750710, -0.039028, 0.521304));
	pieceData.push_back(UT_Vector3(-0.913752, -0.039028, 0.019515));
	pieceData.push_back(UT_Vector3(-0.764889, -0.292290, -0.028854));
	pieceData.push_back(UT_Vector3(-0.601847, -0.120858, 0.195553));
	pieceData.push_back(UT_Vector3(-0.750711, 0.132404, 0.243922));
	pieceData.push_back(UT_Vector3(-0.764888, -0.450008, 0.226338));
	pieceData.push_back(UT_Vector3(-0.913752, -0.196746, 0.274707));
	pieceData.push_back(UT_Vector3(-0.913752, -0.052743, 0.041706));
	pieceData.push_back(UT_Vector3(-0.764889, -0.306005, -0.006663));
	pieceData.push_back(UT_Vector3(-0.750710, -0.025313, 0.499114));
	pieceData.push_back(UT_Vector3(-0.601846, -0.278575, 0.450745));
	pieceData.push_back(UT_Vector3(-0.601847, -0.134573, 0.217744));
	pieceData.push_back(UT_Vector3(-0.750711, 0.118689, 0.266113));
	pieceData.push_back(UT_Vector3(-0.616529, -0.095879, 0.200324));
	pieceData.push_back(UT_Vector3(-0.616529, -0.109594, 0.222514));
	pieceData.push_back(UT_Vector3(-0.616529, -0.253597, 0.455516));
	pieceData.push_back(UT_Vector3(-0.616529, -0.267311, 0.477706));
	pieceData.push_back(UT_Vector3(-0.779570, -0.438744, 0.253299));
	pieceData.push_back(UT_Vector3(-0.779571, -0.425029, 0.231109));
	pieceData.push_back(UT_Vector3(-0.779571, -0.281026, -0.001893));
	pieceData.push_back(UT_Vector3(-0.779571, -0.267311, -0.024083));
	pieceData.push_back(UT_Vector3(-0.777931, -0.028622, 0.507958));
	pieceData.push_back(UT_Vector3(-0.914886, -0.172626, 0.319457));
	pieceData.push_back(UT_Vector3(-0.777931, 0.142809, 0.230576));
	pieceData.push_back(UT_Vector3(-0.914886, -0.001193, 0.042074));
	pieceData.push_back(UT_Vector3(-0.914886, -0.158911, 0.297266));
	pieceData.push_back(UT_Vector3(-0.777931, -0.014908, 0.485768));
	pieceData.push_back(UT_Vector3(-0.777931, 0.129095, 0.252767));
	pieceData.push_back(UT_Vector3(-0.914886, -0.014908, 0.064265));
	pieceData.push_back(UT_Vector3(-0.763753, -0.052743, 0.503352));
	pieceData.push_back(UT_Vector3(-0.900708, -0.196746, 0.314850));
	pieceData.push_back(UT_Vector3(-0.751845, -0.450008, 0.266481));
	pieceData.push_back(UT_Vector3(-0.614890, -0.306005, 0.454983));
	pieceData.push_back(UT_Vector3(-0.614890, -0.134573, 0.177601));
	pieceData.push_back(UT_Vector3(-0.751845, -0.278576, -0.010901));
	pieceData.push_back(UT_Vector3(-0.900709, -0.025314, 0.037468));
	pieceData.push_back(UT_Vector3(-0.763754, 0.118689, 0.225969));
	pieceData.push_back(UT_Vector3(-0.629572, -0.281026, 0.459754));
	pieceData.push_back(UT_Vector3(-0.766527, -0.425029, 0.271252));
	pieceData.push_back(UT_Vector3(-0.629573, -0.109594, 0.182371));
	pieceData.push_back(UT_Vector3(-0.766527, -0.253597, -0.006131));
	pieceData.push_back(UT_Vector3(-0.614890, -0.292290, 0.432792));
	pieceData.push_back(UT_Vector3(-0.751845, -0.436293, 0.244291));
	pieceData.push_back(UT_Vector3(-0.751845, -0.292290, 0.011290));
	pieceData.push_back(UT_Vector3(-0.614890, -0.148287, 0.199791));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 18
//========================================================================================================
void CCornerComponent::Corner_Gray_LightGreen_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.573493, -0.186340, -0.789343));
	pieceData.push_back(UT_Vector3(-0.736534, -0.014908, -0.564936));
	pieceData.push_back(UT_Vector3(-0.309687, -0.014908, -0.875060));
	pieceData.push_back(UT_Vector3(-0.472728, 0.156524, -0.650652));
	pieceData.push_back(UT_Vector3(-0.552389, -0.172626, -0.796201));
	pieceData.push_back(UT_Vector3(-0.330791, -0.028623, -0.868202));
	pieceData.push_back(UT_Vector3(-0.715429, -0.001193, -0.571793));
	pieceData.push_back(UT_Vector3(-0.493832, 0.142809, -0.643795));
	pieceData.push_back(UT_Vector3(-0.472728, -0.463723, -0.650653));
	pieceData.push_back(UT_Vector3(-0.564731, -0.210461, -0.777283));
	pieceData.push_back(UT_Vector3(-0.635769, -0.292290, -0.426245));
	pieceData.push_back(UT_Vector3(-0.727772, -0.039028, -0.552876));
	pieceData.push_back(UT_Vector3(-0.300925, -0.039028, -0.862999));
	pieceData.push_back(UT_Vector3(-0.208922, -0.292290, -0.736369));
	pieceData.push_back(UT_Vector3(-0.371963, -0.120858, -0.511962));
	pieceData.push_back(UT_Vector3(-0.463966, 0.132404, -0.638592));
	pieceData.push_back(UT_Vector3(-0.451624, -0.450008, -0.657510));
	pieceData.push_back(UT_Vector3(-0.543626, -0.196746, -0.784141));
	pieceData.push_back(UT_Vector3(-0.322029, -0.052743, -0.856142));
	pieceData.push_back(UT_Vector3(-0.230026, -0.306005, -0.729511));
	pieceData.push_back(UT_Vector3(-0.706667, -0.025313, -0.559733));
	pieceData.push_back(UT_Vector3(-0.614664, -0.278575, -0.433102));
	pieceData.push_back(UT_Vector3(-0.393067, -0.134573, -0.505104));
	pieceData.push_back(UT_Vector3(-0.485070, 0.118689, -0.631735));
	pieceData.push_back(UT_Vector3(-0.381037, -0.095879, -0.524451));
	pieceData.push_back(UT_Vector3(-0.402141, -0.109594, -0.517594));
	pieceData.push_back(UT_Vector3(-0.623739, -0.253597, -0.445592));
	pieceData.push_back(UT_Vector3(-0.644843, -0.267311, -0.438735));
	pieceData.push_back(UT_Vector3(-0.481802, -0.438744, -0.663142));
	pieceData.push_back(UT_Vector3(-0.460698, -0.425029, -0.669999));
	pieceData.push_back(UT_Vector3(-0.239100, -0.281026, -0.742001));
	pieceData.push_back(UT_Vector3(-0.217996, -0.267311, -0.748858));
	pieceData.push_back(UT_Vector3(-0.723491, -0.028622, -0.582889));
	pieceData.push_back(UT_Vector3(-0.586536, -0.172626, -0.771391));
	pieceData.push_back(UT_Vector3(-0.459685, 0.142809, -0.668605));
	pieceData.push_back(UT_Vector3(-0.322730, -0.001193, -0.857107));
	pieceData.push_back(UT_Vector3(-0.565432, -0.158911, -0.778248));
	pieceData.push_back(UT_Vector3(-0.702386, -0.014908, -0.589746));
	pieceData.push_back(UT_Vector3(-0.480789, 0.129095, -0.661748));
	pieceData.push_back(UT_Vector3(-0.343834, -0.014908, -0.850250));
	pieceData.push_back(UT_Vector3(-0.714728, -0.052743, -0.570829));
	pieceData.push_back(UT_Vector3(-0.577774, -0.196746, -0.759331));
	pieceData.push_back(UT_Vector3(-0.485771, -0.450008, -0.632700));
	pieceData.push_back(UT_Vector3(-0.622726, -0.306005, -0.444198));
	pieceData.push_back(UT_Vector3(-0.358920, -0.134573, -0.529914));
	pieceData.push_back(UT_Vector3(-0.221965, -0.278576, -0.718416));
	pieceData.push_back(UT_Vector3(-0.313968, -0.025314, -0.845047));
	pieceData.push_back(UT_Vector3(-0.450922, 0.118689, -0.656545));
	pieceData.push_back(UT_Vector3(-0.631800, -0.281026, -0.456687));
	pieceData.push_back(UT_Vector3(-0.494846, -0.425029, -0.645189));
	pieceData.push_back(UT_Vector3(-0.367994, -0.109594, -0.542404));
	pieceData.push_back(UT_Vector3(-0.231039, -0.253597, -0.730905));
	pieceData.push_back(UT_Vector3(-0.601621, -0.292290, -0.451055));
	pieceData.push_back(UT_Vector3(-0.464667, -0.436293, -0.639557));
	pieceData.push_back(UT_Vector3(-0.243070, -0.292290, -0.711559));
	pieceData.push_back(UT_Vector3(-0.380024, -0.148287, -0.523057));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 19
//========================================================================================================
void CCornerComponent::Corner_Pink_Blue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.573491, -0.186340, -0.789345));
	pieceData.push_back(UT_Vector3(0.309685, -0.014908, -0.875060));
	pieceData.push_back(UT_Vector3(0.736533, -0.014908, -0.564937));
	pieceData.push_back(UT_Vector3(0.472727, 0.156524, -0.650653));
	pieceData.push_back(UT_Vector3(0.586535, -0.172626, -0.771392));
	pieceData.push_back(UT_Vector3(0.723490, -0.028623, -0.582890));
	pieceData.push_back(UT_Vector3(0.322728, -0.001193, -0.857108));
	pieceData.push_back(UT_Vector3(0.459683, 0.142809, -0.668606));
	pieceData.push_back(UT_Vector3(0.472727, -0.463723, -0.650654));
	pieceData.push_back(UT_Vector3(0.564729, -0.210461, -0.777285));
	pieceData.push_back(UT_Vector3(0.208920, -0.292290, -0.736369));
	pieceData.push_back(UT_Vector3(0.300923, -0.039028, -0.863000));
	pieceData.push_back(UT_Vector3(0.727771, -0.039028, -0.552877));
	pieceData.push_back(UT_Vector3(0.635768, -0.292290, -0.426246));
	pieceData.push_back(UT_Vector3(0.371962, -0.120858, -0.511962));
	pieceData.push_back(UT_Vector3(0.463964, 0.132404, -0.638593));
	pieceData.push_back(UT_Vector3(0.485770, -0.450008, -0.632701));
	pieceData.push_back(UT_Vector3(0.577773, -0.196746, -0.759332));
	pieceData.push_back(UT_Vector3(0.714727, -0.052743, -0.570830));
	pieceData.push_back(UT_Vector3(0.622725, -0.306005, -0.444199));
	pieceData.push_back(UT_Vector3(0.313966, -0.025313, -0.845047));
	pieceData.push_back(UT_Vector3(0.221963, -0.278575, -0.718417));
	pieceData.push_back(UT_Vector3(0.358918, -0.134573, -0.529915));
	pieceData.push_back(UT_Vector3(0.450921, 0.118689, -0.656546));
	pieceData.push_back(UT_Vector3(0.381036, -0.095879, -0.524452));
	pieceData.push_back(UT_Vector3(0.367992, -0.109594, -0.542404));
	pieceData.push_back(UT_Vector3(0.231038, -0.253597, -0.730906));
	pieceData.push_back(UT_Vector3(0.217994, -0.267311, -0.748859));
	pieceData.push_back(UT_Vector3(0.481801, -0.438744, -0.663143));
	pieceData.push_back(UT_Vector3(0.494844, -0.425029, -0.645191));
	pieceData.push_back(UT_Vector3(0.631799, -0.281026, -0.456688));
	pieceData.push_back(UT_Vector3(0.644842, -0.267311, -0.438736));
	pieceData.push_back(UT_Vector3(0.330790, -0.028622, -0.868203));
	pieceData.push_back(UT_Vector3(0.552387, -0.172626, -0.796202));
	pieceData.push_back(UT_Vector3(0.493831, 0.142809, -0.643796));
	pieceData.push_back(UT_Vector3(0.715428, -0.001193, -0.571795));
	pieceData.push_back(UT_Vector3(0.565430, -0.158911, -0.778249));
	pieceData.push_back(UT_Vector3(0.343833, -0.014908, -0.850250));
	pieceData.push_back(UT_Vector3(0.480788, 0.129095, -0.661749));
	pieceData.push_back(UT_Vector3(0.702385, -0.014908, -0.589747));
	pieceData.push_back(UT_Vector3(0.322027, -0.052743, -0.856143));
	pieceData.push_back(UT_Vector3(0.543625, -0.196746, -0.784142));
	pieceData.push_back(UT_Vector3(0.451622, -0.450008, -0.657511));
	pieceData.push_back(UT_Vector3(0.230025, -0.306005, -0.729512));
	pieceData.push_back(UT_Vector3(0.393066, -0.134573, -0.505105));
	pieceData.push_back(UT_Vector3(0.614663, -0.278576, -0.433104));
	pieceData.push_back(UT_Vector3(0.706666, -0.025314, -0.559735));
	pieceData.push_back(UT_Vector3(0.485069, 0.118689, -0.631736));
	pieceData.push_back(UT_Vector3(0.239099, -0.281026, -0.742001));
	pieceData.push_back(UT_Vector3(0.460696, -0.425029, -0.670000));
	pieceData.push_back(UT_Vector3(0.402140, -0.109594, -0.517594));
	pieceData.push_back(UT_Vector3(0.623738, -0.253597, -0.445593));
	pieceData.push_back(UT_Vector3(0.243068, -0.292290, -0.711559));
	pieceData.push_back(UT_Vector3(0.464665, -0.436293, -0.639558));
	pieceData.push_back(UT_Vector3(0.601620, -0.292290, -0.451056));
	pieceData.push_back(UT_Vector3(0.380023, -0.148287, -0.523058));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CORNER 20
//========================================================================================================
void CCornerComponent::Corner_Red_White_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.927930, -0.186340, 0.301502));
	pieceData.push_back(UT_Vector3(0.927930, -0.014908, 0.024120));
	pieceData.push_back(UT_Vector3(0.764888, -0.014908, 0.525910));
	pieceData.push_back(UT_Vector3(0.764888, 0.156524, 0.248527));
	pieceData.push_back(UT_Vector3(0.914886, -0.172626, 0.319455));
	pieceData.push_back(UT_Vector3(0.777932, -0.028623, 0.507957));
	pieceData.push_back(UT_Vector3(0.914886, -0.001193, 0.042073));
	pieceData.push_back(UT_Vector3(0.777932, 0.142809, 0.230575));
	pieceData.push_back(UT_Vector3(0.764889, -0.463723, 0.248527));
	pieceData.push_back(UT_Vector3(0.913752, -0.210461, 0.296896));
	pieceData.push_back(UT_Vector3(0.764889, -0.292290, -0.028855));
	pieceData.push_back(UT_Vector3(0.913752, -0.039028, 0.019514));
	pieceData.push_back(UT_Vector3(0.750711, -0.039028, 0.521303));
	pieceData.push_back(UT_Vector3(0.601847, -0.292290, 0.472934));
	pieceData.push_back(UT_Vector3(0.601848, -0.120858, 0.195552));
	pieceData.push_back(UT_Vector3(0.750711, 0.132404, 0.243921));
	pieceData.push_back(UT_Vector3(0.751845, -0.450008, 0.266480));
	pieceData.push_back(UT_Vector3(0.900709, -0.196746, 0.314848));
	pieceData.push_back(UT_Vector3(0.763754, -0.052743, 0.503350));
	pieceData.push_back(UT_Vector3(0.614891, -0.306005, 0.454982));
	pieceData.push_back(UT_Vector3(0.900709, -0.025313, 0.037466));
	pieceData.push_back(UT_Vector3(0.751845, -0.278575, -0.010903));
	pieceData.push_back(UT_Vector3(0.614891, -0.134573, 0.177599));
	pieceData.push_back(UT_Vector3(0.763754, 0.118689, 0.225968));
	pieceData.push_back(UT_Vector3(0.616530, -0.095879, 0.200322));
	pieceData.push_back(UT_Vector3(0.629573, -0.109594, 0.182370));
	pieceData.push_back(UT_Vector3(0.766528, -0.253597, -0.006132));
	pieceData.push_back(UT_Vector3(0.779571, -0.267311, -0.024085));
	pieceData.push_back(UT_Vector3(0.779571, -0.438744, 0.253298));
	pieceData.push_back(UT_Vector3(0.766528, -0.425029, 0.271250));
	pieceData.push_back(UT_Vector3(0.629573, -0.281026, 0.459752));
	pieceData.push_back(UT_Vector3(0.616530, -0.267311, 0.477705));
	pieceData.push_back(UT_Vector3(0.927930, -0.028622, 0.046311));
	pieceData.push_back(UT_Vector3(0.927930, -0.172626, 0.279312));
	pieceData.push_back(UT_Vector3(0.764888, 0.142809, 0.270718));
	pieceData.push_back(UT_Vector3(0.764888, -0.001193, 0.503719));
	pieceData.push_back(UT_Vector3(0.914886, -0.158911, 0.297264));
	pieceData.push_back(UT_Vector3(0.914886, -0.014908, 0.064263));
	pieceData.push_back(UT_Vector3(0.777932, 0.129095, 0.252765));
	pieceData.push_back(UT_Vector3(0.777932, -0.014908, 0.485766));
	pieceData.push_back(UT_Vector3(0.913752, -0.052743, 0.041704));
	pieceData.push_back(UT_Vector3(0.913752, -0.196746, 0.274705));
	pieceData.push_back(UT_Vector3(0.764889, -0.450008, 0.226337));
	pieceData.push_back(UT_Vector3(0.764889, -0.306005, -0.006665));
	pieceData.push_back(UT_Vector3(0.601848, -0.134573, 0.217743));
	pieceData.push_back(UT_Vector3(0.601847, -0.278576, 0.450744));
	pieceData.push_back(UT_Vector3(0.750711, -0.025314, 0.499112));
	pieceData.push_back(UT_Vector3(0.750711, 0.118689, 0.266111));
	pieceData.push_back(UT_Vector3(0.779571, -0.281026, -0.001894));
	pieceData.push_back(UT_Vector3(0.779571, -0.425029, 0.231107));
	pieceData.push_back(UT_Vector3(0.616530, -0.109594, 0.222513));
	pieceData.push_back(UT_Vector3(0.616530, -0.253597, 0.455514));
	pieceData.push_back(UT_Vector3(0.751845, -0.292290, 0.011288));
	pieceData.push_back(UT_Vector3(0.751845, -0.436293, 0.244289));
	pieceData.push_back(UT_Vector3(0.614891, -0.292290, 0.432791));
	pieceData.push_back(UT_Vector3(0.614891, -0.148287, 0.199790));

	int faces[216] = { 30, 31, 20, 17,
		50, 43, 44, 49,
		39, 40, 37, 38,
		21, 27, 26, 24,
		51, 52, 47, 48,
		29, 30, 17, 9,
		32, 31, 19, 13,
		35, 36, 40, 39,
		34, 33, 38, 37,
		12, 28, 27, 21,
		15, 25, 26, 23,
		5, 6, 19, 18,
		34, 42, 41, 33,
		24, 8, 7, 21,
		36, 35, 48, 47,
		1, 5, 18, 10,
		6, 3, 13, 19,
		21, 7, 2, 12,
		16, 4, 8, 24,
		18, 19, 31, 30,
		42, 50, 49, 41,
		27, 22, 23, 26,
		45, 46, 52, 51,
		10, 18, 30, 29,
		14, 20, 31, 32,
		28, 11, 22, 27,
		25, 16, 24, 26,
		56, 53, 54, 55,
		43, 54, 53, 44,
		45, 56, 55, 46,
		29, 9, 43, 50,
		11, 28, 49, 44,
		40, 6, 5, 37,
		38, 7, 8, 39,
		52, 32, 13, 47,
		48, 16, 25, 51,
		36, 3, 6, 40,
		39, 8, 4, 35,
		33, 2, 7, 38,
		37, 5, 1, 34,
		1, 10, 42, 34,
		12, 2, 33, 41,
		35, 4, 16, 48,
		47, 13, 3, 36,
		10, 29, 50, 42,
		28, 12, 41, 49,
		46, 14, 32, 52,
		51, 25, 15, 45,
		23, 22, 53, 56,
		17, 20, 55, 54,
		9, 17, 54, 43,
		22, 11, 44, 53,
		15, 23, 56, 45,
		20, 14, 46, 55 };

	for (int i = 0; i < 216; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
void CCornerComponent::buildAllBlackCornerGeometryData(CornerBlackGeometryData &cornerGeometry)
{
	vector<UT_Vector3> pieceData;
	vector<int> faceList;
	vector<int> faceListColor;
	string pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Yellow_Blue_Green(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Yellow_Blue_Green = pieceData;
	cornerGeometry.pieceNameCorner_Yellow_Blue_Green = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Yellow_Blue_White(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Yellow_Blue_White = pieceData;
	cornerGeometry.pieceNameCorner_Yellow_Blue_White = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Yellow_Purple_White(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Yellow_Purple_White = pieceData;
	cornerGeometry.pieceNameCorner_Yellow_Purple_White = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Yellow_Purple_Orange(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Yellow_Purple_Orange = pieceData;
	cornerGeometry.pieceNameCorner_Yellow_Purple_Orange = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Yellow_Green_Orange(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Yellow_Green_Orange = pieceData;
	cornerGeometry.pieceNameCorner_Yellow_Green_Orange = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightGreen_DarkGreen_Red(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightGreen_DarkGreen_Red = pieceData;
	cornerGeometry.pieceNameCorner_LightGreen_DarkGreen_Red = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightGreen_Red_Pink(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightGreen_Red_Pink = pieceData;
	cornerGeometry.pieceNameCorner_LightGreen_Red_Pink = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightGreen_Pink_Gray(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightGreen_Pink_Gray = pieceData;
	cornerGeometry.pieceNameCorner_LightGreen_Pink_Gray = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightGreen_Gray_LightBlue(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightGreen_Gray_LightBlue = pieceData;
	cornerGeometry.pieceNameCorner_LightGreen_Gray_LightBlue = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightGreen_LightBlue_DarkGreen(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightGreen_LightBlue_DarkGreen = pieceData;
	cornerGeometry.pieceNameCorner_LightGreen_LightBlue_DarkGreen = pieceName;


	//----------------------------------------------------------------------------------------------------
	Corner_Purple_DarkGreen_LightBlue(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Purple_DarkGreen_LightBlue = pieceData;
	cornerGeometry.pieceNameCorner_Purple_DarkGreen_LightBlue = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Gray_Orange_LightBlue(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Gray_Orange_LightBlue = pieceData;
	cornerGeometry.pieceNameCorner_Gray_Orange_LightBlue = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Pink_LightGreen_Gray(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Pink_LightGreen_Gray = pieceData;
	cornerGeometry.pieceNameCorner_Pink_LightGreen_Gray = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Red_Blue_Pink(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Red_Blue_Pink = pieceData;
	cornerGeometry.pieceNameCorner_Red_Blue_Pink = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_DarkGreen_White_Red(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_DarkGreen_White_Red = pieceData;
	cornerGeometry.pieceNameCorner_DarkGreen_White_Red = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_DarkGreen_Purple_White(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_DarkGreen_Purple_White = pieceData;
	cornerGeometry.pieceNameCorner_DarkGreen_Purple_White = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_LightBlue_Orange_Purple(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_LightBlue_Orange_Purple = pieceData;
	cornerGeometry.pieceNameCorner_LightBlue_Orange_Purple = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Gray_LightGreen_Orange(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Gray_LightGreen_Orange = pieceData;
	cornerGeometry.pieceNameCorner_Gray_LightGreen_Orange = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Pink_Blue_Green(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Pink_Blue_Green = pieceData;
	cornerGeometry.pieceNameCorner_Pink_Blue_Green = pieceName;

	//----------------------------------------------------------------------------------------------------
	Corner_Red_White_Blue(pieceData, faceList, pieceName);
	cornerGeometry.posCorner_Red_White_Blue = pieceData;
	cornerGeometry.pieceNameCorner_Red_White_Blue = pieceName;

	//----------------------------------------------------------------------------------------------------
	CornerColorPiece(pieceData, faceListColor, pieceName);
	cornerGeometry.posCorner_Color = pieceData;

	cornerGeometry.faceListBlack = faceList;
	cornerGeometry.faceListColor = faceListColor;
}
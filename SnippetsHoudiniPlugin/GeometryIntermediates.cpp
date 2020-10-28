//========================================================================================================
//
//	Arquivo: GeometryIntermediates.cpp
//
//	Descrição:	controi geometria dos intermediarios
//
//========================================================================================================

#include "GeometryIntermediates.h"

//========================================================================================================
//	COLOR PIECE
//========================================================================================================
void CIntermediateComponent::IntermediateColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.413693, 0.800344, 0.134404));
	pieceData.push_back(UT_Vector3(0.213291, 0.800344, -0.001047));
	pieceData.push_back(UT_Vector3(0.172011, 0.800345, 0.126002));
	pieceData.push_back(UT_Vector3(0.213291, 0.778345, -0.001047));
	pieceData.push_back(UT_Vector3(0.413693, 0.778344, 0.134404));
	pieceData.push_back(UT_Vector3(0.172011, 0.778345, 0.126002));
	pieceData.push_back(UT_Vector3(0.397660, 0.800344, 0.123568));
	pieceData.push_back(UT_Vector3(0.229323, 0.800344, 0.009789));
	pieceData.push_back(UT_Vector3(0.191345, 0.800345, 0.126674));
	pieceData.push_back(UT_Vector3(0.394358, 0.800344, 0.133732));
	pieceData.push_back(UT_Vector3(0.229323, 0.778345, 0.009789));
	pieceData.push_back(UT_Vector3(0.397660, 0.778344, 0.123568));
	pieceData.push_back(UT_Vector3(0.394358, 0.778344, 0.133732));
	pieceData.push_back(UT_Vector3(0.191345, 0.778345, 0.126674));
	pieceData.push_back(UT_Vector3(0.209989, 0.800344, 0.009117));
	pieceData.push_back(UT_Vector3(0.175313, 0.800345, 0.115838));
	pieceData.push_back(UT_Vector3(0.175313, 0.778345, 0.115838));
	pieceData.push_back(UT_Vector3(0.209989, 0.778345, 0.009117));
	pieceData.push_back(UT_Vector3(0.226285, 0.800344, 0.019140));
	pieceData.push_back(UT_Vector3(0.194383, 0.800345, 0.117324));
	pieceData.push_back(UT_Vector3(0.378591, 0.800344, 0.122982));

	int faces[63] = { 19, 21, 20,
		10, 21, 7, 1,
		7, 8, 11, 12,
		9, 10, 13, 14,
		15, 16, 17, 18,
		16, 15, 19, 20,
		1, 7, 12, 5,
		4, 11, 8, 2,
		3, 9, 14, 6,
		5, 13, 10, 1,
		2, 15, 18, 4,
		6, 17, 16, 3,
		16, 20, 9, 3,
		8, 19, 15, 2,
		7, 21, 19, 8,
		21, 10, 9, 20 };

	for (int i = 0; i < 63; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 1
//========================================================================================================
void CIntermediateComponent::Intermediate_Yellow_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.000000, 0.789344, 0.487842));
	pieceData.push_back(UT_Vector3(-0.100765, 0.511961, 0.626533));
	pieceData.push_back(UT_Vector3(0.100765, 0.511961, 0.626533));
	pieceData.push_back(UT_Vector3(-0.074046, 0.511961, 0.626533));
	pieceData.push_back(UT_Vector3(0.073799, 0.511961, 0.626533));
	pieceData.push_back(UT_Vector3(0.008762, 0.789344, 0.460875));
	pieceData.push_back(UT_Vector3(0.100765, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(0.109527, 0.511961, 0.599566));
	pieceData.push_back(UT_Vector3(0.201530, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.100765, 0.789345, 0.177719));
	pieceData.push_back(UT_Vector3(-0.008762, 0.789344, 0.460875));
	pieceData.push_back(UT_Vector3(-0.201530, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.109527, 0.511962, 0.599566));
	pieceData.push_back(UT_Vector3(0.174565, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(0.082562, 0.511961, 0.599566));
	pieceData.push_back(UT_Vector3(-0.082808, 0.511962, 0.599566));
	pieceData.push_back(UT_Vector3(-0.174811, 0.511962, 0.316410));
	pieceData.push_back(UT_Vector3(-0.074845, 0.789344, 0.177719));
	pieceData.push_back(UT_Vector3(-0.000012, 0.789344, 0.431160));
	pieceData.push_back(UT_Vector3(0.074620, 0.789345, 0.177719));
	pieceData.push_back(UT_Vector3(-0.008061, 0.767154, 0.498937));
	pieceData.push_back(UT_Vector3(-0.092704, 0.534152, 0.615438));
	pieceData.push_back(UT_Vector3(0.092704, 0.534152, 0.615438));
	pieceData.push_back(UT_Vector3(0.008061, 0.767154, 0.498937));
	pieceData.push_back(UT_Vector3(-0.101466, 0.534152, 0.588471));
	pieceData.push_back(UT_Vector3(-0.016824, 0.767154, 0.471970));
	pieceData.push_back(UT_Vector3(-0.108827, 0.767154, 0.188814));
	pieceData.push_back(UT_Vector3(-0.193469, 0.534152, 0.305315));
	pieceData.push_back(UT_Vector3(0.193469, 0.534152, 0.305315));
	pieceData.push_back(UT_Vector3(0.108826, 0.767154, 0.188814));
	pieceData.push_back(UT_Vector3(0.016823, 0.767154, 0.471970));
	pieceData.push_back(UT_Vector3(0.101466, 0.534152, 0.588471));
	pieceData.push_back(UT_Vector3(-0.066906, 0.534152, 0.615438));
	pieceData.push_back(UT_Vector3(-0.000012, 0.742061, 0.511483));
	pieceData.push_back(UT_Vector3(0.066681, 0.534152, 0.615438));
	pieceData.push_back(UT_Vector3(-0.166814, 0.534152, 0.305315));
	pieceData.push_back(UT_Vector3(0.166569, 0.534152, 0.305315));
	pieceData.push_back(UT_Vector3(-0.082843, 0.767154, 0.188814));
	pieceData.push_back(UT_Vector3(0.082616, 0.767154, 0.188814));
	pieceData.push_back(UT_Vector3(0.091501, 0.789345, 0.206231));
	pieceData.push_back(UT_Vector3(0.192266, 0.511962, 0.344922));
	pieceData.push_back(UT_Vector3(-0.091501, 0.789344, 0.206230));
	pieceData.push_back(UT_Vector3(-0.192266, 0.511962, 0.344922));
	pieceData.push_back(UT_Vector3(0.165301, 0.511962, 0.344922));
	pieceData.push_back(UT_Vector3(-0.165547, 0.511962, 0.344922));
	pieceData.push_back(UT_Vector3(-0.066427, 0.789344, 0.206230));
	pieceData.push_back(UT_Vector3(0.066224, 0.789345, 0.206231));
	pieceData.push_back(UT_Vector3(-0.099563, 0.767154, 0.217326));
	pieceData.push_back(UT_Vector3(-0.184205, 0.534152, 0.333826));
	pieceData.push_back(UT_Vector3(0.099562, 0.767154, 0.217326));
	pieceData.push_back(UT_Vector3(0.184205, 0.534152, 0.333827));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41};

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 2
//========================================================================================================
void CIntermediateComponent::Intermediate_Yellow_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.463966, 0.789344, 0.150751));
	pieceData.push_back(UT_Vector3(-0.627007, 0.511962, 0.097776));
	pieceData.push_back(UT_Vector3(-0.564731, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(-0.618750, 0.511962, 0.123188));
	pieceData.push_back(UT_Vector3(-0.573063, 0.511962, 0.263797));
	pieceData.push_back(UT_Vector3(-0.435610, 0.789344, 0.150751));
	pieceData.push_back(UT_Vector3(-0.137883, 0.789345, 0.150752));
	pieceData.push_back(UT_Vector3(-0.536375, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(-0.238648, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(-0.200159, 0.789345, -0.040915));
	pieceData.push_back(UT_Vector3(-0.441026, 0.789344, 0.134085));
	pieceData.push_back(UT_Vector3(-0.363200, 0.511962, -0.093891));
	pieceData.push_back(UT_Vector3(-0.604067, 0.511962, 0.081109));
	pieceData.push_back(UT_Vector3(-0.246981, 0.511962, 0.263797));
	pieceData.push_back(UT_Vector3(-0.544708, 0.511962, 0.263797));
	pieceData.push_back(UT_Vector3(-0.595810, 0.511962, 0.106521));
	pieceData.push_back(UT_Vector3(-0.354944, 0.511962, -0.068479));
	pieceData.push_back(UT_Vector3(-0.192149, 0.789344, -0.016264));
	pieceData.push_back(UT_Vector3(-0.410061, 0.789344, 0.133224));
	pieceData.push_back(UT_Vector3(-0.145962, 0.789345, 0.125886));
	pieceData.push_back(UT_Vector3(-0.477009, 0.767154, 0.146513));
	pieceData.push_back(UT_Vector3(-0.613963, 0.534152, 0.102014));
	pieceData.push_back(UT_Vector3(-0.556669, 0.534152, 0.278348));
	pieceData.push_back(UT_Vector3(-0.472027, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(-0.591024, 0.534152, 0.085347));
	pieceData.push_back(UT_Vector3(-0.454069, 0.767154, 0.129847));
	pieceData.push_back(UT_Vector3(-0.213202, 0.767154, -0.045153));
	pieceData.push_back(UT_Vector3(-0.350157, 0.534153, -0.089653));
	pieceData.push_back(UT_Vector3(-0.230587, 0.534153, 0.278348));
	pieceData.push_back(UT_Vector3(-0.145944, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(-0.443672, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(-0.528314, 0.534152, 0.278348));
	pieceData.push_back(UT_Vector3(-0.605991, 0.534152, 0.126549));
	pieceData.push_back(UT_Vector3(-0.486454, 0.742061, 0.158046));
	pieceData.push_back(UT_Vector3(-0.564711, 0.534152, 0.253598));
	pieceData.push_back(UT_Vector3(-0.341920, 0.534153, -0.064302));
	pieceData.push_back(UT_Vector3(-0.238899, 0.534152, 0.252764));
	pieceData.push_back(UT_Vector3(-0.205173, 0.767154, -0.020441));
	pieceData.push_back(UT_Vector3(-0.154044, 0.767154, 0.136919));
	pieceData.push_back(UT_Vector3(-0.167862, 0.789345, 0.150752));
	pieceData.push_back(UT_Vector3(-0.268627, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(-0.224412, 0.789345, -0.023294));
	pieceData.push_back(UT_Vector3(-0.387454, 0.511962, -0.076270));
	pieceData.push_back(UT_Vector3(-0.276959, 0.511962, 0.263797));
	pieceData.push_back(UT_Vector3(-0.379197, 0.511962, -0.050858));
	pieceData.push_back(UT_Vector3(-0.216664, 0.789344, 0.000553));
	pieceData.push_back(UT_Vector3(-0.175673, 0.789345, 0.126712));
	pieceData.push_back(UT_Vector3(-0.237456, 0.767154, -0.027532));
	pieceData.push_back(UT_Vector3(-0.374410, 0.534153, -0.072032));
	pieceData.push_back(UT_Vector3(-0.175923, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(-0.260565, 0.534152, 0.278348));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 3
//========================================================================================================
void CIntermediateComponent::Intermediate_Yellow_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.286746, 0.789344, -0.394672));
	pieceData.push_back(UT_Vector3(-0.286746, 0.511962, -0.566104));
	pieceData.push_back(UT_Vector3(-0.449788, 0.511962, -0.447648));
	pieceData.push_back(UT_Vector3(-0.308363, 0.511962, -0.550399));
	pieceData.push_back(UT_Vector3(-0.427972, 0.511962, -0.463498));
	pieceData.push_back(UT_Vector3(-0.277984, 0.789344, -0.367705));
	pieceData.push_back(UT_Vector3(-0.185982, 0.789345, -0.084549));
	pieceData.push_back(UT_Vector3(-0.441026, 0.511962, -0.420681));
	pieceData.push_back(UT_Vector3(-0.349023, 0.511962, -0.137525));
	pieceData.push_back(UT_Vector3(-0.022940, 0.789344, -0.203006));
	pieceData.push_back(UT_Vector3(-0.263807, 0.789344, -0.378006));
	pieceData.push_back(UT_Vector3(-0.022940, 0.511962, -0.374438));
	pieceData.push_back(UT_Vector3(-0.263807, 0.511962, -0.549438));
	pieceData.push_back(UT_Vector3(-0.327207, 0.511962, -0.153375));
	pieceData.push_back(UT_Vector3(-0.419210, 0.511962, -0.436531));
	pieceData.push_back(UT_Vector3(-0.285423, 0.511962, -0.533732));
	pieceData.push_back(UT_Vector3(-0.044556, 0.511962, -0.358732));
	pieceData.push_back(UT_Vector3(-0.043910, 0.789345, -0.187771));
	pieceData.push_back(UT_Vector3(-0.253420, 0.789344, -0.348822));
	pieceData.push_back(UT_Vector3(-0.164830, 0.789345, -0.099917));
	pieceData.push_back(UT_Vector3(-0.286746, 0.767154, -0.408387));
	pieceData.push_back(UT_Vector3(-0.286746, 0.534152, -0.552390));
	pieceData.push_back(UT_Vector3(-0.436745, 0.534152, -0.443410));
	pieceData.push_back(UT_Vector3(-0.299790, 0.767154, -0.398910));
	pieceData.push_back(UT_Vector3(-0.263807, 0.534152, -0.535723));
	pieceData.push_back(UT_Vector3(-0.263807, 0.767154, -0.391720));
	pieceData.push_back(UT_Vector3(-0.022940, 0.767154, -0.216721));
	pieceData.push_back(UT_Vector3(-0.022940, 0.534153, -0.360723));
	pieceData.push_back(UT_Vector3(-0.335980, 0.534153, -0.133287));
	pieceData.push_back(UT_Vector3(-0.199025, 0.767154, -0.088787));
	pieceData.push_back(UT_Vector3(-0.291028, 0.767154, -0.371943));
	pieceData.push_back(UT_Vector3(-0.427982, 0.534152, -0.416443));
	pieceData.push_back(UT_Vector3(-0.307617, 0.534152, -0.537226));
	pieceData.push_back(UT_Vector3(-0.300633, 0.742061, -0.413806));
	pieceData.push_back(UT_Vector3(-0.415692, 0.534152, -0.458706));
	pieceData.push_back(UT_Vector3(-0.044505, 0.534152, -0.345055));
	pieceData.push_back(UT_Vector3(-0.314217, 0.534153, -0.149098));
	pieceData.push_back(UT_Vector3(-0.043961, 0.767154, -0.201448));
	pieceData.push_back(UT_Vector3(-0.177820, 0.767154, -0.104194));
	pieceData.push_back(UT_Vector3(-0.195245, 0.789345, -0.113061));
	pieceData.push_back(UT_Vector3(-0.358287, 0.511962, -0.166036));
	pieceData.push_back(UT_Vector3(-0.047193, 0.789345, -0.220627));
	pieceData.push_back(UT_Vector3(-0.047193, 0.511962, -0.392059));
	pieceData.push_back(UT_Vector3(-0.336471, 0.511962, -0.181886));
	pieceData.push_back(UT_Vector3(-0.068810, 0.511962, -0.376353));
	pieceData.push_back(UT_Vector3(-0.067479, 0.789345, -0.205889));
	pieceData.push_back(UT_Vector3(-0.174796, 0.789345, -0.127918));
	pieceData.push_back(UT_Vector3(-0.047193, 0.767154, -0.234341));
	pieceData.push_back(UT_Vector3(-0.047193, 0.534152, -0.378344));
	pieceData.push_back(UT_Vector3(-0.208289, 0.767154, -0.117299));
	pieceData.push_back(UT_Vector3(-0.345244, 0.534153, -0.161798));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 4
//========================================================================================================
void CIntermediateComponent::Intermediate_Yellow_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.286746, 0.789344, -0.394672));
	pieceData.push_back(UT_Vector3(0.449788, 0.511962, -0.447648));
	pieceData.push_back(UT_Vector3(0.286746, 0.511962, -0.566104));
	pieceData.push_back(UT_Vector3(0.428171, 0.511962, -0.463353));
	pieceData.push_back(UT_Vector3(0.308562, 0.511962, -0.550254));
	pieceData.push_back(UT_Vector3(0.263807, 0.789344, -0.378006));
	pieceData.push_back(UT_Vector3(0.022940, 0.789345, -0.203006));
	pieceData.push_back(UT_Vector3(0.263807, 0.511962, -0.549438));
	pieceData.push_back(UT_Vector3(0.022940, 0.511962, -0.374438));
	pieceData.push_back(UT_Vector3(0.185981, 0.789344, -0.084549));
	pieceData.push_back(UT_Vector3(0.277984, 0.789344, -0.367705));
	pieceData.push_back(UT_Vector3(0.349023, 0.511962, -0.137525));
	pieceData.push_back(UT_Vector3(0.441025, 0.511962, -0.420681));
	pieceData.push_back(UT_Vector3(0.044755, 0.511962, -0.358588));
	pieceData.push_back(UT_Vector3(0.285622, 0.511962, -0.533588));
	pieceData.push_back(UT_Vector3(0.419409, 0.511962, -0.436386));
	pieceData.push_back(UT_Vector3(0.327406, 0.511962, -0.153230));
	pieceData.push_back(UT_Vector3(0.165012, 0.789345, -0.099785));
	pieceData.push_back(UT_Vector3(0.253439, 0.789344, -0.348809));
	pieceData.push_back(UT_Vector3(0.044091, 0.789345, -0.187638));
	pieceData.push_back(UT_Vector3(0.299790, 0.767154, -0.398910));
	pieceData.push_back(UT_Vector3(0.436744, 0.534152, -0.443410));
	pieceData.push_back(UT_Vector3(0.286746, 0.534152, -0.552390));
	pieceData.push_back(UT_Vector3(0.286746, 0.767154, -0.408387));
	pieceData.push_back(UT_Vector3(0.427982, 0.534152, -0.416443));
	pieceData.push_back(UT_Vector3(0.291027, 0.767154, -0.371943));
	pieceData.push_back(UT_Vector3(0.199025, 0.767154, -0.088787));
	pieceData.push_back(UT_Vector3(0.335979, 0.534152, -0.133287));
	pieceData.push_back(UT_Vector3(0.022940, 0.534153, -0.360723));
	pieceData.push_back(UT_Vector3(0.022940, 0.767154, -0.216721));
	pieceData.push_back(UT_Vector3(0.263807, 0.767154, -0.391720));
	pieceData.push_back(UT_Vector3(0.263807, 0.534152, -0.535723));
	pieceData.push_back(UT_Vector3(0.415873, 0.534152, -0.458573));
	pieceData.push_back(UT_Vector3(0.300652, 0.742061, -0.413792));
	pieceData.push_back(UT_Vector3(0.307799, 0.534152, -0.537094));
	pieceData.push_back(UT_Vector3(0.314415, 0.534152, -0.148954));
	pieceData.push_back(UT_Vector3(0.044702, 0.534152, -0.344912));
	pieceData.push_back(UT_Vector3(0.178003, 0.767154, -0.104060));
	pieceData.push_back(UT_Vector3(0.044145, 0.767154, -0.201314));
	pieceData.push_back(UT_Vector3(0.047193, 0.789345, -0.220627));
	pieceData.push_back(UT_Vector3(0.047193, 0.511962, -0.392059));
	pieceData.push_back(UT_Vector3(0.195245, 0.789344, -0.113061));
	pieceData.push_back(UT_Vector3(0.358287, 0.511962, -0.166036));
	pieceData.push_back(UT_Vector3(0.069009, 0.511962, -0.376209));
	pieceData.push_back(UT_Vector3(0.336670, 0.511962, -0.181741));
	pieceData.push_back(UT_Vector3(0.174959, 0.789344, -0.127799));
	pieceData.push_back(UT_Vector3(0.067643, 0.789345, -0.205770));
	pieceData.push_back(UT_Vector3(0.208288, 0.767154, -0.117299));
	pieceData.push_back(UT_Vector3(0.345243, 0.534152, -0.161798));
	pieceData.push_back(UT_Vector3(0.047193, 0.767154, -0.234342));
	pieceData.push_back(UT_Vector3(0.047193, 0.534153, -0.378344));
		
	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 5
//========================================================================================================
void CIntermediateComponent::Intermediate_Yellow_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();
	
	pieceData.push_back(UT_Vector3(0.463965, 0.789344, 0.150752));
	pieceData.push_back(UT_Vector3(0.564730, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(0.627007, 0.511962, 0.097776));
	pieceData.push_back(UT_Vector3(0.572987, 0.511962, 0.264031));
	pieceData.push_back(UT_Vector3(0.618674, 0.511962, 0.123422));
	pieceData.push_back(UT_Vector3(0.441026, 0.789344, 0.134085));
	pieceData.push_back(UT_Vector3(0.200159, 0.789345, -0.040915));
	pieceData.push_back(UT_Vector3(0.604067, 0.511962, 0.081110));
	pieceData.push_back(UT_Vector3(0.363200, 0.511962, -0.093891));
	pieceData.push_back(UT_Vector3(0.137883, 0.789345, 0.150752));
	pieceData.push_back(UT_Vector3(0.435610, 0.789344, 0.150752));
	pieceData.push_back(UT_Vector3(0.238648, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(0.536375, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(0.354867, 0.511962, -0.068245));
	pieceData.push_back(UT_Vector3(0.595734, 0.511962, 0.106755));
	pieceData.push_back(UT_Vector3(0.544632, 0.511962, 0.264031));
	pieceData.push_back(UT_Vector3(0.246904, 0.511962, 0.264031));
	pieceData.push_back(UT_Vector3(0.145892, 0.789345, 0.126100));
	pieceData.push_back(UT_Vector3(0.410053, 0.789344, 0.133247));
	pieceData.push_back(UT_Vector3(0.192080, 0.789345, -0.016050));
	pieceData.push_back(UT_Vector3(0.472026, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(0.556669, 0.534152, 0.278348));
	pieceData.push_back(UT_Vector3(0.613963, 0.534152, 0.102014));
	pieceData.push_back(UT_Vector3(0.477009, 0.767154, 0.146514));
	pieceData.push_back(UT_Vector3(0.528314, 0.534152, 0.278348));
	pieceData.push_back(UT_Vector3(0.443671, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(0.145944, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(0.230586, 0.534153, 0.278348));
	pieceData.push_back(UT_Vector3(0.350157, 0.534153, -0.089653));
	pieceData.push_back(UT_Vector3(0.213202, 0.767154, -0.045153));
	pieceData.push_back(UT_Vector3(0.454069, 0.767154, 0.129847));
	pieceData.push_back(UT_Vector3(0.591024, 0.534152, 0.085348));
	pieceData.push_back(UT_Vector3(0.564641, 0.534152, 0.253812));
	pieceData.push_back(UT_Vector3(0.486446, 0.742061, 0.158069));
	pieceData.push_back(UT_Vector3(0.605922, 0.534152, 0.126763));
	pieceData.push_back(UT_Vector3(0.238823, 0.534153, 0.252997));
	pieceData.push_back(UT_Vector3(0.341844, 0.534152, -0.064069));
	pieceData.push_back(UT_Vector3(0.153973, 0.767154, 0.137135));
	pieceData.push_back(UT_Vector3(0.205103, 0.767154, -0.020225));
	pieceData.push_back(UT_Vector3(0.224412, 0.789345, -0.023294));
	pieceData.push_back(UT_Vector3(0.387454, 0.511962, -0.076270));
	pieceData.push_back(UT_Vector3(0.167861, 0.789345, 0.150752));
	pieceData.push_back(UT_Vector3(0.268626, 0.511962, 0.289443));
	pieceData.push_back(UT_Vector3(0.379121, 0.511962, -0.050623));
	pieceData.push_back(UT_Vector3(0.276883, 0.511962, 0.264031));
	pieceData.push_back(UT_Vector3(0.175610, 0.789345, 0.126904));
	pieceData.push_back(UT_Vector3(0.216601, 0.789345, 0.000746));
	pieceData.push_back(UT_Vector3(0.175922, 0.767154, 0.161847));
	pieceData.push_back(UT_Vector3(0.260565, 0.534153, 0.278348));
	pieceData.push_back(UT_Vector3(0.237455, 0.767154, -0.027532));
	pieceData.push_back(UT_Vector3(0.374410, 0.534153, -0.072031));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 6
//========================================================================================================
void CIntermediateComponent::Intermediate_LightGreen_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.463965, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(0.627007, 0.316409, 0.414186));
	pieceData.push_back(UT_Vector3(0.564730, 0.487841, 0.328470));
	pieceData.push_back(UT_Vector3(0.618750, 0.339138, 0.402822));
	pieceData.push_back(UT_Vector3(0.573063, 0.464903, 0.339939));
	pieceData.push_back(UT_Vector3(0.435610, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(0.137883, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(0.536375, 0.487841, 0.328470));
	pieceData.push_back(UT_Vector3(0.238648, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(0.200159, 0.316409, 0.724309));
	pieceData.push_back(UT_Vector3(0.441025, 0.472934, 0.646047));
	pieceData.push_back(UT_Vector3(0.363200, 0.144977, 0.499902));
	pieceData.push_back(UT_Vector3(0.604067, 0.301502, 0.421640));
	pieceData.push_back(UT_Vector3(0.246981, 0.464903, 0.339939));
	pieceData.push_back(UT_Vector3(0.544708, 0.464903, 0.339939));
	pieceData.push_back(UT_Vector3(0.595810, 0.324231, 0.410275));
	pieceData.push_back(UT_Vector3(0.354943, 0.167706, 0.488538));
	pieceData.push_back(UT_Vector3(0.192149, 0.338458, 0.713285));
	pieceData.push_back(UT_Vector3(0.410061, 0.472164, 0.646432));
	pieceData.push_back(UT_Vector3(0.145962, 0.465601, 0.649713));
	pieceData.push_back(UT_Vector3(0.477009, 0.474126, 0.620641));
	pieceData.push_back(UT_Vector3(0.613963, 0.330124, 0.432139));
	pieceData.push_back(UT_Vector3(0.556669, 0.487841, 0.353280));
	pieceData.push_back(UT_Vector3(0.472026, 0.487841, 0.613784));
	pieceData.push_back(UT_Vector3(0.591024, 0.315216, 0.439592));
	pieceData.push_back(UT_Vector3(0.454069, 0.459219, 0.628094));
	pieceData.push_back(UT_Vector3(0.213202, 0.302695, 0.706357));
	pieceData.push_back(UT_Vector3(0.350157, 0.158692, 0.517855));
	pieceData.push_back(UT_Vector3(0.230587, 0.487842, 0.353280));
	pieceData.push_back(UT_Vector3(0.145944, 0.487841, 0.613784));
	pieceData.push_back(UT_Vector3(0.443671, 0.487841, 0.613784));
	pieceData.push_back(UT_Vector3(0.528314, 0.487841, 0.353280));
	pieceData.push_back(UT_Vector3(0.605991, 0.352069, 0.421166));
	pieceData.push_back(UT_Vector3(0.486453, 0.473219, 0.593040));
	pieceData.push_back(UT_Vector3(0.564711, 0.465705, 0.364348));
	pieceData.push_back(UT_Vector3(0.341920, 0.181366, 0.506517));
	pieceData.push_back(UT_Vector3(0.238899, 0.464959, 0.364721));
	pieceData.push_back(UT_Vector3(0.205173, 0.324798, 0.695305));
	pieceData.push_back(UT_Vector3(0.154043, 0.465545, 0.624932));
	pieceData.push_back(UT_Vector3(0.167861, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(0.268627, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(0.224412, 0.332170, 0.716429));
	pieceData.push_back(UT_Vector3(0.387453, 0.160738, 0.492022));
	pieceData.push_back(UT_Vector3(0.276959, 0.464903, 0.339939));
	pieceData.push_back(UT_Vector3(0.379197, 0.183467, 0.480657));
	pieceData.push_back(UT_Vector3(0.216663, 0.353500, 0.705764));
	pieceData.push_back(UT_Vector3(0.175672, 0.466340, 0.649344));
	pieceData.push_back(UT_Vector3(0.237455, 0.318455, 0.698476));
	pieceData.push_back(UT_Vector3(0.374410, 0.174453, 0.509974));
	pieceData.push_back(UT_Vector3(0.175922, 0.487841, 0.613784));
	pieceData.push_back(UT_Vector3(0.260565, 0.487842, 0.353280));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 7
//========================================================================================================
void CIntermediateComponent::Intermediate_LightGreen_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.463965, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.200159, 0.316409, 0.724309));
	pieceData.push_back(UT_Vector3(-0.137882, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.191902, 0.339138, 0.712945));
	pieceData.push_back(UT_Vector3(-0.146215, 0.464903, 0.650063));
	pieceData.push_back(UT_Vector3(-0.472728, 0.487841, 0.611626));
	pieceData.push_back(UT_Vector3(-0.564730, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(-0.146645, 0.487841, 0.611626));
	pieceData.push_back(UT_Vector3(-0.238647, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(-0.627007, 0.316409, 0.414186));
	pieceData.push_back(UT_Vector3(-0.478143, 0.472934, 0.619080));
	pieceData.push_back(UT_Vector3(-0.363200, 0.144978, 0.499902));
	pieceData.push_back(UT_Vector3(-0.214336, 0.301502, 0.704795));
	pieceData.push_back(UT_Vector3(-0.246980, 0.464903, 0.339940));
	pieceData.push_back(UT_Vector3(-0.154978, 0.464903, 0.623095));
	pieceData.push_back(UT_Vector3(-0.206080, 0.324231, 0.693431));
	pieceData.push_back(UT_Vector3(-0.354943, 0.167706, 0.488537));
	pieceData.push_back(UT_Vector3(-0.618997, 0.338458, 0.403162));
	pieceData.push_back(UT_Vector3(-0.488077, 0.472165, 0.589749));
	pieceData.push_back(UT_Vector3(-0.572810, 0.465602, 0.339590));
	pieceData.push_back(UT_Vector3(-0.442861, 0.474127, 0.645450));
	pieceData.push_back(UT_Vector3(-0.221263, 0.330124, 0.717452));
	pieceData.push_back(UT_Vector3(-0.163969, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.437879, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.235441, 0.315217, 0.697938));
	pieceData.push_back(UT_Vector3(-0.457038, 0.459219, 0.625937));
	pieceData.push_back(UT_Vector3(-0.605902, 0.302695, 0.421043));
	pieceData.push_back(UT_Vector3(-0.384305, 0.158692, 0.493045));
	pieceData.push_back(UT_Vector3(-0.264734, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(-0.538644, 0.487842, 0.328470));
	pieceData.push_back(UT_Vector3(-0.446641, 0.487841, 0.611626));
	pieceData.push_back(UT_Vector3(-0.172731, 0.487841, 0.611626));
	pieceData.push_back(UT_Vector3(-0.213291, 0.352069, 0.706479));
	pieceData.push_back(UT_Vector3(-0.413693, 0.473220, 0.645904));
	pieceData.push_back(UT_Vector3(-0.172011, 0.465705, 0.649662));
	pieceData.push_back(UT_Vector3(-0.376068, 0.181367, 0.481707));
	pieceData.push_back(UT_Vector3(-0.273047, 0.464959, 0.339912));
	pieceData.push_back(UT_Vector3(-0.597873, 0.324798, 0.409992));
	pieceData.push_back(UT_Vector3(-0.546743, 0.465546, 0.339618));
	pieceData.push_back(UT_Vector3(-0.555467, 0.487842, 0.356982));
	pieceData.push_back(UT_Vector3(-0.229384, 0.487842, 0.356982));
	pieceData.push_back(UT_Vector3(-0.612017, 0.332170, 0.434817));
	pieceData.push_back(UT_Vector3(-0.348211, 0.160738, 0.520533));
	pieceData.push_back(UT_Vector3(-0.237716, 0.464903, 0.368451));
	pieceData.push_back(UT_Vector3(-0.339954, 0.183467, 0.509169));
	pieceData.push_back(UT_Vector3(-0.604269, 0.353500, 0.424152));
	pieceData.push_back(UT_Vector3(-0.563277, 0.466340, 0.367733));
	pieceData.push_back(UT_Vector3(-0.590913, 0.318456, 0.441674));
	pieceData.push_back(UT_Vector3(-0.369315, 0.174453, 0.513676));
	pieceData.push_back(UT_Vector3(-0.529380, 0.487842, 0.356982));
	pieceData.push_back(UT_Vector3(-0.255470, 0.487842, 0.356982));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 8
//========================================================================================================
void CIntermediateComponent::Intermediate_LightGreen_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.750712, 0.487842, -0.243921));
	pieceData.push_back(UT_Vector3(-0.486905, 0.487841, -0.435587));
	pieceData.push_back(UT_Vector3(-0.587670, 0.316409, -0.468328));
	pieceData.push_back(UT_Vector3(-0.500265, 0.465113, -0.439928));
	pieceData.push_back(UT_Vector3(-0.574187, 0.339348, -0.463947));
	pieceData.push_back(UT_Vector3(-0.750712, 0.472934, -0.219800));
	pieceData.push_back(UT_Vector3(-0.750712, 0.316410, 0.033462));
	pieceData.push_back(UT_Vector3(-0.587670, 0.301502, -0.444208));
	pieceData.push_back(UT_Vector3(-0.587670, 0.144978, -0.190946));
	pieceData.push_back(UT_Vector3(-0.649946, 0.487842, 0.066202));
	pieceData.push_back(UT_Vector3(-0.741949, 0.487841, -0.216953));
	pieceData.push_back(UT_Vector3(-0.386140, 0.487842, -0.125464));
	pieceData.push_back(UT_Vector3(-0.478143, 0.487842, -0.408620));
	pieceData.push_back(UT_Vector3(-0.574187, 0.167916, -0.186565));
	pieceData.push_back(UT_Vector3(-0.574187, 0.324441, -0.439827));
	pieceData.push_back(UT_Vector3(-0.491503, 0.465113, -0.412961));
	pieceData.push_back(UT_Vector3(-0.399500, 0.465113, -0.129805));
	pieceData.push_back(UT_Vector3(-0.662906, 0.465793, 0.061991));
	pieceData.push_back(UT_Vector3(-0.741497, 0.472185, -0.190228));
	pieceData.push_back(UT_Vector3(-0.737639, 0.338650, 0.037709));
	pieceData.push_back(UT_Vector3(-0.729607, 0.487841, -0.259254));
	pieceData.push_back(UT_Vector3(-0.508010, 0.487842, -0.420254));
	pieceData.push_back(UT_Vector3(-0.600713, 0.330124, -0.450375));
	pieceData.push_back(UT_Vector3(-0.737668, 0.474127, -0.261873));
	pieceData.push_back(UT_Vector3(-0.499247, 0.487842, -0.393287));
	pieceData.push_back(UT_Vector3(-0.720845, 0.487841, -0.232287));
	pieceData.push_back(UT_Vector3(-0.628842, 0.487842, 0.050869));
	pieceData.push_back(UT_Vector3(-0.407244, 0.487842, -0.110131));
	pieceData.push_back(UT_Vector3(-0.600714, 0.158692, -0.172993));
	pieceData.push_back(UT_Vector3(-0.737668, 0.302695, 0.015509));
	pieceData.push_back(UT_Vector3(-0.737668, 0.459220, -0.237753));
	pieceData.push_back(UT_Vector3(-0.600713, 0.315217, -0.426255));
	pieceData.push_back(UT_Vector3(-0.520909, 0.465896, -0.424445));
	pieceData.push_back(UT_Vector3(-0.714325, 0.473241, -0.279381));
	pieceData.push_back(UT_Vector3(-0.587702, 0.352260, -0.446148));
	pieceData.push_back(UT_Vector3(-0.420572, 0.465167, -0.114461));
	pieceData.push_back(UT_Vector3(-0.587263, 0.181575, -0.168623));
	pieceData.push_back(UT_Vector3(-0.641834, 0.465738, 0.046648));
	pieceData.push_back(UT_Vector3(-0.724563, 0.324991, 0.019767));
	pieceData.push_back(UT_Vector3(-0.750712, 0.332170, 0.007960));
	pieceData.push_back(UT_Vector3(-0.587670, 0.160738, -0.216447));
	pieceData.push_back(UT_Vector3(-0.659210, 0.487842, 0.037691));
	pieceData.push_back(UT_Vector3(-0.395404, 0.487842, -0.153976));
	pieceData.push_back(UT_Vector3(-0.574187, 0.183677, -0.212066));
	pieceData.push_back(UT_Vector3(-0.408764, 0.465113, -0.158317));
	pieceData.push_back(UT_Vector3(-0.671748, 0.466512, 0.033617));
	pieceData.push_back(UT_Vector3(-0.738073, 0.353672, 0.012067));
	pieceData.push_back(UT_Vector3(-0.638106, 0.487842, 0.022358));
	pieceData.push_back(UT_Vector3(-0.416508, 0.487842, -0.138642));
	pieceData.push_back(UT_Vector3(-0.737668, 0.318456, -0.009992));
	pieceData.push_back(UT_Vector3(-0.600713, 0.174453, -0.198494));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 9
//========================================================================================================
void CIntermediateComponent::Intermediate_LightGreen_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.000000, 0.487841, -0.789345));
	pieceData.push_back(UT_Vector3(-0.263807, 0.316409, -0.703629));
	pieceData.push_back(UT_Vector3(-0.263807, 0.487841, -0.597678));
	pieceData.push_back(UT_Vector3(-0.263807, 0.339138, -0.689582));
	pieceData.push_back(UT_Vector3(-0.263807, 0.464903, -0.611855));
	pieceData.push_back(UT_Vector3(0.022940, 0.487841, -0.772678));
	pieceData.push_back(UT_Vector3(0.263806, 0.487842, -0.597678));
	pieceData.push_back(UT_Vector3(-0.240867, 0.487841, -0.581011));
	pieceData.push_back(UT_Vector3(-0.000000, 0.487842, -0.406012));
	pieceData.push_back(UT_Vector3(0.263806, 0.316409, -0.703629));
	pieceData.push_back(UT_Vector3(0.022940, 0.472934, -0.781891));
	pieceData.push_back(UT_Vector3(-0.000000, 0.144978, -0.617913));
	pieceData.push_back(UT_Vector3(-0.240867, 0.301502, -0.696175));
	pieceData.push_back(UT_Vector3(-0.000000, 0.464903, -0.420188));
	pieceData.push_back(UT_Vector3(-0.240867, 0.464903, -0.595188));
	pieceData.push_back(UT_Vector3(-0.240867, 0.324231, -0.682128));
	pieceData.push_back(UT_Vector3(-0.000000, 0.167707, -0.603866));
	pieceData.push_back(UT_Vector3(0.263806, 0.338458, -0.690002));
	pieceData.push_back(UT_Vector3(0.048217, 0.472165, -0.764002));
	pieceData.push_back(UT_Vector3(0.263806, 0.465602, -0.611423));
	pieceData.push_back(UT_Vector3(-0.021105, 0.474127, -0.782487));
	pieceData.push_back(UT_Vector3(-0.242702, 0.330124, -0.710486));
	pieceData.push_back(UT_Vector3(-0.242702, 0.487841, -0.613011));
	pieceData.push_back(UT_Vector3(-0.021105, 0.487841, -0.774011));
	pieceData.push_back(UT_Vector3(-0.219762, 0.315217, -0.703032));
	pieceData.push_back(UT_Vector3(0.001835, 0.459219, -0.775034));
	pieceData.push_back(UT_Vector3(0.242702, 0.302695, -0.696772));
	pieceData.push_back(UT_Vector3(0.021104, 0.158692, -0.624770));
	pieceData.push_back(UT_Vector3(0.021104, 0.487842, -0.421345));
	pieceData.push_back(UT_Vector3(0.242702, 0.487842, -0.582345));
	pieceData.push_back(UT_Vector3(0.001835, 0.487841, -0.757345));
	pieceData.push_back(UT_Vector3(-0.219763, 0.487841, -0.596345));
	pieceData.push_back(UT_Vector3(-0.242702, 0.352069, -0.696923));
	pieceData.push_back(UT_Vector3(-0.044969, 0.473220, -0.765710));
	pieceData.push_back(UT_Vector3(-0.242702, 0.465705, -0.626692));
	pieceData.push_back(UT_Vector3(0.021104, 0.181367, -0.610756));
	pieceData.push_back(UT_Vector3(0.021104, 0.464959, -0.435487));
	pieceData.push_back(UT_Vector3(0.242702, 0.324798, -0.683111));
	pieceData.push_back(UT_Vector3(0.242702, 0.465546, -0.596125));
	pieceData.push_back(UT_Vector3(0.239553, 0.487842, -0.615299));
	pieceData.push_back(UT_Vector3(-0.024254, 0.487842, -0.423633));
	pieceData.push_back(UT_Vector3(0.239553, 0.332170, -0.711509));
	pieceData.push_back(UT_Vector3(-0.024253, 0.160738, -0.625793));
	pieceData.push_back(UT_Vector3(-0.024254, 0.464903, -0.437809));
	pieceData.push_back(UT_Vector3(-0.024253, 0.183467, -0.611746));
	pieceData.push_back(UT_Vector3(0.239553, 0.353500, -0.698327));
	pieceData.push_back(UT_Vector3(0.239553, 0.466340, -0.628588));
	pieceData.push_back(UT_Vector3(0.218449, 0.318456, -0.704652));
	pieceData.push_back(UT_Vector3(-0.003149, 0.174453, -0.632650));
	pieceData.push_back(UT_Vector3(0.218448, 0.487842, -0.599966));
	pieceData.push_back(UT_Vector3(-0.003149, 0.487842, -0.438966));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 10
//========================================================================================================
void CIntermediateComponent::Intermediate_LightGreen_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.750712, 0.487841, -0.243921));
	pieceData.push_back(UT_Vector3(0.587670, 0.316409, -0.468328));
	pieceData.push_back(UT_Vector3(0.486905, 0.487841, -0.435588));
	pieceData.push_back(UT_Vector3(0.574310, 0.339138, -0.463987));
	pieceData.push_back(UT_Vector3(0.500388, 0.464903, -0.439969));
	pieceData.push_back(UT_Vector3(0.741949, 0.487841, -0.216954));
	pieceData.push_back(UT_Vector3(0.649946, 0.487841, 0.066202));
	pieceData.push_back(UT_Vector3(0.478143, 0.487841, -0.408621));
	pieceData.push_back(UT_Vector3(0.386140, 0.487842, -0.125465));
	pieceData.push_back(UT_Vector3(0.750712, 0.316409, 0.033462));
	pieceData.push_back(UT_Vector3(0.750711, 0.472934, -0.219801));
	pieceData.push_back(UT_Vector3(0.587670, 0.144977, -0.190946));
	pieceData.push_back(UT_Vector3(0.587670, 0.301502, -0.444208));
	pieceData.push_back(UT_Vector3(0.399623, 0.464903, -0.129846));
	pieceData.push_back(UT_Vector3(0.491626, 0.464903, -0.413001));
	pieceData.push_back(UT_Vector3(0.574310, 0.324231, -0.439867));
	pieceData.push_back(UT_Vector3(0.574310, 0.167706, -0.186605));
	pieceData.push_back(UT_Vector3(0.737752, 0.338458, 0.037673));
	pieceData.push_back(UT_Vector3(0.741509, 0.472164, -0.190233));
	pieceData.push_back(UT_Vector3(0.663019, 0.465601, 0.061955));
	pieceData.push_back(UT_Vector3(0.737668, 0.474126, -0.261874));
	pieceData.push_back(UT_Vector3(0.600713, 0.330124, -0.450376));
	pieceData.push_back(UT_Vector3(0.508009, 0.487841, -0.420254));
	pieceData.push_back(UT_Vector3(0.729607, 0.487841, -0.259254));
	pieceData.push_back(UT_Vector3(0.600713, 0.315217, -0.426255));
	pieceData.push_back(UT_Vector3(0.737668, 0.459219, -0.237753));
	pieceData.push_back(UT_Vector3(0.737668, 0.302695, 0.015509));
	pieceData.push_back(UT_Vector3(0.600713, 0.158692, -0.172993));
	pieceData.push_back(UT_Vector3(0.407244, 0.487842, -0.110131));
	pieceData.push_back(UT_Vector3(0.628842, 0.487841, 0.050869));
	pieceData.push_back(UT_Vector3(0.720845, 0.487841, -0.232287));
	pieceData.push_back(UT_Vector3(0.499247, 0.487841, -0.393287));
	pieceData.push_back(UT_Vector3(0.587814, 0.352069, -0.446185));
	pieceData.push_back(UT_Vector3(0.714337, 0.473219, -0.279385));
	pieceData.push_back(UT_Vector3(0.521021, 0.465705, -0.424482));
	pieceData.push_back(UT_Vector3(0.587386, 0.181367, -0.168663));
	pieceData.push_back(UT_Vector3(0.420694, 0.464959, -0.114502));
	pieceData.push_back(UT_Vector3(0.724676, 0.324798, 0.019730));
	pieceData.push_back(UT_Vector3(0.641947, 0.465545, 0.046611));
	pieceData.push_back(UT_Vector3(0.659210, 0.487841, 0.037691));
	pieceData.push_back(UT_Vector3(0.395404, 0.487842, -0.153976));
	pieceData.push_back(UT_Vector3(0.750712, 0.332170, 0.007960));
	pieceData.push_back(UT_Vector3(0.587670, 0.160738, -0.216447));
	pieceData.push_back(UT_Vector3(0.408887, 0.464903, -0.158357));
	pieceData.push_back(UT_Vector3(0.574310, 0.183467, -0.212106));
	pieceData.push_back(UT_Vector3(0.738174, 0.353500, 0.012034));
	pieceData.push_back(UT_Vector3(0.671849, 0.466340, 0.033584));
	pieceData.push_back(UT_Vector3(0.737668, 0.318455, -0.009992));
	pieceData.push_back(UT_Vector3(0.600713, 0.174453, -0.198494));
	pieceData.push_back(UT_Vector3(0.638106, 0.487841, 0.022357));
	pieceData.push_back(UT_Vector3(0.416508, 0.487842, -0.138643));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 11
//========================================================================================================
void CIntermediateComponent::Intermediate_Green_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.750711, -0.487842, 0.243921));
	pieceData.push_back(UT_Vector3(0.649946, -0.487842, -0.066202));
	pieceData.push_back(UT_Vector3(0.750712, -0.316410, -0.033462));
	pieceData.push_back(UT_Vector3(0.663306, -0.465113, -0.061861));
	pieceData.push_back(UT_Vector3(0.737229, -0.339348, -0.037843));
	pieceData.push_back(UT_Vector3(0.736534, -0.472935, 0.263435));
	pieceData.push_back(UT_Vector3(0.587670, -0.316410, 0.468328));
	pieceData.push_back(UT_Vector3(0.736534, -0.301502, -0.013948));
	pieceData.push_back(UT_Vector3(0.587670, -0.144978, 0.190946));
	pieceData.push_back(UT_Vector3(0.486905, -0.487842, 0.435588));
	pieceData.push_back(UT_Vector3(0.727772, -0.487842, 0.260588));
	pieceData.push_back(UT_Vector3(0.386140, -0.487842, 0.125464));
	pieceData.push_back(UT_Vector3(0.627007, -0.487842, -0.049536));
	pieceData.push_back(UT_Vector3(0.574187, -0.167916, 0.186565));
	pieceData.push_back(UT_Vector3(0.723051, -0.324441, -0.018329));
	pieceData.push_back(UT_Vector3(0.640366, -0.465113, -0.045195));
	pieceData.push_back(UT_Vector3(0.399500, -0.465113, 0.129805));
	pieceData.push_back(UT_Vector3(0.499865, -0.465793, 0.439799));
	pieceData.push_back(UT_Vector3(0.711697, -0.472185, 0.281943));
	pieceData.push_back(UT_Vector3(0.574598, -0.338650, 0.464081));
	pieceData.push_back(UT_Vector3(0.742650, -0.487842, 0.219111));
	pieceData.push_back(UT_Vector3(0.658008, -0.487842, -0.041392));
	pieceData.push_back(UT_Vector3(0.750712, -0.330124, -0.011271));
	pieceData.push_back(UT_Vector3(0.750712, -0.474127, 0.221730));
	pieceData.push_back(UT_Vector3(0.635068, -0.487842, -0.024726));
	pieceData.push_back(UT_Vector3(0.719711, -0.487842, 0.235778));
	pieceData.push_back(UT_Vector3(0.478844, -0.487842, 0.410778));
	pieceData.push_back(UT_Vector3(0.394201, -0.487842, 0.150274));
	pieceData.push_back(UT_Vector3(0.587670, -0.158692, 0.213136));
	pieceData.push_back(UT_Vector3(0.587670, -0.302695, 0.446138));
	pieceData.push_back(UT_Vector3(0.736534, -0.459220, 0.241244));
	pieceData.push_back(UT_Vector3(0.736534, -0.315217, 0.008243));
	pieceData.push_back(UT_Vector3(0.670907, -0.465897, -0.037201));
	pieceData.push_back(UT_Vector3(0.742117, -0.473241, 0.193846));
	pieceData.push_back(UT_Vector3(0.737700, -0.352261, -0.015499));
	pieceData.push_back(UT_Vector3(0.407529, -0.465167, 0.154605));
	pieceData.push_back(UT_Vector3(0.574220, -0.181575, 0.208766));
	pieceData.push_back(UT_Vector3(0.491836, -0.465739, 0.414999));
	pieceData.push_back(UT_Vector3(0.574565, -0.324991, 0.441879));
	pieceData.push_back(UT_Vector3(0.602659, -0.332171, 0.447697));
	pieceData.push_back(UT_Vector3(0.602660, -0.160739, 0.170314));
	pieceData.push_back(UT_Vector3(0.511158, -0.487842, 0.417966));
	pieceData.push_back(UT_Vector3(0.410393, -0.487842, 0.107843));
	pieceData.push_back(UT_Vector3(0.589177, -0.183677, 0.165934));
	pieceData.push_back(UT_Vector3(0.423753, -0.465113, 0.112184));
	pieceData.push_back(UT_Vector3(0.523696, -0.466512, 0.422040));
	pieceData.push_back(UT_Vector3(0.590021, -0.353672, 0.443591));
	pieceData.push_back(UT_Vector3(0.503097, -0.487842, 0.393157));
	pieceData.push_back(UT_Vector3(0.418454, -0.487842, 0.132653));
	pieceData.push_back(UT_Vector3(0.602659, -0.318456, 0.425506));
	pieceData.push_back(UT_Vector3(0.602660, -0.174453, 0.192505));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 12
//========================================================================================================
void CIntermediateComponent::Intermediate_Blue_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.000000, -0.487842, 0.789345));
	pieceData.push_back(UT_Vector3(0.263807, -0.487842, 0.597678));
	pieceData.push_back(UT_Vector3(0.263807, -0.316410, 0.703629));
	pieceData.push_back(UT_Vector3(0.263807, -0.465113, 0.611725));
	pieceData.push_back(UT_Vector3(0.263807, -0.339348, 0.689452));
	pieceData.push_back(UT_Vector3(-0.022940, -0.472934, 0.781891));
	pieceData.push_back(UT_Vector3(-0.263806, -0.316410, 0.703629));
	pieceData.push_back(UT_Vector3(0.240867, -0.301502, 0.696175));
	pieceData.push_back(UT_Vector3(0.000000, -0.144978, 0.617913));
	pieceData.push_back(UT_Vector3(-0.263806, -0.487842, 0.597678));
	pieceData.push_back(UT_Vector3(-0.022940, -0.487841, 0.772678));
	pieceData.push_back(UT_Vector3(0.000000, -0.487842, 0.406011));
	pieceData.push_back(UT_Vector3(0.240867, -0.487842, 0.581011));
	pieceData.push_back(UT_Vector3(0.000000, -0.167916, 0.603736));
	pieceData.push_back(UT_Vector3(0.240867, -0.324441, 0.681998));
	pieceData.push_back(UT_Vector3(0.240867, -0.465113, 0.595059));
	pieceData.push_back(UT_Vector3(0.000000, -0.465113, 0.420059));
	pieceData.push_back(UT_Vector3(-0.263806, -0.465793, 0.611305));
	pieceData.push_back(UT_Vector3(-0.048217, -0.472185, 0.763989));
	pieceData.push_back(UT_Vector3(-0.263807, -0.338650, 0.689884));
	pieceData.push_back(UT_Vector3(0.021105, -0.487842, 0.774011));
	pieceData.push_back(UT_Vector3(0.242702, -0.487842, 0.613011));
	pieceData.push_back(UT_Vector3(0.242702, -0.330124, 0.710486));
	pieceData.push_back(UT_Vector3(0.021105, -0.474127, 0.782487));
	pieceData.push_back(UT_Vector3(0.219762, -0.487842, 0.596345));
	pieceData.push_back(UT_Vector3(-0.001835, -0.487842, 0.757345));
	pieceData.push_back(UT_Vector3(-0.242702, -0.487842, 0.582345));
	pieceData.push_back(UT_Vector3(-0.021104, -0.487842, 0.421345));
	pieceData.push_back(UT_Vector3(-0.021104, -0.158692, 0.624770));
	pieceData.push_back(UT_Vector3(-0.242702, -0.302695, 0.696772));
	pieceData.push_back(UT_Vector3(-0.001835, -0.459220, 0.775034));
	pieceData.push_back(UT_Vector3(0.219762, -0.315217, 0.703032));
	pieceData.push_back(UT_Vector3(0.242702, -0.465896, 0.626574));
	pieceData.push_back(UT_Vector3(0.044969, -0.473241, 0.765697));
	pieceData.push_back(UT_Vector3(0.242702, -0.352261, 0.696805));
	pieceData.push_back(UT_Vector3(-0.021104, -0.465167, 0.435358));
	pieceData.push_back(UT_Vector3(-0.021104, -0.181575, 0.610628));
	pieceData.push_back(UT_Vector3(-0.242702, -0.465739, 0.596005));
	pieceData.push_back(UT_Vector3(-0.242702, -0.324991, 0.682992));
	pieceData.push_back(UT_Vector3(-0.239553, -0.332171, 0.711509));
	pieceData.push_back(UT_Vector3(0.024253, -0.160738, 0.625793));
	pieceData.push_back(UT_Vector3(-0.239553, -0.487842, 0.615299));
	pieceData.push_back(UT_Vector3(0.024253, -0.487842, 0.423632));
	pieceData.push_back(UT_Vector3(0.024253, -0.183677, 0.611617));
	pieceData.push_back(UT_Vector3(0.024253, -0.465113, 0.437680));
	pieceData.push_back(UT_Vector3(-0.239553, -0.466512, 0.628481));
	pieceData.push_back(UT_Vector3(-0.239553, -0.353672, 0.698220));
	pieceData.push_back(UT_Vector3(-0.218449, -0.487842, 0.599966));
	pieceData.push_back(UT_Vector3(0.003149, -0.487842, 0.438966));
	pieceData.push_back(UT_Vector3(-0.218449, -0.318456, 0.704652));
	pieceData.push_back(UT_Vector3(0.003149, -0.174453, 0.632651));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 13
//========================================================================================================
void CIntermediateComponent::Intermediate_White_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.750711, -0.487841, 0.243921));
	pieceData.push_back(UT_Vector3(-0.486905, -0.487841, 0.435587));
	pieceData.push_back(UT_Vector3(-0.587670, -0.316409, 0.468328));
	pieceData.push_back(UT_Vector3(-0.500264, -0.465112, 0.439928));
	pieceData.push_back(UT_Vector3(-0.574187, -0.339348, 0.463947));
	pieceData.push_back(UT_Vector3(-0.750711, -0.472934, 0.219801));
	pieceData.push_back(UT_Vector3(-0.750711, -0.316410, -0.033462));
	pieceData.push_back(UT_Vector3(-0.587670, -0.301502, 0.444208));
	pieceData.push_back(UT_Vector3(-0.587670, -0.144978, 0.190946));
	pieceData.push_back(UT_Vector3(-0.649946, -0.487842, -0.066202));
	pieceData.push_back(UT_Vector3(-0.741949, -0.487841, 0.216954));
	pieceData.push_back(UT_Vector3(-0.386140, -0.487842, 0.125464));
	pieceData.push_back(UT_Vector3(-0.478143, -0.487841, 0.408620));
	pieceData.push_back(UT_Vector3(-0.574187, -0.167916, 0.186565));
	pieceData.push_back(UT_Vector3(-0.574187, -0.324441, 0.439827));
	pieceData.push_back(UT_Vector3(-0.491502, -0.465112, 0.412961));
	pieceData.push_back(UT_Vector3(-0.399499, -0.465113, 0.129805));
	pieceData.push_back(UT_Vector3(-0.662906, -0.465793, -0.061991));
	pieceData.push_back(UT_Vector3(-0.741497, -0.472185, 0.190229));
	pieceData.push_back(UT_Vector3(-0.737639, -0.338650, -0.037709));
	pieceData.push_back(UT_Vector3(-0.729607, -0.487841, 0.259254));
	pieceData.push_back(UT_Vector3(-0.508009, -0.487841, 0.420254));
	pieceData.push_back(UT_Vector3(-0.600713, -0.330124, 0.450376));
	pieceData.push_back(UT_Vector3(-0.737668, -0.474127, 0.261873));
	pieceData.push_back(UT_Vector3(-0.499247, -0.487841, 0.393287));
	pieceData.push_back(UT_Vector3(-0.720845, -0.487841, 0.232287));
	pieceData.push_back(UT_Vector3(-0.628842, -0.487842, -0.050869));
	pieceData.push_back(UT_Vector3(-0.407244, -0.487842, 0.110131));
	pieceData.push_back(UT_Vector3(-0.600713, -0.158692, 0.172993));
	pieceData.push_back(UT_Vector3(-0.737668, -0.302695, -0.015509));
	pieceData.push_back(UT_Vector3(-0.737668, -0.459220, 0.237753));
	pieceData.push_back(UT_Vector3(-0.600713, -0.315217, 0.426255));
	pieceData.push_back(UT_Vector3(-0.520908, -0.465896, 0.424445));
	pieceData.push_back(UT_Vector3(-0.714325, -0.473240, 0.279381));
	pieceData.push_back(UT_Vector3(-0.587702, -0.352260, 0.446148));
	pieceData.push_back(UT_Vector3(-0.420572, -0.465167, 0.114461));
	pieceData.push_back(UT_Vector3(-0.587263, -0.181575, 0.168623));
	pieceData.push_back(UT_Vector3(-0.641834, -0.465738, -0.046648));
	pieceData.push_back(UT_Vector3(-0.724563, -0.324991, -0.019767));
	pieceData.push_back(UT_Vector3(-0.750711, -0.332170, -0.007960));
	pieceData.push_back(UT_Vector3(-0.587670, -0.160738, 0.216447));
	pieceData.push_back(UT_Vector3(-0.659210, -0.487842, -0.037691));
	pieceData.push_back(UT_Vector3(-0.395404, -0.487842, 0.153976));
	pieceData.push_back(UT_Vector3(-0.574187, -0.183677, 0.212066));
	pieceData.push_back(UT_Vector3(-0.408763, -0.465113, 0.158317));
	pieceData.push_back(UT_Vector3(-0.671747, -0.466512, -0.033617));
	pieceData.push_back(UT_Vector3(-0.738073, -0.353672, -0.012067));
	pieceData.push_back(UT_Vector3(-0.638106, -0.487842, -0.022357));
	pieceData.push_back(UT_Vector3(-0.416508, -0.487842, 0.138642));
	pieceData.push_back(UT_Vector3(-0.737668, -0.318456, 0.009992));
	pieceData.push_back(UT_Vector3(-0.600713, -0.174453, 0.198494));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 14
//========================================================================================================
void CIntermediateComponent::Intermediate_Purple_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.463965, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(-0.200159, -0.316409, -0.724309));
	pieceData.push_back(UT_Vector3(-0.137882, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(-0.191902, -0.339138, -0.712945));
	pieceData.push_back(UT_Vector3(-0.146215, -0.464903, -0.650063));
	pieceData.push_back(UT_Vector3(-0.472727, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(-0.564730, -0.487841, -0.328470));
	pieceData.push_back(UT_Vector3(-0.146644, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(-0.238647, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(-0.627007, -0.316409, -0.414186));
	pieceData.push_back(UT_Vector3(-0.478143, -0.472934, -0.619080));
	pieceData.push_back(UT_Vector3(-0.363200, -0.144977, -0.499902));
	pieceData.push_back(UT_Vector3(-0.214336, -0.301502, -0.704796));
	pieceData.push_back(UT_Vector3(-0.246980, -0.464903, -0.339940));
	pieceData.push_back(UT_Vector3(-0.154977, -0.464903, -0.623095));
	pieceData.push_back(UT_Vector3(-0.206079, -0.324231, -0.693431));
	pieceData.push_back(UT_Vector3(-0.354943, -0.167706, -0.488538));
	pieceData.push_back(UT_Vector3(-0.618997, -0.338458, -0.403162));
	pieceData.push_back(UT_Vector3(-0.488077, -0.472164, -0.589749));
	pieceData.push_back(UT_Vector3(-0.572810, -0.465601, -0.339590));
	pieceData.push_back(UT_Vector3(-0.442861, -0.474126, -0.645451));
	pieceData.push_back(UT_Vector3(-0.221263, -0.330124, -0.717452));
	pieceData.push_back(UT_Vector3(-0.163969, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(-0.437879, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(-0.235441, -0.315217, -0.697938));
	pieceData.push_back(UT_Vector3(-0.457038, -0.459219, -0.625937));
	pieceData.push_back(UT_Vector3(-0.605902, -0.302695, -0.421043));
	pieceData.push_back(UT_Vector3(-0.384305, -0.158692, -0.493045));
	pieceData.push_back(UT_Vector3(-0.264734, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(-0.538644, -0.487841, -0.328470));
	pieceData.push_back(UT_Vector3(-0.446641, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(-0.172731, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(-0.213291, -0.352069, -0.706479));
	pieceData.push_back(UT_Vector3(-0.413692, -0.473219, -0.645904));
	pieceData.push_back(UT_Vector3(-0.172010, -0.465705, -0.649662));
	pieceData.push_back(UT_Vector3(-0.376068, -0.181366, -0.481707));
	pieceData.push_back(UT_Vector3(-0.273047, -0.464959, -0.339912));
	pieceData.push_back(UT_Vector3(-0.597873, -0.324798, -0.409992));
	pieceData.push_back(UT_Vector3(-0.546743, -0.465545, -0.339618));
	pieceData.push_back(UT_Vector3(-0.555466, -0.487841, -0.356982));
	pieceData.push_back(UT_Vector3(-0.229383, -0.487842, -0.356982));
	pieceData.push_back(UT_Vector3(-0.612017, -0.332170, -0.434817));
	pieceData.push_back(UT_Vector3(-0.348211, -0.160738, -0.520533));
	pieceData.push_back(UT_Vector3(-0.237716, -0.464903, -0.368451));
	pieceData.push_back(UT_Vector3(-0.339954, -0.183467, -0.509169));
	pieceData.push_back(UT_Vector3(-0.604269, -0.353500, -0.424152));
	pieceData.push_back(UT_Vector3(-0.563277, -0.466340, -0.367733));
	pieceData.push_back(UT_Vector3(-0.590913, -0.318455, -0.441675));
	pieceData.push_back(UT_Vector3(-0.369315, -0.174453, -0.513676));
	pieceData.push_back(UT_Vector3(-0.529380, -0.487841, -0.356982));
	pieceData.push_back(UT_Vector3(-0.255470, -0.487842, -0.356982));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 15
//========================================================================================================
void CIntermediateComponent::Intermediate_Orange_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.463965, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(0.137883, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(0.200159, -0.316409, -0.724309));
	pieceData.push_back(UT_Vector3(0.146139, -0.465112, -0.649958));
	pieceData.push_back(UT_Vector3(0.191826, -0.339348, -0.712840));
	pieceData.push_back(UT_Vector3(0.478143, -0.472934, -0.619079));
	pieceData.push_back(UT_Vector3(0.627007, -0.316410, -0.414186));
	pieceData.push_back(UT_Vector3(0.214336, -0.301502, -0.704795));
	pieceData.push_back(UT_Vector3(0.363200, -0.144978, -0.499902));
	pieceData.push_back(UT_Vector3(0.564730, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(0.472727, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(0.238648, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(0.146645, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(0.354867, -0.167916, -0.488433));
	pieceData.push_back(UT_Vector3(0.206003, -0.324441, -0.693326));
	pieceData.push_back(UT_Vector3(0.154901, -0.465112, -0.622990));
	pieceData.push_back(UT_Vector3(0.246904, -0.465113, -0.339835));
	pieceData.push_back(UT_Vector3(0.572740, -0.465793, -0.339494));
	pieceData.push_back(UT_Vector3(0.488070, -0.472185, -0.589739));
	pieceData.push_back(UT_Vector3(0.618928, -0.338650, -0.403066));
	pieceData.push_back(UT_Vector3(0.437879, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(0.163969, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(0.221263, -0.330124, -0.717452));
	pieceData.push_back(UT_Vector3(0.442861, -0.474127, -0.645450));
	pieceData.push_back(UT_Vector3(0.172731, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(0.446641, -0.487841, -0.611626));
	pieceData.push_back(UT_Vector3(0.538644, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(0.264734, -0.487842, -0.328470));
	pieceData.push_back(UT_Vector3(0.384305, -0.158692, -0.493045));
	pieceData.push_back(UT_Vector3(0.605902, -0.302695, -0.421043));
	pieceData.push_back(UT_Vector3(0.457038, -0.459220, -0.625937));
	pieceData.push_back(UT_Vector3(0.235441, -0.315217, -0.697938));
	pieceData.push_back(UT_Vector3(0.171941, -0.465896, -0.649566));
	pieceData.push_back(UT_Vector3(0.413685, -0.473240, -0.645894));
	pieceData.push_back(UT_Vector3(0.213222, -0.352260, -0.706384));
	pieceData.push_back(UT_Vector3(0.272971, -0.465167, -0.339807));
	pieceData.push_back(UT_Vector3(0.375992, -0.181575, -0.481603));
	pieceData.push_back(UT_Vector3(0.546673, -0.465739, -0.339522));
	pieceData.push_back(UT_Vector3(0.597803, -0.324991, -0.409895));
	pieceData.push_back(UT_Vector3(0.612017, -0.332171, -0.434817));
	pieceData.push_back(UT_Vector3(0.348211, -0.160738, -0.520533));
	pieceData.push_back(UT_Vector3(0.555467, -0.487842, -0.356981));
	pieceData.push_back(UT_Vector3(0.229384, -0.487842, -0.356982));
	pieceData.push_back(UT_Vector3(0.339878, -0.183677, -0.509064));
	pieceData.push_back(UT_Vector3(0.237640, -0.465113, -0.368346));
	pieceData.push_back(UT_Vector3(0.563215, -0.466512, -0.367646));
	pieceData.push_back(UT_Vector3(0.604206, -0.353672, -0.424066));
	pieceData.push_back(UT_Vector3(0.529380, -0.487842, -0.356981));
	pieceData.push_back(UT_Vector3(0.255470, -0.487842, -0.356982));
	pieceData.push_back(UT_Vector3(0.590913, -0.318456, -0.441674));
	pieceData.push_back(UT_Vector3(0.369315, -0.174453, -0.513676));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 16
//========================================================================================================
void CIntermediateComponent::Intermediate_Pink_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.463966, -0.789344, -0.150751));
	pieceData.push_back(UT_Vector3(0.200159, -0.789344, 0.040915));
	pieceData.push_back(UT_Vector3(0.137883, -0.789344, -0.150751));
	pieceData.push_back(UT_Vector3(0.191902, -0.789344, 0.015504));
	pieceData.push_back(UT_Vector3(0.146215, -0.789344, -0.125105));
	pieceData.push_back(UT_Vector3(0.472728, -0.765224, -0.162811));
	pieceData.push_back(UT_Vector3(0.564731, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(0.146645, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(0.238648, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(0.627007, -0.511962, -0.097776));
	pieceData.push_back(UT_Vector3(0.478143, -0.765224, -0.146145));
	pieceData.push_back(UT_Vector3(0.363200, -0.511962, 0.093891));
	pieceData.push_back(UT_Vector3(0.214336, -0.765224, 0.045522));
	pieceData.push_back(UT_Vector3(0.246980, -0.511962, -0.263797));
	pieceData.push_back(UT_Vector3(0.154978, -0.765224, -0.137166));
	pieceData.push_back(UT_Vector3(0.206080, -0.765224, 0.020110));
	pieceData.push_back(UT_Vector3(0.354944, -0.511962, 0.068479));
	pieceData.push_back(UT_Vector3(0.618997, -0.511962, -0.122427));
	pieceData.push_back(UT_Vector3(0.488078, -0.738646, -0.158573));
	pieceData.push_back(UT_Vector3(0.572810, -0.511962, -0.264578));
	pieceData.push_back(UT_Vector3(0.442861, -0.789344, -0.135418));
	pieceData.push_back(UT_Vector3(0.221263, -0.789344, 0.025582));
	pieceData.push_back(UT_Vector3(0.163969, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(0.437879, -0.789344, -0.150751));
	pieceData.push_back(UT_Vector3(0.235441, -0.765224, 0.030189));
	pieceData.push_back(UT_Vector3(0.457039, -0.765224, -0.130811));
	pieceData.push_back(UT_Vector3(0.605902, -0.511962, -0.082443));
	pieceData.push_back(UT_Vector3(0.384305, -0.511962, 0.078557));
	pieceData.push_back(UT_Vector3(0.264734, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(0.538644, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(0.446641, -0.765224, -0.162811));
	pieceData.push_back(UT_Vector3(0.172731, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(0.213291, -0.789344, 0.001047));
	pieceData.push_back(UT_Vector3(0.413693, -0.789344, -0.134404));
	pieceData.push_back(UT_Vector3(0.172011, -0.789344, -0.126002));
	pieceData.push_back(UT_Vector3(0.376068, -0.511962, 0.053206));
	pieceData.push_back(UT_Vector3(0.273047, -0.511962, -0.263859));
	pieceData.push_back(UT_Vector3(0.597873, -0.511962, -0.107155));
	pieceData.push_back(UT_Vector3(0.546743, -0.511962, -0.264515));
	pieceData.push_back(UT_Vector3(0.555467, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(0.229384, -0.537464, -0.276692));
	pieceData.push_back(UT_Vector3(0.612017, -0.537463, -0.102646));
	pieceData.push_back(UT_Vector3(0.348211, -0.537463, 0.089020));
	pieceData.push_back(UT_Vector3(0.237717, -0.537463, -0.251046));
	pieceData.push_back(UT_Vector3(0.339954, -0.537463, 0.063609));
	pieceData.push_back(UT_Vector3(0.604269, -0.537463, -0.126494));
	pieceData.push_back(UT_Vector3(0.563278, -0.537463, -0.252652));
	pieceData.push_back(UT_Vector3(0.590913, -0.537463, -0.087313));
	pieceData.push_back(UT_Vector3(0.369315, -0.537463, 0.073687));
	pieceData.push_back(UT_Vector3(0.529380, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(0.255470, -0.537464, -0.276692));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 17
//========================================================================================================
void CIntermediateComponent::Intermediate_Gray_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.286746, -0.789344, 0.394673));
	pieceData.push_back(UT_Vector3(0.022940, -0.789344, 0.203006));
	pieceData.push_back(UT_Vector3(0.185981, -0.789345, 0.084549));
	pieceData.push_back(UT_Vector3(0.044556, -0.789344, 0.187301));
	pieceData.push_back(UT_Vector3(0.164165, -0.789344, 0.100399));
	pieceData.push_back(UT_Vector3(0.300924, -0.765224, 0.399279));
	pieceData.push_back(UT_Vector3(0.449788, -0.511962, 0.447648));
	pieceData.push_back(UT_Vector3(0.200159, -0.765224, 0.089156));
	pieceData.push_back(UT_Vector3(0.349023, -0.511962, 0.137525));
	pieceData.push_back(UT_Vector3(0.286746, -0.511962, 0.566104));
	pieceData.push_back(UT_Vector3(0.286746, -0.765224, 0.409580));
	pieceData.push_back(UT_Vector3(0.022940, -0.511962, 0.374438));
	pieceData.push_back(UT_Vector3(0.022940, -0.765224, 0.217913));
	pieceData.push_back(UT_Vector3(0.327207, -0.511962, 0.153375));
	pieceData.push_back(UT_Vector3(0.178343, -0.765224, 0.105006));
	pieceData.push_back(UT_Vector3(0.044556, -0.765224, 0.202208));
	pieceData.push_back(UT_Vector3(0.044556, -0.511962, 0.358732));
	pieceData.push_back(UT_Vector3(0.307716, -0.511962, 0.550869));
	pieceData.push_back(UT_Vector3(0.301637, -0.738646, 0.415187));
	pieceData.push_back(UT_Vector3(0.428636, -0.511962, 0.463016));
	pieceData.push_back(UT_Vector3(0.265642, -0.789344, 0.379339));
	pieceData.push_back(UT_Vector3(0.044044, -0.789344, 0.218339));
	pieceData.push_back(UT_Vector3(0.194042, -0.789345, 0.109359));
	pieceData.push_back(UT_Vector3(0.278685, -0.789344, 0.369863));
	pieceData.push_back(UT_Vector3(0.044044, -0.765224, 0.233246));
	pieceData.push_back(UT_Vector3(0.265642, -0.765224, 0.394246));
	pieceData.push_back(UT_Vector3(0.265642, -0.511962, 0.550771));
	pieceData.push_back(UT_Vector3(0.044044, -0.511962, 0.389771));
	pieceData.push_back(UT_Vector3(0.357084, -0.511962, 0.162334));
	pieceData.push_back(UT_Vector3(0.441727, -0.511962, 0.422838));
	pieceData.push_back(UT_Vector3(0.292863, -0.765224, 0.374469));
	pieceData.push_back(UT_Vector3(0.208220, -0.765224, 0.113966));
	pieceData.push_back(UT_Vector3(0.064915, -0.789344, 0.203176));
	pieceData.push_back(UT_Vector3(0.255664, -0.789344, 0.351912));
	pieceData.push_back(UT_Vector3(0.172990, -0.789345, 0.124655));
	pieceData.push_back(UT_Vector3(0.065609, -0.511962, 0.374103));
	pieceData.push_back(UT_Vector3(0.335321, -0.511962, 0.178146));
	pieceData.push_back(UT_Vector3(0.286663, -0.511962, 0.535498));
	pieceData.push_back(UT_Vector3(0.420522, -0.511962, 0.438244));
	pieceData.push_back(UT_Vector3(0.434798, -0.537463, 0.442778));
	pieceData.push_back(UT_Vector3(0.334033, -0.537464, 0.132654));
	pieceData.push_back(UT_Vector3(0.286746, -0.537463, 0.550344));
	pieceData.push_back(UT_Vector3(0.022940, -0.537463, 0.358677));
	pieceData.push_back(UT_Vector3(0.312218, -0.537464, 0.148504));
	pieceData.push_back(UT_Vector3(0.044556, -0.537463, 0.342972));
	pieceData.push_back(UT_Vector3(0.307032, -0.537463, 0.535605));
	pieceData.push_back(UT_Vector3(0.414349, -0.537463, 0.457635));
	pieceData.push_back(UT_Vector3(0.265642, -0.537463, 0.535010));
	pieceData.push_back(UT_Vector3(0.044044, -0.537463, 0.374010));
	pieceData.push_back(UT_Vector3(0.426737, -0.537463, 0.417968));
	pieceData.push_back(UT_Vector3(0.342095, -0.537464, 0.157464));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 18
//========================================================================================================
void CIntermediateComponent::Intermediate_LightBlue_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.286746, -0.789344, 0.394672));
	pieceData.push_back(UT_Vector3(-0.185981, -0.789344, 0.084549));
	pieceData.push_back(UT_Vector3(-0.022940, -0.789345, 0.203006));
	pieceData.push_back(UT_Vector3(-0.164365, -0.789344, 0.100255));
	pieceData.push_back(UT_Vector3(-0.044755, -0.789345, 0.187156));
	pieceData.push_back(UT_Vector3(-0.286746, -0.765224, 0.409579));
	pieceData.push_back(UT_Vector3(-0.286746, -0.511962, 0.566104));
	pieceData.push_back(UT_Vector3(-0.022940, -0.765224, 0.217913));
	pieceData.push_back(UT_Vector3(-0.022940, -0.511962, 0.374438));
	pieceData.push_back(UT_Vector3(-0.449788, -0.511962, 0.447648));
	pieceData.push_back(UT_Vector3(-0.300924, -0.765224, 0.399279));
	pieceData.push_back(UT_Vector3(-0.349023, -0.511962, 0.137525));
	pieceData.push_back(UT_Vector3(-0.200159, -0.765224, 0.089156));
	pieceData.push_back(UT_Vector3(-0.044755, -0.511962, 0.358588));
	pieceData.push_back(UT_Vector3(-0.044755, -0.765224, 0.202063));
	pieceData.push_back(UT_Vector3(-0.178542, -0.765224, 0.104861));
	pieceData.push_back(UT_Vector3(-0.327406, -0.511962, 0.153230));
	pieceData.push_back(UT_Vector3(-0.428818, -0.511962, 0.462883));
	pieceData.push_back(UT_Vector3(-0.301656, -0.738646, 0.415173));
	pieceData.push_back(UT_Vector3(-0.307898, -0.511962, 0.550737));
	pieceData.push_back(UT_Vector3(-0.278685, -0.789344, 0.369863));
	pieceData.push_back(UT_Vector3(-0.194042, -0.789344, 0.109359));
	pieceData.push_back(UT_Vector3(-0.044044, -0.789344, 0.218339));
	pieceData.push_back(UT_Vector3(-0.265642, -0.789344, 0.379339));
	pieceData.push_back(UT_Vector3(-0.208220, -0.765224, 0.113966));
	pieceData.push_back(UT_Vector3(-0.292863, -0.765224, 0.374469));
	pieceData.push_back(UT_Vector3(-0.441727, -0.511962, 0.422838));
	pieceData.push_back(UT_Vector3(-0.357084, -0.511962, 0.162334));
	pieceData.push_back(UT_Vector3(-0.044044, -0.511962, 0.389771));
	pieceData.push_back(UT_Vector3(-0.265642, -0.511962, 0.550771));
	pieceData.push_back(UT_Vector3(-0.265642, -0.765224, 0.394246));
	pieceData.push_back(UT_Vector3(-0.044044, -0.765224, 0.233246));
	pieceData.push_back(UT_Vector3(-0.173171, -0.789344, 0.124523));
	pieceData.push_back(UT_Vector3(-0.255683, -0.789344, 0.351897));
	pieceData.push_back(UT_Vector3(-0.065097, -0.789345, 0.203043));
	pieceData.push_back(UT_Vector3(-0.335519, -0.511962, 0.178002));
	pieceData.push_back(UT_Vector3(-0.065807, -0.511962, 0.373959));
	pieceData.push_back(UT_Vector3(-0.420705, -0.511962, 0.438111));
	pieceData.push_back(UT_Vector3(-0.286847, -0.511962, 0.535365));
	pieceData.push_back(UT_Vector3(-0.286746, -0.537463, 0.550344));
	pieceData.push_back(UT_Vector3(-0.022940, -0.537463, 0.358677));
	pieceData.push_back(UT_Vector3(-0.434798, -0.537463, 0.442777));
	pieceData.push_back(UT_Vector3(-0.334033, -0.537463, 0.132654));
	pieceData.push_back(UT_Vector3(-0.044755, -0.537463, 0.342827));
	pieceData.push_back(UT_Vector3(-0.312417, -0.537463, 0.148360));
	pieceData.push_back(UT_Vector3(-0.414513, -0.537463, 0.457516));
	pieceData.push_back(UT_Vector3(-0.307196, -0.537463, 0.535486));
	pieceData.push_back(UT_Vector3(-0.426737, -0.537463, 0.417967));
	pieceData.push_back(UT_Vector3(-0.342094, -0.537463, 0.157464));
	pieceData.push_back(UT_Vector3(-0.265642, -0.537463, 0.535010));
	pieceData.push_back(UT_Vector3(-0.044044, -0.537463, 0.374010));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 19
//========================================================================================================
void CIntermediateComponent::Intermediate_LightBlue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.463965, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(-0.137882, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(-0.200158, -0.789344, 0.040915));
	pieceData.push_back(UT_Vector3(-0.146139, -0.789344, -0.125340));
	pieceData.push_back(UT_Vector3(-0.191826, -0.789344, 0.015269));
	pieceData.push_back(UT_Vector3(-0.478143, -0.765224, -0.146145));
	pieceData.push_back(UT_Vector3(-0.627007, -0.511962, -0.097776));
	pieceData.push_back(UT_Vector3(-0.214336, -0.765224, 0.045522));
	pieceData.push_back(UT_Vector3(-0.363200, -0.511962, 0.093891));
	pieceData.push_back(UT_Vector3(-0.564730, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(-0.472727, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(-0.238647, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(-0.146644, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(-0.354867, -0.511962, 0.068245));
	pieceData.push_back(UT_Vector3(-0.206003, -0.765224, 0.019876));
	pieceData.push_back(UT_Vector3(-0.154901, -0.765224, -0.137400));
	pieceData.push_back(UT_Vector3(-0.246904, -0.511962, -0.264031));
	pieceData.push_back(UT_Vector3(-0.572740, -0.511962, -0.264792));
	pieceData.push_back(UT_Vector3(-0.488070, -0.738646, -0.158596));
	pieceData.push_back(UT_Vector3(-0.618927, -0.511962, -0.122641));
	pieceData.push_back(UT_Vector3(-0.437878, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(-0.163969, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(-0.221263, -0.789344, 0.025582));
	pieceData.push_back(UT_Vector3(-0.442861, -0.789344, -0.135418));
	pieceData.push_back(UT_Vector3(-0.172731, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(-0.446641, -0.765224, -0.162812));
	pieceData.push_back(UT_Vector3(-0.538644, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(-0.264734, -0.511962, -0.289443));
	pieceData.push_back(UT_Vector3(-0.384304, -0.511962, 0.078557));
	pieceData.push_back(UT_Vector3(-0.605902, -0.511962, -0.082443));
	pieceData.push_back(UT_Vector3(-0.457038, -0.765224, -0.130812));
	pieceData.push_back(UT_Vector3(-0.235441, -0.765224, 0.030188));
	pieceData.push_back(UT_Vector3(-0.171941, -0.789344, -0.126216));
	pieceData.push_back(UT_Vector3(-0.413685, -0.789344, -0.134427));
	pieceData.push_back(UT_Vector3(-0.213222, -0.789344, 0.000833));
	pieceData.push_back(UT_Vector3(-0.272971, -0.511962, -0.264092));
	pieceData.push_back(UT_Vector3(-0.375992, -0.511962, 0.052974));
	pieceData.push_back(UT_Vector3(-0.546673, -0.511962, -0.264731));
	pieceData.push_back(UT_Vector3(-0.597803, -0.511962, -0.107371));
	pieceData.push_back(UT_Vector3(-0.612017, -0.537463, -0.102647));
	pieceData.push_back(UT_Vector3(-0.348211, -0.537463, 0.089020));
	pieceData.push_back(UT_Vector3(-0.555466, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(-0.229383, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(-0.339878, -0.537463, 0.063374));
	pieceData.push_back(UT_Vector3(-0.237640, -0.537463, -0.251280));
	pieceData.push_back(UT_Vector3(-0.563215, -0.537463, -0.252845));
	pieceData.push_back(UT_Vector3(-0.604206, -0.537463, -0.126686));
	pieceData.push_back(UT_Vector3(-0.529380, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(-0.255470, -0.537463, -0.276692));
	pieceData.push_back(UT_Vector3(-0.590913, -0.537463, -0.087313));
	pieceData.push_back(UT_Vector3(-0.369315, -0.537463, 0.073687));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 20
//========================================================================================================
void CIntermediateComponent::Intermediate_Green_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.000000, -0.789344, -0.487842));
	pieceData.push_back(UT_Vector3(0.100765, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(-0.100765, -0.789345, -0.177719));
	pieceData.push_back(UT_Vector3(0.074046, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(-0.073799, -0.789344, -0.177719));
	pieceData.push_back(UT_Vector3(-0.008762, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(-0.100765, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(-0.109527, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(-0.201530, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.100765, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.008762, -0.765224, -0.499902));
	pieceData.push_back(UT_Vector3(0.201530, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.109528, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(-0.174564, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(-0.082561, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.082808, -0.765224, -0.189779));
	pieceData.push_back(UT_Vector3(0.174811, -0.511962, -0.316410));
	pieceData.push_back(UT_Vector3(0.074845, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.000012, -0.738646, -0.513191));
	pieceData.push_back(UT_Vector3(-0.074620, -0.511962, -0.626533));
	pieceData.push_back(UT_Vector3(0.008062, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.092704, -0.789344, -0.202529));
	pieceData.push_back(UT_Vector3(-0.092704, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(-0.008061, -0.789344, -0.463032));
	pieceData.push_back(UT_Vector3(0.101466, -0.765224, -0.214589));
	pieceData.push_back(UT_Vector3(0.016824, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(0.108827, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(0.193469, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.193469, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.108826, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.016823, -0.765224, -0.475092));
	pieceData.push_back(UT_Vector3(-0.101466, -0.765224, -0.214589));
	pieceData.push_back(UT_Vector3(0.066906, -0.789344, -0.202528));
	pieceData.push_back(UT_Vector3(0.000012, -0.789344, -0.434978));
	pieceData.push_back(UT_Vector3(-0.066681, -0.789345, -0.202528));
	pieceData.push_back(UT_Vector3(0.166814, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(-0.166569, -0.511962, -0.341220));
	pieceData.push_back(UT_Vector3(0.082843, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.082616, -0.511962, -0.601723));
	pieceData.push_back(UT_Vector3(-0.091501, -0.537463, -0.613783));
	pieceData.push_back(UT_Vector3(-0.192266, -0.537463, -0.303659));
	pieceData.push_back(UT_Vector3(0.091501, -0.537463, -0.613782));
	pieceData.push_back(UT_Vector3(0.192267, -0.537463, -0.303659));
	pieceData.push_back(UT_Vector3(-0.165301, -0.537463, -0.303659));
	pieceData.push_back(UT_Vector3(0.165547, -0.537463, -0.303659));
	pieceData.push_back(UT_Vector3(0.066427, -0.537463, -0.613782));
	pieceData.push_back(UT_Vector3(-0.066224, -0.537463, -0.613782));
	pieceData.push_back(UT_Vector3(0.099563, -0.537463, -0.588973));
	pieceData.push_back(UT_Vector3(0.184205, -0.537463, -0.328469));
	pieceData.push_back(UT_Vector3(-0.099562, -0.537463, -0.588973));
	pieceData.push_back(UT_Vector3(-0.184205, -0.537463, -0.328469));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 21
//========================================================================================================
void CIntermediateComponent::Intermediate_Pink_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.286746, 0.000001, -0.882514));
	pieceData.push_back(UT_Vector3(-0.022940, -0.171431, -0.796798));
	pieceData.push_back(UT_Vector3(-0.185981, -0.277382, -0.743823));
	pieceData.push_back(UT_Vector3(-0.044556, -0.185478, -0.789775));
	pieceData.push_back(UT_Vector3(-0.164165, -0.263205, -0.750911));
	pieceData.push_back(UT_Vector3(-0.300924, 0.014908, -0.863000));
	pieceData.push_back(UT_Vector3(-0.449788, 0.171433, -0.658107));
	pieceData.push_back(UT_Vector3(-0.200159, -0.262475, -0.724309));
	pieceData.push_back(UT_Vector3(-0.349023, -0.105950, -0.519416));
	pieceData.push_back(UT_Vector3(-0.286746, 0.277383, -0.711082));
	pieceData.push_back(UT_Vector3(-0.286746, 0.024121, -0.867607));
	pieceData.push_back(UT_Vector3(-0.022940, 0.105951, -0.625366));
	pieceData.push_back(UT_Vector3(-0.022940, -0.147311, -0.781891));
	pieceData.push_back(UT_Vector3(-0.327207, -0.091774, -0.526504));
	pieceData.push_back(UT_Vector3(-0.178343, -0.248298, -0.731398));
	pieceData.push_back(UT_Vector3(-0.044556, -0.161358, -0.774867));
	pieceData.push_back(UT_Vector3(-0.044556, 0.091904, -0.618343));
	pieceData.push_back(UT_Vector3(-0.307716, 0.263757, -0.704268));
	pieceData.push_back(UT_Vector3(-0.301636, 0.041023, -0.846343));
	pieceData.push_back(UT_Vector3(-0.428636, 0.185178, -0.664979));
	pieceData.push_back(UT_Vector3(-0.265642, -0.013713, -0.875657));
	pieceData.push_back(UT_Vector3(-0.044044, -0.157716, -0.803655));
	pieceData.push_back(UT_Vector3(-0.194042, -0.255191, -0.754918));
	pieceData.push_back(UT_Vector3(-0.278685, -0.022190, -0.871419));
	pieceData.push_back(UT_Vector3(-0.044044, -0.133596, -0.788748));
	pieceData.push_back(UT_Vector3(-0.265642, 0.010407, -0.860750));
	pieceData.push_back(UT_Vector3(-0.265642, 0.263669, -0.704225));
	pieceData.push_back(UT_Vector3(-0.044044, 0.119666, -0.632223));
	pieceData.push_back(UT_Vector3(-0.357084, -0.083760, -0.530511));
	pieceData.push_back(UT_Vector3(-0.441726, 0.149242, -0.647012));
	pieceData.push_back(UT_Vector3(-0.292862, -0.007282, -0.851905));
	pieceData.push_back(UT_Vector3(-0.208220, -0.240284, -0.735405));
	pieceData.push_back(UT_Vector3(-0.064915, -0.171279, -0.796874));
	pieceData.push_back(UT_Vector3(-0.255664, -0.038245, -0.863391));
	pieceData.push_back(UT_Vector3(-0.172989, -0.241510, -0.761759));
	pieceData.push_back(UT_Vector3(-0.065609, 0.105652, -0.625217));
	pieceData.push_back(UT_Vector3(-0.335321, -0.069617, -0.537582));
	pieceData.push_back(UT_Vector3(-0.286663, 0.250008, -0.697394));
	pieceData.push_back(UT_Vector3(-0.420522, 0.163022, -0.653901));
	pieceData.push_back(UT_Vector3(-0.434798, 0.155672, -0.678738));
	pieceData.push_back(UT_Vector3(-0.334033, -0.121711, -0.540047));
	pieceData.push_back(UT_Vector3(-0.286746, 0.251882, -0.726843));
	pieceData.push_back(UT_Vector3(-0.022940, 0.080450, -0.641127));
	pieceData.push_back(UT_Vector3(-0.312217, -0.107534, -0.547135));
	pieceData.push_back(UT_Vector3(-0.044556, 0.066403, -0.634103));
	pieceData.push_back(UT_Vector3(-0.307032, 0.238700, -0.720251));
	pieceData.push_back(UT_Vector3(-0.414349, 0.168961, -0.685382));
	pieceData.push_back(UT_Vector3(-0.265642, 0.238168, -0.719985));
	pieceData.push_back(UT_Vector3(-0.044044, 0.094165, -0.647984));
	pieceData.push_back(UT_Vector3(-0.426737, 0.133481, -0.667643));
	pieceData.push_back(UT_Vector3(-0.342094, -0.099520, -0.551142));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 22
//========================================================================================================
void CIntermediateComponent::Intermediate_Red_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.286747, 0.000001, -0.882514));
	pieceData.push_back(UT_Vector3(0.185981, -0.277382, -0.743823));
	pieceData.push_back(UT_Vector3(0.022940, -0.171431, -0.796798));
	pieceData.push_back(UT_Vector3(0.164365, -0.263335, -0.750846));
	pieceData.push_back(UT_Vector3(0.044756, -0.185608, -0.789710));
	pieceData.push_back(UT_Vector3(0.286746, 0.024121, -0.867607));
	pieceData.push_back(UT_Vector3(0.286746, 0.277383, -0.711082));
	pieceData.push_back(UT_Vector3(0.022940, -0.147311, -0.781891));
	pieceData.push_back(UT_Vector3(0.022940, 0.105951, -0.625366));
	pieceData.push_back(UT_Vector3(0.449788, 0.171432, -0.658106));
	pieceData.push_back(UT_Vector3(0.300924, 0.014908, -0.863000));
	pieceData.push_back(UT_Vector3(0.349023, -0.105950, -0.519415));
	pieceData.push_back(UT_Vector3(0.200159, -0.262475, -0.724309));
	pieceData.push_back(UT_Vector3(0.044755, 0.091775, -0.618278));
	pieceData.push_back(UT_Vector3(0.044756, -0.161488, -0.774803));
	pieceData.push_back(UT_Vector3(0.178542, -0.248428, -0.731333));
	pieceData.push_back(UT_Vector3(0.327406, -0.091903, -0.526439));
	pieceData.push_back(UT_Vector3(0.428818, 0.185059, -0.664920));
	pieceData.push_back(UT_Vector3(0.301656, 0.041010, -0.846336));
	pieceData.push_back(UT_Vector3(0.307898, 0.263638, -0.704209));
	pieceData.push_back(UT_Vector3(0.278685, -0.022190, -0.871418));
	pieceData.push_back(UT_Vector3(0.194043, -0.255191, -0.754918));
	pieceData.push_back(UT_Vector3(0.044044, -0.157717, -0.803656));
	pieceData.push_back(UT_Vector3(0.265642, -0.013714, -0.875656));
	pieceData.push_back(UT_Vector3(0.208220, -0.240284, -0.735404));
	pieceData.push_back(UT_Vector3(0.292863, -0.007283, -0.851905));
	pieceData.push_back(UT_Vector3(0.441727, 0.149242, -0.647011));
	pieceData.push_back(UT_Vector3(0.357084, -0.083760, -0.530511));
	pieceData.push_back(UT_Vector3(0.044044, 0.119666, -0.632224));
	pieceData.push_back(UT_Vector3(0.265642, 0.263669, -0.704225));
	pieceData.push_back(UT_Vector3(0.265642, 0.010406, -0.860749));
	pieceData.push_back(UT_Vector3(0.044044, -0.133596, -0.788748));
	pieceData.push_back(UT_Vector3(0.173172, -0.241629, -0.761699));
	pieceData.push_back(UT_Vector3(0.255684, -0.038258, -0.863384));
	pieceData.push_back(UT_Vector3(0.065097, -0.171398, -0.796815));
	pieceData.push_back(UT_Vector3(0.335519, -0.069746, -0.537517));
	pieceData.push_back(UT_Vector3(0.065807, 0.105524, -0.625152));
	pieceData.push_back(UT_Vector3(0.420705, 0.162902, -0.653841));
	pieceData.push_back(UT_Vector3(0.286847, 0.249889, -0.697335));
	pieceData.push_back(UT_Vector3(0.286746, 0.251882, -0.726843));
	pieceData.push_back(UT_Vector3(0.022940, 0.080450, -0.641127));
	pieceData.push_back(UT_Vector3(0.434799, 0.155672, -0.678738));
	pieceData.push_back(UT_Vector3(0.334033, -0.121711, -0.540047));
	pieceData.push_back(UT_Vector3(0.044755, 0.066273, -0.634039));
	pieceData.push_back(UT_Vector3(0.312417, -0.107664, -0.547070));
	pieceData.push_back(UT_Vector3(0.414513, 0.168854, -0.685329));
	pieceData.push_back(UT_Vector3(0.307196, 0.238593, -0.720198));
	pieceData.push_back(UT_Vector3(0.426737, 0.133481, -0.667642));
	pieceData.push_back(UT_Vector3(0.342095, -0.099520, -0.551142));
	pieceData.push_back(UT_Vector3(0.265642, 0.238167, -0.719985));
	pieceData.push_back(UT_Vector3(0.044044, 0.094164, -0.647984));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 23
//========================================================================================================
void CIntermediateComponent::Intermediate_Red_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.750711, -0.000001, -0.545424));
	pieceData.push_back(UT_Vector3(0.486905, 0.171431, -0.631140));
	pieceData.push_back(UT_Vector3(0.587670, 0.277382, -0.492449));
	pieceData.push_back(UT_Vector3(0.500264, 0.185478, -0.612752));
	pieceData.push_back(UT_Vector3(0.574187, 0.263205, -0.511006));
	pieceData.push_back(UT_Vector3(0.750711, -0.014908, -0.521303));
	pieceData.push_back(UT_Vector3(0.750711, -0.171433, -0.268041));
	pieceData.push_back(UT_Vector3(0.587670, 0.262475, -0.468328));
	pieceData.push_back(UT_Vector3(0.587670, 0.105950, -0.215066));
	pieceData.push_back(UT_Vector3(0.649946, -0.277384, -0.406732));
	pieceData.push_back(UT_Vector3(0.741949, -0.024121, -0.533364));
	pieceData.push_back(UT_Vector3(0.386140, -0.105951, -0.492448));
	pieceData.push_back(UT_Vector3(0.478142, 0.147311, -0.619080));
	pieceData.push_back(UT_Vector3(0.574187, 0.091774, -0.233623));
	pieceData.push_back(UT_Vector3(0.574187, 0.248298, -0.486886));
	pieceData.push_back(UT_Vector3(0.491502, 0.161358, -0.600692));
	pieceData.push_back(UT_Vector3(0.399499, -0.091904, -0.474060));
	pieceData.push_back(UT_Vector3(0.662906, -0.263757, -0.388894));
	pieceData.push_back(UT_Vector3(0.741497, -0.041023, -0.507408));
	pieceData.push_back(UT_Vector3(0.737639, -0.185178, -0.286034));
	pieceData.push_back(UT_Vector3(0.729607, 0.013713, -0.552281));
	pieceData.push_back(UT_Vector3(0.508009, 0.157716, -0.624282));
	pieceData.push_back(UT_Vector3(0.600713, 0.255191, -0.496687));
	pieceData.push_back(UT_Vector3(0.737668, 0.022190, -0.541186));
	pieceData.push_back(UT_Vector3(0.499247, 0.133596, -0.612222));
	pieceData.push_back(UT_Vector3(0.720844, -0.010407, -0.540221));
	pieceData.push_back(UT_Vector3(0.628841, -0.263669, -0.413590));
	pieceData.push_back(UT_Vector3(0.407244, -0.119666, -0.485591));
	pieceData.push_back(UT_Vector3(0.600713, 0.083760, -0.219304));
	pieceData.push_back(UT_Vector3(0.737668, -0.149242, -0.263803));
	pieceData.push_back(UT_Vector3(0.737668, 0.007282, -0.517065));
	pieceData.push_back(UT_Vector3(0.600713, 0.240284, -0.472566));
	pieceData.push_back(UT_Vector3(0.520908, 0.171279, -0.606529));
	pieceData.push_back(UT_Vector3(0.714325, 0.038245, -0.548223));
	pieceData.push_back(UT_Vector3(0.587702, 0.241510, -0.514595));
	pieceData.push_back(UT_Vector3(0.420572, -0.105652, -0.467247));
	pieceData.push_back(UT_Vector3(0.587263, 0.069617, -0.237816));
	pieceData.push_back(UT_Vector3(0.641833, -0.250008, -0.395708));
	pieceData.push_back(UT_Vector3(0.724563, -0.163022, -0.281841));
	pieceData.push_back(UT_Vector3(0.750711, -0.155672, -0.293543));
	pieceData.push_back(UT_Vector3(0.587670, 0.121711, -0.240567));
	pieceData.push_back(UT_Vector3(0.659210, -0.251882, -0.419483));
	pieceData.push_back(UT_Vector3(0.395403, -0.080450, -0.505199));
	pieceData.push_back(UT_Vector3(0.574187, 0.107534, -0.259125));
	pieceData.push_back(UT_Vector3(0.408763, -0.066403, -0.486811));
	pieceData.push_back(UT_Vector3(0.671747, -0.238700, -0.402227));
	pieceData.push_back(UT_Vector3(0.738073, -0.168961, -0.310938));
	pieceData.push_back(UT_Vector3(0.638105, -0.238168, -0.426340));
	pieceData.push_back(UT_Vector3(0.416508, -0.094165, -0.498342));
	pieceData.push_back(UT_Vector3(0.737668, -0.133481, -0.289304));
	pieceData.push_back(UT_Vector3(0.600713, 0.099520, -0.244805));
		
	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 24
//========================================================================================================
void CIntermediateComponent::Intermediate_White_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.927930, 0.000001, 0.000000));
	pieceData.push_back(UT_Vector3(0.764889, -0.277382, -0.052975));
	pieceData.push_back(UT_Vector3(0.764889, -0.171431, -0.224407));
	pieceData.push_back(UT_Vector3(0.764889, -0.263335, -0.075704));
	pieceData.push_back(UT_Vector3(0.764889, -0.185608, -0.201469));
	pieceData.push_back(UT_Vector3(0.913753, 0.024121, 0.004607));
	pieceData.push_back(UT_Vector3(0.764889, 0.277383, 0.052976));
	pieceData.push_back(UT_Vector3(0.750711, -0.147311, -0.219801));
	pieceData.push_back(UT_Vector3(0.601847, 0.105951, -0.171432));
	pieceData.push_back(UT_Vector3(0.764889, 0.171432, 0.224408));
	pieceData.push_back(UT_Vector3(0.913753, 0.014908, 0.019514));
	pieceData.push_back(UT_Vector3(0.601848, -0.105950, 0.171432));
	pieceData.push_back(UT_Vector3(0.750711, -0.262475, -0.033462));
	pieceData.push_back(UT_Vector3(0.601847, 0.091774, -0.148493));
	pieceData.push_back(UT_Vector3(0.750711, -0.161488, -0.196862));
	pieceData.push_back(UT_Vector3(0.750711, -0.248428, -0.056190));
	pieceData.push_back(UT_Vector3(0.601848, -0.091903, 0.148703));
	pieceData.push_back(UT_Vector3(0.764889, 0.185059, 0.202359));
	pieceData.push_back(UT_Vector3(0.898130, 0.041010, 0.025359));
	pieceData.push_back(UT_Vector3(0.764889, 0.263638, 0.075216));
	pieceData.push_back(UT_Vector3(0.914887, -0.022190, -0.004238));
	pieceData.push_back(UT_Vector3(0.777932, -0.255192, -0.048737));
	pieceData.push_back(UT_Vector3(0.777932, -0.157717, -0.206455));
	pieceData.push_back(UT_Vector3(0.914887, -0.013714, -0.017952));
	pieceData.push_back(UT_Vector3(0.763755, -0.240284, -0.029224));
	pieceData.push_back(UT_Vector3(0.900709, -0.007283, 0.015276));
	pieceData.push_back(UT_Vector3(0.751845, 0.149242, 0.220170));
	pieceData.push_back(UT_Vector3(0.614891, -0.083760, 0.175670));
	pieceData.push_back(UT_Vector3(0.614891, 0.119666, -0.153479));
	pieceData.push_back(UT_Vector3(0.751845, 0.263669, 0.035023));
	pieceData.push_back(UT_Vector3(0.900709, 0.010406, -0.013346));
	pieceData.push_back(UT_Vector3(0.763755, -0.133597, -0.201848));
	pieceData.push_back(UT_Vector3(0.777932, -0.241629, -0.070682));
	pieceData.push_back(UT_Vector3(0.900138, -0.038259, -0.023631));
	pieceData.push_back(UT_Vector3(0.777932, -0.171398, -0.184318));
	pieceData.push_back(UT_Vector3(0.614891, -0.069746, 0.152996));
	pieceData.push_back(UT_Vector3(0.614891, 0.105523, -0.130597));
	pieceData.push_back(UT_Vector3(0.751845, 0.162902, 0.198066));
	pieceData.push_back(UT_Vector3(0.751845, 0.249889, 0.057319));
	pieceData.push_back(UT_Vector3(0.779878, 0.251882, 0.048105));
	pieceData.push_back(UT_Vector3(0.616837, 0.080450, -0.176302));
	pieceData.push_back(UT_Vector3(0.779878, 0.155671, 0.203776));
	pieceData.push_back(UT_Vector3(0.616837, -0.121711, 0.150801));
	pieceData.push_back(UT_Vector3(0.616837, 0.066273, -0.153364));
	pieceData.push_back(UT_Vector3(0.616837, -0.107664, 0.128072));
	pieceData.push_back(UT_Vector3(0.779878, 0.168854, 0.182447));
	pieceData.push_back(UT_Vector3(0.779878, 0.238593, 0.069607));
	pieceData.push_back(UT_Vector3(0.766835, 0.133481, 0.199538));
	pieceData.push_back(UT_Vector3(0.629880, -0.099521, 0.155039));
	pieceData.push_back(UT_Vector3(0.766835, 0.238167, 0.030153));
	pieceData.push_back(UT_Vector3(0.629880, 0.094164, -0.158350));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 25
//========================================================================================================
void CIntermediateComponent::Intermediate_Purple_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.750711, 0.000001, 0.545424));
	pieceData.push_back(UT_Vector3(0.486905, -0.171431, 0.631140));
	pieceData.push_back(UT_Vector3(0.587670, -0.277382, 0.492448));
	pieceData.push_back(UT_Vector3(0.500265, -0.185478, 0.612752));
	pieceData.push_back(UT_Vector3(0.574187, -0.263205, 0.511006));
	pieceData.push_back(UT_Vector3(0.750711, 0.014908, 0.521303));
	pieceData.push_back(UT_Vector3(0.750711, 0.171432, 0.268041));
	pieceData.push_back(UT_Vector3(0.587670, -0.262475, 0.468328));
	pieceData.push_back(UT_Vector3(0.587670, -0.105950, 0.215066));
	pieceData.push_back(UT_Vector3(0.649946, 0.277383, 0.406732));
	pieceData.push_back(UT_Vector3(0.741949, 0.024121, 0.533364));
	pieceData.push_back(UT_Vector3(0.386140, 0.105951, 0.492448));
	pieceData.push_back(UT_Vector3(0.478143, -0.147311, 0.619080));
	pieceData.push_back(UT_Vector3(0.574187, -0.091774, 0.233623));
	pieceData.push_back(UT_Vector3(0.574187, -0.248298, 0.486886));
	pieceData.push_back(UT_Vector3(0.491502, -0.161358, 0.600691));
	pieceData.push_back(UT_Vector3(0.399499, 0.091904, 0.474060));
	pieceData.push_back(UT_Vector3(0.662906, 0.263756, 0.388894));
	pieceData.push_back(UT_Vector3(0.741497, 0.041023, 0.507408));
	pieceData.push_back(UT_Vector3(0.737639, 0.185178, 0.286034));
	pieceData.push_back(UT_Vector3(0.729607, -0.013714, 0.552281));
	pieceData.push_back(UT_Vector3(0.508009, -0.157717, 0.624282));
	pieceData.push_back(UT_Vector3(0.600713, -0.255192, 0.496687));
	pieceData.push_back(UT_Vector3(0.737668, -0.022190, 0.541186));
	pieceData.push_back(UT_Vector3(0.499247, -0.133596, 0.612222));
	pieceData.push_back(UT_Vector3(0.720844, 0.010406, 0.540221));
	pieceData.push_back(UT_Vector3(0.628841, 0.263669, 0.413590));
	pieceData.push_back(UT_Vector3(0.407244, 0.119666, 0.485591));
	pieceData.push_back(UT_Vector3(0.600713, -0.083760, 0.219304));
	pieceData.push_back(UT_Vector3(0.737668, 0.149242, 0.263803));
	pieceData.push_back(UT_Vector3(0.737668, -0.007283, 0.517065));
	pieceData.push_back(UT_Vector3(0.600713, -0.240284, 0.472566));
	pieceData.push_back(UT_Vector3(0.520908, -0.171280, 0.606529));
	pieceData.push_back(UT_Vector3(0.714325, -0.038246, 0.548223));
	pieceData.push_back(UT_Vector3(0.587702, -0.241510, 0.514595));
	pieceData.push_back(UT_Vector3(0.420572, 0.105652, 0.467247));
	pieceData.push_back(UT_Vector3(0.587263, -0.069618, 0.237816));
	pieceData.push_back(UT_Vector3(0.641833, 0.250008, 0.395708));
	pieceData.push_back(UT_Vector3(0.724563, 0.163021, 0.281841));
	pieceData.push_back(UT_Vector3(0.750711, 0.155672, 0.293543));
	pieceData.push_back(UT_Vector3(0.587670, -0.121711, 0.240567));
	pieceData.push_back(UT_Vector3(0.659210, 0.251882, 0.419483));
	pieceData.push_back(UT_Vector3(0.395404, 0.080450, 0.505199));
	pieceData.push_back(UT_Vector3(0.574187, -0.107534, 0.259125));
	pieceData.push_back(UT_Vector3(0.408763, 0.066403, 0.486811));
	pieceData.push_back(UT_Vector3(0.671747, 0.238699, 0.402227));
	pieceData.push_back(UT_Vector3(0.738073, 0.168960, 0.310938));
	pieceData.push_back(UT_Vector3(0.638105, 0.238167, 0.426340));
	pieceData.push_back(UT_Vector3(0.416508, 0.094164, 0.498342));
	pieceData.push_back(UT_Vector3(0.737668, 0.133481, 0.289305));
	pieceData.push_back(UT_Vector3(0.600713, -0.099521, 0.244805));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 26
//========================================================================================================
void CIntermediateComponent::Intermediate_Purple_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.286746, 0.000001, 0.882514));
	pieceData.push_back(UT_Vector3(0.286746, -0.277382, 0.711082));
	pieceData.push_back(UT_Vector3(0.449788, -0.171431, 0.658107));
	pieceData.push_back(UT_Vector3(0.308363, -0.263335, 0.704059));
	pieceData.push_back(UT_Vector3(0.427972, -0.185608, 0.665195));
	pieceData.push_back(UT_Vector3(0.277984, 0.024121, 0.870454));
	pieceData.push_back(UT_Vector3(0.185981, 0.277383, 0.743823));
	pieceData.push_back(UT_Vector3(0.441025, -0.147311, 0.646047));
	pieceData.push_back(UT_Vector3(0.349023, 0.105951, 0.519416));
	pieceData.push_back(UT_Vector3(0.022939, 0.171432, 0.796798));
	pieceData.push_back(UT_Vector3(0.263806, 0.014908, 0.875060));
	pieceData.push_back(UT_Vector3(0.022940, -0.105950, 0.625366));
	pieceData.push_back(UT_Vector3(0.263806, -0.262475, 0.703629));
	pieceData.push_back(UT_Vector3(0.327207, 0.091774, 0.526504));
	pieceData.push_back(UT_Vector3(0.419210, -0.161488, 0.653135));
	pieceData.push_back(UT_Vector3(0.285423, -0.248428, 0.696605));
	pieceData.push_back(UT_Vector3(0.044556, -0.091903, 0.618343));
	pieceData.push_back(UT_Vector3(0.043909, 0.185059, 0.789985));
	pieceData.push_back(UT_Vector3(0.253419, 0.041010, 0.862009));
	pieceData.push_back(UT_Vector3(0.164829, 0.263638, 0.750695));
	pieceData.push_back(UT_Vector3(0.286746, -0.022190, 0.868799));
	pieceData.push_back(UT_Vector3(0.286746, -0.255192, 0.724797));
	pieceData.push_back(UT_Vector3(0.436744, -0.157717, 0.676059));
	pieceData.push_back(UT_Vector3(0.299789, -0.013714, 0.864561));
	pieceData.push_back(UT_Vector3(0.263806, -0.240284, 0.717343));
	pieceData.push_back(UT_Vector3(0.263806, -0.007283, 0.861346));
	pieceData.push_back(UT_Vector3(0.022939, 0.149242, 0.783083));
	pieceData.push_back(UT_Vector3(0.022940, -0.083760, 0.639081));
	pieceData.push_back(UT_Vector3(0.335979, 0.119666, 0.537368));
	pieceData.push_back(UT_Vector3(0.199024, 0.263669, 0.725870));
	pieceData.push_back(UT_Vector3(0.291027, 0.010406, 0.852501));
	pieceData.push_back(UT_Vector3(0.427982, -0.133597, 0.663999));
	pieceData.push_back(UT_Vector3(0.307617, -0.241629, 0.718015));
	pieceData.push_back(UT_Vector3(0.300632, -0.038258, 0.848780));
	pieceData.push_back(UT_Vector3(0.415691, -0.171398, 0.682900));
	pieceData.push_back(UT_Vector3(0.044504, -0.069746, 0.632074));
	pieceData.push_back(UT_Vector3(0.314217, 0.105523, 0.544439));
	pieceData.push_back(UT_Vector3(0.043961, 0.162902, 0.776253));
	pieceData.push_back(UT_Vector3(0.177819, 0.249889, 0.732760));
	pieceData.push_back(UT_Vector3(0.195245, 0.251882, 0.756573));
	pieceData.push_back(UT_Vector3(0.358287, 0.080450, 0.532166));
	pieceData.push_back(UT_Vector3(0.047193, 0.155672, 0.804678));
	pieceData.push_back(UT_Vector3(0.047193, -0.121711, 0.633247));
	pieceData.push_back(UT_Vector3(0.336471, 0.066273, 0.539255));
	pieceData.push_back(UT_Vector3(0.068809, -0.107664, 0.626223));
	pieceData.push_back(UT_Vector3(0.067478, 0.168854, 0.798087));
	pieceData.push_back(UT_Vector3(0.174795, 0.238593, 0.763218));
	pieceData.push_back(UT_Vector3(0.047193, 0.133481, 0.790964));
	pieceData.push_back(UT_Vector3(0.047193, -0.099520, 0.646961));
	pieceData.push_back(UT_Vector3(0.208288, 0.238167, 0.738621));
	pieceData.push_back(UT_Vector3(0.345243, 0.094164, 0.550119));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 27
//========================================================================================================
void CIntermediateComponent::Intermediate_Orange_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.286746, 0.000001, 0.882514));
	pieceData.push_back(UT_Vector3(-0.449788, -0.171431, 0.658107));
	pieceData.push_back(UT_Vector3(-0.286746, -0.277382, 0.711082));
	pieceData.push_back(UT_Vector3(-0.428171, -0.185478, 0.665130));
	pieceData.push_back(UT_Vector3(-0.308562, -0.263205, 0.703994));
	pieceData.push_back(UT_Vector3(-0.263806, 0.014908, 0.875060));
	pieceData.push_back(UT_Vector3(-0.022940, 0.171432, 0.796798));
	pieceData.push_back(UT_Vector3(-0.263806, -0.262475, 0.703629));
	pieceData.push_back(UT_Vector3(-0.022940, -0.105950, 0.625366));
	pieceData.push_back(UT_Vector3(-0.185981, 0.277383, 0.743822));
	pieceData.push_back(UT_Vector3(-0.277984, 0.024121, 0.870454));
	pieceData.push_back(UT_Vector3(-0.349022, 0.105951, 0.519415));
	pieceData.push_back(UT_Vector3(-0.441025, -0.147311, 0.646047));
	pieceData.push_back(UT_Vector3(-0.044755, -0.091774, 0.618278));
	pieceData.push_back(UT_Vector3(-0.285622, -0.248298, 0.696540));
	pieceData.push_back(UT_Vector3(-0.419409, -0.161358, 0.653070));
	pieceData.push_back(UT_Vector3(-0.327406, 0.091904, 0.526439));
	pieceData.push_back(UT_Vector3(-0.165011, 0.263757, 0.750636));
	pieceData.push_back(UT_Vector3(-0.253439, 0.041023, 0.862003));
	pieceData.push_back(UT_Vector3(-0.044091, 0.185178, 0.789925));
	pieceData.push_back(UT_Vector3(-0.299789, -0.013714, 0.864561));
	pieceData.push_back(UT_Vector3(-0.436744, -0.157717, 0.676059));
	pieceData.push_back(UT_Vector3(-0.286746, -0.255191, 0.724797));
	pieceData.push_back(UT_Vector3(-0.286746, -0.022190, 0.868799));
	pieceData.push_back(UT_Vector3(-0.427982, -0.133596, 0.663999));
	pieceData.push_back(UT_Vector3(-0.291027, 0.010407, 0.852501));
	pieceData.push_back(UT_Vector3(-0.199024, 0.263669, 0.725870));
	pieceData.push_back(UT_Vector3(-0.335979, 0.119666, 0.537368));
	pieceData.push_back(UT_Vector3(-0.022940, -0.083760, 0.639081));
	pieceData.push_back(UT_Vector3(-0.022940, 0.149242, 0.783083));
	pieceData.push_back(UT_Vector3(-0.263806, -0.007283, 0.861346));
	pieceData.push_back(UT_Vector3(-0.263806, -0.240284, 0.717343));
	pieceData.push_back(UT_Vector3(-0.415873, -0.171279, 0.682841));
	pieceData.push_back(UT_Vector3(-0.300652, -0.038245, 0.848773));
	pieceData.push_back(UT_Vector3(-0.307799, -0.241510, 0.717956));
	pieceData.push_back(UT_Vector3(-0.314414, 0.105652, 0.544375));
	pieceData.push_back(UT_Vector3(-0.044702, -0.069618, 0.632010));
	pieceData.push_back(UT_Vector3(-0.178003, 0.250008, 0.732700));
	pieceData.push_back(UT_Vector3(-0.044144, 0.163022, 0.776194));
	pieceData.push_back(UT_Vector3(-0.047193, 0.155672, 0.804678));
	pieceData.push_back(UT_Vector3(-0.047193, -0.121711, 0.633247));
	pieceData.push_back(UT_Vector3(-0.195245, 0.251882, 0.756573));
	pieceData.push_back(UT_Vector3(-0.358286, 0.080450, 0.532166));
	pieceData.push_back(UT_Vector3(-0.069009, -0.107534, 0.626158));
	pieceData.push_back(UT_Vector3(-0.336670, 0.066403, 0.539190));
	pieceData.push_back(UT_Vector3(-0.174959, 0.238699, 0.763164));
	pieceData.push_back(UT_Vector3(-0.067642, 0.168961, 0.798034));
	pieceData.push_back(UT_Vector3(-0.208288, 0.238167, 0.738621));
	pieceData.push_back(UT_Vector3(-0.345243, 0.094165, 0.550119));
	pieceData.push_back(UT_Vector3(-0.047193, 0.133481, 0.790964));
	pieceData.push_back(UT_Vector3(-0.047193, -0.099521, 0.646961));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 28
//========================================================================================================
void CIntermediateComponent::Intermediate_Orange_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.750711, 0.000001, 0.545423));
	pieceData.push_back(UT_Vector3(-0.587670, -0.277382, 0.492448));
	pieceData.push_back(UT_Vector3(-0.486905, -0.171431, 0.631140));
	pieceData.push_back(UT_Vector3(-0.574310, -0.263335, 0.510836));
	pieceData.push_back(UT_Vector3(-0.500388, -0.185608, 0.612582));
	pieceData.push_back(UT_Vector3(-0.741949, 0.024121, 0.533363));
	pieceData.push_back(UT_Vector3(-0.649946, 0.277383, 0.406732));
	pieceData.push_back(UT_Vector3(-0.478143, -0.147311, 0.619079));
	pieceData.push_back(UT_Vector3(-0.386140, 0.105951, 0.492448));
	pieceData.push_back(UT_Vector3(-0.750711, 0.171433, 0.268041));
	pieceData.push_back(UT_Vector3(-0.750711, 0.014908, 0.521303));
	pieceData.push_back(UT_Vector3(-0.587670, -0.105950, 0.215066));
	pieceData.push_back(UT_Vector3(-0.587670, -0.262475, 0.468328));
	pieceData.push_back(UT_Vector3(-0.399622, 0.091775, 0.473891));
	pieceData.push_back(UT_Vector3(-0.491625, -0.161488, 0.600522));
	pieceData.push_back(UT_Vector3(-0.574310, -0.248428, 0.486716));
	pieceData.push_back(UT_Vector3(-0.574310, -0.091903, 0.233454));
	pieceData.push_back(UT_Vector3(-0.737751, 0.185059, 0.285878));
	pieceData.push_back(UT_Vector3(-0.741509, 0.041010, 0.507392));
	pieceData.push_back(UT_Vector3(-0.663019, 0.263638, 0.388739));
	pieceData.push_back(UT_Vector3(-0.737668, -0.022190, 0.541185));
	pieceData.push_back(UT_Vector3(-0.600713, -0.255191, 0.496686));
	pieceData.push_back(UT_Vector3(-0.508009, -0.157717, 0.624282));
	pieceData.push_back(UT_Vector3(-0.729607, -0.013714, 0.552281));
	pieceData.push_back(UT_Vector3(-0.600713, -0.240284, 0.472566));
	pieceData.push_back(UT_Vector3(-0.737668, -0.007283, 0.517065));
	pieceData.push_back(UT_Vector3(-0.737668, 0.149242, 0.263803));
	pieceData.push_back(UT_Vector3(-0.600713, -0.083760, 0.219304));
	pieceData.push_back(UT_Vector3(-0.407244, 0.119666, 0.485591));
	pieceData.push_back(UT_Vector3(-0.628842, 0.263669, 0.413589));
	pieceData.push_back(UT_Vector3(-0.720845, 0.010406, 0.540220));
	pieceData.push_back(UT_Vector3(-0.499247, -0.133596, 0.612222));
	pieceData.push_back(UT_Vector3(-0.587814, -0.241629, 0.514440));
	pieceData.push_back(UT_Vector3(-0.714337, -0.038258, 0.548205));
	pieceData.push_back(UT_Vector3(-0.521021, -0.171398, 0.606374));
	pieceData.push_back(UT_Vector3(-0.587386, -0.069746, 0.237648));
	pieceData.push_back(UT_Vector3(-0.420694, 0.105524, 0.467079));
	pieceData.push_back(UT_Vector3(-0.724676, 0.162903, 0.281684));
	pieceData.push_back(UT_Vector3(-0.641947, 0.249889, 0.395552));
	pieceData.push_back(UT_Vector3(-0.659210, 0.251882, 0.419483));
	pieceData.push_back(UT_Vector3(-0.395404, 0.080450, 0.505199));
	pieceData.push_back(UT_Vector3(-0.750711, 0.155672, 0.293542));
	pieceData.push_back(UT_Vector3(-0.587670, -0.121711, 0.240567));
	pieceData.push_back(UT_Vector3(-0.408886, 0.066273, 0.486641));
	pieceData.push_back(UT_Vector3(-0.574310, -0.107664, 0.258955));
	pieceData.push_back(UT_Vector3(-0.738174, 0.168854, 0.310798));
	pieceData.push_back(UT_Vector3(-0.671849, 0.238593, 0.402088));
	pieceData.push_back(UT_Vector3(-0.737668, 0.133481, 0.289304));
	pieceData.push_back(UT_Vector3(-0.600713, -0.099520, 0.244805));
	pieceData.push_back(UT_Vector3(-0.638106, 0.238167, 0.426340));
	pieceData.push_back(UT_Vector3(-0.416508, 0.094164, 0.498342));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 29
//========================================================================================================
void CIntermediateComponent::Intermediate_Green_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.927930, 0.000001, -0.000000));
	pieceData.push_back(UT_Vector3(-0.764889, -0.171431, -0.224407));
	pieceData.push_back(UT_Vector3(-0.764889, -0.277382, -0.052975));
	pieceData.push_back(UT_Vector3(-0.764889, -0.185478, -0.201678));
	pieceData.push_back(UT_Vector3(-0.764889, -0.263205, -0.075914));
	pieceData.push_back(UT_Vector3(-0.913753, 0.014908, 0.019513));
	pieceData.push_back(UT_Vector3(-0.764889, 0.171433, 0.224407));
	pieceData.push_back(UT_Vector3(-0.750711, -0.262475, -0.033462));
	pieceData.push_back(UT_Vector3(-0.601848, -0.105950, 0.171432));
	pieceData.push_back(UT_Vector3(-0.764889, 0.277383, 0.052975));
	pieceData.push_back(UT_Vector3(-0.913753, 0.024121, 0.004606));
	pieceData.push_back(UT_Vector3(-0.601847, 0.105952, -0.171432));
	pieceData.push_back(UT_Vector3(-0.750711, -0.147311, -0.219801));
	pieceData.push_back(UT_Vector3(-0.601848, -0.091774, 0.148493));
	pieceData.push_back(UT_Vector3(-0.750711, -0.248298, -0.056400));
	pieceData.push_back(UT_Vector3(-0.750711, -0.161358, -0.197072));
	pieceData.push_back(UT_Vector3(-0.601847, 0.091904, -0.148703));
	pieceData.push_back(UT_Vector3(-0.764889, 0.263757, 0.075024));
	pieceData.push_back(UT_Vector3(-0.898130, 0.041023, 0.025339));
	pieceData.push_back(UT_Vector3(-0.764889, 0.185178, 0.202167));
	pieceData.push_back(UT_Vector3(-0.914887, -0.013713, -0.017953));
	pieceData.push_back(UT_Vector3(-0.777932, -0.157716, -0.206455));
	pieceData.push_back(UT_Vector3(-0.777932, -0.255191, -0.048737));
	pieceData.push_back(UT_Vector3(-0.914887, -0.022190, -0.004238));
	pieceData.push_back(UT_Vector3(-0.763755, -0.133596, -0.201848));
	pieceData.push_back(UT_Vector3(-0.900709, 0.010407, -0.013346));
	pieceData.push_back(UT_Vector3(-0.751845, 0.263669, 0.035023));
	pieceData.push_back(UT_Vector3(-0.614891, 0.119666, -0.153479));
	pieceData.push_back(UT_Vector3(-0.614891, -0.083760, 0.175670));
	pieceData.push_back(UT_Vector3(-0.751845, 0.149242, 0.220169));
	pieceData.push_back(UT_Vector3(-0.900709, -0.007282, 0.015275));
	pieceData.push_back(UT_Vector3(-0.763755, -0.240284, -0.029224));
	pieceData.push_back(UT_Vector3(-0.777932, -0.171279, -0.184510));
	pieceData.push_back(UT_Vector3(-0.900138, -0.038245, -0.023652));
	pieceData.push_back(UT_Vector3(-0.777932, -0.241510, -0.070874));
	pieceData.push_back(UT_Vector3(-0.614891, 0.105652, -0.130805));
	pieceData.push_back(UT_Vector3(-0.614891, -0.069617, 0.152787));
	pieceData.push_back(UT_Vector3(-0.751845, 0.250008, 0.057126));
	pieceData.push_back(UT_Vector3(-0.751845, 0.163022, 0.197873));
	pieceData.push_back(UT_Vector3(-0.779878, 0.155672, 0.203776));
	pieceData.push_back(UT_Vector3(-0.616837, -0.121711, 0.150801));
	pieceData.push_back(UT_Vector3(-0.779878, 0.251882, 0.048105));
	pieceData.push_back(UT_Vector3(-0.616837, 0.080450, -0.176302));
	pieceData.push_back(UT_Vector3(-0.616837, -0.107534, 0.127862));
	pieceData.push_back(UT_Vector3(-0.616837, 0.066403, -0.153573));
	pieceData.push_back(UT_Vector3(-0.779878, 0.238700, 0.069435));
	pieceData.push_back(UT_Vector3(-0.779878, 0.168961, 0.182274));
	pieceData.push_back(UT_Vector3(-0.766835, 0.238167, 0.030152));
	pieceData.push_back(UT_Vector3(-0.629880, 0.094165, -0.158350));
	pieceData.push_back(UT_Vector3(-0.766835, 0.133481, 0.199538));
	pieceData.push_back(UT_Vector3(-0.629880, -0.099520, 0.155039));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	INTERMEDIATE 30
//========================================================================================================
void CIntermediateComponent::Intermediate_Green_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.750711, 0.000001, -0.545424));
	pieceData.push_back(UT_Vector3(-0.649946, -0.277382, -0.406733));
	pieceData.push_back(UT_Vector3(-0.750711, -0.171431, -0.268041));
	pieceData.push_back(UT_Vector3(-0.663306, -0.263335, -0.388345));
	pieceData.push_back(UT_Vector3(-0.737229, -0.185608, -0.286599));
	pieceData.push_back(UT_Vector3(-0.736534, 0.024121, -0.540817));
	pieceData.push_back(UT_Vector3(-0.587670, 0.277383, -0.492448));
	pieceData.push_back(UT_Vector3(-0.736534, -0.147311, -0.263435));
	pieceData.push_back(UT_Vector3(-0.587670, 0.105951, -0.215066));
	pieceData.push_back(UT_Vector3(-0.486904, 0.171433, -0.631140));
	pieceData.push_back(UT_Vector3(-0.727771, 0.014908, -0.552877));
	pieceData.push_back(UT_Vector3(-0.386140, -0.105950, -0.492449));
	pieceData.push_back(UT_Vector3(-0.627006, -0.262475, -0.414186));
	pieceData.push_back(UT_Vector3(-0.574187, 0.091775, -0.233623));
	pieceData.push_back(UT_Vector3(-0.723051, -0.161488, -0.281992));
	pieceData.push_back(UT_Vector3(-0.640366, -0.248427, -0.395798));
	pieceData.push_back(UT_Vector3(-0.399499, -0.091903, -0.474060));
	pieceData.push_back(UT_Vector3(-0.499864, 0.185059, -0.613302));
	pieceData.push_back(UT_Vector3(-0.711697, 0.041010, -0.548424));
	pieceData.push_back(UT_Vector3(-0.574597, 0.263638, -0.510441));
	pieceData.push_back(UT_Vector3(-0.742650, -0.022190, -0.534329));
	pieceData.push_back(UT_Vector3(-0.658007, -0.255191, -0.417828));
	pieceData.push_back(UT_Vector3(-0.750711, -0.157717, -0.290232));
	pieceData.push_back(UT_Vector3(-0.750711, -0.013714, -0.523233));
	pieceData.push_back(UT_Vector3(-0.635068, -0.240284, -0.425282));
	pieceData.push_back(UT_Vector3(-0.719710, -0.007283, -0.541782));
	pieceData.push_back(UT_Vector3(-0.478843, 0.149242, -0.620045));
	pieceData.push_back(UT_Vector3(-0.394201, -0.083760, -0.503544));
	pieceData.push_back(UT_Vector3(-0.587670, 0.119666, -0.237256));
	pieceData.push_back(UT_Vector3(-0.587670, 0.263669, -0.470258));
	pieceData.push_back(UT_Vector3(-0.736534, 0.010407, -0.518627));
	pieceData.push_back(UT_Vector3(-0.736534, -0.133596, -0.285625));
	pieceData.push_back(UT_Vector3(-0.670906, -0.241628, -0.400074));
	pieceData.push_back(UT_Vector3(-0.742117, -0.038258, -0.509970));
	pieceData.push_back(UT_Vector3(-0.737700, -0.171398, -0.308141));
	pieceData.push_back(UT_Vector3(-0.407529, -0.069746, -0.485200));
	pieceData.push_back(UT_Vector3(-0.574220, 0.105524, -0.255769));
	pieceData.push_back(UT_Vector3(-0.491835, 0.162902, -0.602163));
	pieceData.push_back(UT_Vector3(-0.574565, 0.249889, -0.488296));
	pieceData.push_back(UT_Vector3(-0.602659, 0.251882, -0.497319));
	pieceData.push_back(UT_Vector3(-0.602659, 0.080450, -0.219936));
	pieceData.push_back(UT_Vector3(-0.511158, 0.155672, -0.623259));
	pieceData.push_back(UT_Vector3(-0.410393, -0.121711, -0.484568));
	pieceData.push_back(UT_Vector3(-0.589177, 0.066273, -0.238494));
	pieceData.push_back(UT_Vector3(-0.423753, -0.107664, -0.466180));
	pieceData.push_back(UT_Vector3(-0.523695, 0.168854, -0.606003));
	pieceData.push_back(UT_Vector3(-0.590021, 0.238593, -0.514714));
	pieceData.push_back(UT_Vector3(-0.503097, 0.133481, -0.612164));
	pieceData.push_back(UT_Vector3(-0.418454, -0.099520, -0.495663));
	pieceData.push_back(UT_Vector3(-0.602659, 0.238167, -0.475128));
	pieceData.push_back(UT_Vector3(-0.602659, 0.094164, -0.242127));

	int faces[198] = { 46, 19, 47,
		34, 33, 35,
		48, 49, 25, 26,
		46, 42, 11, 19,
		31, 32, 51, 50,
		24, 1, 21, 34,
		15, 16, 45, 44,
		41, 8, 15, 44,
		45, 16, 13, 43,
		21, 26, 25, 22,
		24, 23, 32, 31,
		5, 4, 16, 15,
		3, 5, 15, 8,
		16, 4, 2, 13,
		11, 1, 6, 19,
		40, 47, 19, 6,
		48, 26, 11, 42,
		43, 13, 25, 49,
		40, 6, 31, 50,
		41, 51, 32, 8,
		22, 2, 4, 33,
		1, 11, 26, 21,
		13, 2, 22, 25,
		23, 3, 8, 32,
		31, 6, 1, 24,
		5, 3, 23, 35,
		34, 35, 23, 24,
		21, 22, 33, 34,
		33, 4, 5, 35,
		17, 12, 28, 36,
		14, 17, 36, 37,
		29, 9, 14, 37,
		27, 38, 36, 28,
		38, 39, 37, 36,
		37, 39, 30, 29,
		10, 18, 38, 27,
		18, 20, 39, 38,
		39, 20, 7, 30,
		48, 27, 28, 49,
		18, 10, 42, 46,
		29, 30, 50, 51,
		17, 14, 44, 45,
		14, 9, 41, 44,
		43, 12, 17, 45,
		20, 18, 46, 47,
		40, 7, 20, 47,
		42, 10, 27, 48,
		49, 28, 12, 43,
		30, 7, 40, 50,
		9, 29, 51, 41 };

	for (int i = 0; i < 198; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
void CIntermediateComponent::buildAllIntermediateGeometryData(IntermediateGeometryData &intermediateGeometry)
{
	vector<UT_Vector3> pieceData;
	vector<int> faceList;
	vector<int> faceListColor;
	string pieceName;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Yellow_Orange(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Yellow_Orange = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Yellow_Purple(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Yellow_Purple = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Yellow_White(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Yellow_White = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Yellow_Blue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Yellow_Blue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Yellow_Green(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Yellow_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightGreen_Pink(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightGreen_Pink = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightGreen_Red(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightGreen_Red = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightGreen_Green(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightGreen_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightGreen_LightBlue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightGreen_LightBlue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightGreen_Gray(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightGreen_Gray = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Green_Blue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Green_Blue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Blue_White(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Blue_White = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_White_Purple(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_White_Purple = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Purple_Orange(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Purple_Orange = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Orange_Green(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Orange_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Pink_Red(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Pink_Red = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Gray_Pink(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Gray_Pink = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightBlue_Gray(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightBlue_Gray = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_LightBlue_Green(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_LightBlue_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Green_Red(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Green_Red = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Pink_Blue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Pink_Blue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Red_Blue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Red_Blue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Red_White(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Red_White = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_White_Green(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_White_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Purple_Red(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Purple_Red = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Purple_LightBlue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Purple_LightBlue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Orange_LightBlue(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Orange_LightBlue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Orange_Gray(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Orange_Gray = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Green_Gray(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Green_Gray = pieceData;

	//----------------------------------------------------------------------------------------------------
	Intermediate_Green_Pink(pieceData, faceList, pieceName);
	intermediateGeometry.posIntermediate_Green_Pink = pieceData;

	//----------------------------------------------------------------------------------------------------
	IntermediateColorPiece(pieceData, faceListColor, pieceName);
	intermediateGeometry.posIntermediate_Color = pieceData;

	intermediateGeometry.faceListBlack = faceList;
	intermediateGeometry.faceListColor = faceListColor;
}
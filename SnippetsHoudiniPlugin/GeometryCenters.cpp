//========================================================================================================
//
//	Arquivo: GeometryCenters.cpp
//
//	Descrição:	controi geometria centrais
//
//========================================================================================================

#include "GeometryCenters.h"

//========================================================================================================
//	COLOR PIECE
//========================================================================================================
void CCenterComponent::CenterColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.090776, 0.800724, 0.131824));
	pieceData.push_back(UT_Vector3(0.153423, 0.800724, -0.045597));
	pieceData.push_back(UT_Vector3(0.004045, 0.800724, -0.160004));
	pieceData.push_back(UT_Vector3(-0.150923, 0.800724, -0.053291));
	pieceData.push_back(UT_Vector3(-0.097321, 0.800724, 0.127069));
	pieceData.push_back(UT_Vector3(0.097321, 0.800724, 0.127069));
	pieceData.push_back(UT_Vector3(0.150923, 0.800724, -0.053291));
	pieceData.push_back(UT_Vector3(-0.004045, 0.800724, -0.160004));
	pieceData.push_back(UT_Vector3(-0.153423, 0.800724, -0.045597));
	pieceData.push_back(UT_Vector3(-0.090776, 0.800724, 0.131824));
	pieceData.push_back(UT_Vector3(0.090776, 0.779166, 0.131824));
	pieceData.push_back(UT_Vector3(0.153423, 0.779166, -0.045597));
	pieceData.push_back(UT_Vector3(0.004045, 0.779166, -0.160004));
	pieceData.push_back(UT_Vector3(-0.150923, 0.779166, -0.053291));
	pieceData.push_back(UT_Vector3(-0.097321, 0.779166, 0.127069));
	pieceData.push_back(UT_Vector3(0.097321, 0.779166, 0.127069));
	pieceData.push_back(UT_Vector3(0.150923, 0.779166, -0.053291));
	pieceData.push_back(UT_Vector3(-0.004045, 0.779166, -0.160004));
	pieceData.push_back(UT_Vector3(-0.153423, 0.779166, -0.045597));
	pieceData.push_back(UT_Vector3(-0.090776, 0.779166, 0.131824));
	pieceData.push_back(UT_Vector3(0.088814, 0.800724, 0.120888));
	pieceData.push_back(UT_Vector3(0.142908, 0.800724, -0.045597));
	pieceData.push_back(UT_Vector3(0.142416, 0.800724, -0.047111));
	pieceData.push_back(UT_Vector3(0.000796, 0.800724, -0.150004));
	pieceData.push_back(UT_Vector3(-0.000796, 0.800724, -0.150004));
	pieceData.push_back(UT_Vector3(-0.142416, 0.800724, -0.047111));
	pieceData.push_back(UT_Vector3(-0.142908, 0.800724, -0.045597));
	pieceData.push_back(UT_Vector3(-0.088814, 0.800724, 0.120888));
	pieceData.push_back(UT_Vector3(-0.087526, 0.800724, 0.121824));
	pieceData.push_back(UT_Vector3(0.087526, 0.800724, 0.121824));
	pieceData.push_back(UT_Vector3(-0.000000, 0.800724, 0.000000));

	int faces[110] = { 21, 22, 31,
		22, 23, 31,
		23, 24, 31,
		24, 25, 31,
		25, 26, 31,
		26, 27, 31,
		27, 28, 31,
		28, 29, 31,
		29, 30, 31,
		30, 21, 31,
		16, 12, 2, 6,
		17, 13, 3, 7,
		18, 14, 4, 8,
		19, 15, 5, 9,
		20, 11, 1, 10,
		11, 16, 6, 1,
		12, 17, 7, 2,
		13, 18, 8, 3,
		14, 19, 9, 4,
		15, 20, 10, 5,
		6, 2, 22, 21,
		2, 7, 23, 22,
		7, 3, 24, 23,
		3, 8, 25, 24,
		8, 4, 26, 25,
		4, 9, 27, 26,
		9, 5, 28, 27,
		5, 10, 29, 28,
		10, 1, 30, 29,
		1, 6, 21, 30};

	for (int i = 0; i < 110; i++)
	{
		faceList.push_back(faces[i]);
	}

}

//========================================================================================================
//	CENTER 1
//========================================================================================================
void CCenterComponent::Center_Yellow(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.173174, 0.789344, -0.060521));
	pieceData.push_back(UT_Vector3(0.004045, 0.789344, -0.183400));
	pieceData.push_back(UT_Vector3(-0.173174, 0.789344, -0.060521));
	pieceData.push_back(UT_Vector3(0.111072, 0.789344, 0.145996));
	pieceData.push_back(UT_Vector3(-0.111072, 0.789344, 0.145996));
	pieceData.push_back(UT_Vector3(-0.113431, 0.764834, 0.163007));
	pieceData.push_back(UT_Vector3(-0.187581, 0.764834, -0.065202));
	pieceData.push_back(UT_Vector3(0.004045, 0.764834, -0.198548));
	pieceData.push_back(UT_Vector3(0.190081, 0.764834, -0.057508));
	pieceData.push_back(UT_Vector3(0.119976, 0.764834, 0.158251));
	pieceData.push_back(UT_Vector3(0.175674, 0.789344, -0.052827));
	pieceData.push_back(UT_Vector3(-0.004045, 0.789344, -0.183400));
	pieceData.push_back(UT_Vector3(-0.175674, 0.789344, -0.052827));
	pieceData.push_back(UT_Vector3(0.104527, 0.789344, 0.150752));
	pieceData.push_back(UT_Vector3(-0.104527, 0.789344, 0.150752));
	pieceData.push_back(UT_Vector3(0.094048, 0.789344, 0.129446));
	pieceData.push_back(UT_Vector3(0.152173, 0.789344, -0.049444));
	pieceData.push_back(UT_Vector3(-0.000000, 0.789344, -0.160004));
	pieceData.push_back(UT_Vector3(-0.152173, 0.789344, -0.049444));
	pieceData.push_back(UT_Vector3(-0.094048, 0.789344, 0.129446));
	pieceData.push_back(UT_Vector3(-0.119976, 0.764834, 0.158251));
	pieceData.push_back(UT_Vector3(-0.190081, 0.764834, -0.057508));
	pieceData.push_back(UT_Vector3(-0.004045, 0.764834, -0.198548));
	pieceData.push_back(UT_Vector3(0.187581, 0.764834, -0.065202));
	pieceData.push_back(UT_Vector3(0.113431, 0.764834, 0.163007));
	pieceData.push_back(UT_Vector3(-0.342430, 0.505642, -0.107009));
	pieceData.push_back(UT_Vector3(-0.339930, 0.505642, -0.114703));
	pieceData.push_back(UT_Vector3(-0.004045, 0.505642, -0.358738));
	pieceData.push_back(UT_Vector3(0.004045, 0.505642, -0.358738));
	pieceData.push_back(UT_Vector3(0.339930, 0.505642, -0.114703));
	pieceData.push_back(UT_Vector3(0.342430, 0.505642, -0.107009));
	pieceData.push_back(UT_Vector3(0.214133, 0.505642, 0.287847));
	pieceData.push_back(UT_Vector3(0.207588, 0.505642, 0.292603));
	pieceData.push_back(UT_Vector3(-0.207588, 0.505642, 0.292603));
	pieceData.push_back(UT_Vector3(-0.214133, 0.505642, 0.287848));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 2
//========================================================================================================
void CCenterComponent::Center_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.104527, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.104527, 0.487841, 0.638593));
	pieceData.push_back(UT_Vector3(-0.175674, 0.305755, 0.729636));
	pieceData.push_back(UT_Vector3(0.175674, 0.305755, 0.729636));
	pieceData.push_back(UT_Vector3(-0.004045, 0.188967, 0.788030));
	pieceData.push_back(UT_Vector3(0.004045, 0.164457, 0.772882));
	pieceData.push_back(UT_Vector3(-0.190081, 0.290607, 0.709807));
	pieceData.push_back(UT_Vector3(-0.113431, 0.487841, 0.611190));
	pieceData.push_back(UT_Vector3(0.119976, 0.483588, 0.613317));
	pieceData.push_back(UT_Vector3(0.190081, 0.290607, 0.709807));
	pieceData.push_back(UT_Vector3(0.111072, 0.483588, 0.640720));
	pieceData.push_back(UT_Vector3(-0.111072, 0.483588, 0.640720));
	pieceData.push_back(UT_Vector3(-0.173174, 0.298874, 0.733077));
	pieceData.push_back(UT_Vector3(0.173174, 0.298874, 0.733077));
	pieceData.push_back(UT_Vector3(0.004045, 0.188967, 0.788030));
	pieceData.push_back(UT_Vector3(0.152173, 0.308781, 0.728123));
	pieceData.push_back(UT_Vector3(0.094048, 0.468785, 0.648121));
	pieceData.push_back(UT_Vector3(-0.094048, 0.468785, 0.648121));
	pieceData.push_back(UT_Vector3(-0.152173, 0.308781, 0.728123));
	pieceData.push_back(UT_Vector3(0.000000, 0.209893, 0.777567));
	pieceData.push_back(UT_Vector3(-0.004045, 0.164457, 0.772882));
	pieceData.push_back(UT_Vector3(-0.187581, 0.283725, 0.713248));
	pieceData.push_back(UT_Vector3(-0.119976, 0.483588, 0.613317));
	pieceData.push_back(UT_Vector3(0.113431, 0.487841, 0.611190));
	pieceData.push_back(UT_Vector3(0.187581, 0.283725, 0.713248));
	pieceData.push_back(UT_Vector3(-0.339930, 0.123536, 0.503557));
	pieceData.push_back(UT_Vector3(-0.342430, 0.130418, 0.500116));
	pieceData.push_back(UT_Vector3(-0.214133, 0.483589, 0.323531));
	pieceData.push_back(UT_Vector3(-0.207588, 0.487842, 0.321405));
	pieceData.push_back(UT_Vector3(0.207588, 0.487842, 0.321405));
	pieceData.push_back(UT_Vector3(0.214133, 0.483588, 0.323531));
	pieceData.push_back(UT_Vector3(0.342430, 0.130418, 0.500116));
	pieceData.push_back(UT_Vector3(0.339930, 0.123536, 0.503557));
	pieceData.push_back(UT_Vector3(0.004045, -0.094735, 0.612692));
	pieceData.push_back(UT_Vector3(-0.004045, -0.094735, 0.612692));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 3
//========================================================================================================
void CCenterComponent::Center_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.575038, 0.487841, 0.296748));
	pieceData.push_back(UT_Vector3(-0.639639, 0.487841, 0.097925));
	pieceData.push_back(UT_Vector3(-0.748212, 0.305755, 0.058394));
	pieceData.push_back(UT_Vector3(-0.639639, 0.305755, 0.392546));
	pieceData.push_back(UT_Vector3(-0.750711, 0.188967, 0.239668));
	pieceData.push_back(UT_Vector3(-0.733805, 0.164457, 0.242681));
	pieceData.push_back(UT_Vector3(-0.733805, 0.290607, 0.038565));
	pieceData.push_back(UT_Vector3(-0.616328, 0.487841, 0.080989));
	pieceData.push_back(UT_Vector3(-0.546224, 0.483588, 0.303630));
	pieceData.push_back(UT_Vector3(-0.616328, 0.290607, 0.400120));
	pieceData.push_back(UT_Vector3(-0.575038, 0.483588, 0.303630));
	pieceData.push_back(UT_Vector3(-0.643684, 0.483588, 0.092357));
	pieceData.push_back(UT_Vector3(-0.750712, 0.298874, 0.061835));
	pieceData.push_back(UT_Vector3(-0.643684, 0.298874, 0.391232));
	pieceData.push_back(UT_Vector3(-0.748211, 0.188967, 0.247362));
	pieceData.push_back(UT_Vector3(-0.645462, 0.308781, 0.369728));
	pieceData.push_back(UT_Vector3(-0.587338, 0.468785, 0.289726));
	pieceData.push_back(UT_Vector3(-0.645463, 0.468785, 0.110836));
	pieceData.push_back(UT_Vector3(-0.739511, 0.308781, 0.080278));
	pieceData.push_back(UT_Vector3(-0.739510, 0.209893, 0.240282));
	pieceData.push_back(UT_Vector3(-0.736305, 0.164457, 0.234987));
	pieceData.push_back(UT_Vector3(-0.736305, 0.283725, 0.042006));
	pieceData.push_back(UT_Vector3(-0.620373, 0.483588, 0.075421));
	pieceData.push_back(UT_Vector3(-0.546224, 0.487841, 0.296748));
	pieceData.push_back(UT_Vector3(-0.620373, 0.283725, 0.398806));
	pieceData.push_back(UT_Vector3(-0.583955, 0.123536, -0.167685));
	pieceData.push_back(UT_Vector3(-0.581455, 0.130418, -0.171126));
	pieceData.push_back(UT_Vector3(-0.373867, 0.483589, -0.103676));
	pieceData.push_back(UT_Vector3(-0.369822, 0.487842, -0.098109));
	pieceData.push_back(UT_Vector3(-0.241526, 0.487842, 0.296748));
	pieceData.push_back(UT_Vector3(-0.241526, 0.483588, 0.303630));
	pieceData.push_back(UT_Vector3(-0.369822, 0.130418, 0.480215));
	pieceData.push_back(UT_Vector3(-0.373867, 0.123536, 0.478900));
	pieceData.push_back(UT_Vector3(-0.581455, -0.094735, 0.193180));
	pieceData.push_back(UT_Vector3(-0.583955, -0.094735, 0.185485));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 4
//========================================================================================================
void CCenterComponent::Center_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.459920, 0.487841, -0.455193));
	pieceData.push_back(UT_Vector3(-0.290791, 0.487841, -0.578072));
	pieceData.push_back(UT_Vector3(-0.286746, 0.305755, -0.693547));
	pieceData.push_back(UT_Vector3(-0.570993, 0.305755, -0.487029));
	pieceData.push_back(UT_Vector3(-0.459920, 0.188967, -0.639907));
	pieceData.push_back(UT_Vector3(-0.457561, 0.164457, -0.622897));
	pieceData.push_back(UT_Vector3(-0.263436, 0.290607, -0.685972));
	pieceData.push_back(UT_Vector3(-0.267481, 0.487841, -0.561136));
	pieceData.push_back(UT_Vector3(-0.457561, 0.483588, -0.425663));
	pieceData.push_back(UT_Vector3(-0.570993, 0.290607, -0.462519));
	pieceData.push_back(UT_Vector3(-0.466465, 0.483588, -0.453066));
	pieceData.push_back(UT_Vector3(-0.286746, 0.483588, -0.583640));
	pieceData.push_back(UT_Vector3(-0.290791, 0.298874, -0.694861));
	pieceData.push_back(UT_Vector3(-0.570993, 0.298874, -0.491283));
	pieceData.push_back(UT_Vector3(-0.466465, 0.188967, -0.635152));
	pieceData.push_back(UT_Vector3(-0.551091, 0.308781, -0.499619));
	pieceData.push_back(UT_Vector3(-0.457043, 0.468785, -0.469061));
	pieceData.push_back(UT_Vector3(-0.304870, 0.468785, -0.579621));
	pieceData.push_back(UT_Vector3(-0.304870, 0.308781, -0.678509));
	pieceData.push_back(UT_Vector3(-0.457043, 0.209893, -0.629065));
	pieceData.push_back(UT_Vector3(-0.451016, 0.164457, -0.627652));
	pieceData.push_back(UT_Vector3(-0.267481, 0.283725, -0.687287));
	pieceData.push_back(UT_Vector3(-0.263436, 0.483588, -0.566704));
	pieceData.push_back(UT_Vector3(-0.451016, 0.487841, -0.427790));
	pieceData.push_back(UT_Vector3(-0.570993, 0.283725, -0.466772));
	pieceData.push_back(UT_Vector3(-0.020974, 0.123536, -0.607192));
	pieceData.push_back(UT_Vector3(-0.016929, 0.130418, -0.605878));
	pieceData.push_back(UT_Vector3(-0.016929, 0.483589, -0.387607));
	pieceData.push_back(UT_Vector3(-0.020974, 0.487842, -0.382039));
	pieceData.push_back(UT_Vector3(-0.356859, 0.487842, -0.138004));
	pieceData.push_back(UT_Vector3(-0.363404, 0.483588, -0.135878));
	pieceData.push_back(UT_Vector3(-0.570993, 0.130418, -0.203327));
	pieceData.push_back(UT_Vector3(-0.570993, 0.123536, -0.207580));
	pieceData.push_back(UT_Vector3(-0.363404, -0.094735, -0.493301));
	pieceData.push_back(UT_Vector3(-0.356859, -0.094735, -0.498056));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 5
//========================================================================================================
void CCenterComponent::Center_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.639639, 0.487841, 0.097925));
	pieceData.push_back(UT_Vector3(0.575038, 0.487841, 0.296748));
	pieceData.push_back(UT_Vector3(0.639639, 0.305755, 0.392546));
	pieceData.push_back(UT_Vector3(0.748211, 0.305755, 0.058394));
	pieceData.push_back(UT_Vector3(0.748211, 0.188967, 0.247362));
	pieceData.push_back(UT_Vector3(0.736305, 0.164457, 0.234987));
	pieceData.push_back(UT_Vector3(0.616328, 0.290607, 0.400120));
	pieceData.push_back(UT_Vector3(0.546224, 0.487841, 0.296748));
	pieceData.push_back(UT_Vector3(0.620373, 0.483588, 0.075421));
	pieceData.push_back(UT_Vector3(0.733805, 0.290607, 0.038565));
	pieceData.push_back(UT_Vector3(0.643684, 0.483588, 0.092357));
	pieceData.push_back(UT_Vector3(0.575038, 0.483588, 0.303630));
	pieceData.push_back(UT_Vector3(0.643684, 0.298874, 0.391231));
	pieceData.push_back(UT_Vector3(0.750711, 0.298874, 0.061835));
	pieceData.push_back(UT_Vector3(0.750711, 0.188967, 0.239668));
	pieceData.push_back(UT_Vector3(0.739511, 0.308781, 0.080277));
	pieceData.push_back(UT_Vector3(0.645463, 0.468785, 0.110835));
	pieceData.push_back(UT_Vector3(0.587338, 0.468785, 0.289726));
	pieceData.push_back(UT_Vector3(0.645463, 0.308781, 0.369728));
	pieceData.push_back(UT_Vector3(0.739510, 0.209893, 0.240281));
	pieceData.push_back(UT_Vector3(0.733805, 0.164457, 0.242681));
	pieceData.push_back(UT_Vector3(0.620373, 0.283725, 0.398806));
	pieceData.push_back(UT_Vector3(0.546224, 0.483588, 0.303630));
	pieceData.push_back(UT_Vector3(0.616328, 0.487841, 0.080989));
	pieceData.push_back(UT_Vector3(0.736305, 0.283725, 0.042006));
	pieceData.push_back(UT_Vector3(0.373867, 0.123536, 0.478900));
	pieceData.push_back(UT_Vector3(0.369822, 0.130418, 0.480215));
	pieceData.push_back(UT_Vector3(0.241526, 0.483589, 0.303630));
	pieceData.push_back(UT_Vector3(0.241526, 0.487842, 0.296748));
	pieceData.push_back(UT_Vector3(0.369822, 0.487842, -0.098109));
	pieceData.push_back(UT_Vector3(0.373867, 0.483588, -0.103676));
	pieceData.push_back(UT_Vector3(0.581456, 0.130418, -0.171126));
	pieceData.push_back(UT_Vector3(0.583956, 0.123536, -0.167685));
	pieceData.push_back(UT_Vector3(0.583955, -0.094735, 0.185485));
	pieceData.push_back(UT_Vector3(0.581455, -0.094735, 0.193180));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 6
//========================================================================================================
void CCenterComponent::Center_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.290791, 0.487841, -0.578073));
	pieceData.push_back(UT_Vector3(0.459920, 0.487841, -0.455193));
	pieceData.push_back(UT_Vector3(0.570992, 0.305755, -0.487030));
	pieceData.push_back(UT_Vector3(0.286746, 0.305755, -0.693547));
	pieceData.push_back(UT_Vector3(0.466465, 0.188967, -0.635152));
	pieceData.push_back(UT_Vector3(0.451016, 0.164457, -0.627652));
	pieceData.push_back(UT_Vector3(0.570993, 0.290607, -0.462519));
	pieceData.push_back(UT_Vector3(0.451016, 0.487841, -0.427790));
	pieceData.push_back(UT_Vector3(0.263435, 0.483588, -0.566704));
	pieceData.push_back(UT_Vector3(0.263435, 0.290607, -0.685972));
	pieceData.push_back(UT_Vector3(0.286746, 0.483588, -0.583640));
	pieceData.push_back(UT_Vector3(0.466465, 0.483588, -0.453067));
	pieceData.push_back(UT_Vector3(0.570992, 0.298874, -0.491283));
	pieceData.push_back(UT_Vector3(0.290791, 0.298874, -0.694861));
	pieceData.push_back(UT_Vector3(0.459920, 0.188967, -0.639908));
	pieceData.push_back(UT_Vector3(0.304870, 0.308781, -0.678509));
	pieceData.push_back(UT_Vector3(0.304870, 0.468785, -0.579621));
	pieceData.push_back(UT_Vector3(0.457043, 0.468785, -0.469061));
	pieceData.push_back(UT_Vector3(0.551091, 0.308781, -0.499619));
	pieceData.push_back(UT_Vector3(0.457042, 0.209893, -0.629065));
	pieceData.push_back(UT_Vector3(0.457561, 0.164457, -0.622897));
	pieceData.push_back(UT_Vector3(0.570992, 0.283725, -0.466773));
	pieceData.push_back(UT_Vector3(0.457561, 0.483588, -0.425663));
	pieceData.push_back(UT_Vector3(0.267481, 0.487841, -0.561136));
	pieceData.push_back(UT_Vector3(0.267480, 0.283725, -0.687287));
	pieceData.push_back(UT_Vector3(0.570993, 0.123536, -0.207580));
	pieceData.push_back(UT_Vector3(0.570993, 0.130418, -0.203327));
	pieceData.push_back(UT_Vector3(0.363404, 0.483589, -0.135878));
	pieceData.push_back(UT_Vector3(0.356859, 0.487842, -0.138004));
	pieceData.push_back(UT_Vector3(0.020974, 0.487842, -0.382039));
	pieceData.push_back(UT_Vector3(0.016929, 0.483588, -0.387607));
	pieceData.push_back(UT_Vector3(0.016929, 0.130418, -0.605878));
	pieceData.push_back(UT_Vector3(0.020974, 0.123536, -0.607192));
	pieceData.push_back(UT_Vector3(0.356859, -0.094735, -0.498056));
	pieceData.push_back(UT_Vector3(0.363404, -0.094735, -0.493301));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 7
//========================================================================================================
void CCenterComponent::Center_LightGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.639639, -0.487841, -0.097925));
	pieceData.push_back(UT_Vector3(0.575038, -0.487841, -0.296748));
	pieceData.push_back(UT_Vector3(0.639639, -0.305755, -0.392546));
	pieceData.push_back(UT_Vector3(0.748212, -0.305755, -0.058394));
	pieceData.push_back(UT_Vector3(0.748212, -0.188967, -0.247362));
	pieceData.push_back(UT_Vector3(0.736305, -0.164456, -0.234987));
	pieceData.push_back(UT_Vector3(0.616328, -0.290607, -0.400120));
	pieceData.push_back(UT_Vector3(0.546224, -0.487841, -0.296748));
	pieceData.push_back(UT_Vector3(0.620374, -0.483588, -0.075421));
	pieceData.push_back(UT_Vector3(0.733805, -0.290607, -0.038565));
	pieceData.push_back(UT_Vector3(0.643684, -0.483588, -0.092357));
	pieceData.push_back(UT_Vector3(0.575038, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(0.643684, -0.298873, -0.391231));
	pieceData.push_back(UT_Vector3(0.750712, -0.298873, -0.061835));
	pieceData.push_back(UT_Vector3(0.750712, -0.188967, -0.239668));
	pieceData.push_back(UT_Vector3(0.739511, -0.308781, -0.080277));
	pieceData.push_back(UT_Vector3(0.645463, -0.468785, -0.110836));
	pieceData.push_back(UT_Vector3(0.587338, -0.468785, -0.289726));
	pieceData.push_back(UT_Vector3(0.645463, -0.308781, -0.369728));
	pieceData.push_back(UT_Vector3(0.739511, -0.209893, -0.240281));
	pieceData.push_back(UT_Vector3(0.733805, -0.164456, -0.242681));
	pieceData.push_back(UT_Vector3(0.620374, -0.283725, -0.398806));
	pieceData.push_back(UT_Vector3(0.546224, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(0.616329, -0.487841, -0.080989));
	pieceData.push_back(UT_Vector3(0.736305, -0.283725, -0.042006));
	pieceData.push_back(UT_Vector3(0.373867, -0.123536, -0.478900));
	pieceData.push_back(UT_Vector3(0.369822, -0.130418, -0.480215));
	pieceData.push_back(UT_Vector3(0.241526, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(0.241526, -0.487842, -0.296748));
	pieceData.push_back(UT_Vector3(0.369822, -0.487842, 0.098109));
	pieceData.push_back(UT_Vector3(0.373867, -0.483588, 0.103676));
	pieceData.push_back(UT_Vector3(0.581456, -0.130418, 0.171126));
	pieceData.push_back(UT_Vector3(0.583956, -0.123536, 0.167685));
	pieceData.push_back(UT_Vector3(0.583955, 0.094736, -0.185485));
	pieceData.push_back(UT_Vector3(0.581455, 0.094736, -0.193179));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 8
//========================================================================================================
void CCenterComponent::Center_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.290791, -0.487841, 0.578073));
	pieceData.push_back(UT_Vector3(0.459920, -0.487841, 0.455193));
	pieceData.push_back(UT_Vector3(0.570993, -0.305755, 0.487030));
	pieceData.push_back(UT_Vector3(0.286746, -0.305755, 0.693547));
	pieceData.push_back(UT_Vector3(0.466465, -0.188967, 0.635152));
	pieceData.push_back(UT_Vector3(0.451016, -0.164456, 0.627653));
	pieceData.push_back(UT_Vector3(0.570993, -0.290607, 0.462519));
	pieceData.push_back(UT_Vector3(0.451016, -0.487841, 0.427790));
	pieceData.push_back(UT_Vector3(0.263436, -0.483588, 0.566704));
	pieceData.push_back(UT_Vector3(0.263435, -0.290607, 0.685973));
	pieceData.push_back(UT_Vector3(0.286746, -0.483588, 0.583640));
	pieceData.push_back(UT_Vector3(0.466465, -0.483588, 0.453067));
	pieceData.push_back(UT_Vector3(0.570993, -0.298873, 0.491283));
	pieceData.push_back(UT_Vector3(0.290791, -0.298873, 0.694861));
	pieceData.push_back(UT_Vector3(0.459920, -0.188967, 0.639908));
	pieceData.push_back(UT_Vector3(0.304870, -0.308781, 0.678509));
	pieceData.push_back(UT_Vector3(0.304870, -0.468785, 0.579621));
	pieceData.push_back(UT_Vector3(0.457043, -0.468785, 0.469061));
	pieceData.push_back(UT_Vector3(0.551091, -0.308781, 0.499619));
	pieceData.push_back(UT_Vector3(0.457043, -0.209893, 0.629065));
	pieceData.push_back(UT_Vector3(0.457561, -0.164456, 0.622897));
	pieceData.push_back(UT_Vector3(0.570993, -0.283725, 0.466773));
	pieceData.push_back(UT_Vector3(0.457561, -0.483588, 0.425663));
	pieceData.push_back(UT_Vector3(0.267481, -0.487841, 0.561136));
	pieceData.push_back(UT_Vector3(0.267481, -0.283725, 0.687287));
	pieceData.push_back(UT_Vector3(0.570993, -0.123536, 0.207580));
	pieceData.push_back(UT_Vector3(0.570993, -0.130418, 0.203327));
	pieceData.push_back(UT_Vector3(0.363405, -0.483588, 0.135878));
	pieceData.push_back(UT_Vector3(0.356859, -0.487842, 0.138005));
	pieceData.push_back(UT_Vector3(0.020974, -0.487842, 0.382039));
	pieceData.push_back(UT_Vector3(0.016929, -0.483588, 0.387607));
	pieceData.push_back(UT_Vector3(0.016929, -0.130418, 0.605878));
	pieceData.push_back(UT_Vector3(0.020974, -0.123536, 0.607192));
	pieceData.push_back(UT_Vector3(0.356859, 0.094736, 0.498056));
	pieceData.push_back(UT_Vector3(0.363404, 0.094736, 0.493301));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 9
//========================================================================================================
void CCenterComponent::Center_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.459920, -0.487841, 0.455193));
	pieceData.push_back(UT_Vector3(-0.290792, -0.487841, 0.578073));
	pieceData.push_back(UT_Vector3(-0.286746, -0.305755, 0.693547));
	pieceData.push_back(UT_Vector3(-0.570993, -0.305755, 0.487030));
	pieceData.push_back(UT_Vector3(-0.459920, -0.188967, 0.639908));
	pieceData.push_back(UT_Vector3(-0.457561, -0.164456, 0.622897));
	pieceData.push_back(UT_Vector3(-0.263436, -0.290607, 0.685973));
	pieceData.push_back(UT_Vector3(-0.267481, -0.487841, 0.561136));
	pieceData.push_back(UT_Vector3(-0.457561, -0.483588, 0.425663));
	pieceData.push_back(UT_Vector3(-0.570993, -0.290607, 0.462519));
	pieceData.push_back(UT_Vector3(-0.466465, -0.483588, 0.453067));
	pieceData.push_back(UT_Vector3(-0.286746, -0.483588, 0.583640));
	pieceData.push_back(UT_Vector3(-0.290791, -0.298873, 0.694861));
	pieceData.push_back(UT_Vector3(-0.570993, -0.298873, 0.491283));
	pieceData.push_back(UT_Vector3(-0.466465, -0.188967, 0.635152));
	pieceData.push_back(UT_Vector3(-0.551091, -0.308781, 0.499619));
	pieceData.push_back(UT_Vector3(-0.457043, -0.468785, 0.469061));
	pieceData.push_back(UT_Vector3(-0.304870, -0.468785, 0.579621));
	pieceData.push_back(UT_Vector3(-0.304870, -0.308781, 0.678509));
	pieceData.push_back(UT_Vector3(-0.457043, -0.209893, 0.629065));
	pieceData.push_back(UT_Vector3(-0.451016, -0.164456, 0.627652));
	pieceData.push_back(UT_Vector3(-0.267481, -0.283725, 0.687287));
	pieceData.push_back(UT_Vector3(-0.263436, -0.483588, 0.566704));
	pieceData.push_back(UT_Vector3(-0.451016, -0.487841, 0.427790));
	pieceData.push_back(UT_Vector3(-0.570993, -0.283725, 0.466772));
	pieceData.push_back(UT_Vector3(-0.020974, -0.123536, 0.607192));
	pieceData.push_back(UT_Vector3(-0.016929, -0.130418, 0.605878));
	pieceData.push_back(UT_Vector3(-0.016929, -0.483588, 0.387607));
	pieceData.push_back(UT_Vector3(-0.020975, -0.487842, 0.382039));
	pieceData.push_back(UT_Vector3(-0.356859, -0.487842, 0.138005));
	pieceData.push_back(UT_Vector3(-0.363405, -0.483588, 0.135878));
	pieceData.push_back(UT_Vector3(-0.570993, -0.130418, 0.203327));
	pieceData.push_back(UT_Vector3(-0.570993, -0.123536, 0.207581));
	pieceData.push_back(UT_Vector3(-0.363404, 0.094736, 0.493301));
	pieceData.push_back(UT_Vector3(-0.356859, 0.094736, 0.498056));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 10
//========================================================================================================
void CCenterComponent::Center_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(-0.575038, -0.487841, -0.296748));
	pieceData.push_back(UT_Vector3(-0.639639, -0.487841, -0.097925));
	pieceData.push_back(UT_Vector3(-0.748212, -0.305755, -0.058394));
	pieceData.push_back(UT_Vector3(-0.639639, -0.305755, -0.392546));
	pieceData.push_back(UT_Vector3(-0.750711, -0.188967, -0.239668));
	pieceData.push_back(UT_Vector3(-0.733805, -0.164456, -0.242681));
	pieceData.push_back(UT_Vector3(-0.733805, -0.290607, -0.038565));
	pieceData.push_back(UT_Vector3(-0.616329, -0.487841, -0.080989));
	pieceData.push_back(UT_Vector3(-0.546224, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(-0.616328, -0.290607, -0.400120));
	pieceData.push_back(UT_Vector3(-0.575038, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(-0.643684, -0.483588, -0.092357));
	pieceData.push_back(UT_Vector3(-0.750712, -0.298873, -0.061835));
	pieceData.push_back(UT_Vector3(-0.643684, -0.298873, -0.391232));
	pieceData.push_back(UT_Vector3(-0.748211, -0.188967, -0.247362));
	pieceData.push_back(UT_Vector3(-0.645463, -0.308781, -0.369728));
	pieceData.push_back(UT_Vector3(-0.587338, -0.468785, -0.289726));
	pieceData.push_back(UT_Vector3(-0.645463, -0.468785, -0.110836));
	pieceData.push_back(UT_Vector3(-0.739511, -0.308781, -0.080278));
	pieceData.push_back(UT_Vector3(-0.739511, -0.209893, -0.240282));
	pieceData.push_back(UT_Vector3(-0.736305, -0.164456, -0.234987));
	pieceData.push_back(UT_Vector3(-0.736305, -0.283725, -0.042006));
	pieceData.push_back(UT_Vector3(-0.620374, -0.483588, -0.075421));
	pieceData.push_back(UT_Vector3(-0.546224, -0.487841, -0.296748));
	pieceData.push_back(UT_Vector3(-0.620373, -0.283725, -0.398806));
	pieceData.push_back(UT_Vector3(-0.583956, -0.123536, 0.167685));
	pieceData.push_back(UT_Vector3(-0.581455, -0.130418, 0.171126));
	pieceData.push_back(UT_Vector3(-0.373868, -0.483588, 0.103676));
	pieceData.push_back(UT_Vector3(-0.369822, -0.487842, 0.098109));
	pieceData.push_back(UT_Vector3(-0.241526, -0.487842, -0.296748));
	pieceData.push_back(UT_Vector3(-0.241526, -0.483588, -0.303630));
	pieceData.push_back(UT_Vector3(-0.369822, -0.130418, -0.480215));
	pieceData.push_back(UT_Vector3(-0.373867, -0.123536, -0.478900));
	pieceData.push_back(UT_Vector3(-0.581455, 0.094736, -0.193180));
	pieceData.push_back(UT_Vector3(-0.583955, 0.094736, -0.185485));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 11
//========================================================================================================
void CCenterComponent::Center_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.104527, -0.487841, -0.638593));
	pieceData.push_back(UT_Vector3(-0.104527, -0.487841, -0.638594));
	pieceData.push_back(UT_Vector3(-0.175674, -0.305755, -0.729636));
	pieceData.push_back(UT_Vector3(0.175674, -0.305755, -0.729636));
	pieceData.push_back(UT_Vector3(-0.004045, -0.188967, -0.788030));
	pieceData.push_back(UT_Vector3(0.004045, -0.164456, -0.772882));
	pieceData.push_back(UT_Vector3(-0.190081, -0.290607, -0.709807));
	pieceData.push_back(UT_Vector3(-0.113431, -0.487841, -0.611190));
	pieceData.push_back(UT_Vector3(0.119976, -0.483588, -0.613317));
	pieceData.push_back(UT_Vector3(0.190081, -0.290607, -0.709807));
	pieceData.push_back(UT_Vector3(0.111073, -0.483588, -0.640720));
	pieceData.push_back(UT_Vector3(-0.111072, -0.483588, -0.640720));
	pieceData.push_back(UT_Vector3(-0.173174, -0.298873, -0.733077));
	pieceData.push_back(UT_Vector3(0.173174, -0.298873, -0.733077));
	pieceData.push_back(UT_Vector3(0.004045, -0.188967, -0.788030));
	pieceData.push_back(UT_Vector3(0.152173, -0.308781, -0.728123));
	pieceData.push_back(UT_Vector3(0.094048, -0.468785, -0.648121));
	pieceData.push_back(UT_Vector3(-0.094048, -0.468785, -0.648122));
	pieceData.push_back(UT_Vector3(-0.152173, -0.308781, -0.728123));
	pieceData.push_back(UT_Vector3(0.000000, -0.209893, -0.777567));
	pieceData.push_back(UT_Vector3(-0.004045, -0.164456, -0.772882));
	pieceData.push_back(UT_Vector3(-0.187581, -0.283725, -0.713248));
	pieceData.push_back(UT_Vector3(-0.119976, -0.483588, -0.613317));
	pieceData.push_back(UT_Vector3(0.113431, -0.487841, -0.611190));
	pieceData.push_back(UT_Vector3(0.187581, -0.283725, -0.713248));
	pieceData.push_back(UT_Vector3(-0.339930, -0.123536, -0.503557));
	pieceData.push_back(UT_Vector3(-0.342430, -0.130418, -0.500116));
	pieceData.push_back(UT_Vector3(-0.214133, -0.483588, -0.323531));
	pieceData.push_back(UT_Vector3(-0.207588, -0.487842, -0.321405));
	pieceData.push_back(UT_Vector3(0.207588, -0.487842, -0.321405));
	pieceData.push_back(UT_Vector3(0.214133, -0.483588, -0.323531));
	pieceData.push_back(UT_Vector3(0.342430, -0.130418, -0.500116));
	pieceData.push_back(UT_Vector3(0.339930, -0.123536, -0.503557));
	pieceData.push_back(UT_Vector3(0.004045, 0.094736, -0.612692));
	pieceData.push_back(UT_Vector3(-0.004045, 0.094736, -0.612692));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
//	CENTER 12
//========================================================================================================
void CCenterComponent::Center_DarkGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName)
{
	pieceData.clear();
	faceList.clear();

	pieceData.push_back(UT_Vector3(0.173174, -0.789344, 0.060521));
	pieceData.push_back(UT_Vector3(0.004045, -0.789344, 0.183400));
	pieceData.push_back(UT_Vector3(-0.173174, -0.789344, 0.060521));
	pieceData.push_back(UT_Vector3(0.111072, -0.789344, -0.145996));
	pieceData.push_back(UT_Vector3(-0.111072, -0.789344, -0.145996));
	pieceData.push_back(UT_Vector3(-0.113431, -0.764834, -0.163007));
	pieceData.push_back(UT_Vector3(-0.187581, -0.764834, 0.065202));
	pieceData.push_back(UT_Vector3(0.004045, -0.764834, 0.198548));
	pieceData.push_back(UT_Vector3(0.190081, -0.764834, 0.057508));
	pieceData.push_back(UT_Vector3(0.119976, -0.764834, -0.158252));
	pieceData.push_back(UT_Vector3(0.175674, -0.789344, 0.052826));
	pieceData.push_back(UT_Vector3(-0.004045, -0.789344, 0.183400));
	pieceData.push_back(UT_Vector3(-0.175674, -0.789344, 0.052826));
	pieceData.push_back(UT_Vector3(0.104527, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(-0.104527, -0.789344, -0.150752));
	pieceData.push_back(UT_Vector3(0.094048, -0.789344, -0.129446));
	pieceData.push_back(UT_Vector3(0.152173, -0.789344, 0.049444));
	pieceData.push_back(UT_Vector3(-0.000000, -0.789344, 0.160004));
	pieceData.push_back(UT_Vector3(-0.152173, -0.789344, 0.049444));
	pieceData.push_back(UT_Vector3(-0.094048, -0.789344, -0.129446));
	pieceData.push_back(UT_Vector3(-0.119976, -0.764834, -0.158252));
	pieceData.push_back(UT_Vector3(-0.190081, -0.764834, 0.057508));
	pieceData.push_back(UT_Vector3(-0.004045, -0.764834, 0.198548));
	pieceData.push_back(UT_Vector3(0.187581, -0.764834, 0.065202));
	pieceData.push_back(UT_Vector3(0.113431, -0.764834, -0.163007));
	pieceData.push_back(UT_Vector3(-0.342430, -0.505642, 0.107009));
	pieceData.push_back(UT_Vector3(-0.339930, -0.505642, 0.114703));
	pieceData.push_back(UT_Vector3(-0.004045, -0.505642, 0.358738));
	pieceData.push_back(UT_Vector3(0.004045, -0.505642, 0.358738));
	pieceData.push_back(UT_Vector3(0.339930, -0.505642, 0.114703));
	pieceData.push_back(UT_Vector3(0.342430, -0.505642, 0.107009));
	pieceData.push_back(UT_Vector3(0.214133, -0.505642, -0.287848));
	pieceData.push_back(UT_Vector3(0.207588, -0.505642, -0.292603));
	pieceData.push_back(UT_Vector3(-0.207588, -0.505642, -0.292603));
	pieceData.push_back(UT_Vector3(-0.214133, -0.505642, -0.287848));

	int faces[120] = { 14, 4, 16,
		11, 1, 17,
		2, 12, 18,
		3, 13, 19,
		5, 15, 20,
		4, 11, 17, 16,
		1, 2, 18, 17,
		12, 3, 19, 18,
		13, 5, 20, 19,
		15, 14, 16, 20,
		3, 12, 23, 7,
		2, 1, 24, 8,
		11, 4, 10, 9,
		5, 13, 22, 21,
		14, 15, 6, 25,
		1, 11, 9, 24,
		4, 14, 25, 10,
		21, 6, 15, 5,
		7, 22, 13, 3,
		8, 23, 12, 2,
		9, 31, 30, 24,
		25, 33, 32, 10,
		7, 23, 28, 27,
		8, 24, 30, 29,
		9, 10, 32, 31,
		21, 22, 26, 35,
		25, 6, 34, 33,
		22, 7, 27, 26,
		23, 8, 29, 28,
		6, 21, 35, 34,
		19, 20, 16, 17, 18 };

	for (int i = 0; i < 120; i++)
	{
		faceList.push_back(faces[i]);
	}
}

//========================================================================================================
void CCenterComponent::buildAllCenterGeometryData(CentersGeometryData &centerGeometry)
{
	vector<UT_Vector3> pieceData;
	vector<int> faceList;
	vector<int> faceListColor;
	string pieceName;

	//----------------------------------------------------------------------------------------------------
	Center_Yellow(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Yellow = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_White(pieceData, faceList, pieceName);
	centerGeometry.posCenter_White = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Blue(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Blue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Green(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Green = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Orange(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Orange = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Purple(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Purple = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_LightGreen(pieceData, faceList, pieceName);
	centerGeometry.posCenter_LightGreen = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Red(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Red = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Pink(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Pink = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_Gray(pieceData, faceList, pieceName);
	centerGeometry.posCenter_Gray = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_LightBlue(pieceData, faceList, pieceName);
	centerGeometry.posCenter_LightBlue = pieceData;

	//----------------------------------------------------------------------------------------------------
	Center_DarkGreen(pieceData, faceList, pieceName);
	centerGeometry.posCenter_DarkGreen = pieceData;

	//----------------------------------------------------------------------------------------------------
	CenterColorPiece(pieceData, faceListColor, pieceName);
	centerGeometry.posCenter_Color = pieceData;

	centerGeometry.faceListBlack = faceList;
	centerGeometry.faceListColor = faceListColor;
}

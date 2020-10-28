//===================================================================================================
//
//	Arquivo: GeometryCenters.h
//
//	Descrição:	controi geometria dos centros
//
//===================================================================================================

#ifndef __GEOMETRY_CENTERS__
#define __GEOMETRY_CENTERS__

#include <HOM/HOM_Module.h>
#include <HOM/HOM_ui.h>
#include <SOP/SOP_Node.h>

#include <vector>
#include <string>
using namespace std;


//========================================================================================================
typedef struct CentersGeometryData
{
	//position list color
	vector<UT_Vector3> posCenter_Color;

	//position list black
	vector<UT_Vector3> posCenter_Yellow;
	vector<UT_Vector3> posCenter_White;
	vector<UT_Vector3> posCenter_Blue;
	vector<UT_Vector3> posCenter_Green;
	vector<UT_Vector3> posCenter_Orange;
	vector<UT_Vector3> posCenter_Purple;
	vector<UT_Vector3> posCenter_LightGreen;
	vector<UT_Vector3> posCenter_Red;
	vector<UT_Vector3> posCenter_Pink;
	vector<UT_Vector3> posCenter_Gray;
	vector<UT_Vector3> posCenter_LightBlue;
	vector<UT_Vector3> posCenter_DarkGreen;

	//facelist
	vector<int> faceListBlack;
	vector<int> faceListColor;

	//pieceName attribute
	string pieceNameIntermediate_Yellow_Blue_Green;
}SCentersGeometryData, *PCentersGeometryData;

//========================================================================================================
class CCenterComponent
{
public:
	void buildAllCenterGeometryData(CentersGeometryData &centerGeometry);

private:

	//colors
	void CenterColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	//blacks
	void Center_Yellow(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_LightGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Center_DarkGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

};

#endif	//__GEOMETRY_INTERMEDIATES__
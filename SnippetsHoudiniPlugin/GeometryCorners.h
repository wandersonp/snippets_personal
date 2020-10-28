//===================================================================================================
//
//	Arquivo: SOP_Megamix.h
//
//	Descrição:	cria um point cloud num box
//
//===================================================================================================

#ifndef __GEOMETRY_CORNERS__
#define __GEOMETRY_CORNERS__

#include <HOM/HOM_Module.h>
#include <HOM/HOM_ui.h>
#include <SOP/SOP_Node.h>

#include <vector>
#include <string>
using namespace std;

//"controller_yellow");
//"controller_white");
//"controller_blue");
//"controller_green");
//"controller_orange");
//"controller_purple");
//"controller_light_green");
//"controller_red");
//"controller_pink");
//"controller_gray");
//"controller_light_blue");
//"controller_dark_green");

//========================================================================================================
typedef struct CornerBlackGeometryData
{
	//position list color
	vector<UT_Vector3> posCorner_Color;

	//position list black
	vector<UT_Vector3> posCorner_Yellow_Blue_Green;
	vector<UT_Vector3> posCorner_Yellow_Blue_White;
	vector<UT_Vector3> posCorner_Yellow_Purple_White;
	vector<UT_Vector3> posCorner_Yellow_Purple_Orange;
	vector<UT_Vector3> posCorner_Yellow_Green_Orange;

	vector<UT_Vector3> posCorner_LightGreen_DarkGreen_Red;
	vector<UT_Vector3> posCorner_LightGreen_Red_Pink;
	vector<UT_Vector3> posCorner_LightGreen_Pink_Gray;
	vector<UT_Vector3> posCorner_LightGreen_Gray_LightBlue;
	vector<UT_Vector3> posCorner_LightGreen_LightBlue_DarkGreen;

	vector<UT_Vector3> posCorner_Purple_DarkGreen_LightBlue;
	vector<UT_Vector3> posCorner_Gray_Orange_LightBlue;
	vector<UT_Vector3> posCorner_Pink_LightGreen_Gray;
	vector<UT_Vector3> posCorner_Red_Blue_Pink;
	vector<UT_Vector3> posCorner_DarkGreen_White_Red;

	vector<UT_Vector3> posCorner_DarkGreen_Purple_White;
	vector<UT_Vector3> posCorner_LightBlue_Orange_Purple;
	vector<UT_Vector3> posCorner_Gray_LightGreen_Orange;
	vector<UT_Vector3> posCorner_Pink_Blue_Green;
	vector<UT_Vector3> posCorner_Red_White_Blue;

	//facelist
	vector<int> faceListBlack;
	vector<int> faceListColor;
	//vector<int> faceListCorner_Yellow_Blue_White;
	//vector<int> faceListCorner_Yellow_Purple_White;
	//vector<int> faceListCorner_Yellow_Purple_Orange;
	//vector<int> faceListCorner_Yellow_Green_Orange;

	//vector<int> faceListCorner_LightGreen_DarkGreen_Red;
	//vector<int> faceListCorner_LightGreen_Red_Pink;
	//vector<int> faceListCorner_LightGreen_Pink_Gray;
	//vector<int> faceListCorner_LightGreen_Gray_LightBlue;
	//vector<int> faceListCorner_LightGreen_LightBlue_DarkGreen;

	//vector<int> faceListCorner_Purple_DarkGreen_LightBlue;
	//vector<int> faceListCorner_Gray_Orange_LightBlue;
	//vector<int> faceListCorner_Pink_LightGreen_Gray;
	//vector<int> faceListCorner_Red_Blue_Pink;
	//vector<int> faceListCorner_DarkGreen_White_Red;

	//vector<int> faceListCorner_DarkGreen_Purple_White;
	//vector<int> faceListCorner_LightBlue_Orange_Purple;
	//vector<int> faceListCorner_Gray_LightGreen_Orange;
	//vector<int> faceListCorner_Pink_Blue_Green;
	//vector<int> faceListCorner_Red_White_Blue;

	//pieceName attribute
	string pieceNameCorner_Yellow_Blue_Green;
	string pieceNameCorner_Yellow_Blue_White;
	string pieceNameCorner_Yellow_Purple_White;
	string pieceNameCorner_Yellow_Purple_Orange;
	string pieceNameCorner_Yellow_Green_Orange;

	string pieceNameCorner_LightGreen_DarkGreen_Red;
	string pieceNameCorner_LightGreen_Red_Pink;
	string pieceNameCorner_LightGreen_Pink_Gray;
	string pieceNameCorner_LightGreen_Gray_LightBlue;
	string pieceNameCorner_LightGreen_LightBlue_DarkGreen;

	string pieceNameCorner_Purple_DarkGreen_LightBlue;
	string pieceNameCorner_Gray_Orange_LightBlue;
	string pieceNameCorner_Pink_LightGreen_Gray;
	string pieceNameCorner_Red_Blue_Pink;
	string pieceNameCorner_DarkGreen_White_Red;

	string pieceNameCorner_DarkGreen_Purple_White;
	string pieceNameCorner_LightBlue_Orange_Purple;
	string pieceNameCorner_Gray_LightGreen_Orange;
	string pieceNameCorner_Pink_Blue_Green;
	string pieceNameCorner_Red_White_Blue;
}SCornerBlackGeometryData, *PCornerBlackGeometryData;

//========================================================================================================
class CCornerComponent
{
public:
	void buildAllBlackCornerGeometryData(CornerBlackGeometryData &cornerGeometry);

private:
	//colors
	void CornerColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	//black
	void Corner_Yellow_Blue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Yellow_Blue_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Yellow_Purple_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Yellow_Purple_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Yellow_Green_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Corner_LightGreen_DarkGreen_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_LightGreen_Red_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_LightGreen_Pink_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_LightGreen_Gray_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_LightGreen_LightBlue_DarkGreen(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Corner_Purple_DarkGreen_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Gray_Orange_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Pink_LightGreen_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Red_Blue_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_DarkGreen_White_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Corner_DarkGreen_Purple_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_LightBlue_Orange_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Gray_LightGreen_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Pink_Blue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Corner_Red_White_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
};

#endif	//__GEOMETRY_CORNERS__
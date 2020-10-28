//===================================================================================================
//
//	Arquivo: GeometryIntermediates.h
//
//	Descrição:	controi geometria dos intermediarios
//
//===================================================================================================

#ifndef __GEOMETRY_INTERMEDIATES__
#define __GEOMETRY_INTERMEDIATES__

#include <HOM/HOM_Module.h>
#include <HOM/HOM_ui.h>
#include <SOP/SOP_Node.h>

#include <vector>
#include <string>
using namespace std;


//========================================================================================================
typedef struct IntermediateGeometryData
{
	//position list color
	vector<UT_Vector3> posIntermediate_Color;

	//position list black
	vector<UT_Vector3> posIntermediate_Yellow_Orange;
	vector<UT_Vector3> posIntermediate_Yellow_Purple;
	vector<UT_Vector3> posIntermediate_Yellow_White;
	vector<UT_Vector3> posIntermediate_Yellow_Blue;
	vector<UT_Vector3> posIntermediate_Yellow_Green;

	vector<UT_Vector3> posIntermediate_LightGreen_Pink;
	vector<UT_Vector3> posIntermediate_LightGreen_Red;
	vector<UT_Vector3> posIntermediate_LightGreen_Green;
	vector<UT_Vector3> posIntermediate_LightGreen_LightBlue;
	vector<UT_Vector3> posIntermediate_LightGreen_Gray;

	vector<UT_Vector3> posIntermediate_Green_Blue;
	vector<UT_Vector3> posIntermediate_Blue_White;
	vector<UT_Vector3> posIntermediate_White_Purple;
	vector<UT_Vector3> posIntermediate_Purple_Orange;
	vector<UT_Vector3> posIntermediate_Orange_Green;

	vector<UT_Vector3> posIntermediate_Pink_Red;
	vector<UT_Vector3> posIntermediate_Gray_Pink;
	vector<UT_Vector3> posIntermediate_LightBlue_Gray;
	vector<UT_Vector3> posIntermediate_LightBlue_Green;
	vector<UT_Vector3> posIntermediate_Green_Red;

	vector<UT_Vector3> posIntermediate_Pink_Blue;
	vector<UT_Vector3> posIntermediate_Red_Blue;
	vector<UT_Vector3> posIntermediate_Red_White;
	vector<UT_Vector3> posIntermediate_White_Green;
	vector<UT_Vector3> posIntermediate_Purple_Red;
	vector<UT_Vector3> posIntermediate_Purple_LightBlue;
	vector<UT_Vector3> posIntermediate_Orange_LightBlue;
	vector<UT_Vector3> posIntermediate_Orange_Gray;

	vector<UT_Vector3> posIntermediate_Green_Gray;
	vector<UT_Vector3> posIntermediate_Green_Pink;

	//facelist
	vector<int> faceListBlack;
	vector<int> faceListColor;

	//pieceName attribute
	string pieceNameIntermediate_Yellow_Blue_Green;
}SIntermediateBlackGeometryData, *PIntermediateBlackGeometryData;

//========================================================================================================
class CIntermediateComponent
{
public:
	void buildAllIntermediateGeometryData(IntermediateGeometryData &intermediateGeometry);

private:

	//colors
	void IntermediateColorPiece(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	//black
	void Intermediate_Yellow_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Yellow_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Yellow_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Yellow_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Yellow_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Intermediate_LightGreen_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightGreen_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightGreen_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightGreen_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightGreen_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Intermediate_Green_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Blue_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_White_Purple(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Purple_Orange(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Orange_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Intermediate_Pink_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Gray_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightBlue_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_LightBlue_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Green_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Intermediate_Pink_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Red_Blue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Red_White(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_White_Green(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Purple_Red(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Purple_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Orange_LightBlue(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Orange_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

	void Intermediate_Green_Gray(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);
	void Intermediate_Green_Pink(vector<UT_Vector3> &pieceData, vector<int> &faceList, string pieceName);

};

#endif	//__GEOMETRY_INTERMEDIATES__
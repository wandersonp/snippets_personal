//===================================================================================================
//
//	Arquivo: SOP_Megamix.cpp
//
//	Descrição:	cria um point cloud num box
//
//===================================================================================================

#include <UT/UT_DSOVersion.h>

#include <UT/UT_Interrupt.h>
#include <UT/UT_Vector3.h>
#include <UT/UT_Vector4.h>
#include <GEO/GEO_PrimPart.h>
#include <GU/GU_Detail.h>
#include <GU/GU_RayIntersect.h>
#include <PRM/PRM_Include.h>
#include <OP/OP_Director.h>
#include <OP/OP_Operator.h>
#include <OP/OP_OperatorTable.h>
#include <GU/GU_PrimPoly.h>

#include "SOP_Megamix.h"

#define M_PI    3.14159265358979323846

using namespace HDK_Sample;


//! used in xform rotation conversion
inline fpreal DegreesToRadians(fpreal iDegrees)
{
	return (iDegrees * (fpreal)M_PI) / (fpreal)180.0;
}

inline fpreal RadiansToDegrees(fpreal iRadians)
{
	return iRadians * ((fpreal)180.0 / (fpreal)M_PI);
}

//UT_Vector3 *rotate_vector_by_quaternion(UT_Vector3 *v, UT_Quaternion *q)
//{
//	// Extract the vector part of the quaternion
//	//UT_Vector3 u(q->x, q->y, q->z);
//
//	// Extract the scalar part of the quaternion
//	float s = q->w;
//
//	// Do the math
//	return NULL;// new UT_Vector3(u * 2.0f * dot(u, v) + (s * s - dot(u, u)) * v + 2.0f * s * cross(u, v));
//	//return &vector;
//}

//UT_Vector3 *rotateByQuaternion(UT_Vector3 *value, UT_Quaternion *rotation)
//{
//	float num12 = rotation->x + rotation->x;
//	//float num2 = rotation->y + rotation->y;
//	//float num = rotation->z + rotation->z;
//	//float num11 = rotation->w * num12;
//	//float num10 = rotation->w * num2;
//	//float num9 = rotation->w * num;
//	//float num8 = rotation->x * num12;
//	//float num7 = rotation->x * num2;
//	//float num6 = rotation->x * num;
//	//float num5 = rotation->y * num2;
//	//float num4 = rotation->y * num;
//	//float num3 = rotation->z * num;
//	//float num15 = ((value->x * ((1.0f - num5) - num3)) + (value->y * (num7 - num9))) + (value->z * (num6 + num10));
//	//float num14 = ((value->x * (num7 + num9)) + (value->y * ((1.0f - num8) - num3))) + (value->z * (num4 - num11));
//	//float num13 = ((value->x * (num6 - num10)) + (value->y * (num4 + num11))) + (value->z * ((1.0f - num8) - num5));
//	
//	return new UT_Vector3(1.0, 2.0, 3.0);
//	//return new UT_Vector3F(num15, num14, num13);
//}

void
newSopOperator(OP_OperatorTable *table)
{
	table->addOperator(new OP_Operator(	"hdk_megamix",
										"SOP_Megamix",
										SOP_Megamix::myConstructor,
										SOP_Megamix::myTemplateList,
										0,	// Min required sources
										0,	// Maximum sources
										0));
}

// The names here have to match the inline evaluation functions
static PRM_Name        names[] = {
	PRM_Name("point", "Total Points"),
};

static PRM_Default	totalPoints[] = { PRM_Default(0), PRM_Default(0), PRM_Default(0) };

PRM_Template SOP_Megamix::myTemplateList[] = {
	PRM_Template(PRM_XYZ_J, 3, &names[0], totalPoints),
	PRM_Template(),
};

int *SOP_Megamix::myOffsets = 0;

OP_Node *SOP_Megamix::myConstructor(OP_Network *net, const char *name, OP_Operator *op)
{
	return new SOP_Megamix(net, name, op);
}

SOP_Megamix::SOP_Megamix(OP_Network *net, const char *name, OP_Operator *op)
	: SOP_Node(net, name, op)
	, Points(NULL)
{
	// Make sure that our offsets are allocated.  Here we allow up to 32
	// parameters, no harm in over allocating.  The definition for this
	// function is in OP/OP_Parameters.h
	if (!myOffsets)
		myOffsets = allocIndirect(32);
}

SOP_Megamix::~SOP_Megamix() 
{}


void SOP_Megamix::buildPieceData()
{
	//	inicializa geometria dos cantos
	m_pieceCorner.push_back(UT_Vector3(0.000000, 0.789344, -0.603006));
	m_pieceCorner.push_back(UT_Vector3(0.000000, 0.487842, -0.372678));
	m_pieceCorner.push_back(UT_Vector3(-0.000000, 0.487842, -0.789345));
	m_pieceCorner.push_back(UT_Vector3(-0.286746, 0.789344, -0.394672));
	m_pieceCorner.push_back(UT_Vector3(-0.286746, 0.487842, -0.581011));
	m_pieceCorner.push_back(UT_Vector3(0.286746, 0.487842, -0.581011));
	m_pieceCorner.push_back(UT_Vector3(0.286746, 0.789344, -0.394672));
	m_pieceCorner.push_back(UT_Vector3(0.000000, 0.789344, -0.186339));

	int faceListCorner[24] = { 1, 3, 5, 4, 6, 3, 1, 7, 8, 7, 1, 4, 2, 5, 3, 6, 4, 5, 2, 8, 7, 8, 2, 6 };
	for (int i = 0; i < 24; i++)
	{
		m_faceListCorner.push_back(faceListCorner[i]);
	}

	//	inicializa geometria dos cantos coloridos
	m_pieceCornerColor.push_back(UT_Vector3(-0.347172, 0.809344, 0.477842));
	m_pieceCornerColor.push_back(UT_Vector3(-0.013764, 0.809344, 0.477842));
	m_pieceCornerColor.push_back(UT_Vector3(-0.116793, 0.809344, 0.160752));
	m_pieceCornerColor.push_back(UT_Vector3(-0.450201, 0.809344, 0.160752));
	m_pieceCornerColor.push_back(UT_Vector3(-0.347172, 0.789344, 0.477842));
	m_pieceCornerColor.push_back(UT_Vector3(-0.013764, 0.789344, 0.477842));
	m_pieceCornerColor.push_back(UT_Vector3(-0.116793, 0.789344, 0.160752));
	m_pieceCornerColor.push_back(UT_Vector3(-0.450201, 0.789344, 0.160752));

	int faceListCornerColor[24] = { 3, 4, 1, 2, 5, 8, 7, 6, 5, 6, 2, 1, 6, 7, 3, 2, 7, 8, 4, 3, 8, 5, 1, 4 };
	for (int i = 0; i < 24; i++)
	{
		m_faceListCornerColor.push_back(faceListCornerColor[i]);
	}

	//	inicializa geometria dos centros
	m_pieceCenter.push_back(UT_Vector3(0.177219, 0.789344, -0.057582));
	m_pieceCenter.push_back(UT_Vector3(-0.000000, 0.789344, -0.186339));
	m_pieceCenter.push_back(UT_Vector3(-0.177219, 0.789344, -0.057582));
	m_pieceCenter.push_back(UT_Vector3(0.000000, 0.487842, -0.372678));
	m_pieceCenter.push_back(UT_Vector3(0.219055, 0.487842, 0.301503));
	m_pieceCenter.push_back(UT_Vector3(0.354438, 0.487842, -0.115164));
	m_pieceCenter.push_back(UT_Vector3(-0.219055, 0.487842, 0.301503));
	m_pieceCenter.push_back(UT_Vector3(0.109527, 0.789344, 0.150752));
	m_pieceCenter.push_back(UT_Vector3(-0.109527, 0.789344, 0.150752));
	m_pieceCenter.push_back(UT_Vector3(-0.354438, 0.487842, -0.115164));

	int faceListCenter[30] = { 2, 4, 10, 3, 1, 6, 4, 2, 8, 5, 6, 1, 3, 10, 7, 9, 9, 7, 5, 8, 5, 7, 10, 4, 6, 2, 3, 9, 8, 1 };
	for (int i = 0; i < 30; i++)
	{
		m_faceListCenter.push_back(faceListCenter[i]);
	}

	//	inicializa geometria dos centros coloridos
	m_pieceCenterColor.push_back(UT_Vector3(0.102262, 0.809344, 0.140752));
	m_pieceCenterColor.push_back(UT_Vector3(0.165463, 0.809344, -0.053762));
	m_pieceCenterColor.push_back(UT_Vector3(-0.000000, 0.809344, -0.173978));
	m_pieceCenterColor.push_back(UT_Vector3(-0.165463, 0.809344, -0.053762));
	m_pieceCenterColor.push_back(UT_Vector3(-0.102262, 0.809344, 0.140752));
	m_pieceCenterColor.push_back(UT_Vector3(0.102262, 0.789344, 0.140752));
	m_pieceCenterColor.push_back(UT_Vector3(0.165463, 0.789344, -0.053762));
	m_pieceCenterColor.push_back(UT_Vector3(-0.000000, 0.789344, -0.173978));
	m_pieceCenterColor.push_back(UT_Vector3(-0.165463, 0.789344, -0.053762));
	m_pieceCenterColor.push_back(UT_Vector3(-0.102262, 0.789344, 0.140752));

	int faceListCenterColor[30] = { 8, 9, 4, 3, 9, 10, 5, 4, 7, 8, 3, 2, 6, 7, 2, 1, 10, 6, 1, 5, 5, 1, 2, 3, 4, 10, 9, 8, 7, 6 };
	for (int i = 0; i < 30; i++)
	{
		m_faceListCenterColor.push_back(faceListCenterColor[i]);
	}

	//	inicializa geometria intermediarias
	m_pieceInbetween.push_back(UT_Vector3(0.219055, 0.487842, 0.301503));
	m_pieceInbetween.push_back(UT_Vector3(-0.109527, 0.487842, 0.638593));
	m_pieceInbetween.push_back(UT_Vector3(0.109527, 0.487842, 0.638593));
	m_pieceInbetween.push_back(UT_Vector3(-0.219055, 0.487842, 0.301503));
	m_pieceInbetween.push_back(UT_Vector3(0.109527, 0.789344, 0.150752));
	m_pieceInbetween.push_back(UT_Vector3(-0.109527, 0.789345, 0.150751));
	m_pieceInbetween.push_back(UT_Vector3(0.000000, 0.789344, 0.487842));

	int faceListInbetween[22] = { 2, 3, 7, 5, 6, 7, 2, 4, 1, 3, 6, 5, 1, 4, 2, 7, 6, 4, 5, 7, 3, 1 };
	for (int i = 0; i < 22; i++)
	{
		m_faceListInbetween.push_back(faceListInbetween[i]);
	}

	//	inicializa geometria intermediarias coloridas
	m_pieceInbetweenColor.push_back(UT_Vector3(-0.095763, 0.809344, 0.160752));
	m_pieceInbetweenColor.push_back(UT_Vector3(-0.000000, 0.809344, 0.455481));
	m_pieceInbetweenColor.push_back(UT_Vector3(0.095763, 0.809344, 0.160752));
	m_pieceInbetweenColor.push_back(UT_Vector3(-0.095764, 0.789344, 0.160752));
	m_pieceInbetweenColor.push_back(UT_Vector3(-0.000000, 0.789344, 0.455481));
	m_pieceInbetweenColor.push_back(UT_Vector3(0.095763, 0.789344, 0.160752));

	int faceListInbetweenColor[18] = { 1, 2, 3, 6, 5, 4, 4, 5, 2, 1, 5, 6, 3, 2, 6, 4, 1, 3 };
	for (int i = 0; i < 18; i++)
	{
		m_faceListInbetweenColor.push_back(faceListInbetweenColor[i]);
	}
}


void SOP_Megamix::cleanPieceData()
{
	m_pieceCorner.clear();
	m_pieceCornerColor.clear();
	m_pieceCenter.clear();
	m_pieceCenterColor.clear();
	m_pieceInbetween.clear();
	m_pieceInbetweenColor.clear();

	m_faceListCorner.clear();
	m_faceListCornerColor.clear();
	m_faceListCenter.clear();
	m_faceListCenterColor.clear();
	m_faceListInbetween.clear();
	m_faceListInbetweenColor.clear();
}

void buildPointAndQuaternion(GA_Offset &ptoff, GA_RWHandleV3 &ph, GA_RWHandleQ &orient, UT_Vector3F &position, UT_QuaternionF &quaternion)
{
	//UT_QuaternionF quaternion(DegreesToRadians(0.0), UT_Vector3F(0.0, -1.0, 0.0));
	quaternion.normalize();
	orient.set(ptoff, quaternion);
	ph.set(ptoff, position);
}

void SOP_Megamix::buildPiece(	OP_Context &context, 
								GU_Detail *gdp, 
								vector<UT_Vector3> piece, 
								UT_IntArray &vertexOrder, 
								GA_Size totalTriangles,
								GA_Size totalQuads,
								GA_Size totalPentagons,
								UT_Vector3 color,
								UT_QuaternionF quatPosition,
								UT_QuaternionF quatRotation,
								UT_Vector3 Offset)
{
	UT_DMatrix4		xform(1.0);
	GEO_PolyCounts	sizelist;
	GA_Size			npoints = static_cast<int>(piece.size());
	GA_Offset		startpt = gdp->appendPointBlock(npoints);
	GA_RWHandleV3	pthandle(gdp->getP());
	GA_RWHandleV3	myColor(gdp, GA_ATTRIB_POINT, "Cd");

	vector<UT_Vector3> colorList;

	for (int i = 0; i < npoints; i++)
	{
		colorList.push_back(color);
	}

	if (totalTriangles > 0)
	{
		sizelist.append(3, totalTriangles);
	}
	if (totalQuads > 0)
	{
		sizelist.append(4, totalQuads);
	}
	if (totalPentagons > 0)
	{
		sizelist.append(5, totalPentagons);

	}

	quatPosition.normalize();
	quatRotation.normalize();

	for (int i = 0; i < npoints; i++)
	{
		UT_Vector3 tempPos(piece.at(i));
		piece.at(i) = quatPosition.rotate(tempPos);
		tempPos = piece.at(i);
		piece.at(i) = quatRotation.rotate(tempPos);
		piece.at(i) += Offset;
	}

	pthandle.setBlock(startpt, npoints, (UT_Vector3 *)piece.data());

	GU_PrimPoly::buildBlock(gdp, startpt, npoints, sizelist, vertexOrder.array());
	myColor.setBlock(startpt, npoints, (UT_Vector3 *)colorList.data());
}

void SOP_Megamix::buildMegamixGeometry(OP_Context &context, GU_Detail *gdp)
{


	//---------------------------------------------------------------------------------------------------------
	vector<UT_Vector3> pieceData;
	vector<int> faceList;

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

	////----------------------------------------------------------------------------------------------------------
	//UT_Interrupt    *boss;
	//UT_QuaternionF	quatPosition, quatRotation;
	//UT_Vector3		colorPieceBase(1.0, 1.0, 1.0);

	////----------------------------------------------------------------------------------------------------------
	////constroi vetores de quaternions
	//quatPositionList.clear();
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(0), UT_Vector3F(1.0, 0.0, 0.0)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(180), UT_Vector3F(1.0, 0.0, 0.0)));

	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(63.435), UT_Vector3F(1.0, 0.0, 0.0)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(243.435), UT_Vector3F(1.0, 0.0, 0.0)));

	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(63.435), UT_Vector3F(0.309017, 0.0, -0.951056)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(243.435), UT_Vector3F(0.309017, 0.0, -0.951056)));

	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(63.435), UT_Vector3F(-0.809017, 0.0, -0.587785)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(243.435), UT_Vector3F(-0.809017, 0.0, -0.587785)));

	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(63.435), UT_Vector3F(-0.809017, 0.0, 0.587785)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(243.435), UT_Vector3F(-0.809017, 0.0, 0.587785)));

	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(63.435), UT_Vector3F(0.309017, 0.0, 0.951056)));
	//quatPositionList.push_back(UT_QuaternionF(DegreesToRadians(243.435), UT_Vector3F(0.309017, 0.0, 0.951056)));

	//quatRotationList.clear();
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(0), UT_Vector3F(0.0, 1.0, 0.0)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(0), UT_Vector3F(0.0, 1.0, 0.0)));

	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.0, -0.447213, -0.894428)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.0, -0.447213, -0.894428)));

	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));

	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));

	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.527531, -0.447213, 0.723607)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.527531, -0.447213, 0.723607)));

	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.850651, -0.447213, -0.276394)));
	//quatRotationList.push_back(UT_QuaternionF(DegreesToRadians(36), UT_Vector3F(0.850651, -0.447213, -0.276394)));

	////----------------------------------------------------------------------------------------------------------
	////constroi dados das peças
	//buildPieceData();

	//// Check to see that there hasn't been a critical error in cooking the SOP.
	//if (error() < UT_ERROR_ABORT)
	//{
	//	boss = UTgetInterrupt();

	//	gdp->clearAndDestroy();
	//	// Start the interrupt server
	//	if (boss->opStart("Building Megamix Geometry"))
	//	{
	//		GA_RWHandleV3	color = GA_RWHandleV3(gdp->addFloatTuple(GA_ATTRIB_POINT, "Cd", 3));

	//		UT_IntArray	vertexOrderCorner(24, 6);
	//		UT_IntArray	vertexOrderCornerColor(24, 6);
	//		UT_IntArray	vertexOrderCenter(30, 7);
	//		UT_IntArray	vertexOrderCenterColor(30, 7);
	//		UT_IntArray	vertexOrderInbetween(24, 6);
	//		UT_IntArray	vertexOrderInbetweenColor(24, 6);

	//		//----------------------------------------------------------------------------------------------------------
	//		//constroi centros
	//		for (int i = 0; i < static_cast<int>(m_faceListCenter.size()); i++)
	//		{
	//			vertexOrderCenter(i) = m_faceListCenter.at(i) - 1;
	//		}

	//		for (int i = 0; i < static_cast<int>(m_faceListCenterColor.size()); i++)
	//		{
	//			vertexOrderCenterColor(i) = m_faceListCenterColor.at(i) - 1;
	//		}

	//		for (int i = 0; i < static_cast<int>(quatPositionList.size()); i++)
	//		{
	//			buildPiece(context, gdp, m_pieceCenter, vertexOrderCenter, 0, 5, 2, colorPieceBase, quatPositionList.at(i), quatRotationList.at(i));
	//		}

	//		//----------------------------------------------------------------------------------------------------------
	//		//constroi cantos
	//		for (int i = 0; i < static_cast<int>(m_faceListCorner.size()); i++)
	//		{
	//			vertexOrderCorner(i) = m_faceListCorner.at(i) - 1;
	//		}

	//		for (int i = 0; i < static_cast<int>(m_faceListCornerColor.size()); i++)
	//		{
	//			vertexOrderCornerColor(i) = m_faceListCornerColor.at(i) - 1;
	//		}

	//		//topos
	//		//for (int i = 0; i < 5; i++)
	//		//{
	//		//	UT_QuaternionF tempQuaterion(quatRotationList.at(0));
	//		//	tempQuaterion = tempQuaterion + UT_QuaternionF(DegreesToRadians(i * 144), UT_Vector3F(0.0, 1.0, 0.0));
	//		//	buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPieceBase, quatPositionList.at(0), tempQuaterion);
	//		//}

	//		////bases
	//		//for (int i = 0; i < 5; i++)
	//		//{
	//		//	UT_QuaternionF tempQuaterion(quatRotationList.at(0));
	//		//	tempQuaterion = tempQuaterion + UT_QuaternionF(DegreesToRadians(i * 144), UT_Vector3F(0.0, 1.0, 0.0));
	//		//	buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPieceBase, quatPositionList.at(1), tempQuaterion);
	//		//}

	//		//meios
	//		for (int i = 0; i < 1; i++)
	//		{
	//			UT_QuaternionF tempQuaterion(quatRotationList.at(3));
	//			tempQuaterion = tempQuaterion + UT_QuaternionF(DegreesToRadians((fpreal)pointX()), UT_Vector3F(0.0, -0.447213, -0.894428));
	//			buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPieceBase, quatPositionList.at(3), tempQuaterion);
	//		}

	//		//----------------------------------------------------------------------------------------------------------
	//		//constroi topo
	//		//quatPosition.identity();
	//		//quatPosition = UT_QuaternionF(DegreesToRadians(0), UT_Vector3F(1.0, 0.0, 0.0));
	//		//for (int i = 0; i < 5; i++)
	//		{
	//			//quatRotation = UT_QuaternionF(DegreesToRadians(pointX() + (i * 72)), UT_Vector3F(0.0, 1.0, 0.0));
	//			//buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPiece, quatPosition, quatRotation);
	//		}

	//		//----------------------------------------------------------------------------------------------------------
	//		//constroi base
	//		//quatPosition.identity();
	//		//quatPosition = UT_QuaternionF(DegreesToRadians(180), UT_Vector3F(1.0, 0.0, 0.0));
	//		//for (int i = 0; i < 5; i++)
	//		{
	//			//quatRotation =	UT_QuaternionF(DegreesToRadians(pointX() + (i * 72)), UT_Vector3F(0.0, -1.0, 0.0));
	//			//buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPiece, quatPosition, quatRotation);
	//		}

	//		//----------------------------------------------------------------------------------------------------------
	//		//constroi base
	//		//quatPosition.identity();
	//		//quatPosition = UT_QuaternionF(DegreesToRadians(180), UT_Vector3F(1.0, 0.0, 0.0));
	//		//for (int i = 0; i < 5; i++)
	//		{
	//			//quatRotation = UT_QuaternionF(DegreesToRadians(pointX() + (i * 72)), UT_Vector3F(0.0, -1.0, 0.0));
	//			//buildPiece(context, gdp, m_pieceCorner, vertexOrderCorner, 0, 6, 0, colorPiece, quatPosition, quatRotation);
	//		}

	//		////buildPiece(context, gdp, m_pieceCornerColor, vertexOrderCornerColor, 0, 6, 0, new UT_Vector3(1, 0, 0));

	//		////buildPiece(context, gdp, m_pieceCenter, vertexOrderCenter, 0, 5, 2, new UT_Vector3(0.07, 0.07, 0.07));
	//		////buildPiece(context, gdp, m_pieceCenterColor, vertexOrderCenterColor, 0, 5, 2, new UT_Vector3(0, 1, 0));

	//		//for (int i = 0; i < static_cast<int>(m_faceListInbetween.size()); i++)
	//		//{
	//		//	vertexOrderInbetween(i) = m_faceListInbetween.at(i) - 1;
	//		//}

	//		//for (int i = 0; i < static_cast<int>(m_faceListInbetweenColor.size()); i++)
	//		//{
	//		//	vertexOrderInbetweenColor(i) = m_faceListInbetweenColor.at(i) - 1;
	//		//}

	//		//buildPiece(context, gdp, m_pieceInbetween, vertexOrderInbetween, 2, 4, 0, new UT_Vector3(0.07, 0.07, 0.07));
	//		//buildPiece(context, gdp, m_pieceInbetweenColor, vertexOrderInbetweenColor, 2, 3, 0, new UT_Vector3(0, 0, 1));
	//		
	//		// Highlight the star which we have just generated.  This routine
	//		// call clears any currently highlighted geometry, and then it
	//		// highlights every primitive for this SOP. 
	//		//select(GU_SPrimitive);
	//	}
	//	// Tell the interrupt server that we've completed. Must do this
	//	// regardless of what opStart() returns.
	//	boss->opEnd();
	//}

	//cleanPieceData();

	//------------------------------------------------------------------------------------------------
	UT_Interrupt			*boss;	//interrupt server

	//// Check to see that there hasn't been a critical error in cooking the SOP.
	if (error() < UT_ERROR_ABORT)
	{
		boss = UTgetInterrupt();
		gdp->clearAndDestroy();

		// start the interrupt server
		if (boss->opStart("Building Megamix Geometry"))
		{
			UT_QuaternionF					quat(0, 0, 1, 0);
			UT_Vector3						colorBlack(0.1, 0.1, 0.1);
			GA_RWHandleV3					color = GA_RWHandleV3(gdp->addFloatTuple(GA_ATTRIB_POINT, "Cd", 3));

			//colors
			vector<UT_Vector3> colors;
			colors.push_back(UT_Vector3(1, 1, 0));             //yellow
			colors.push_back(UT_Vector3(1, 1, 1));             //white
			colors.push_back(UT_Vector3(0, 0, 1));             //blue
			colors.push_back(UT_Vector3(0, 1, 0));             //green
			colors.push_back(UT_Vector3(0.9, 0.45, 0));        //orange
			colors.push_back(UT_Vector3(0.25, 0, 0.5));        //purple
			colors.push_back(UT_Vector3(0.6, 0.9, 0.4));       //light_green
			colors.push_back(UT_Vector3(1, 0, 0));             //red
			colors.push_back(UT_Vector3(0.9, 0, 0.9));         //pink
			colors.push_back(UT_Vector3(0.5, 0.5, 0.5));       //gray
			colors.push_back(UT_Vector3(0, 0.45, 0.9));        //light_blue
			colors.push_back(UT_Vector3(0.01, 0.14, 0.03));    //dark green

			//----------------------------------------------------------------------------------------------------------
			//constroi vetores de quaternions
			quatPositionList.clear();
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(0), UT_Vector3F(1.0, 0.0, 0.0)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(180), UT_Vector3F(1.0, 0.0, 0.0)));

			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(63.435), UT_Vector3F(1.0, 0.0, 0.0)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(243.435), UT_Vector3F(1.0, 0.0, 0.0)));

			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(63.435), UT_Vector3F(0.309017, 0.0, -0.951056)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(243.435), UT_Vector3F(0.309017, 0.0, -0.951056)));

			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(63.435), UT_Vector3F(-0.809017, 0.0, -0.587785)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(243.435), UT_Vector3F(-0.809017, 0.0, -0.587785)));

			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(63.435), UT_Vector3F(-0.809017, 0.0, 0.587785)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(243.435), UT_Vector3F(-0.809017, 0.0, 0.587785)));

			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(63.435), UT_Vector3F(0.309017, 0.0, 0.951056)));
			quatPositionList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(243.435), UT_Vector3F(0.309017, 0.0, 0.951056)));

			quatRotationList.clear();
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(0), UT_Vector3F(0.0, 1.0, 0.0)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(0), UT_Vector3F(0.0, 1.0, 0.0)));

			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.0, -0.447213, -0.894428)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.0, -0.447213, -0.894428)));

			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));

			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));

			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.527531, -0.447213, 0.723607)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.527531, -0.447213, 0.723607)));

			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.850651, -0.447213, -0.276394)));
			quatRotationList.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(36), UT_Vector3F(0.850651, -0.447213, -0.276394)));

			////Quaternion position
			//vector<UT_Vector4> quaternionPosition;
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(0), 1, 0, 0));                          //yellow
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(63.435), 1, 0, 0));                     //white
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(63.435), 0.309017, 0.0, -0.951056));    //blue
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(63.435), -0.809017, 0.0, -0.587785));   //green
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(63.435), -0.809017, 0.0, 0.587785));    //orange
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(63.435), 0.309017, 0.0, 0.951056));     //purple

			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(180), 1, 0, 0));                        //light green
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(243.435), -0.809017, 0.0, 0.587785));   //red
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(243.435), 0.309017, 0.0, 0.951056));    //pink
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(243.435), 1, 0, 0));                    //white                
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(243.435), 0.309017, 0.0, -0.951056));   //light blue
			//quaternionPosition.push_back(UT_Vector4(DegreesToRadians(243.435), -0.809017, 0.0, -0.587785));  //dark green

			////Quaternion rotation
			//vector<UT_Vector4> quaternionRotation;
			//quaternionRotation.push_back(UT_Vector4(0, 0, 1, 0));
			//quaternionRotation.push_back(UT_Vector4(0, 0.0, -0.447213, -0.894428));
			//quaternionRotation.push_back(UT_Vector4(0, -0.850651, -0.447213, -0.276394));
			//quaternionRotation.push_back(UT_Vector4(0, -0.525731, -0.447213, 0.723607));
			//quaternionRotation.push_back(UT_Vector4(0, 0.527531, -0.447213, 0.723607));
			//quaternionRotation.push_back(UT_Vector4(0, 0.850651, -0.447213, -0.276394));

			//quaternionRotation.push_back(UT_Vector4(0, 0, 1, 0));
			//quaternionRotation.push_back(UT_Vector4(0, 0.527531, -0.447213, 0.723607));
			//quaternionRotation.push_back(UT_Vector4(0, 0.850651, -0.447213, -0.276394));
			//quaternionRotation.push_back(UT_Vector4(0, 0.0, -0.447213, -0.894428));
			//quaternionRotation.push_back(UT_Vector4(0, -0.850651, -0.447213, -0.276394));
			//quaternionRotation.push_back(UT_Vector4(0, -0.525731, -0.447213, 0.723607));


			//buildBlackCornerData(cornerPieceBlack, faceListCornerPieceBlack);


			
			//UT_IntArray	vertexOrderInbetween(24, 6);
			//UT_IntArray	vertexOrderInbetweenColor(18);

			////for (int i = 0; i < static_cast<int>(m_faceListInbetween.size()); i++)
			////{
			////	vertexOrderInbetween(i) = m_faceListInbetween.at(i) - 1;
			////}

			//for (int i = 0; i < static_cast<int>(m_faceListInbetweenColor.size()); i++)
			//{
			//	vertexOrderInbetweenColor(i) = m_faceListInbetweenColor.at(i) - 1;
			//}

			////buildPiece(context, gdp, m_pieceInbetween, vertexOrderInbetween, 2, 4, 0, colorBlack, quat, quat);
			//buildPiece(context, gdp, m_pieceInbetweenColor, vertexOrderInbetweenColor, 2, 3, 0, colorBlack, quat, quat);

			
			//---------------------------------------------------------------------------------------------------------------------------
			//	CENTERS
			//---------------------------------------------------------------------------------------------------------------------------
			UT_IntArray				vertexOrderCenterPieceBlack(120, 31);
			UT_IntArray				vertexOrderCenterPieceColor(110, 30);
			CCenterComponent		geometryCenter;
			CentersGeometryData		centerGeometryData;

			//build center black
			geometryCenter.buildAllCenterGeometryData(centerGeometryData);

			//colors
			for (int j = 0; j < static_cast<int>(centerGeometryData.faceListColor.size()); j++)
			{
				vertexOrderCenterPieceColor(j) = centerGeometryData.faceListColor.at(j) - 1;
			}

			for (int j = 0; j < static_cast<int>(quatPositionList.size()); j++)
			{
				buildPiece(context, gdp, centerGeometryData.posCenter_Color, vertexOrderCenterPieceColor, 10, 20, 0, colors.at(j), 
					quatPositionList.at(j), quatRotationList.at(j), UT_Vector3(0, 0, 0));
			}

			//black
			for (int j = 0; j < static_cast<int>(centerGeometryData.faceListBlack.size()); j++)
			{
				vertexOrderCenterPieceBlack(j) = centerGeometryData.faceListBlack.at(j) - 1;
			}

			buildPiece(context, gdp, centerGeometryData.posCenter_Yellow, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_White, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Blue, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Green, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Orange, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Purple, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_LightGreen, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Red, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Pink, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_Gray, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_LightBlue, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, centerGeometryData.posCenter_DarkGreen, vertexOrderCenterPieceBlack, 5, 25, 1, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			//---------------------------------------------------------------------------------------------------------------------------
			//	CORNERS
			//---------------------------------------------------------------------------------------------------------------------------
			UT_IntArray				vertexOrderCornerPieceBlack(216, 54);
			UT_IntArray				vertexOrderCornerPieceColor(216, 54);
			CCornerComponent		geometryCorner;
			CornerBlackGeometryData	cornerGeometryData;

			//build corner black
			geometryCorner.buildAllBlackCornerGeometryData(cornerGeometryData);

			//colors
			for (int j = 0; j < static_cast<int>(cornerGeometryData.faceListColor.size()); j++)
			{
				vertexOrderCornerPieceColor(j) = cornerGeometryData.faceListColor.at(j) - 1;
			}

			for (int j = 0; j < static_cast<int>(quatPositionList.size()); j++)
			{
				for (int k = 0; k < 5; k++)
				{
					vector<UT_QuaternionF> tempQuaternion;
					tempQuaternion.clear();
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72), UT_Vector3F(0.0, 1.0, 0.0)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72), UT_Vector3F(0.0, 1.0, 0.0)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.0, -0.447213, -0.894428)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.0, -0.447213, -0.894428)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.527531, -0.447213, 0.723607)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.527531, -0.447213, 0.723607)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.850651, -0.447213, -0.276394)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.850651, -0.447213, -0.276394)));

					buildPiece(context, gdp, cornerGeometryData.posCorner_Color, vertexOrderCornerPieceColor, 0, 21, 0, colors.at(j), 
						quatPositionList.at(j), tempQuaternion.at(j), UT_Vector3(0, 0, 0));
				}
			}



			//black
			for (int j = 0; j < static_cast<int>(cornerGeometryData.faceListBlack.size()); j++)
			{
				vertexOrderCornerPieceBlack(j) = cornerGeometryData.faceListBlack.at(j) - 1;
			}

			buildPiece(context, gdp, cornerGeometryData.posCorner_Yellow_Blue_Green, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Yellow_Blue_White, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Yellow_Purple_White, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Yellow_Purple_Orange, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Yellow_Green_Orange, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, cornerGeometryData.posCorner_LightGreen_DarkGreen_Red, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_LightGreen_Red_Pink, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_LightGreen_Pink_Gray, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_LightGreen_Gray_LightBlue, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_LightGreen_LightBlue_DarkGreen, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, cornerGeometryData.posCorner_Purple_DarkGreen_LightBlue, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Gray_Orange_LightBlue, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Pink_LightGreen_Gray, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Red_Blue_Pink, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_DarkGreen_White_Red, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, cornerGeometryData.posCorner_DarkGreen_Purple_White, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_LightBlue_Orange_Purple, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Gray_LightGreen_Orange, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Pink_Blue_Green, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, cornerGeometryData.posCorner_Red_White_Blue, vertexOrderCornerPieceBlack, 0, 54, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			//---------------------------------------------------------------------------------------------------------------------------
			//	INTERMEDIATE
			//---------------------------------------------------------------------------------------------------------------------------
			UT_IntArray					vertexOrderIntermediatesPieceBlack(198, 50);
			UT_IntArray					vertexOrderIntermediatesPieceColors(63, 16);
			CIntermediateComponent		geometryIntermediate;
			IntermediateGeometryData	intermediateGeometryData;

			geometryIntermediate.buildAllIntermediateGeometryData(intermediateGeometryData);

			//	COLORS
			for (int j = 0; j < static_cast<int>(intermediateGeometryData.faceListColor.size()); j++)
			{
				vertexOrderIntermediatesPieceColors(j) = intermediateGeometryData.faceListColor.at(j) - 1;
			}

			
			for (int j = 0; j < static_cast<int>(quatPositionList.size()); j++)
			{
				for (int k = 0; k < 5; k++)
				{
					vector<UT_QuaternionF> tempQuaternion;
					tempQuaternion.clear();
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72), UT_Vector3F(0.0, 1.0, 0.0)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72), UT_Vector3F(0.0, 1.0, 0.0)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.0, -0.447213, -0.894428)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.0, -0.447213, -0.894428)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.850651, -0.447213, -0.276394)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(-0.525731, -0.447213, 0.723607)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.527531, -0.447213, 0.723607)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.527531, -0.447213, 0.723607)));

					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.850651, -0.447213, -0.276394)));
					tempQuaternion.push_back(UT_QuaternionF((fpreal32)DegreesToRadians(k * 72 + 36), UT_Vector3F(0.850651, -0.447213, -0.276394)));

					buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Color, vertexOrderIntermediatesPieceColors, 1, 15, 0, colors.at(j),
						quatPositionList.at(j), tempQuaternion.at(j), UT_Vector3(0, 0, 0));
				}
			}

			//	BLACKS
			for (int j = 0; j < static_cast<int>(intermediateGeometryData.faceListBlack.size()); j++)
			{
				vertexOrderIntermediatesPieceBlack(j) = intermediateGeometryData.faceListBlack.at(j) - 1;
			}

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Yellow_Orange, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Yellow_Purple, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Yellow_White, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Yellow_Blue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Yellow_Green, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightGreen_Pink, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightGreen_Red, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightGreen_Green, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightGreen_LightBlue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightGreen_Gray, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Green_Blue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Blue_White, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_White_Purple, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Purple_Orange, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Orange_Green, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Pink_Red, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Gray_Pink, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightBlue_Gray, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_LightBlue_Green, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Green_Red, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Pink_Blue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Red_Blue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Red_White, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_White_Green, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Purple_Red, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Purple_LightBlue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Orange_LightBlue, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Orange_Gray, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));

			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Green_Gray, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
			buildPiece(context, gdp, intermediateGeometryData.posIntermediate_Green_Pink, vertexOrderIntermediatesPieceBlack, 2, 48, 0, colorBlack, quat, quat, UT_Vector3(0, 0, 0));
		}

		//	finish interrupt server
		boss->opEnd();
	}
}

void SOP_Megamix::buildMegamix(OP_Context &context)
{
	//UT_DMatrix4 xform(1.0);
	////UT_QuaternionF quatRot((fpreal32)1.0, 0.0, 0.0, 0.0);
	//UT_Vector3F position;
	//GA_Offset ptoff;
	//UT_Vector3F newpos;
	//double offsetRot = 45;

	//------------------------------------------------------------------------------------------------
	//inicializa o Details do SOP
	if (!gdp)
		gdp = new GU_Detail;
	//gdp->clearAndDestroy();

	//cria geometria do megamix
	buildMegamixGeometry(context, gdp);
}

OP_ERROR SOP_Megamix::cookMySop(OP_Context &context)
{
	// Before we do anything, we must lock our inputs.  Before returning,
	//	we have to make sure that the inputs get unlocked.
	if (lockInputs(context) >= UT_ERROR_ABORT)
		return error();
	
	buildMegamix(context);

	unlockInputs();
	return error();
}
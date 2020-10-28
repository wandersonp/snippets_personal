//===================================================================================================
//
//	Arquivo: SOP_Megamix.h
//
//	Descrição:	cria um point cloud num box
//
//===================================================================================================

#ifndef __SOP_Megamix__
#define __SOP_Megamix__

#include <vector>

#include <HOM/HOM_Module.h>
#include <HOM/HOM_ui.h>

#include <SOP/SOP_Node.h>

#include "GeometryCenters.h"
#include "GeometryIntermediates.h"
#include "GeometryCorners.h"

using namespace std;

#define INT_PARM(name, idx, vidx, t)	\
	    return evalInt(name, &myOffsets[idx], vidx, t);

#define FLT_PARM(name, idx, vidx, t)	\
	    return evalFloat(name, &myOffsets[idx], vidx, t);

class GEO_Point;

namespace HDK_Sample {
	class SOP_Megamix : public SOP_Node
	{
	public:
		SOP_Megamix(OP_Network *net, const char *name, OP_Operator *op);
		virtual ~SOP_Megamix();

		static PRM_Template		 myTemplateList[];
		static OP_Node			*myConstructor(OP_Network*, const char *, OP_Operator *);

	protected:

		// Method to cook geometry for the SOP
		virtual OP_ERROR		 cookMySop(OP_Context &context);

		void buildMegamix(OP_Context &context);
		void buildMegamixGeometry(OP_Context &context, GU_Detail *gdp);
		void buildPiece(OP_Context &context,
			GU_Detail *gdp,
			vector <UT_Vector3> piece,
			UT_IntArray &vertexOrder,
			GA_Size totalTriangles,
			GA_Size totalQuads,
			GA_Size totalPentagons,
			UT_Vector3 color,
			UT_QuaternionF quatPosition,
			UT_QuaternionF quatRotation,
			UT_Vector3 Offset);
			//UT_Vector3 position = UT_Vector3(0, 0, 0),
			//UT_Vector3 rotation = UT_Vector3(0, 0, 0));
		void buildPieceData();
		void cleanPieceData();

	private:
		// These use defines to make it easy to add parms and remove them.
		// The evaluation routines use the indexed name lookup which is quite
		//	fast, yet easy to change indices (since the order of the indices
		//	doesn't have to be in sequential order...
		//int			 RESET()	{ INT_PARM("reset", 0, 0, 0) }
		//int			 BIRTH(fpreal t){ INT_PARM("birth", 2, 0, t) }
		fpreal	pointX()	{ FLT_PARM("point", 0, 0, 0) }
		fpreal	pointY()	{ FLT_PARM("point", 0, 1, 0) }
		fpreal	pointZ()	{ FLT_PARM("point", 0, 2, 0) }

		const GA_PointGroup *myGroup;

		GEO_Point			*Points;
		GA_RWHandleV3		m_Position;		

		fpreal				oldFrame, currFrame;

		static int			*myOffsets;

		//	peças suporte
		vector<UT_Vector3>	m_pieceCorner;
		vector<UT_Vector3>	m_pieceCornerColor;
		vector<UT_Vector3>	m_pieceCenter;
		vector<UT_Vector3>	m_pieceCenterColor;
		vector<UT_Vector3>	m_pieceInbetween;
		vector<UT_Vector3>	m_pieceInbetweenColor;

		//	peças coloridas
		vector<int> m_faceListCorner;
		vector<int> m_faceListCornerColor;
		vector<int> m_faceListCenter;
		vector<int> m_faceListCenterColor;
		vector<int> m_faceListInbetween;
		vector<int> m_faceListInbetweenColor;

		//	vetores de quaternions
		vector<UT_QuaternionF> quatPositionList;
		vector<UT_QuaternionF> quatRotationList;

	};
} 

#endif

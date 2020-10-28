//==================================================================================================================
//
//	File:	DungeonGenerator.cs
//	Date:	29-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	dungeon procedural generator
//
//==================================================================================================================

using UnityEngine;
#if UNITY_EDITOR
using UnityEditor;
#endif
using System.Collections;
using System.Collections.Generic;
//==================================================================================================================
namespace Dungeon
{
    //==================================================================================================================
    public class Tile
    {
        public int x;
        public int y;
        public TileType type;
        public bool northNeighbour;
        public bool southNeighbour;
        public bool westNeighbour;
        public bool eastNeighbour;
        public int version;

        //------------------------------------------------------------------------------------------------------------------
        public enum TileType
        {
            NONE,
            CROSS,
            CORNER_1,
            CORNER_2,
            CORNER_3,
            CORNER_4,
            TRIPLE_1,
            TRIPLE_2,
            TRIPLE_3,
            TRIPLE_4,
            DEAD_END_1,
            DEAD_END_2,
            DEAD_END_3,
            DEAD_END_4,
            LINE_VERTICAL,
            LINE_HORIZONTAL
        }

        //------------------------------------------------------------------------------------------------------------------
        public Tile()
        {
            this.x = 0;
            this.y = 0;
            this.type = TileType.NONE;
            this.northNeighbour = false;
            this.southNeighbour = false;
            this.westNeighbour = false;
            this.eastNeighbour = false;
            this.version = 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        public Tile(int x, int y)
        {
            this.x = x;
            this.y = y;
            this.type = TileType.NONE;
            this.northNeighbour = false;
            this.southNeighbour = false;
            this.westNeighbour = false;
            this.eastNeighbour = false;
            this.version = 0;
        }

        //------------------------------------------------------------------------------------------------------------------
        public Tile(Tile tile)
        {
            this.x = tile.x;
            this.y = tile.y;
            this.type = tile.type;
            this.northNeighbour = tile.northNeighbour;
            this.southNeighbour = tile.southNeighbour;
            this.westNeighbour = tile.westNeighbour;
            this.eastNeighbour = tile.eastNeighbour;
            this.version = tile.version;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override bool Equals(object obj)
        {
            if (obj.GetType() == typeof(Tile))
            {
                Tile tile = (Tile)obj;
                if (this.x == tile.x && this.y == tile.y)
                {
                    return true;
                }
            }
            return false;
        }

        //------------------------------------------------------------------------------------------------------------------
        public override int GetHashCode()
        {
            int value = this.x ^ 5 + this.y ^ 4;
            return value;
        }
    }

    //==================================================================================================================
#if UNITY_EDITOR
    [ExecuteInEditMode]
#endif
    public class SYS_DungeonGenerator : MonoBehaviour
    {
        private List<Tile> m_map;
        private List<GameObject> m_dungeonPieceList;
        private List<GameObject> m_crossPiece;

        private List<GameObject> m_cornerPieceList_A;
        private List<GameObject> m_cornerPieceList_B;
        private List<GameObject> m_cornerPieceList_C;
        private List<GameObject> m_cornerPieceList_D;

        private List<GameObject> m_linePieceList_A;
        private List<GameObject> m_linePieceList_B;
        private List<GameObject> m_linePieceList_C;
        private List<GameObject> m_linePieceList_D;

        private List<GameObject> m_triplePieceList_A;
        private List<GameObject> m_triplePieceList_B;
        private List<GameObject> m_triplePieceList_C;
        private List<GameObject> m_triplePieceList_D;

        private List<GameObject> m_deadEndPieceList_A;
        private List<GameObject> m_deadEndPieceList_B;
        private List<GameObject> m_deadEndPieceList_C;
        private List<GameObject> m_deadEndPieceList_D;

        private GameObject m_nonePiece;

        private string m_mainPath;
        private float m_tileScale = 50.0f;

        private float m_frameCount = 0;
        private bool m_rebuildNavmesh = false;


        private RaycastHit m_hitPosition;
        private GameObject m_charProxy;

        //------------------------------------------------------------------------------------------------------------------
        public enum Direction
        {
            NORTH = 0,
            SOUTH = 1,
            EAST = 2,
            WEST = 3,
        }

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
//#if UNITY_EDITOR
//            UnityEditor.SceneView.FocusWindowIfItsOpen(typeof(UnityEditor.SceneView));
//#endif

            this.m_charProxy = GameObject.Find("GAMEOBJ_CharProxy");
            this.m_mainPath = "Prefab/_Level_A/";

#if UNITY_EDITOR
            LoadCrossPieces();
            LoadCornerPieces();
            LoadLinePieces();
            LoadDeadEndPieces();
            LoadTriplePieces();
            LoadNonePiece();
            CreateRandomDungeon();
            MoveAllMapLinkedToFirstPiecePivot(0, 0);
            ScrambleTileVersions();
            ModifyTilePatterns();
            PopulatePiecesAtDungeon();
            PlaceAgentAtStartPointInNavmesh();

            NavMeshBuilder.ClearAllNavMeshes();
            NavMeshBuilder.BuildNavMesh();
#endif
        }

        //------------------------------------------------------------------------------------------------------------------
        void Update()
        {
            GameObject.Find("PREFAB_CameraMovement").transform.position = this.m_charProxy.transform.position;

            //keep char_proxy at NavigationMesh
            if (GameSystem.HeroControl.LeftMouseClick())
            {
                if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out m_hitPosition, 100))
                {
                    //if (m_hitPosition.collider.gameObject.tag == "NavigationMesh")
                    {
                        NavMeshAgent agent = this.m_charProxy.GetComponent<NavMeshAgent>();
                        agent.destination = m_hitPosition.point;
                        agent.acceleration = 1000.0f;
                        agent.angularSpeed = 1000.0f;
                        agent.speed = 10.0f;
                        agent.updateRotation = true;

                        Debug.Log("clicked navmesh");
                    }
                }
            }

#if UNITY_EDITOR
            if (Input.GetKeyDown(KeyCode.Space))
            {
                m_frameCount = Time.frameCount;
                Debug.Log("space pressed");

                NavMeshBuilder.ClearAllNavMeshes();
                DestroyDungeon();
                m_rebuildNavmesh = true;
            }

            if (m_frameCount < Time.frameCount && m_rebuildNavmesh)
            {
                CreateRandomDungeon();
                MoveAllMapLinkedToFirstPiecePivot(0, 0);
                ScrambleTileVersions();
                ModifyTilePatterns();
                PopulatePiecesAtDungeon();
                PlaceAgentAtStartPointInNavmesh();

                NavMeshBuilder.BuildNavMesh();
                m_rebuildNavmesh = false;
            }
#endif
        }

        //------------------------------------------------------------------------------------------------------------------
        private void PlaceAgentAtStartPointInNavmesh()
        {
            //place agent inside some piece
            Vector3 position = Vector3.zero;
            foreach (Tile tile in this.m_map)
            {
                if (tile.type == Tile.TileType.CROSS || 
                    tile.type == Tile.TileType.LINE_HORIZONTAL ||
                    tile.type == Tile.TileType.LINE_VERTICAL)
                {
                    position = new Vector3((float)tile.x * m_tileScale, 0, (float)tile.y * m_tileScale);
                }
            }
            this.m_charProxy.transform.position = position;
        }
        //------------------------------------------------------------------------------------------------------------------
        private void CreateRandomDungeon()
        {
            HashSet<Tile> map = new HashSet<Tile>();

            Random.seed = System.DateTime.Now.Millisecond;
            int maxTiles = Random.Range(20, 30);
            int positionX = 0;
            int positionY = 0;

            //create logic map
            while (map.Count < maxTiles)
            {
                int direction = Random.Range(0, 4);
                switch (direction)
                {
                    case (int)Direction.NORTH:
                        Tile tile = new Tile(positionX, positionY - 1);
                        map.Add(tile);
                        positionY--;
                        break;
                    case (int)Direction.SOUTH:
                        tile = new Tile(positionX, positionY + 1);
                        map.Add(tile);
                        positionY++;
                        break;
                    case (int)Direction.WEST:
                        tile = new Tile(positionX - 1, positionY);
                        map.Add(tile);
                        positionX--;
                        break;
                    case (int)Direction.EAST:
                        tile = new Tile(positionX + 1, positionY);
                        map.Add(tile);
                        positionX++;
                        break;
                }
            }

            //convert hash to list
            this.m_map = new List<Tile>(map);

            //set neighbors
            CheckForNeighbors();

            //set neighbours
            SetTileType();
        }

        //------------------------------------------------------------------------------------------------------------------
        private void CheckForNeighbors()
        {
            //check if possible neighbors are valid
            for (int j = 0; j < this.m_map.Count; j++)
            {
                //get coordinates for current tile
                int x = this.m_map[j].x;
                int y = this.m_map[j].y;

                //create temp neighbours for this tile
                List<Tile> tempMap = new List<Tile>();
                tempMap.Add(new Tile(x, y - 1));    //north
                tempMap.Add(new Tile(x, y + 1));    //south
                tempMap.Add(new Tile(x - 1, y));    //west
                tempMap.Add(new Tile(x + 1, y));    //east

                Tile tempTile = this.m_map[j];
                //check north neighbor
                if (this.m_map.Contains(tempMap[0]))
                {
                    tempTile.northNeighbour = true;
                }
                //check south neighbor
                if (this.m_map.Contains(tempMap[1]))
                {
                    tempTile.southNeighbour = true;
                }
                //check west neighbor
                if (this.m_map.Contains(tempMap[2]))
                {
                    tempTile.westNeighbour = true;
                }
                //check north neighbor
                if (this.m_map.Contains(tempMap[3]))
                {
                    tempTile.eastNeighbour = true;
                }
                this.m_map[j] = tempTile;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void PopulatePiecesAtDungeon()
        {
            this.m_dungeonPieceList = new List<GameObject>();

            //instantiate each position in map
            foreach (Tile tile in this.m_map)
            {
                GameObject pieceObject = null;
                Random.seed = Time.frameCount;
                int version = 0;// tile.version;// Random.Range(0, 4);

                switch (tile.type)
                {
                    case Tile.TileType.CROSS:
                        pieceObject = InstantiateCrossPiece(version);
                        break;
                    case Tile.TileType.CORNER_1:
                        pieceObject = InstantiateCornerPiece(0, version);
                        break;
                    case Tile.TileType.CORNER_2:
                        pieceObject = InstantiateCornerPiece(1, version);
                        break;
                    case Tile.TileType.CORNER_3:
                        pieceObject = InstantiateCornerPiece(2, version);
                        break;
                    case Tile.TileType.CORNER_4:
                        pieceObject = InstantiateCornerPiece(3, version);
                        break;
                    case Tile.TileType.TRIPLE_1:
                        pieceObject = InstantiateTriplePiece(0, version);
                        break;
                    case Tile.TileType.TRIPLE_2:
                        pieceObject = InstantiateTriplePiece(1, version);
                        break;
                    case Tile.TileType.TRIPLE_3:
                        pieceObject = InstantiateTriplePiece(2, version);
                        break;
                    case Tile.TileType.TRIPLE_4:
                        pieceObject = InstantiateTriplePiece(3, version);
                        break;
                    case Tile.TileType.DEAD_END_1:
                        pieceObject = InstantiateDeadEndPiece(0, version);
                        break;
                    case Tile.TileType.DEAD_END_2:
                        pieceObject = InstantiateDeadEndPiece(1, version);
                        break;
                    case Tile.TileType.DEAD_END_3:
                        pieceObject = InstantiateDeadEndPiece(2, version);
                        break;
                    case Tile.TileType.DEAD_END_4:
                        pieceObject = InstantiateDeadEndPiece(3, version);
                        break;
                    case Tile.TileType.LINE_VERTICAL:
                        pieceObject = InstantiateLinePiece(0, version);
                        break;
                    case Tile.TileType.LINE_HORIZONTAL:
                        pieceObject = InstantiateLinePiece(1, version);
                        break;
                    case Tile.TileType.NONE:
                        pieceObject = InstantiateNonePiece();
                        break;
                }
                pieceObject.transform.position = new Vector3((float)tile.x * m_tileScale, 0, (float)tile.y * m_tileScale);
                this.m_dungeonPieceList.Add(pieceObject);
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetTileType()
        {
            for (int i = 0; i < m_map.Count; i++)
            {
                //check for cross
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.CROSS;
                    m_map[i] = tempTile;
                }

                //chech for corner 1
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.CORNER_1;
                    m_map[i] = tempTile;
                }

                //chech for corner 2
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.CORNER_2;
                    m_map[i] = tempTile;
                }

                //chech for corner 3
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.CORNER_3;
                    m_map[i] = tempTile;
                }

                //chech for corner 4
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.CORNER_4;
                    m_map[i] = tempTile;
                }

                //chech for triple 1
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.TRIPLE_1;
                    m_map[i] = tempTile;
                }

                //chech for triple 2
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.TRIPLE_2;
                    m_map[i] = tempTile;
                }

                //chech for triple 3
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.TRIPLE_3;
                    m_map[i] = tempTile;
                }

                //chech for triple 4
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.TRIPLE_4;
                    m_map[i] = tempTile;
                }

                //chech for dead end 1
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.DEAD_END_1;
                    m_map[i] = tempTile;
                }

                //chech for dead end 2
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.DEAD_END_2;
                    m_map[i] = tempTile;
                }

                //chech for dead end 3
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.DEAD_END_3;
                    m_map[i] = tempTile;
                }

                //chech for dead end 4
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.DEAD_END_4;
                    m_map[i] = tempTile;
                }

                //chech for line vertical
                if (m_map[i].northNeighbour == true &&
                    m_map[i].southNeighbour == true &&
                    m_map[i].westNeighbour == false &&
                    m_map[i].eastNeighbour == false)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.LINE_VERTICAL;
                    m_map[i] = tempTile;
                }

                //chech for line horizontal
                if (m_map[i].northNeighbour == false &&
                    m_map[i].southNeighbour == false &&
                    m_map[i].westNeighbour == true &&
                    m_map[i].eastNeighbour == true)
                {
                    Tile tempTile = m_map[i];
                    tempTile.type = Tile.TileType.LINE_HORIZONTAL;
                    m_map[i] = tempTile;
                }
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void ScrambleTileVersions()
        {
            int crossCount = 0;
            List<int> crossTypes = new List<int>();

            //scramble
            for (int i = 0; i < m_map.Count; i++)
            {
                Tile tempTile = m_map[i];
                tempTile.version = i % 4;
                m_map[i] = tempTile;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void ModifyTilePatterns()
        {
            //check for 5 cross, remove center cross and change remaining to tripple
            for (int j = 0; j < m_map.Count; j++)
            {
                //get coordinates for current tile
                int x = m_map[j].x;
                int y = m_map[j].y;

                //create temp neighbours for this tile
                List<Tile> tempMap = new List<Tile>();
                tempMap.Add(new Tile(x, y - 1));    //north
                tempMap.Add(new Tile(x, y + 1));    //south
                tempMap.Add(new Tile(x - 1, y));    //west
                tempMap.Add(new Tile(x + 1, y));    //east

                //check if tile is cross
                if (GetTileType(x, y) == Tile.TileType.CROSS)
                {
                    Tile.TileType tipo1 = GetTileType(x, y - 1);
                    Tile.TileType tipo2 = GetTileType(x, y + 1);
                    Tile.TileType tipo3 = GetTileType(x - 1, y);
                    Tile.TileType tipo4 = GetTileType(x + 1, y);

                    if (tipo1 == Tile.TileType.CROSS && tipo2 == Tile.TileType.CROSS && tipo3 == Tile.TileType.CROSS && tipo4 == Tile.TileType.CROSS)
                    {
                        //set current tile to None
                        m_map[j].type = Tile.TileType.NONE;
                        SetTileType(x, y - 1, Tile.TileType.TRIPLE_4);
                        SetTileType(x, y + 1, Tile.TileType.TRIPLE_2);
                        SetTileType(x - 1, y, Tile.TileType.TRIPLE_3);
                        SetTileType(x + 1, y, Tile.TileType.TRIPLE_1);
                    }
                }
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private Tile.TileType GetTileType(int x, int y)
        {
            foreach (Tile item in this.m_map)
	        {
		        if(item.x == x && item.y == y){
                    return item.type;
                }
	        }
            return Tile.TileType.NONE;
        }

        //------------------------------------------------------------------------------------------------------------------
        private void SetTileType(int x, int y, Tile.TileType type)
        {
            for (int i = 0; i < this.m_map.Count; i++)
            {
                if (this.m_map[i].x == x && this.m_map[i].y == y)
                {
                    this.m_map[i].type = type;
                }                
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void MoveAllMapLinkedToFirstPiecePivot(int x, int y)
        {
            int newX = this.m_map[0].x - x;
            int newY = this.m_map[0].y - y;

            for (int i = 0; i < this.m_map.Count; i++)
            {
                this.m_map[i].x -= newX;
                this.m_map[i].y -= newY;
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadCrossPieces()
        {
            this.m_crossPiece = new List<GameObject>();
            string version = "ABCD";

            for (int i = 0; i < version.Length; i++)
            {
                string assetPath = this.m_mainPath + "cross/PREFAB_piece_cross_" + version[i];
                this.m_crossPiece.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadCornerPieces()
        {
            this.m_cornerPieceList_A = new List<GameObject>();
            this.m_cornerPieceList_B = new List<GameObject>();
            this.m_cornerPieceList_C = new List<GameObject>();
            this.m_cornerPieceList_D = new List<GameObject>();
            string version = "ABCD";

            for (int i = 1; i < 5; i++)
            {
                string assetPath = m_mainPath + "corner/PREFAB_piece_corner_" + version[0] + "_" + i.ToString();
                this.m_cornerPieceList_A.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "corner/PREFAB_piece_corner_" + version[1] + "_" + i.ToString();
                this.m_cornerPieceList_B.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "corner/PREFAB_piece_corner_" + version[2] + "_" + i.ToString();
                this.m_cornerPieceList_C.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "corner/PREFAB_piece_corner_" + version[3] + "_" + i.ToString();
                this.m_cornerPieceList_D.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadLinePieces()
        {
            this.m_linePieceList_A = new List<GameObject>();
            this.m_linePieceList_B = new List<GameObject>();
            this.m_linePieceList_C = new List<GameObject>();
            this.m_linePieceList_D = new List<GameObject>();
            string version = "ABCD";

            for (int i = 1; i < 3; i++)
            {
                string assetPath = m_mainPath + "line/PREFAB_piece_line_" + version[0] + "_" + i.ToString();
                this.m_linePieceList_A.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "line/PREFAB_piece_line_" + version[1] + "_" + i.ToString();
                this.m_linePieceList_B.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "line/PREFAB_piece_line_" + version[2] + "_" + i.ToString();
                this.m_linePieceList_C.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "line/PREFAB_piece_line_" + version[3] + "_" + i.ToString();
                this.m_linePieceList_D.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadDeadEndPieces()
        {
            this.m_deadEndPieceList_A = new List<GameObject>();
            this.m_deadEndPieceList_B = new List<GameObject>();
            this.m_deadEndPieceList_C = new List<GameObject>();
            this.m_deadEndPieceList_D = new List<GameObject>();
            string version = "ABCD";

            for (int i = 1; i < 5; i++)
            {
                string assetPath = m_mainPath + "dead_end/PREFAB_piece_dead_end_" + version[0] + "_" + i.ToString();
                this.m_deadEndPieceList_A.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "dead_end/PREFAB_piece_dead_end_" + version[1] + "_" + i.ToString();
                this.m_deadEndPieceList_B.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "dead_end/PREFAB_piece_dead_end_" + version[2] + "_" + i.ToString();
                this.m_deadEndPieceList_C.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "dead_end/PREFAB_piece_dead_end_" + version[3] + "_" + i.ToString();
                this.m_deadEndPieceList_D.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadTriplePieces()
        {
            this.m_triplePieceList_A = new List<GameObject>();
            this.m_triplePieceList_B = new List<GameObject>();
            this.m_triplePieceList_C = new List<GameObject>();
            this.m_triplePieceList_D = new List<GameObject>();
            string version = "ABCD";

            for (int i = 1; i < 5; i++)
            {
                string assetPath = m_mainPath + "triple/PREFAB_piece_triple_" + version[0] + "_" + i.ToString();
                this.m_triplePieceList_A.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "triple/PREFAB_piece_triple_" + version[1] + "_" + i.ToString();
                this.m_triplePieceList_B.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "triple/PREFAB_piece_triple_" + version[2] + "_" + i.ToString();
                this.m_triplePieceList_C.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));

                assetPath = m_mainPath + "triple/PREFAB_piece_triple_" + version[3] + "_" + i.ToString();
                this.m_triplePieceList_D.Add((GameObject)Resources.Load(assetPath, typeof(GameObject)));
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void LoadNonePiece()
        {
            string assetPath = this.m_mainPath + "PREFAB_PieceNone";
            this.m_nonePiece = (GameObject)Resources.Load(assetPath, typeof(GameObject));
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateCrossPiece(int version)
        {
            return GameObject.Instantiate((GameObject)m_crossPiece[version]);
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateCornerPiece(int type, int version)
        {
            GameObject pieceObject = null;
            switch (version)
            {
                case 0:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_cornerPieceList_A[type]);
                    break;
                case 1:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_cornerPieceList_B[type]);
                    break;
                case 2:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_cornerPieceList_C[type]);
                    break;
                case 3:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_cornerPieceList_D[type]);
                    break;
            }
            return pieceObject;
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateTriplePiece(int type, int version)
        {
            GameObject pieceObject = null;
            switch (version)
            {
                case 0:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_triplePieceList_A[type]);
                    break;
                case 1:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_triplePieceList_B[type]);
                    break;
                case 2:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_triplePieceList_C[type]);
                    break;
                case 3:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_triplePieceList_D[type]);
                    break;
            }
            return pieceObject;
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateDeadEndPiece(int type, int version)
        {
            GameObject pieceObject = null;
            switch (version)
            {
                case 0:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_deadEndPieceList_A[type]);
                    break;
                case 1:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_deadEndPieceList_B[type]);
                    break;
                case 2:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_deadEndPieceList_C[type]);
                    break;
                case 3:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_deadEndPieceList_D[type]);
                    break;
            }
            return pieceObject;
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateLinePiece(int type, int version)
        {
            GameObject pieceObject = null;
            switch (version)
            {
                case 0:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_linePieceList_A[type]);
                    break;
                case 1:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_linePieceList_B[type]);
                    break;
                case 2:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_linePieceList_C[type]);
                    break;
                case 3:
                    pieceObject = GameObject.Instantiate((GameObject)this.m_linePieceList_D[type]);
                    break;
            }
            return pieceObject;
        }

        //------------------------------------------------------------------------------------------------------------------
        private GameObject InstantiateNonePiece()
        {
            return GameObject.Instantiate((GameObject)m_nonePiece);
        }

        //------------------------------------------------------------------------------------------------------------------
        private void DestroyDungeon()
        {
            this.m_map.Clear();

            for (int i = 0; i < this.m_dungeonPieceList.Count; i++)
            {
                GameObject.Destroy(this.m_dungeonPieceList[i]);
            }
            this.m_dungeonPieceList.Clear();

            /*for (int i = 0; i < this.m_crossPiece.Count; i++)
            {
                //GameObject.Destroy(this.m_crossPiece[i]);                
            }

            for (int i = 0; i < this.m_cornerPieceList_A.Count; i++)
            {
                GameObject.Destroy(this.m_cornerPieceList_A[i]);
                GameObject.Destroy(this.m_cornerPieceList_B[i]);
                GameObject.Destroy(this.m_cornerPieceList_C[i]);
                GameObject.Destroy(this.m_cornerPieceList_D[i]);
            }

            for (int i = 0; i < this.m_linePieceList_A.Count; i++)
            {
                GameObject.Destroy(this.m_linePieceList_A[i]);
                GameObject.Destroy(this.m_linePieceList_B[i]);
                GameObject.Destroy(this.m_linePieceList_C[i]);
                GameObject.Destroy(this.m_linePieceList_D[i]);
            }

            for (int i = 0; i < this.m_triplePieceList_A.Count; i++)
            {
                GameObject.Destroy(this.m_triplePieceList_A[i]);
                GameObject.Destroy(this.m_triplePieceList_B[i]);
                GameObject.Destroy(this.m_triplePieceList_C[i]);
                GameObject.Destroy(this.m_triplePieceList_D[i]);
            }

            for (int i = 0; i < this.m_deadEndPieceList_A.Count; i++)
            {
                GameObject.Destroy(this.m_deadEndPieceList_A[i]);
                GameObject.Destroy(this.m_deadEndPieceList_B[i]);
                GameObject.Destroy(this.m_deadEndPieceList_C[i]);
                GameObject.Destroy(this.m_deadEndPieceList_D[i]);
            }

            this.m_crossPiece.Clear();

            this.m_cornerPieceList_A.Clear();
            this.m_cornerPieceList_B.Clear();
            this.m_cornerPieceList_C.Clear();
            this.m_cornerPieceList_D.Clear();

            this.m_linePieceList_A.Clear();
            this.m_linePieceList_B.Clear();
            this.m_linePieceList_C.Clear();
            this.m_linePieceList_D.Clear();

            this.m_triplePieceList_A.Clear();
            this.m_triplePieceList_B.Clear();
            this.m_triplePieceList_C.Clear();
            this.m_triplePieceList_D.Clear();

            this.m_deadEndPieceList_A.Clear();
            this.m_deadEndPieceList_B.Clear();
            this.m_deadEndPieceList_C.Clear();
            this.m_deadEndPieceList_D.Clear();
            */
        }
    }
}
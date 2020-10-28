using UnityEngine;
//using UnityEditor;
using System.Collections;

public class PlayerMovement : MonoBehaviour {

	private GameObject m_playerPositionDummy;
	private GameObject m_playerRotationDummy;
	private GameObject m_cameraDummy;
	private GameObject m_character;
	private Animator m_animator; 
	
	//navigation mesh
	private GameObject m_terrain;
	private NavMeshAgent m_player;
	private RaycastHit m_hitPosition;
	private Vector3 m_playerRotationVector;
	
	//lineRenderer
	private LineRenderer m_lineRenderer;
	private Vector3[] m_lineRendererPoints;
	
	//health bar
	public Texture m_healthBar;
	
	void Start () {
		m_playerPositionDummy = GameObject.Find("GAMEOBJ_PlayerPositionDummy");
		m_playerRotationDummy = GameObject.Find("GAMEOBJ_PlayerRotationDummy");
		m_cameraDummy = GameObject.Find("GAMEOBJ_CameraDummy");
		m_character = GameObject.FindWithTag("Player");
		m_animator = m_character.GetComponent<Animator>();
		
		m_terrain = GameObject.FindWithTag("Terrain");
		
		m_player = m_character.GetComponent<NavMeshAgent>();
		
		m_lineRenderer = GameObject.Find("GAMEOBJ_LineRenderer").GetComponent<LineRenderer>();
		m_lineRenderer.SetVertexCount(2);
		
		OK_CreateNavigationMesh();
	}
	
	void Update () {
		WIP_MousePointClickDestination();
		WIP_MousePointDragDestination();
		
		DrawLinesGameMode(new Vector3(0,0,0), new Vector3(10,0,0));
		
					
//		else{
//			m_animator.SetFloat("Idle_Walk", 0.0f);
////			m_animator.speed = 1.0f;		
//		}
		
		//check for attack mouse control
		if (Input.GetMouseButton(1)){
//			m_animator.speed = 1.0f;
//			m_animator.SetFloat("Idle_Walk", 1.0f);
		}
		
//		//keep walking until character reach hitPosition
//		Vector3 currentCharacterPosition = m_character.transform.position;
//		if(Vector3.Distance(currentCharacterPosition, m_hitPosition.point) <= 0.1f){
//			m_animator.SetFloat("Idle_Walk", 0.0f);
//			//m_animator.speed = 2.0f;				
//		}else{
//			m_animator.SetFloat("Idle_Walk", 1.0f);
//			m_animator.speed = 2.0f;				
//		}
		
	}
	
	void OnGUI(){
		WIP_DrawHealthBar();
	}

	void OnCollisionEnter(Collision col){
		if(col.gameObject.tag == "CollisionObjectsOnTheGround")
		{
			m_animator.SetFloat("Idle_Walk", 1.0f);
		}
	}
	
	
	private void WIP_DrawHealthBar(){
		Vector3 position = m_character.transform.position;
		Vector3 guiPosition = Camera.main.WorldToScreenPoint(position);
		GUI.DrawTexture(new Rect(guiPosition.x - 50, Screen.height - guiPosition.y - 180, 100, 8), m_healthBar);
		//GUI.Label(new Rect(100, 85, 100, 100), "1234567890", m_style);			
		
		//GUI.Box(new Rect (0,0, 100,100), m_healthBar);
	}

	private void WIP_MousePointClickDestination()
	{
		//bool isInDestination = false;
		
		//check for walk mouse control
		if (Input.GetMouseButton(0)){
			
			//Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
			
			//			//if hit terrain
			//			if (Physics.Raycast(ray, out hit))
			//			{
			//				if(hit.collider.gameObject.tag == "Terrain"){
			//					//move character
			//					float speedCharacter = Time.deltaTime * 8.0f;
			////					m_playerPositionDummy.transform.position = Vector3.Lerp(m_playerPositionDummy.transform.position, hit.point, Time.deltaTime);
			//					m_playerPositionDummy.transform.position += Vector3.Normalize(hit.point - m_playerPositionDummy.transform.position) * speedCharacter;
			//
			//					//rotate character
			//					Vector3 rotation = Vector3.Normalize(hit.point - m_playerPositionDummy.transform.position);
			//					m_playerRotationDummy.transform.rotation = Quaternion.LookRotation(rotation);
			//					m_animator.SetFloat("Idle_Walk", 1.0f);
			//					m_animator.speed = 2.0f;
			//				}
			//			}
			
			if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out m_hitPosition, 100)) {
//				if(m_hitPosition.collider.gameObject.tag == "Terrain"){
					m_player.destination = m_hitPosition.point;
					m_player.updateRotation = true;
//				}
				//m_animator.SetFloat("Idle_Walk", 1.0f);
				//m_animator.speed = 2.0f;				
			}
			
			else{	
				//m_animator.SetBool("IsIdle", true);
			}
		}
				
		//-------------------------------------------------------------------------------------------------------------
		//keep walking until character reach hitPosition
		Vector3 currentCharacterPosition = m_character.transform.position;
		if(Vector3.Distance(currentCharacterPosition, m_hitPosition.point) <= 0.2f){
			m_animator.SetFloat("Idle_Walk", 0.0f);
			m_animator.speed = 2.0f;				
		}else{
			m_animator.SetFloat("Idle_Walk", 1.0f);
		}
		
//		//-------------------------------------------------------------------------------------------------------------
//		//keep player rotated
//		m_playerRotationVector = Vector3.Normalize(m_hitPosition.point - m_character.transform.position);
//		m_playerRotationVector += new Vector3(0.01f, 0, 0.01f);
//		if(Vector3.Magnitude(m_playerRotationVector) <= 0.02f){
//			m_character.transform.rotation = Quaternion.LookRotation(m_playerRotationVector);
////			m_character.transform.rotation = Quaternion.LookRotation(new Vector3(0,0,0));
////			m_character.transform.rotation = Quaternion.Euler(new Vector3(0,0,0));
//		}else{
//			//m_character.transform.rotation = Quaternion.Euler(new Vector3(90,0,0));
//		}
		
		//-------------------------------------------------------------------------------------------------------------
		//lock camera on character position
		m_cameraDummy.transform.position = m_character.transform.position;
	}
	
	private void WIP_MousePointDragDestination()
	{
	}
	
	private void DrawLineDebugMode(Vector3 p1, Vector3 p2, Color color){
		Debug.DrawLine(p1, p2, color);
	}
	
	private void DrawLinesGameMode(Vector3 p1, Vector3 p2){
		m_lineRendererPoints = new Vector3[2];
		m_lineRendererPoints[0] = m_character.transform.position;
		m_lineRendererPoints[1] = m_hitPosition.point;
		
		for (int i = 0; i < 2; i++) {
			m_lineRenderer.SetPosition(i, m_lineRendererPoints[i]);
		}
	}

	private void OK_CreateNavigationMesh(){
		//StaticEditorFlags flags =  StaticEditorFlags.NavigationStatic;//GameObjectUtility.GetStaticEditorFlags(m_terrain.gameObject);
		//flags = flags & (StaticEditorFlags.NavigationStatic);
		//GameObjectUtility.SetStaticEditorFlags(m_terrain, flags);
		
		//NavMeshBuilder.ClearAllNavMeshes();
		//NavMeshBuilder.BuildNavMesh();
		
//		GameObjectUtility.SetStaticEditorFlags(m_terrain, StaticEditorFlags.NavigationStatic);
//		NavMeshBuilder.ClearAllNavMeshes();
//		NavMeshBuilder.BuildNavMesh();
	}
	
}

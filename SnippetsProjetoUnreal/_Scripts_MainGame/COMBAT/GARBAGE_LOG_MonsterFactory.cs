//==================================================================================================================
//
//	File:	LOG_MonsterFactory.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
//using UnityEditor;
using System.Collections;
using System.Collections.Generic;

//------------------------------------------------------------------------------------------------------------------
public class MonsterFactory : MonoBehaviour {

	private List<GameObject> monsterAssets;
	private List<GameObject> monsterRuntime;
	
	//health bar
	public Texture m_healthBar;
	private GUIStyle m_style;
	 
	//character position
	private Vector3 m_playerPosition;
		
	//------------------------------------------------------------------------------------------------------------------
	void Awake()
	{
		//health bar and numbers
		//m_style.normal.textColor = Color.yellow;
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void Start () {
		monsterAssets = new List<GameObject>();
		monsterRuntime = new List<GameObject>();
		LoadAssetMonsters();
		CreateMonsterCrowd(30);		
	}
	
	//------------------------------------------------------------------------------------------------------------------
	// Update is called once per frame
	void Update () {
		m_playerPosition = GameObject.FindWithTag("Player").transform.position;
		
		//define destination for each monster
		for (int i = 0; i < 10; i++) {
			monsterRuntime[i].GetComponent<NavMeshAgent>().destination = m_playerPosition;

//			Vector3 monsterPosition = monsterRuntime[i].GetComponent<NavMeshAgent>().transform.position;
//			if(Vector3.Distance (m_playerPosition, monsterPosition) < 50){
//				monsterRuntime[i].GetComponent<NavMeshAgent>().destination = m_playerPosition;
//			}else{
//				monsterRuntime[i].GetComponent<NavMeshAgent>().destination = monsterPosition;
//			}
		}
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void OnGUI(){
		MOVED_DrawMonsterInfo();
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void LoadAssetMonsters(){
		for (int i = 1; i <= 10; i++) {
			string assetPath = "Models/Monsters/ID_"+ i.ToString("00") +"/PREFAB_monster_ID_"+ i.ToString("00") +"";
			monsterAssets.Add( (GameObject)Resources.Load(assetPath, typeof(GameObject)) );
//			monsterAssets.Add( (GameObject)AssetDatabase.LoadAssetAtPath(assetPath, typeof(GameObject)) );
		}
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void SpawnMonster(int id, Vector3 position, Quaternion rotation){
		GameObject monster = GameObject.Instantiate( (GameObject)monsterAssets[id], position, rotation) as GameObject;
		
		//add navmesh agent component
		monster.AddComponent<NavMeshAgent>();
		monster.GetComponent<NavMeshAgent>().radius = 0.5f;
		monster.GetComponent<NavMeshAgent>().speed = Random.Range(5.0f, 10.0f);
		monster.transform.parent = GameObject.Find("GAMEOBJ_Monsters").transform;
		
		//add material component
		Material monsterMaterial = (Material)Resources.Load("Assets/Materials/Monsters/MAT_Monster_ID_01", typeof(Material));
		MeshRenderer monsterMeshRenderer = monster.AddComponent<MeshRenderer>();
		monsterMeshRenderer.material = monsterMaterial;
		
		monsterRuntime.Add (monster);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void CreateMonsterCrowd(int total){
		for (int i = 0; i < total; i++) {
			NavMeshHit hit;
			int idMonster = Random.Range(0, 9);
			Vector3 position = new Vector3(Random.Range(-50.0f, 50.0f), 0, Random.Range(-50.0f, 50.0f));
			NavMesh.SamplePosition(position, out hit, 100, 1);
			Quaternion rotation = Quaternion.Euler(0, Random.Range(0.0f, 360.0f), 0);
			SpawnMonster(idMonster, hit.position, rotation);			
		}
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void SetMonsterState(int id, int state){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void KillMonster(int id){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void MOVED_DrawHealthBar(){
		GUI.Box(new Rect (0,0, 100,100), m_healthBar);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void MOVED_DrawHealthNumbers(){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void MOVED_DrawMonsterMainHealthBar(){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void MOVED_DrawMonsterInfo(){
//		DrawHealthBar();
//		DrawHealthNumbers();
//		DrawMonsterMainHealthBar();
		for (int i = 0; i < monsterRuntime.Count; i++) {
			Vector3 position = monsterRuntime[i].transform.position;
			Vector3 guiPosition = Camera.main.WorldToScreenPoint(position);
			GUI.DrawTexture(new Rect(guiPosition.x-50, Screen.height - guiPosition.y - 300, 100, 8), m_healthBar);
			//GUI.Label(new Rect(100, 85, 100, 100), "1234567890", m_style);			
		}		
	}
}

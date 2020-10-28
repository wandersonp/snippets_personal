//==================================================================================================================
//
//	File:	UI_HealthyBars.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

public class UI_HealthBars :ScriptableObject{

	public Texture m_healthBar;
	private GUIStyle m_style;

	//------------------------------------------------------------------------------------------------------------------
	public void Initialize(){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void Run(){
	}

	//------------------------------------------------------------------------------------------------------------------
	public void Release(){
	}	
			
	//------------------------------------------------------------------------------------------------------------------
	public void Draw(){
		DrawAllHealthInfo();
	}	

	//------------------------------------------------------------------------------------------------------------------
	private void DrawAllHealthInfo(){
//		DrawHealthBar();
//		DrawHealthNumbers();
//		DrawMonsterTitleHealthBar();
//		DrawHeroHeadHealthBar();
		
//		for (int i = 0; i < monsterRuntime.Count; i++) {
//			Vector3 position = monsterRuntime[i].transform.position;
//			Vector3 guiPosition = Camera.main.WorldToScreenPoint(position);
//			GUI.DrawTexture(new Rect(guiPosition.x-50, Screen.height - guiPosition.y - 300, 100, 8), m_healthBar);
//			//GUI.Label(new Rect(100, 85, 100, 100), "1234567890", m_style);			
//		}		
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawSingleHealthBar(Vector3 worldPosition, float percent){
		//GUI.Box(new Rect (0,0, 100,100), m_healthBar);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawHealthNumbers(Vector3 worldPosition, int value){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawMonsterTitleHealthBar(float percent){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawMonsterHeadHealthBar(Vector3 worldPosition, int value){
	}
		
	//------------------------------------------------------------------------------------------------------------------
	private void DrawHeroHeadHealthBar(Vector3 worldPosition, int value){
	}	
}

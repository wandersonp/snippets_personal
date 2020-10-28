//==================================================================================================================
//
//	File:	UI_HeadUpDisplay.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

//------------------------------------------------------------------------------------------------------------------
public class UI_HeadUpDisplay : MonoBehaviour {

	private UI_DamageNumbersManager m_damageNumbersManager;
	private UI_HealthBars m_healthBars;
	private UI_PlayerHUD m_playerHUD;
	private UI_MiniMap m_miniMap;
	private UI_MessageBox m_messageBox;
	private UI_DeadScreen m_deadScreen;
	private UI_MainMenuScreen m_mainMenuScreen;
	private UI_StatisticsScreen m_statisticsScreen;
	
	//------------------------------------------------------------------------------------------------------------------
	void Start () {
		m_damageNumbersManager = ScriptableObject.CreateInstance<UI_DamageNumbersManager>();
		m_damageNumbersManager.Initialize();
		
		m_healthBars = ScriptableObject.CreateInstance<UI_HealthBars>();
		m_healthBars.Initialize();

		m_playerHUD = ScriptableObject.CreateInstance<UI_PlayerHUD>();
		m_playerHUD.Initialize();

		m_miniMap = ScriptableObject.CreateInstance<UI_MiniMap>();
		m_miniMap.Initialize();

		m_messageBox = ScriptableObject.CreateInstance<UI_MessageBox>();
		m_messageBox.Initialize();

		m_deadScreen = ScriptableObject.CreateInstance<UI_DeadScreen>();
		m_deadScreen.Initialize();

		m_mainMenuScreen = ScriptableObject.CreateInstance<UI_MainMenuScreen>();
		m_mainMenuScreen.Initialize();

		m_statisticsScreen = ScriptableObject.CreateInstance<UI_StatisticsScreen>();
		m_statisticsScreen.Initialize();
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void FixedUpdate () {
		m_damageNumbersManager.Run();
		m_healthBars.Run();
		m_playerHUD.Run();
		m_miniMap.Run();
		m_messageBox.Run();
		m_deadScreen.Run();
		m_mainMenuScreen.Run();
		m_statisticsScreen.Run();
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void OnDestroy() {
		m_damageNumbersManager.Release();
		m_healthBars.Release();
		m_playerHUD.Release();
		m_miniMap.Release();
		m_messageBox.Release();
		m_deadScreen.Release();
		m_mainMenuScreen.Release();
		m_statisticsScreen.Release();
	}
	
	//------------------------------------------------------------------------------------------------------------------
	void OnGUI(){
		m_damageNumbersManager.Draw();
		m_healthBars.Draw();
		m_playerHUD.Draw();
		m_miniMap.Draw();
		m_messageBox.Draw();
		m_deadScreen.Draw();
		m_mainMenuScreen.Draw();
		m_statisticsScreen.Draw();
	}
}










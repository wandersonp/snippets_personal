//==================================================================================================================
//
//	File:	UI_PlayerHUD.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
public class UI_PlayerHUD : ScriptableObject {

	//UI elements
	private Texture m_healthGlobe;	
	private Texture m_manaGlobe;
	private Texture m_levelProgressionBar;
	private Texture m_shellBottomHUD;
	private Texture m_characterIcon;
	private Texture m_skillButtonA;
	private Texture m_skillButtonB;
	private Texture m_skillButtonC;
	private Texture m_skillButtonD;
	private Texture m_skillButtonMouseLeft;
	private Texture m_skillButtonMouseRight;
	
	//used for screen proportions
	private float m_screenWidth;
	private float m_guiRatio;
	private Vector3 m_guiScaled;
	
	//variables to estimate hud sizes
	private float m_healthGlobePercent;
	private float m_manaGlobePercent;
	private float m_levelProgressionBarPercent;
	
	private GUIStyle m_guiStyle;
	
	//------------------------------------------------------------------------------------------------------------------
	public void Initialize(){
	
		//initial states for dynamic bars
		m_healthGlobePercent = 1.0f;
		m_manaGlobePercent = 1.0f;
		m_levelProgressionBarPercent = 1.0f;
		
		m_screenWidth = Screen.width;
		m_guiRatio = m_screenWidth/1920;
		m_guiScaled = new Vector3(m_guiRatio, m_guiRatio, 1);
		
		//resources 
		string healthGlobeImage = "images/UI/health_globe";
		string manaGlobeImage = "images/UI/mana_globe";
		string levelProgressionImage = "images/UI/level_progression_bar";
		string shelBottonHUDImage = "images/UI/shell_botton_HUD";
		string characterIconImage = "images/UI/character_icon";
		string skillButtonAImage = "images/UI/skill_button_A";
		string skillButtonBImage = "images/UI/skill_button_B";
		string skillButtonCImage = "images/UI/skill_button_C";
		string skillButtonDImage = "images/UI/skill_button_D";
		string skillButtonMouseLeftImage = "images/UI/skill_button_mouse_left";
		string skillButtonMouseRightImage = "images/UI/skill_button_mouse_right";

		m_healthGlobe = (Texture)Resources.Load(healthGlobeImage, typeof(Texture));
		m_manaGlobe = (Texture)Resources.Load(manaGlobeImage, typeof(Texture));
		m_levelProgressionBar = (Texture)Resources.Load(levelProgressionImage, typeof(Texture));		
		m_shellBottomHUD = (Texture)Resources.Load(shelBottonHUDImage, typeof(Texture));	
		m_characterIcon = (Texture)Resources.Load(characterIconImage, typeof(Texture));	
		m_skillButtonA = (Texture)Resources.Load(skillButtonAImage, typeof(Texture));	
		m_skillButtonB = (Texture)Resources.Load(skillButtonBImage, typeof(Texture));	
		m_skillButtonC = (Texture)Resources.Load(skillButtonCImage, typeof(Texture));	
		m_skillButtonD = (Texture)Resources.Load(skillButtonDImage, typeof(Texture));	
		m_skillButtonMouseLeft = (Texture)Resources.Load(skillButtonMouseLeftImage, typeof(Texture));	
		m_skillButtonMouseRight = (Texture)Resources.Load(skillButtonMouseRightImage, typeof(Texture));	
			
		//text style
		m_guiStyle = new GUIStyle();
		m_guiStyle.normal.textColor = Color.yellow;	
		m_guiStyle.fontSize = 30;
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void Run(){
		//keep variables inside range 0-1
		m_healthGlobePercent = Mathf.Clamp(m_healthGlobePercent, 0, 1.0f);
		m_manaGlobePercent = Mathf.Clamp(m_manaGlobePercent, 0, 1.0f);
		m_levelProgressionBarPercent = Mathf.Clamp(m_levelProgressionBarPercent, 0, 1.0f);
		
		TEST_CheckAnimationForHUD();
	}

	//------------------------------------------------------------------------------------------------------------------
	public void Release(){
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void Draw(){
		DrawHealthGlobe();
		DrawManaGlobe();
		DrawLevelProgressionBar();
		DrawSkillsButtons();
		DrawShellBottomHUD();
		DrawIconImage();
		DrawIconLevelNumber();
		DrawCurrentTime();
		DrawDugeonNameLocation();
		DrawCharacterName();
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawIconImage(){
		Rect textureRect = new Rect(50, 50, 84, 84);
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);
		GUI.DrawTexture(textureRect, m_characterIcon);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawIconLevelNumber(){
		GUI.Label(new Rect(80, 140, 100, 100), "30", m_guiStyle);			
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawHealthGlobe(){
		Rect textureRect = new Rect(400, 900, 180, 180 * m_healthGlobePercent);
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);
		GUI.DrawTexture(textureRect, m_healthGlobe);
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawManaGlobe(){
		Rect textureRect = new Rect(1340, 900, 180, 180 * m_manaGlobePercent);
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);
		GUI.DrawTexture(textureRect, m_manaGlobe);
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawLevelProgressionBar(){
		Rect textureRect = new Rect(610, 955, 700 * m_levelProgressionBarPercent, 10);
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);
		GUI.DrawTexture(textureRect, m_levelProgressionBar);
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawSkillsButtons(){
		float offsetX = 100;
		Rect textureRect = new Rect(650, 992, 70, 70);
		
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);

		GUI.DrawTexture(textureRect, m_skillButtonA);

		textureRect.x += offsetX;
		GUI.DrawTexture(textureRect, m_skillButtonB);
		
		textureRect.x += offsetX;
		GUI.DrawTexture(textureRect, m_skillButtonC);
		
		textureRect.x += offsetX;
		GUI.DrawTexture(textureRect, m_skillButtonD);
		
		textureRect.x += offsetX;
		GUI.DrawTexture(textureRect, m_skillButtonMouseLeft);
		
		textureRect.x += offsetX;
		GUI.DrawTexture(textureRect, m_skillButtonMouseRight);	
	}

	//------------------------------------------------------------------------------------------------------------------
	private void DrawShellBottomHUD(){
		Rect textureRect = new Rect(360, 876, 1199, 204);
		GUI.matrix = Matrix4x4.TRS(new Vector3(m_guiScaled.x, m_guiScaled.y, 0), Quaternion.identity, m_guiScaled);
		GUI.DrawTexture(textureRect, m_shellBottomHUD);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawCurrentTime(){
		string currentTime = System.DateTime.Now.ToString("hh:mm");
		m_guiStyle.fontSize = 25;
		GUI.Label(new Rect(1800, 20, 100, 100), currentTime, m_guiStyle);			
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void DrawDugeonNameLocation(){
		string dungeonNameLocation = "Largo da Batata";
		m_guiStyle.fontSize = 30;
		GUI.Label(new Rect(1700, 50, 100, 100), dungeonNameLocation, m_guiStyle);			
	}
	
	private void DrawCharacterName(){
		m_guiStyle.fontSize = 25;
		string characterName = "Houdinik";
		GUI.Label(new Rect(0, 0, 100, 100), characterName, m_guiStyle);			
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void TEST_CheckAnimationForHUD()
	{
		//teste for bars
		if(Input.GetKeyUp(KeyCode.Q)){
//			m_healthGlobePercent = Mathf.Lerp(m_healthGlobePercent, m_healthGlobePercent -0.05f, 1 * Time.deltaTime);
			m_healthGlobePercent -= 0.05f;
		}
		if(Input.GetKeyDown(KeyCode.A)){
			m_healthGlobePercent += 0.05f;
		}
		if(Input.GetKeyDown(KeyCode.W)){
			m_manaGlobePercent -= 0.05f;
		}
		if(Input.GetKeyDown(KeyCode.S)){
			m_manaGlobePercent += 0.05f;
		}
		if(Input.GetKeyDown(KeyCode.E)){
			m_levelProgressionBarPercent -= 0.05f;
		}
		if(Input.GetKeyDown(KeyCode.D)){
			m_levelProgressionBarPercent += 0.05f;
		}
	}
}

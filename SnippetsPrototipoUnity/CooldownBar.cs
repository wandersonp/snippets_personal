using UnityEngine;
using System.Collections;

public class CooldownBar : MonoBehaviour {

	private Texture m_textureBar;
	private Texture m_textureButton;
	private bool m_cooldown;
	private float m_timer;
	private float m_endTime;
	private float m_offsetBar;
	
	void Start () {
		this.m_textureBar = (Texture)Resources.Load("cooldown_bar", typeof(Texture)); 
		this.m_textureButton = (Texture)Resources.Load("skill_button_A_active", typeof(Texture)); 
		this.m_cooldown = false;
		this.m_timer = 1.0f;
		this.m_endTime = 2.0f;
		this.m_offsetBar = 1.0f;
	}
	
	void FixedUpdate () {	
		UpdateCooldownBar();
	}
	
	void OnGUI(){
		Vector2 textureBarSize = new Vector2(5, 100);
		Vector2 textureButtonSize = new Vector2(80, 80);
		
		float offsetBottom = textureBarSize.y * this.m_offsetBar;
		Rect rect = new Rect(300, Screen.height - 200 - offsetBottom, textureBarSize.x, offsetBottom);
		GUI.DrawTexture(rect, m_textureBar);
		rect = new Rect(0, 0, textureButtonSize.x, textureButtonSize.y);
		GUI.DrawTexture(rect, m_textureButton);
	}
	
	public void UpdateCooldownBar(){
		if(Input.GetMouseButtonDown(0))
		{
			this.m_cooldown = true;
			this.m_timer = Time.time + this.m_endTime;
		}
		
		if(this.m_cooldown == true){
			this.m_offsetBar -= Time.deltaTime;
			this.m_offsetBar = Mathf.Clamp(this.m_offsetBar, 0, 1.0f);
			
			if(this.m_timer >= Time.time){
				this.m_cooldown = false;
				this.m_offsetBar = 1.0f;
			}
		}
		
//		if(this.m_timer <= 0.0f){
//			this.m_cooldown = false;
//			this.m_timer = 1.0f;
//		}
//		this.m_timer = Mathf.Clamp(m_timer, 0, 1.0f);
	}
}


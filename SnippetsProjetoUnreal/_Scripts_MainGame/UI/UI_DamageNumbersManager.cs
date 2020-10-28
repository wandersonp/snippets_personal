//==================================================================================================================
//
//	File:	UI_DamageNumbersManager.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

//------------------------------------------------------------------------------------------------------------------
public class UI_DamageNumbersManager :ScriptableObject{

	private float m_overallTimeDuration;
	private List<SDamageNumbersData> m_damageNumbersList;
	public GUIStyle m_style { get; set; }

	//------------------------------------------------------------------------------------------------------------------
	struct SDamageNumbersData{
		public List<string> m_textValue;
		public List<Rect> m_rectStartPosition;
		public List<Rect> m_rectCurrentPosition;
		public List<Rect> m_rectEndPosition;
		public float m_currentTime;
		public float m_scale;
	}
		
	//------------------------------------------------------------------------------------------------------------------
	public void Initialize(){
		//create new UI Style
		m_style = new GUIStyle();
		m_style.normal.textColor = Color.yellow;
		m_style.alignment = TextAnchor.MiddleCenter;
		m_style.fontSize = 20;
		m_style.font = (Font)Resources.Load("Fonts/TIMESBD", typeof(Font));
		m_style.fontStyle = FontStyle.Bold | FontStyle.Italic;
		
		m_overallTimeDuration = 0.5f;
		m_damageNumbersList = new List<SDamageNumbersData>();	
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void Run(){
		IncrementAnimationForAllDamageNumberData();
		RemoveCompletedDamageNumberData();
		
		if(Input.GetMouseButtonDown(0))
		{
			AppendDamageNumbersData();
		}
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void Release(){
		m_damageNumbersList.Clear();
	}
		
	//------------------------------------------------------------------------------------------------------------------
	public void Draw() {
		int countGroupDamage = m_damageNumbersList.Count;
		if(countGroupDamage > 0)
		{
			for (int i = 0; i < countGroupDamage; i++) {
				int countDamageValuesIndividuals = m_damageNumbersList[i].m_textValue.Count;

				AnimateAlpha(i);
				for (int j = 0; j < countDamageValuesIndividuals; j++) {
					AnimatePosition(i, j);
					AnimateScale(i, j);
//					GUI.Label( newPosition, m_damageNumbersList[i].m_textValue[j], m_style );					
					GUI.Label( m_damageNumbersList[i].m_rectCurrentPosition[j], m_damageNumbersList[i].m_textValue[j], m_style );					
				}
			}
		}		
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public void GetDamageInfoFromSimulation(){
	}

	//------------------------------------------------------------------------------------------------------------------
	private void AppendDamageNumbersData() {
		AppendRandomDamageNumberData();		
	}

	//------------------------------------------------------------------------------------------------------------------
	private void AppendRandomDamageNumberData(){
		SDamageNumbersData damageNumber = InitializeNullDamageNumbersStruct();
		
		int count = Random.Range(1, 10);
		for(int i = 0; i < count; i++){
			Rect startPosicao = new Rect( Random.Range(400, Screen.width-400), Random.Range(400, Screen.height-400), 100, 20 );
			Vector2 endVector = new Vector2( Random.Range(-10.0f, 10.0f), Random.Range(-10.0f, 0) );
			endVector.Normalize();
			endVector *= Random.Range(100.0f, 150.0f);
			Rect endPosicao = new Rect( endVector.x, endVector.y, 100, 20 );
			endPosicao.x += startPosicao.x;
			endPosicao.y += startPosicao.y;
			
			int damageValue = Random.Range(1000000, 10000000);
			string damageValueText = damageValue.ToString();
			damageValueText = string.Format("{0:0,0}", damageValue);
			
			damageNumber.m_textValue.Add( damageValueText );
			damageNumber.m_rectStartPosition.Add( startPosicao );
			damageNumber.m_rectCurrentPosition.Add( startPosicao );
			damageNumber.m_rectEndPosition.Add( endPosicao );
			damageNumber.m_currentTime = 0.0f;
			damageNumber.m_scale = 1.0f;
		}
				
		m_damageNumbersList.Add(damageNumber);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void IncrementAnimationForAllDamageNumberData(){
		for(int i = 0; i < m_damageNumbersList.Count; i++){
			SDamageNumbersData damageNumber = m_damageNumbersList[i];
			damageNumber.m_currentTime += m_overallTimeDuration * Time.deltaTime;
			damageNumber.m_scale += 1.0f * Time.deltaTime;
			m_damageNumbersList[i] = damageNumber;			
		}
	}
		
	//------------------------------------------------------------------------------------------------------------------
	private void RemoveCompletedDamageNumberData(){
		for(int i = m_damageNumbersList.Count-1; i >= 0; i--){
			if( m_damageNumbersList[i].m_currentTime >= m_overallTimeDuration ){
				m_damageNumbersList.RemoveAt(i);
			}   
		} 
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private SDamageNumbersData InitializeNullDamageNumbersStruct(){
		SDamageNumbersData damageNumber = new SDamageNumbersData();
		damageNumber.m_textValue = new List<string>();
		damageNumber.m_rectStartPosition = new List<Rect>() ;
		damageNumber.m_rectCurrentPosition = new List<Rect>() ;
		damageNumber.m_rectEndPosition = new List<Rect>() ;
		damageNumber.m_currentTime = 0.0f;
		damageNumber.m_scale = 1.0f;
		
		return damageNumber;
	}
		
	//------------------------------------------------------------------------------------------------------------------
	private void AnimateAlpha(int group){
		//animate alpha for each group
		m_style.normal.textColor = new Color(1.0f, 1.0f, 0.0f, 1.0f - m_damageNumbersList[group].m_currentTime * 2 );				
	}
	
	//------------------------------------------------------------------------------------------------------------------
	private void AnimatePosition(int group, int item){
		SDamageNumbersData damageNumber = m_damageNumbersList[group];
		
		Vector2 startPosition = new Vector2(damageNumber.m_rectStartPosition[item].x, damageNumber.m_rectStartPosition[item].y);
		Vector2 endPosition = new Vector2(damageNumber.m_rectEndPosition[item].x, damageNumber.m_rectEndPosition[item].y);
		Vector2 position = Vector2.Lerp(startPosition, endPosition, damageNumber.m_currentTime);
		Rect rectPosition = new Rect(position.x, position.y, damageNumber.m_rectStartPosition[item].width, damageNumber.m_rectStartPosition[item].height);
		damageNumber.m_rectCurrentPosition[item] = rectPosition;
		m_damageNumbersList[group] = damageNumber;
	}

	//------------------------------------------------------------------------------------------------------------------
	private void AnimateScale(int group, int item){
		//reset matrix gui
		GUI.matrix = Matrix4x4.identity;
		
		//animate scale
		Vector2 pivotPoint = new Vector2( m_damageNumbersList[group].m_rectCurrentPosition[item].x + 
		                                 m_damageNumbersList[group].m_rectCurrentPosition[item].width * 0.5f, 
		                                 m_damageNumbersList[group].m_rectCurrentPosition[item].y + 
		                                 m_damageNumbersList[group].m_rectCurrentPosition[item].height * 0.5f);
		Vector2 scale = Vector2.one * m_damageNumbersList[group].m_scale;
		GUIUtility.ScaleAroundPivot( scale, pivotPoint );						
	}
	
	
	
	

	//private List<Rect> m_currRect;
	
//	//public Font m_font;
//	private GUIStyle m_style;
//	
//	void Start(){
//		//Font ArialFont = (Font)Resources.GetBuiltinResource (typeof(Font), "JollyLodger");
//		//m_style.renderer.sharedMaterial = ArialFont.material;
//
//		m_style = new GUIStyle();
//		m_style.alignment = TextAnchor.MiddleCenter;
//		m_style.normal.textColor = Color.yellow;
//		m_style.fontSize = 30;
//		m_style.font = (Font)Resources.Load("Fonts/TIMESBD", typeof(Font));
//
//		//m_style.fontStyle = FontStyle.Bold | FontStyle.Italic;
//		//m_style.font = ArialFont;
//		
//	}
//	
//	void OnGUI(){
//	
//		GUI.Label(new Rect(100, 85, 100, 100), "1.234.567.890", m_style);			
//	}
	
	
	//public float m_time = 1.0f; // The length of the animation
	//public bool m_animatePos = true; // Does the position need to be animated ?
	//public bool m_animateAlpha = true; // Does the text need to fade ?
	//public bool m_animateSize = true; // Does the scale need to be animated ?
	//public Rect m_startRect = new Rect(10 ,10, 100, 100 ); // The start pos
	//public Vector2 m_movement = new Vector2(200, 0); // The endPos ( startRect + movement );
	
	//public AnimationCurve m_moveCurve; // The lerp between startRect and ( startRect + movement )
	//public AnimationCurve m_fadeCurve; // How is alpha behaving ?
	//public AnimationCurve m_sizeCurve; // How is the scale behaving ?
	
	
	//private float m_alpha = 1f;
	//private float m_scale = 1f;
		
//	void FixedUpdate(){
//		UpdateTime();
//	}
//	
//	
//	void Awake () 
//	{
//		//m_alpha = 0f;
//		m_style.normal.textColor = Color.yellow;
//		m_damageNumbers = new List<string>();
//		m_currRect = new List<Rect>();
//	}
//	
//	void Update(){
//		if(Input.GetMouseButtonDown(0)){
//			m_damageNumbers.Clear();
//			m_currRect.Clear();
//			int countDamageNumbers = Random.Range(1, 30);
//			for (int i = 0; i < countDamageNumbers; i++) {
//				int damageValue = Random.Range(1000000, 10000000);
//				int positionX = Random.Range(400, Screen.width-400);
//				int positionY = Random.Range(400, Screen.height-400);
//				
//				m_currRect.Add( new Rect(positionX ,positionY, 100, 100 ));
//				string damageValueText = damageValue.ToString();
//				damageValueText = string.Format("{0:0,0}", damageValue);
//				m_damageNumbers.Add( damageValueText );			
//			}
//			//Begin();
//		}	
//		if(Input.GetMouseButtonUp(0)){
//			m_damageNumbers.Clear();
//			m_currRect.Clear();
//		}
//	}
//
//	void OnGUI()
//	{
//		int countDamage = m_damageNumbers.Count;
//		if(countDamage > 0)
//		{
//			for (int i = 0; i < countDamage; i++) {
//				GUI.Label( m_currRect[i], m_damageNumbers[i], m_style );			
//			}
//			//			GUI.color = new Color(1,1,1, m_alpha );
//			//		
//			//			Vector2 pivotPoint = new Vector2( m_currRect.x + m_currRect.width * 0.5f, m_currRect.y + m_currRect.height * 0.5f);
//			//			Vector2 scale = Vector2.one * m_scale;
//			//			GUIUtility.ScaleAroundPivot( scale, pivotPoint ); 		
//			//			GUI.Label( m_currRect, m_damageNumbers[0], m_style );
//		}
//	}
//
//	// Start the animation with the argument
//	public void Begin()
//	{
////		StartCoroutine( Animate() );
//	}
		
	// The animation coroutine
//	IEnumerator Animate()
//	{
//		float step = 1f / m_time;
//		float counter = 0f;
//		m_currRect = m_startRect;
//		m_alpha = 1f;
//		m_scale = 1f;
//		while( counter < m_time )
//		{
//			float s = counter * step;
//			float t = m_moveCurve.Evaluate( s );
//			
//			// Fading
//			m_alpha = m_animateAlpha ? m_fadeCurve.Evaluate( s ) : 1f;
//			// Scaling
//			m_scale = m_animateSize ? m_sizeCurve.Evaluate( s ) : 1f;
//			// Moving
//			if( m_animatePos ){
//				m_currRect = new Rect( Mathf.Lerp( m_startRect.x, m_startRect.x + m_movement.x, t ),
//				                      Mathf.Lerp( m_startRect.y, m_startRect.y + m_movement.y, t ),
//				                      m_startRect.width, m_startRect.height );
//			}
//			
//			yield return null;
//			counter += Time.deltaTime;
//		}
//	}
}

//==================================================================================================================
//
//	File:	PlayerControls.cs
//	Date:	17-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	static functions for main hero controls
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
namespace GameSystem
{
	//------------------------------------------------------------------------------------------------------------------
	public class HeroControl {
	
		//------------------------------------------------------------------------------------------------------------------
		public static bool LeftMouseClick(){
			return Input.GetMouseButton(0);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool RightMouseClick(){
			return Input.GetMouseButton(1);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool LeftMouseClickDown(){
			return Input.GetMouseButtonDown(0);
		}
	
		//------------------------------------------------------------------------------------------------------------------
		public static bool RightMouseClickDown(){
			return Input.GetMouseButtonDown(1);
		}
	
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber0(){
			return Input.GetKey (KeyCode.Alpha0);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber0Down(){
			return Input.GetKeyDown (KeyCode.Alpha0);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber1(){
			return Input.GetKey (KeyCode.Alpha1);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber1Down(){
			return Input.GetKeyDown (KeyCode.Alpha1);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber2(){
			return Input.GetKey (KeyCode.Alpha2);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber2Down(){
			return Input.GetKeyDown (KeyCode.Alpha2);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber3(){
			return Input.GetKey (KeyCode.Alpha3);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber3Down(){
			return Input.GetKeyDown (KeyCode.Alpha3);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber4(){
			return Input.GetKey (KeyCode.Alpha4);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber4Down(){
			return Input.GetKeyDown (KeyCode.Alpha4);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber5(){
			return Input.GetKey (KeyCode.Alpha5);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber5Down(){
			return Input.GetKeyDown (KeyCode.Alpha5);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber6(){
			return Input.GetKey (KeyCode.Alpha6);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber6Down(){
			return Input.GetKeyDown (KeyCode.Alpha6);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber7(){
			return Input.GetKey (KeyCode.Alpha7);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber7Down(){
			return Input.GetKeyDown (KeyCode.Alpha7);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber8(){
			return Input.GetKey (KeyCode.Alpha8);
		}
	
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber8Down(){
			return Input.GetKeyDown (KeyCode.Alpha8);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber9(){
			return Input.GetKey (KeyCode.Alpha9);
		}
						
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonNumber9Down(){
			return Input.GetKeyDown (KeyCode.Alpha9);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterQ(){
			return Input.GetKey (KeyCode.Q);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterQDown(){
			return Input.GetKeyDown (KeyCode.Q);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterW(){
			return Input.GetKey (KeyCode.W);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterWDown(){
			return Input.GetKeyDown (KeyCode.W);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterE(){
			return Input.GetKey (KeyCode.E);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterEDown(){
			return Input.GetKeyDown (KeyCode.E);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterR(){
			return Input.GetKey (KeyCode.R);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterRDown(){
			return Input.GetKeyDown (KeyCode.R);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterT(){
			return Input.GetKey (KeyCode.T);
		}

		//------------------------------------------------------------------------------------------------------------------
		public static bool ButtonLetterTDown(){
			return Input.GetKeyDown (KeyCode.T);
		}
	}
}
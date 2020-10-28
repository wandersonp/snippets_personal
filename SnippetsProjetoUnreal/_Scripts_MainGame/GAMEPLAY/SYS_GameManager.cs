//==================================================================================================================
//
//	File:	SYS_GameManager.cs
//	Date:	17-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	Singleton Game manager for entire application
//
//==================================================================================================================

#define HUD
#define PLAYER
#define MONSTERS
#define COMBAT

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

//------------------------------------------------------------------------------------------------------------------
namespace GameSystem
{
	//------------------------------------------------------------------------------------------------------------------
	public class SYS_GameManager : Object{
	
		//------------------------------------------------------------------------------------------------------------------
		private static SYS_GameManager m_gameManagerInstance = null;
	
		//------------------------------------------------------------------------------------------------------------------
		//	Game Objects
		//------------------------------------------------------------------------------------------------------------------
		public Combat.UNIT_ISoldier m_hero;
		public List<Combat.UNIT_ISoldier> m_enemyArmy;
        public HUD.SYS_PlayerHUD m_playerHUD;
			
		//------------------------------------------------------------------------------------------------------------------
		//	Mediators
		//------------------------------------------------------------------------------------------------------------------
		public Combat.IMediator m_combatMediator;
	
		//------------------------------------------------------------------------------------------------------------------
		protected SYS_GameManager(){
		
#if (PLAYER)
            //create hero
			m_hero = new Combat.UNIT_Hero(100, 10, new Vector3(0,0,0));
#endif
                                       
#if (MONSTERS)
            //create enemy army
			m_enemyArmy = new List<Combat.UNIT_ISoldier>();
			for (int i = 0; i < 1; i++) {
				Vector3 position = new Vector3(Random.Range (-30.0f, 30.0f), 0, Random.Range (-30.0f, 30.0f));
                float visionRadius = 20.0f;// Random.Range(5.0f, 15.0f);
                float movementSpeed = 20.0f;// Random.Range(5.0f, 20.0f);
                m_enemyArmy.Add(new Combat.UNIT_Enemy(100, 10, visionRadius, movementSpeed, position));				
			}
#endif

#if (COMBAT)
            //create Combat mediator
			m_combatMediator = new Combat.SYS_CombatMediator();
			
			//register soldiers for combat mediator
			m_combatMediator.RegisterSoldier(m_hero);
			foreach (Combat.UNIT_ISoldier enemy in m_enemyArmy) {
				m_combatMediator.RegisterSoldier(enemy);				
			}
#endif

#if HUD
            //create HUD
            this.m_playerHUD = new HUD.SYS_PlayerHUD();
#endif
        }
			
		//------------------------------------------------------------------------------------------------------------------
		public static SYS_GameManager Instance{
			get {
				if (SYS_GameManager.m_gameManagerInstance == null){
					SYS_GameManager.m_gameManagerInstance = new SYS_GameManager();
					DontDestroyOnLoad(SYS_GameManager.m_gameManagerInstance);
				}
				return SYS_GameManager.m_gameManagerInstance;
			}
		}	
	}		
}

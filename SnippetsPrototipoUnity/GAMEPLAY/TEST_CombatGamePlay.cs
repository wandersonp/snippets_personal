//==================================================================================================================
//
//	File:	TEST_CombatGamePlay.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	test combat
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

namespace GamePlay
{
	//------------------------------------------------------------------------------------------------------------------
	public class TEST_CombatGamePlay : MonoBehaviour {
	
		//------------------------------------------------------------------------------------------------------------------
		GameSystem.SYS_GameManager m_gameManager;
	
		//------------------------------------------------------------------------------------------------------------------
		void Awake () {
			m_gameManager = GameSystem.SYS_GameManager.Instance;
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void Start(){
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void FixedUpdate () {
            Execute();
		}
		
		private void Execute(){
			if (GameSystem.HeroControl.LeftMouseClickDown()){
				int damage = Random.Range (10, 20);
				m_gameManager.m_hero.Attack(m_gameManager.m_combatMediator, damage);
				//			Debug.Log ("Player life: " + m_gameManager.m_hero.GetLife() + ", Attack: " + damage);
				//			Debug.Log ("Monster life: " + m_gameManager.m_enemyArmy[0].GetLife() );
			}
			
			if (GameSystem.HeroControl.RightMouseClickDown()){
				int damage = Random.Range (10, 20);
				m_gameManager.m_enemyArmy[0].Attack(m_gameManager.m_combatMediator, damage);
				//			Debug.Log ("Monster life: " + m_gameManager.m_enemyArmy[0].GetLife() + ", Attack: " + damage);
				//			Debug.Log ("Player life: " + m_gameManager.m_hero.GetLife() );
			}
			
			//check for hero life 
			if(m_gameManager.m_hero.IsDead()){
				Debug.Log ("Hero is dead");
			}
			
			//check for monster life
			if(m_gameManager.m_enemyArmy[0].IsDead()){
				Debug.Log ("Monster is dead");
			}
			
			//WaitForHeroSkills();
			//WaitForMonstersSkills();

            m_gameManager.m_hero.Update(m_gameManager.m_combatMediator);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		private void WaitForHeroSkills(){
			//activate Runner skill
			if (GameSystem.HeroControl.ButtonNumber1Down()){
				if(m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero)){
					Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
					hero.UseRunnerSkill();
				}
			}
			
			//activate ImpactSlice skill
			if (GameSystem.HeroControl.ButtonNumber2Down()){
				if(m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero)){
					Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
					hero.UseImpactSliceSkill(m_gameManager.m_combatMediator);
				}
			}
        
            //activate BlindTorture skill
            if (GameSystem.HeroControl.ButtonNumber3Down())
            {
                if (m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero))
                {
                    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
                    hero.UseBlindTortureSkill(m_gameManager.m_combatMediator);
                }
            }

            //activate Shout skill
            if (GameSystem.HeroControl.ButtonNumber4Down())
            {
                if (m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero))
                {
                    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
                    hero.UseShoutSkill(m_gameManager.m_combatMediator);
                }
            }
            //activate LeapOfFaith skill
            if (GameSystem.HeroControl.ButtonNumber5Down())
            {
                if (m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero))
                {
                    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
                    hero.UseLeapOfFaithSkill(m_gameManager.m_combatMediator);
                }
            }
            //activate HeavenSpin skill
            if (GameSystem.HeroControl.ButtonNumber6Down())
            {
                if (m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero))
                {
                    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
                    hero.UseHeavenSpinSKill(m_gameManager.m_combatMediator);
                }
            }
            //activate InvencibleShield skill
            if (GameSystem.HeroControl.ButtonNumber7Down())
            {
                if (m_gameManager.m_hero.GetType() == typeof(Combat.UNIT_Hero))
                {
                    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
                    hero.UseInvencibleShieldSkill(m_gameManager.m_combatMediator);
                }
            }
        }
		
		//------------------------------------------------------------------------------------------------------------------
		private void WaitForMonstersSkills(){
		}
	}
}
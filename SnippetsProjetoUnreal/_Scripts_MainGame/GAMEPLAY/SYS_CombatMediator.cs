//==================================================================================================================
//
//	File:	SYS_CombatMediator.cs
//	Date:	17-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	mediator class for combat damage, attack and spells information
//
//==================================================================================================================

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

//------------------------------------------------------------------------------------------------------------------
namespace Combat{

	//------------------------------------------------------------------------------------------------------------------
	public interface IMediator{
        //List<UNIT_ISoldier> soldierList { get; }
        //List<UNIT_ISoldier> soldierAliveList { get; }
        //List<UNIT_ISoldier> soldierDeadList { get; }
		void RegisterSoldier(UNIT_ISoldier soldier);
		
		//send information to enemies
        void DistributeMessageHeroPosition(UNIT_ISoldier hero);
        //void DistributeMessageHeroAttack(UNIT_ISoldier hero, int damage);
        //void DistributeMessageHeroRunnerSkill(UNIT_ISoldier hero);
        //void DistributeMessageHeroImpactSliceSkill(UNIT_ISoldier hero);
        //void DistributeMessageHeroBlindTortureSkill(UNIT_ISoldier hero);
        //void DistributeMessageHeroShoutSkill(UNIT_ISoldier hero);
        //void DistributeMessageHeroLeapOfFaithSkill(UNIT_ISoldier hero);
        //void DistributeMessageHeroHeavenSpinSkill(UNIT_ISoldier hero);	
        //void DistributeMessageHeroInvencibleShieldSkill(UNIT_ISoldier hero);	

		//send information to hero
//		void DistributeMessageEnemyAttack(UNIT_ISoldier attacker, int damage);
//		void DistributeMessageEnemyBlindSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyStunSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyFearSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyFreezeSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyJailerSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyArcaneSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyEletricSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyShieldSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyReflectDamageSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyMoltenSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyFireChainsSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyKnockBackSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyOrbiterSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyPlagueSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyIllusionistSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyNighmarishSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyAvengerSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyDesecratorSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyFastSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyVortexSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyTeleporterSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyThunderStormSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyWallerSkill(UNIT_ISoldier attacker);
//		void DistributeMessageEnemyHordeSkill(UNIT_ISoldier sender);
	}
	
	//------------------------------------------------------------------------------------------------------------------
	public class SYS_CombatMediator : IMediator{
        private List<UNIT_ISoldier> m_soldierList = new List<UNIT_ISoldier>();
        //private List<UNIT_ISoldier> soldierAliveList = new List<UNIT_ISoldier>();
		//private List<UNIT_ISoldier> soldierDeadList = new List<UNIT_ISoldier>();
		
		//------------------------------------------------------------------------------------------------------------------
        //List<UNIT_ISoldier> IMediator.soldierList{
        //    get { return soldierAliveList; }
        //}
		
        ////------------------------------------------------------------------------------------------------------------------
        //List<UNIT_ISoldier> IMediator.soldierDeadList{
        //    get { return soldierAliveList; }
        //}

		//------------------------------------------------------------------------------------------------------------------
		void IMediator.RegisterSoldier(UNIT_ISoldier soldier){
            m_soldierList.Add(soldier);
		}
				
		//------------------------------------------------------------------------------------------------------------------
//		void IMediator.AdviceForMonsterAttack(UNIT_ISoldier attacker, int damage)
//		{		
//			for (int i = soldierAliveList.Count-1; i >= 0 ; i--){
//				UNIT_ISoldier soldier = soldierAliveList[i]; 
//				
//				if(soldier.GetType() == typeof(UNIT_Hero))
//				{
//					Debug.Log("im a hero");
//				}
//				
//				if (soldier != attacker){
//					soldier.ReceiveAttack(damage);
//					soldier.SetMaterialEmissionDamage();
//					//move to dead list
//					if(soldier.IsDead()){
//						soldierDeadList.Add(soldier);
//						soldierAliveList.Remove(soldier);
//					}
//				}
//			}
//		}

        //------------------------------------------------------------------------------------------------------------------
        void IMediator.DistributeMessageHeroPosition(UNIT_ISoldier hero)
        {
            Vector3 heroPosition = hero.GetPosition();
            Vector3 enemyPosition = Vector3.zero;
            for (int i = 0; i < m_soldierList.Count; i++)
            {
                UNIT_ISoldier soldier = m_soldierList[i];
                //check if is not the player
                if (soldier != hero)
                {
                    enemyPosition = soldier.GetPosition();
                    float distance = Vector3.Distance(heroPosition, enemyPosition);

                    //chase hero
                    UNIT_Enemy enemy = (UNIT_Enemy)soldier;
                    float visionRadius = enemy.GetVisionRadius();
                    if (distance <= visionRadius)
                    {
                        soldier.MoveTo(heroPosition);
                    }
                }
            }
        }
        
        /*
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroAttack
        void IMediator.DistributeMessageHeroAttack(UNIT_ISoldier attacker, int damage){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster receive simple attack
            }
        }
		
        //------------------------------------------------------------------------------------------------------------------
        void IMediator.DistributeMessageHeroRunnerSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //do nothing
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroImpactSliceSkill
        void IMediator.DistributeMessageHeroImpactSliceSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster receive damage
                //by X distance from hero
                //caused by ImpactSlice skill
            }
        }
		
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroBlindTortureSkill
        void IMediator.DistributeMessageHeroBlindTortureSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster stay blinded 
                //by X distance from hero
                //by Y seconds 
                //caused by BlindTorture skill
            }
        }
		
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroShoutSkill
        void IMediator.DistributeMessageHeroShoutSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster slow down movement
                //by X percent 
                //for Y seconds
                //by Z distance from hero
                //caused by Shout skill
            }
        }
		
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroLeapOfFaithSkill
        void IMediator.DistributeMessageHeroLeapOfFaithSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster receive damage
                //when hero reach the ground
                //and push away from hero position
                //caused by LeapOfFaith skill
            }
        }
		
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroSpinHeavenSkill
        void IMediator.DistributeMessageHeroHeavenSpinSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster receive damage
                //by X distance from hero
                //caused by SpinHeaven skill
            }
        }
			
        //------------------------------------------------------------------------------------------------------------------
        //TODO DistributeMessageHeroInvencibleShieldSkill
        void IMediator.DistributeMessageHeroInvencibleShieldSkill(UNIT_ISoldier attacker){
            if(attacker.GetType() == typeof(UNIT_Hero))
            {
                //monster deal 0 damage to hero
                //caused by InvencibleShield
            }
        }
        */
		
		/*
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyAttack
		void IMediator.DistributeMessageEnemyAttack(UNIT_ISoldier attacker, int damage){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyBlindSkill
		void IMediator.DistributeMessageEnemyBlindSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyStunSkill
		void IMediator.DistributeMessageEnemyStunSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyFearSkill
		void IMediator.DistributeMessageEnemyFearSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyFreezeSkill
		void IMediator.DistributeMessageEnemyFreezeSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyJailerSkill
		void IMediator.DistributeMessageEnemyJailerSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyArcaneSkill
		void IMediator.DistributeMessageEnemyArcaneSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyEletricSkill
		void IMediator.DistributeMessageEnemyEletricSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyShieldSkill
		void IMediator.DistributeMessageEnemyShieldSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyReflectDamageSkill
		void IMediator.DistributeMessageEnemyReflectDamageSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyMoltenSkill
		void IMediator.DistributeMessageEnemyMoltenSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyFireChainsSkill
		void IMediator.DistributeMessageEnemyFireChainsSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyKnockBackSkill
		void IMediator.DistributeMessageEnemyKnockBackSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyOrbiterSkill
		void IMediator.DistributeMessageEnemyOrbiterSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyPlagueSkill
		void IMediator.DistributeMessageEnemyPlagueSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyIllusionistSkill
		void IMediator.DistributeMessageEnemyIllusionistSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyNighmarishSkill
		void IMediator.DistributeMessageEnemyNighmarishSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyAvengerSkill
		void IMediator.DistributeMessageEnemyAvengerSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyDesecratorSkill
		void IMediator.DistributeMessageEnemyDesecratorSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyFastSkill
		void IMediator.DistributeMessageEnemyFastSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyVortexSkill
		void IMediator.DistributeMessageEnemyVortexSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyTeleporterSkill
		void IMediator.DistributeMessageEnemyTeleporterSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyThunderStormSkill
		void IMediator.DistributeMessageEnemyThunderStormSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyWallerSkill
		void IMediator.DistributeMessageEnemyWallerSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		//TODO DistributeMessageEnemyHordeSkill
		void IMediator.DistributeMessageEnemyHordeSkill(UNIT_ISoldier attacker){
			if(attacker.GetType() == typeof(UNIT_Enemy))
			{
			}
		}
		*/
	}
}


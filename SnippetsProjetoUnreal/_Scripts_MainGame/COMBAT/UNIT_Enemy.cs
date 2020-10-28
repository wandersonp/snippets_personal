//==================================================================================================================
//
//	File:	UNIT_Enemy.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	enemy class
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
namespace Combat
{
	//------------------------------------------------------------------------------------------------------------------
	public class UNIT_Enemy : UNIT_ISoldier{

		//------------------------------------------------------------------------------------------------------------------
		//GAMEOBJECT
		private GameObject m_enemyGameObject;
        private Animator m_animator;
		
		//------------------------------------------------------------------------------------------------------------------
		//MAIN STATS
		private int m_maxLife;
		private int m_currentLife;
		private float m_damage;
		private bool m_dead;
		private bool m_damageTake;
		private float m_movementSpeed;
        private float m_attackSpeed;
        private float m_visionRadius;
		
		//------------------------------------------------------------------------------------------------------------------
		public UNIT_Enemy(int maxLife, int damage, float visionRadius, float movementSpeed, Vector3 position){
			this.m_maxLife = maxLife;
			this.m_currentLife = maxLife;
			this.m_damage = damage;
			this.m_dead = false;
			this.m_damageTake = false;
            this.m_visionRadius = visionRadius;
            this.m_movementSpeed = movementSpeed;

			//geometry for monster
            //this.m_enemyGameObject = GameObject.CreatePrimitive(PrimitiveType.Sphere);
            //m_enemyGameObject.transform.position = position;

            string assetPath = "Models/Monsters/ID_01/PREFAB_monster_ID_01";
            GameObject prefab = (GameObject)Resources.Load(assetPath, typeof(GameObject));
            this.m_enemyGameObject = GameObject.Instantiate((GameObject)prefab) as GameObject;
            this.m_enemyGameObject.transform.position = position;

            //animator control
            this.m_animator = this.m_enemyGameObject.GetComponent<Animator>();
            this.m_animator.speed = this.m_movementSpeed/5;
            
            //material
            //Renderer rend = m_enemyGameObject.GetComponent<Renderer>();
            //rend.material = Resources.Load("Materials/MAT_Simple", typeof(Material)) as Material;
            //rend.material.SetColor("_Color", Color.red);
			//rend.material.SetColor("_EmissionColor", Color.white);	
		}

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.Update(Combat.IMediator mediator)
        {
            //this.Chase(mediator);
        }

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.MoveTo(Vector3 destination)
        {
            NavMeshAgent agent = this.m_enemyGameObject.GetComponent<NavMeshAgent>();
            agent.destination = destination;
            agent.acceleration = 1000;
            agent.speed = m_movementSpeed;
            agent.updateRotation = true;
        }

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.SetState(int state)
        {
        }

        #region GETTERS_SETTERS
		//------------------------------------------------------------------------------------------------------------------
		int UNIT_ISoldier.GetMaxLife(){	
			return this.m_maxLife;
		}
		void UNIT_ISoldier.SetMaxLife(int value){	
			this.m_maxLife = value;
		}
        void UNIT_ISoldier.IncrementMaxLife(int value)
        {
            this.m_maxLife += value;
            this.m_maxLife = Mathf.Clamp(this.m_maxLife, 0, this.m_maxLife);
        }
        void UNIT_ISoldier.DecreaseMaxLife(int value)
        {
            this.m_maxLife -= value;
            this.m_maxLife = Mathf.Clamp(this.m_maxLife, 0, this.m_maxLife);
        }
		
		//------------------------------------------------------------------------------------------------------------------
		int UNIT_ISoldier.GetCurrentLife(){	
			return this.m_currentLife;
		}
		void UNIT_ISoldier.SetCurrentLife(int value){	
			this.m_maxLife = value;
		}
        void UNIT_ISoldier.IncrementCurrentLife(int value)
        {
            this.m_currentLife += value;
            this.m_currentLife = Mathf.Clamp(this.m_currentLife, 0, this.m_maxLife);
        }
        void UNIT_ISoldier.DecreaseCurrentLife(int value)
        {
            this.m_currentLife -= value;
            this.m_currentLife = Mathf.Clamp(this.m_currentLife, 0, this.m_maxLife);
        }
		
		//------------------------------------------------------------------------------------------------------------------
		float UNIT_ISoldier.GetDamage(){	
			return this.m_damage;
		}
		void UNIT_ISoldier.SetDamage(float value){	
			this.m_damage = value;
		}
		
		//------------------------------------------------------------------------------------------------------------------
		float UNIT_ISoldier.GetMovementSpeed(){	
			return this.m_movementSpeed;
		}
		void UNIT_ISoldier.SetMovementSpeed(float value){	
			this.m_movementSpeed = value;
		}
		
		//------------------------------------------------------------------------------------------------------------------
		Vector3 UNIT_ISoldier.GetPosition(){
			return m_enemyGameObject.transform.position;
		}
		void UNIT_ISoldier.SetPosition(Vector3 position){
			m_enemyGameObject.transform.position = position;
		}
		
		//------------------------------------------------------------------------------------------------------------------
		float UNIT_ISoldier.GetAtackSpeed(){
			return m_attackSpeed;
		}	
		void UNIT_ISoldier.SetAttackSpeed(float value){
			this.m_attackSpeed = value;
		}	
		//------------------------------------------------------------------------------------------------------------------
		int UNIT_ISoldier.GetMaxMana(){
			//do nothing
			return 0;
		}
		void UNIT_ISoldier.SetMaxMana(int value){
			//do nothing
		}
        void UNIT_ISoldier.IncrementMaxMana(int value)
        {
            //do nothing
        }
        void UNIT_ISoldier.DecreaseMaxMana(int value)
        {
            //do nothing
        }

        //------------------------------------------------------------------------------------------------------------------
        int UNIT_ISoldier.GetCurrentMana()
        {
            //do nothing
            return 0;
        }
        void UNIT_ISoldier.SetCurrentMana(int value)
        {
            //do nothing
        }
        void UNIT_ISoldier.IncrementCurrentMana(int value)
        {
            //do nothing
        }
        void UNIT_ISoldier.DecreaseCurrentMana(int value)
        {
            //do nothing
        }

        //------------------------------------------------------------------------------------------------------------------
        float UNIT_ISoldier.GetAnimatorSpeed()
        {
            return 0;
        }
        void UNIT_ISoldier.SetAnimatorSpeed(float value)
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        public float GetVisionRadius()
        {
            return this.m_visionRadius;
        }
        public void SetVisionRadius(float value)
        {
            this.m_visionRadius = value;
        }

        #endregion GETTERS_SETTERS
        
        //------------------------------------------------------------------------------------------------------------------
        private void Chase(Combat.IMediator mediator)
        {
            //mediator.DistributeMessageHeroPosition(this);
        }
        
        //------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.Attack(Combat.IMediator mediator, int damage){
			//mediator.AdviceAForAttack(this, damage);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveAttack(int damage){
			m_damageTake = true;
			m_currentLife -= damage;
			m_currentLife = Mathf.Clamp( m_currentLife, 0, m_maxLife );
			if(m_currentLife == 0){
				m_dead = true;
				m_enemyGameObject.transform.localScale = new Vector3(1.0f, 0.1f, 1.0f);
			}
		}
		
		//------------------------------------------------------------------------------------------------------------------
		bool UNIT_ISoldier.IsDead(){
			return m_dead;
		}
										
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.SetMaterialEmissionDamage(){
			Renderer renderer = m_enemyGameObject.GetComponent<Renderer>();
			
			if(m_damageTake){
				renderer.material.SetColor("_EmissionColor", new Color(0.3f, 0.3f, 0.3f));
			}else{
				renderer.material.SetColor("_EmissionColor", new Color(0,0,0));
			}
			
			//m_damageTake = false;
		}
		
		#region SKILLS BEHAVIOUR
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveRunnerSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoRunnerSkillBehaviour(Combat.IMediator mediator){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveImpactSliceSkillBehaviour(){
			//TODO subtract life from monsters
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoImpactSliceSkillBehaviour(Combat.IMediator mediator){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveBlindTortureSkillBehaviour(){
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoBlindTortureSkillBehaviour(Combat.IMediator mediator){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveShoutSkillBehaviour(){
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoShoutSkillBehaviour(Combat.IMediator mediator){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveLeapOfFaithSkillBehaviour(){
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoLeapOfFaithSkillBehaviour(Combat.IMediator mediator){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.ReceiveHeavenSpinSkillBehaviour()
        {
		}
			
		//------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.DoHeavenSpinSkillBehaviour(Combat.IMediator mediator)
        {
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveInvencibleShieldSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoInvencibleShieldSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroInvencibleShieldSkill(this);
		}
				
		#endregion SKILLS BEHAVIOUR	
		
												
														
																
																		
																				
																						
																										
		//STATES
	//	private enum HeroStates{
	//		MONSTER_WALK,
	//		MONSTER_ATTACK,
	//		MONSTER_IDLE,
	//		MONSTER_STUNNED,
	//		MONSTER_DEAD,
	//		MONSTER_SHAKEBODY,
	//		MONSTER_FREEZE,
	//		MONSTER_FEAR
	//	};
		
	//	//DAMAGE	
	//	private float m_attackSpeed;
	//	private bool m_dealAttack;
		
		
		/*
		skills dos elites
		
		-jailer
		-arcane
		-desecrator
		-teleporter
		-fast
		-vortex
		-thunderstorm
		-frozen
		-eletric
		-mortar
		-shield
		-molten
		-fire chains
		-waller
		-knockback
		-orbiter
		-plague
		-reflect damage
		-llusionist
		-nightmarish
		-horde
		-avenger
		-healthy link
		
		
		
		
		
		
	
		*/	
	}
}
//==================================================================================================================
//
//	File:	UNIT_Hero.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	hero class
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Combat
{
    //STATES
    public enum HeroStates
    {
        HERO_RUN,
        HERO_IDLE,
        //HERO_ATTACK,
        //HERO_STUNNED,
        //HERO_DEAD,
        //HERO_FEAR,
        //HERO_FREEZE,
        //HERO_SKILL_SLOT_01,
        //HERO_SKILL_SLOT_02
    };
    
    //==================================================================================================================
	public class UNIT_Hero : UNIT_ISoldier{
	
		//------------------------------------------------------------------------------------------------------------------
		//GAMEOBJECT
		private GameObject m_heroGameObject;
        private Animator m_animator;
        private float m_animatorSpeed;
        private RaycastHit m_hitPosition;

        
        //------------------------------------------------------------------------------------------------------------------
		//SKILLS
		private IHeroSkill m_skill_1;
        private IHeroSkill m_skill_2;
        private IHeroSkill m_skill_3;
        private IHeroSkill m_skill_4;
        private IHeroSkill m_skill_5;
        private IHeroSkill m_skill_6;
        private IHeroSkill m_skill_7;
	
		//------------------------------------------------------------------------------------------------------------------
		//MAIN STATS
		private int m_maxLife;
		private int m_currentLife;
		private float m_damage;
		private float m_attackSpeed;
		private bool m_dead;
		private bool m_damageTake;
		private float m_movementSpeed;
        private int m_maxMana;
        private int m_currentMana;
	
		//------------------------------------------------------------------------------------------------------------------
		public UNIT_Hero(int maxLife, int damage, Vector3 position){
			this.m_maxLife = maxLife;
			this.m_currentLife = maxLife;
			this.m_damage = damage;
			this.m_dead = false;
			this.m_damageTake = false;
			this.m_movementSpeed = 10.0f;
            this.m_maxMana = 100;
            this.m_currentMana = 50;
						
			//geometry for hero
			//this.m_heroGameObject = GameObject.CreatePrimitive(PrimitiveType.Cube);
            string assetPath = "Models/Player/ID_01/PREFAB_player_ID_01";
            GameObject prefab = (GameObject)Resources.Load(assetPath, typeof(GameObject));
            this.m_heroGameObject = GameObject.Instantiate((GameObject)prefab) as GameObject;
            this.m_heroGameObject.transform.position = position;
            //this.m_heroGameObject.transform.parent = GameObject.Find("GAMEOBJ_Dummy").transform;
            //this.m_heroGameObject.AddComponent<NavMeshAgent>();
			
            //animator control
            this.m_animator = this.m_heroGameObject.GetComponent<Animator>();
            this.m_animatorSpeed = 2.0f;




			//material
            //Material material = (Material)Resources.Load("Materials/Monsters/MAT_Monster_ID_01", typeof(Material));
            //MeshRenderer meshRenderer = this.m_heroGameObject.AddComponent<MeshRenderer>();
            //meshRenderer.material = material;
            
            //Renderer rend = m_heroGameObject.GetComponent<Renderer>();
			//rend.material = Resources.Load("Materials/MAT_Simple", typeof(Material)) as Material;
			//rend.material.SetColor("_Color", Color.yellow);
			
			//skills
			DefineInitialStateSkills();
		}

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.Update(Combat.IMediator mediator)
        {
            UNIT_ISoldier hero = this;

            //lock camera on player movement
            GameObject.Find("GAMEOBJ_Dummy").transform.position = this.m_heroGameObject.transform.position;

            //activate Runner skill
            if (GameSystem.HeroControl.RightMouseClickDown())
            {
                this.UseRunnerSkill();
            }

            m_skill_1.UpdateSkill();
            m_skill_2.UpdateSkill();
            m_skill_3.UpdateSkill();
            m_skill_4.UpdateSkill();
            m_skill_5.UpdateSkill();
            m_skill_6.UpdateSkill();
            m_skill_7.UpdateSkill();

            //keep player at NavigationMesh
            if (GameSystem.HeroControl.LeftMouseClick())
            {
                if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out m_hitPosition, 100))
                {
                    //if (hitPosition.collider.gameObject.tag == "NavigationMesh")
                    {
                        hero.MoveTo(m_hitPosition.point);
                    }
                }
            }

            //keep walking until character reach hitPosition
            Vector3 position = hero.GetPosition();
            if (Vector3.Distance(position, m_hitPosition.point) <= 0.2f)
            {
                hero.SetState((int)Combat.HeroStates.HERO_IDLE);
            }
            else
            {
                hero.SetState((int)Combat.HeroStates.HERO_RUN);
            }

            //messages to mediator
            mediator.DistributeMessageHeroPosition(this);
        }

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.MoveTo(Vector3 destination)
        {
            NavMeshAgent agent = this.m_heroGameObject.GetComponent<NavMeshAgent>();
            agent.destination = destination;
            agent.acceleration = 1000;
            agent.speed = m_movementSpeed;
            agent.updateRotation = true;
        }

        //------------------------------------------------------------------------------------------------------------------
        void UNIT_ISoldier.SetState(int state)
        {
            if (state == (int)HeroStates.HERO_IDLE)
            {
                this.m_animator.SetFloat("Idle_Walk", 0.0f);
                this.m_animator.speed = 1.0f;
            }
            if (state == (int)HeroStates.HERO_RUN)
            {
                this.m_animator.SetFloat("Idle_Walk", 1.0f);
                this.m_animator.speed = this.m_animatorSpeed;
            }
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
            this.m_currentLife = value;
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
			return m_heroGameObject.transform.position;
		}
		void UNIT_ISoldier.SetPosition(Vector3 position){
			m_heroGameObject.transform.position = position;
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
			return this.m_maxMana;
		}	
		void UNIT_ISoldier.SetMaxMana(int value){
			this.m_maxMana = value;
		}
        void UNIT_ISoldier.IncrementMaxMana(int value)
        {
            this.m_maxMana += value;
            this.m_maxMana = Mathf.Clamp(this.m_maxMana, 0, this.m_maxMana);
        }
        void UNIT_ISoldier.DecreaseMaxMana(int value)
        {
            this.m_maxMana -= value;
            this.m_maxMana = Mathf.Clamp(this.m_maxMana, 0, this.m_maxMana);
        }

        //------------------------------------------------------------------------------------------------------------------
        int UNIT_ISoldier.GetCurrentMana()
        {
            return this.m_currentMana;
        }
        void UNIT_ISoldier.SetCurrentMana(int value)
        {
            this.m_currentMana = value;
        }
        void UNIT_ISoldier.IncrementCurrentMana(int value)
        {
            this.m_currentMana += value;
            this.m_currentMana = Mathf.Clamp(this.m_currentMana, 0, this.m_maxMana);
        }
        void UNIT_ISoldier.DecreaseCurrentMana(int value)
        {
            this.m_currentMana -= value;
            this.m_currentMana = Mathf.Clamp(this.m_currentMana, 0, this.m_maxMana);
        }

        //------------------------------------------------------------------------------------------------------------------
        float UNIT_ISoldier.GetAnimatorSpeed()
        {
            return this.m_animatorSpeed;
        }
        void UNIT_ISoldier.SetAnimatorSpeed(float value)
        {
            this.m_animatorSpeed = value;        
        }

        //------------------------------------------------------------------------------------------------------------------
        public float GetSkill1CurrentTime()
        {
            return this.m_skill_1.GetCurrentTime();
        }

        //------------------------------------------------------------------------------------------------------------------
        public float GetSkill1EndTime()
        {
            return this.m_skill_1.GetEndTime();
        }
		
		#endregion GETTERS_SETTERS
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.Attack(Combat.IMediator mediator, int damage){
			//mediator.AdviceForMonsterAttack(this, damage);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveAttack(int damage){
			m_damageTake = true;
			m_currentLife -= damage;
			m_currentLife = Mathf.Clamp( m_currentLife, 0, m_maxLife );
			if(m_currentLife == 0){
				m_dead = true;
				m_heroGameObject.transform.localScale = new Vector3(1.0f, 0.1f, 1.0f);
			}
		}

		//------------------------------------------------------------------------------------------------------------------
		bool UNIT_ISoldier.IsDead(){
			return m_dead;
		}
						
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.SetMaterialEmissionDamage(){
			Renderer renderer = m_heroGameObject.GetComponent<Renderer>();
			
			if(m_damageTake){
				renderer.material.SetColor("_EmissionColor", new Color(0.3f, 0.3f, 0.3f));
			}else{
				renderer.material.SetColor("_EmissionColor", new Color(0,0,0));
			}
			//m_damageTake = false;
		}

        #region USE SKILSS
        //------------------------------------------------------------------------------------------------------------------
		public void UseRunnerSkill(){
			m_skill_1.UseSkill(true);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		public void UseImpactSliceSkill(Combat.IMediator mediator){
            m_skill_2.UseSkill(true);
            //m_skill_2
			UNIT_ISoldier soldier = this;
			soldier.DoImpactSliceSkillBehaviour(mediator);
		}
		
		//------------------------------------------------------------------------------------------------------------------
        public void UseBlindTortureSkill(Combat.IMediator mediator)
        {
            m_skill_3.UseSkill(true);
            UNIT_ISoldier soldier = this;
            soldier.DoBlindTortureSkillBehaviour(mediator);
        }
		
		//------------------------------------------------------------------------------------------------------------------
        public void UseInvencibleShieldSkill(Combat.IMediator mediator)
        {
            m_skill_4.UseSkill(true);
            UNIT_ISoldier soldier = this;
            soldier.DoInvencibleShieldSkillBehaviour(mediator);
        }
		
		//------------------------------------------------------------------------------------------------------------------
        public void UseLeapOfFaithSkill(Combat.IMediator mediator)
        {
            m_skill_5.UseSkill(true);
            UNIT_ISoldier soldier = this;
            soldier.DoLeapOfFaithSkillBehaviour(mediator);
        }

		//------------------------------------------------------------------------------------------------------------------
        public void UseShoutSkill(Combat.IMediator mediator)
        {
            m_skill_6.UseSkill(true);
            UNIT_ISoldier soldier = this;
            soldier.DoShoutSkillBehaviour(mediator);
        }

		//------------------------------------------------------------------------------------------------------------------
        public void UseHeavenSpinSKill(Combat.IMediator mediator)
        {
            m_skill_7.UseSkill(true);
            UNIT_ISoldier soldier = this;
            soldier.DoHeavenSpinSkillBehaviour(mediator);
        }
		
		#endregion
		
		#region SKILLS BEHAVIOUR			
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveRunnerSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoRunnerSkillBehaviour(Combat.IMediator mediator){
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveImpactSliceSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoImpactSliceSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroImpactSliceSkill(this);
		}
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveBlindTortureSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoBlindTortureSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroBlindTortureSkill(this);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveShoutSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoShoutSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroShoutSkill(this);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveLeapOfFaithSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoLeapOfFaithSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroLeapOfFaithSkill(this);
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.ReceiveHeavenSpinSkillBehaviour(){
			//do nothing
		}
		
		//------------------------------------------------------------------------------------------------------------------
		void UNIT_ISoldier.DoHeavenSpinSkillBehaviour(Combat.IMediator mediator){
			//mediator.DistributeMessageHeroHeavenSpinSkill(this);
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
		
		//------------------------------------------------------------------------------------------------------------------
		private void DefineInitialStateSkills(){
			this.m_skill_1 = new HeroRunnerSkill(this);
            this.m_skill_2 = new HeroImpactSliceSkill(this);
            this.m_skill_3 = new HeroInvencibleShieldSkill(this);
            this.m_skill_4 = new HeroBlindTortureSkill(this);
            this.m_skill_5 = new HeroLeapOfFaithSkill(this);
            this.m_skill_6 = new HeroShoutSkill(this);
            this.m_skill_7 = new HeroHeavenSpinSKill(this);

            m_skill_1.SetMinCooldown(3.0f);

            m_skill_1.UseSkill(false);
            m_skill_2.UseSkill(false);
            m_skill_3.UseSkill(false);
            m_skill_4.UseSkill(false);
            m_skill_5.UseSkill(false);
            m_skill_6.UseSkill(false);
            m_skill_7.UseSkill(false);
		}
						
							
								
									
										
											
													
	//
	//	//OFFENSE
	//	private float m_attackSpeed;
	//	private bool m_dealAttack;
	//	private int m_strengh;
	//	
	//	//LIFE
	//	private int m_maxLife;
	//	private int m_currentLife;
	//	private int m_lifePerSecond;
	//	private int m_lifePerHit;
	//	private int m_lifePerKill;
	//	
	//	//RESOURCE
	//	private int m_maxMana;
	//	private int m_currentMana;
	//	private int m_manaPerSecond;
	//	
	//	//ADVENTURE
	//	private float m_movementSpeed;
	//	private int m_magicFind;
	//	private int m_bonusExperience;
	//	private int m_bonusExperiencePerKill;
	//		
	//	//DEFENSE
	//	private int m_armour;
	//	private int m_physicalResistance;
	//	private int m_coldResistance;
	//	private int m_fireResistance;
	//	private int m_poisonResistance;
	//	private int m_lightingResistance;
	//	
	//	private int m_arcaneResistance;
	//
	//	//properties comming from itens
	//	private float m_criticalDamage;
	//	private float m_criticalChance;
	//	private float m_damagePerSecond;
	//	
	//	//
	//	private int m_dodgeChance;
		
		//shader colors for damage receive
		
		
		
		/*
		quais atributos vem dos itens
		
		-fire resistance
		-cold resistance
		-arcane resistance
		-physical resistance
		-all resistance
		-critical chance
		-critical damage
		-attack speed
		-life per second
		-life percent
		-mana per second
		-vitality
		-mana points
		-strengh
		-movement speed (apenas botas)
		-monster grant experience
		-healty pickup radius
		-increase X skill by Y percent damage
		-armour
		-X life after each kill
		-X max mana increase
		*/
	
	}
}
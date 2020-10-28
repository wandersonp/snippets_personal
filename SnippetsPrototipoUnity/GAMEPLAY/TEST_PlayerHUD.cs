//==================================================================================================================
//
//	File:	TEST_HUD.cs
//	Date:	21-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	test HUD and hero skill timers
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
namespace GamePlay
{
    //------------------------------------------------------------------------------------------------------------------
    public class TEST_PlayerHUD : MonoBehaviour 
    {
        //------------------------------------------------------------------------------------------------------------------
        GameSystem.SYS_GameManager m_gameManager;

        //RaycastHit m_hitPosition;

        //------------------------------------------------------------------------------------------------------------------
        void Awake()
        {
            m_gameManager = GameSystem.SYS_GameManager.Instance;
        }

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
        }

        //------------------------------------------------------------------------------------------------------------------
        void Update()
        {
            m_gameManager.m_hero.Update(m_gameManager.m_combatMediator);
            if (Time.frameCount % 10 == 0)
            {
                m_gameManager.m_enemyArmy[0].Update(m_gameManager.m_combatMediator);
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        //void FixedUpdate()
        //{
        //    //UpdateHUDInformation();
        //    TEST_WaitPlayerActions();
        //    TEST_UpdateRunnerSkillInfo();
        //    m_gameManager.m_playerHUD.Update();
        //}

        //------------------------------------------------------------------------------------------------------------------
        private void TEST_UpdateRunnerSkillInfo()
        {
            Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
            float currentTime = hero.GetSkill1CurrentTime();
            float endTime = hero.GetSkill1EndTime();
            m_gameManager.m_playerHUD.SetSkillGCurrentTimer(currentTime);
            m_gameManager.m_playerHUD.SetSkillGEndTimer(endTime);
        }

        //------------------------------------------------------------------------------------------------------------------
        private void UpdateHUDInformation() 
        {
            //update health globe
            float maxLife = m_gameManager.m_hero.GetMaxLife();
            float currentLife = m_gameManager.m_hero.GetCurrentLife();
            float percentageLife = currentLife / maxLife;
            m_gameManager.m_playerHUD.SetHealthGlobePercentage(percentageLife);

            //update mana globe
            float maxMana = m_gameManager.m_hero.GetMaxMana();
            float currentMana = m_gameManager.m_hero.GetCurrentMana();
            float percentageMana = currentMana / (float)maxMana;
            m_gameManager.m_playerHUD.SetManaGlobePercentage(percentageMana);

            //debug for health globe
            if (GameSystem.HeroControl.ButtonNumber1Down())
            {
                m_gameManager.m_hero.IncrementCurrentLife(10);
                Debug.Log("Current life " + m_gameManager.m_hero.GetCurrentLife());
                //IEnumerator coroutine = null;
                //coroutine = IncreaseLife(10);
                //StartCoroutine(coroutine);
            }

            if (GameSystem.HeroControl.ButtonNumber2Down())
            {
                m_gameManager.m_hero.DecreaseCurrentLife(10);
                Debug.Log("Current life " + m_gameManager.m_hero.GetCurrentLife());
            }

            //debug for mana globe
            if (GameSystem.HeroControl.LeftMouseClickDown())
            {
                m_gameManager.m_hero.IncrementCurrentMana(10);
                Debug.Log("Current mana " + m_gameManager.m_hero.GetCurrentMana());
            }

            if (GameSystem.HeroControl.RightMouseClickDown())
            {
                m_gameManager.m_hero.DecreaseCurrentMana(10);
                Debug.Log("Current mana " + m_gameManager.m_hero.GetCurrentMana());
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        private void TEST_WaitPlayerActions(){
            //if (GameSystem.HeroControl.RightMouseClickDown()){
            //    Combat.UNIT_Hero hero = (Combat.UNIT_Hero)m_gameManager.m_hero;
            //    hero.UseRunnerSkill();
            //    Debug.Log("Use Runner Skill");
            //}

            //move player to destination
            //if (GameSystem.HeroControl.LeftMouseClick())
            //{
            //    if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out m_hitPosition, 100))
            //    {
            //        //if (hitPosition.collider.gameObject.tag == "NavigationMesh")
            //        {
            //            m_gameManager.m_hero.MoveTo(m_hitPosition.point);
            //        }
            //    }
            //}

            ////keep walking until character reach hitPosition
            //Vector3 position = this.m_gameManager.m_hero.GetPosition();
            //if (Vector3.Distance(position, m_hitPosition.point) <= 0.2f)
            //{
            //    m_gameManager.m_hero.SetState((int)Combat.HeroStates.HERO_IDLE);
            //}
            //else
            //{
            //    m_gameManager.m_hero.SetState((int)Combat.HeroStates.HERO_RUN);
            //}
        }

        //------------------------------------------------------------------------------------------------------------------
        //IEnumerator IncreaseLife(int value)
        //{
        //    for (int i = 0; i < value; i++)
        //    {
        //        m_gameManager.m_hero.IncrementCurrentLife(1);
        //        yield return null;  
        //    }
        //}
    }


}

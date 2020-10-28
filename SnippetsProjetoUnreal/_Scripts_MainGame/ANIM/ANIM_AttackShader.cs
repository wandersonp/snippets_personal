//==================================================================================================================
//
//	File:	AnimAttackShader.cs
//	Date:	06-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	Animation Color for Enemy and Hero Attacks
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Anim
{
    public class ANIM_AttackShader : MonoBehaviour
    {
        public GameObject m_gameObject;
        private MeshRenderer m_meshRenderer;
        private Color m_attackColor;
        private bool m_mouseOver;

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
            this.m_mouseOver = false;
            this.m_attackColor = new Color(1.0f, 1.0f, 1.0f);
            this.m_meshRenderer = m_gameObject.GetComponent<MeshRenderer>();
            //this.m_gameObject.tag = "GlowOutline";
            
            //Color color = new Color(Random.value, Random.value, Random.value);
            //this.m_meshRenderer.material.SetColor("_BaseColor", color);
        }

        //------------------------------------------------------------------------------------------------------------------
        void FixedUpdate()
        {
            this.m_mouseOver = false;
            if (Input.GetMouseButtonDown(0))
            {
                //this.m_mouseOver = true;
                StartCoroutine("AnimateAttackColor");
            }
                
            //Ray ray;
            //RaycastHit hit; 

            //ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            //if (Physics.Raycast(ray, out hit))
            //{

            //}
        }

        //------------------------------------------------------------------------------------------------------------------
        void OnMouseOver()
        {
        	//change gameTag
            this.m_gameObject.tag = "GlowOutline";
        	
            if (this.m_mouseOver)
            {
                StartCoroutine("AnimateAttackColor");
            }
            //print(gameObject.name);
        }
        
		//------------------------------------------------------------------------------------------------------------------
		void OnMouseExit()
		{
			//change gameTag
			this.m_gameObject.tag = "Untagged";
		}

        //------------------------------------------------------------------------------------------------------------------
        IEnumerator AnimateAttackColor()
        {
            int maxFrames = 10;
            for (int i = maxFrames; i >= 0; i--)
            {
                float tone = (float)i / maxFrames;
                this.m_attackColor = new Color(tone, tone, tone);
                this.m_meshRenderer.material.SetColor("_AttackColor", this.m_attackColor);
                yield return null;
            }
            yield return null;
        }
    }
}

//==================================================================================================================
//
//	File:	AnimShaderOpacity.cs
//	Date:	01-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Anim
{
    //==================================================================================================================
    public class ANIM_ShaderOpacity : MonoBehaviour
    {
        public GameObject m_asset;
        private Renderer m_renderer;
        private Color m_color;
        private bool m_inside = false;

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
            this.m_color = new Color(1.0f, 0, 0, 1.0f);
        }

        //------------------------------------------------------------------------------------------------------------------
        void Update()
        {
            this.m_renderer = m_asset.GetComponent<Renderer>();
            this.m_renderer.material.color = this.m_color;
        }

        //------------------------------------------------------------------------------------------------------------------
        void OnTriggerEnter(Collider collider)
        {
            if (collider.GetComponent<Collider>().tag == "Player")
            {
                StartCoroutine("AnimateShaderFadeOut");
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        void OnTriggerExit(Collider collider)
        {
            if (collider.GetComponent<Collider>().tag == "Player")
            {
                StartCoroutine("AnimateShaderFadeIn");
            }
        }

        //------------------------------------------------------------------------------------------------------------------
        IEnumerator AnimateShaderFadeOut()
        {
            for (int i = 50; i >= 0; i--)
            {
                this.m_color = new Color(1.0f, 0, 0, Mathf.Clamp((float)i / 50, 0.2f, 1.0f));
                yield return null;
            }
            yield return null;
        }

        //------------------------------------------------------------------------------------------------------------------
        IEnumerator AnimateShaderFadeIn()
        {
            for (int i = 0; i <= 50; i++)
            {
                this.m_color = new Color(1.0f, 0, 0, Mathf.Clamp((float)i / 50, 0.2f, 1.0f));
                yield return null;
            }
            yield return null;
        }
    }
}
//==================================================================================================================
//
//	File:	AnimAtmosphereSmokePlane.cs
//	Date:	06-05-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	Animation Opacity for Smoke Planes
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//==================================================================================================================
namespace Anim
{
    //==================================================================================================================
    public class ANIM_AtmosphereSmokePlane : MonoBehaviour
    {
        public GameObject m_plane;
        private MeshRenderer m_meshRenderer;
        private Material m_material;
        private float m_animSeed;
        private float m_speed;

        //------------------------------------------------------------------------------------------------------------------
        void Start()
        {
            this.m_speed = Random.Range(0.01f, 0.02f);

            this.m_meshRenderer = m_plane.GetComponent<MeshRenderer>();
            this.m_material = new Material(this.m_meshRenderer.material);
            this.m_meshRenderer.material = this.m_material;
        }

        //------------------------------------------------------------------------------------------------------------------
        void FixedUpdate()
        {
            this.m_animSeed = (float)(this.m_plane.GetInstanceID() + Time.frameCount);
            this.m_animSeed = Mathf.Clamp(Mathf.Sin(this.m_animSeed * this.m_speed), 0, 1.0f);
            this.m_material.SetFloat("_IntensitySmoke", this.m_animSeed);
        }
    }
}

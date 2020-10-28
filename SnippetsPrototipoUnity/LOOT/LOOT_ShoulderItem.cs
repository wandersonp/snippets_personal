//==================================================================================================================
//
//	File:	LOOT_ShoulderItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for shoulder itens
//
//==================================================================================================================

//#define SHOULDER

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Shoulder Item Class
#if (SHOULDER)
    //==================================================================================================================
    public class ShoulderItem : ILoot
    { 
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public ShoulderItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //SHOULDER
    #endregion
}

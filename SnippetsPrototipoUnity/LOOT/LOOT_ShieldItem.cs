//==================================================================================================================
//
//	File:	LOOT_ShieldItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for shield itens
//
//==================================================================================================================

//#define SHIELD

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Shield Item Class
#if (SHIELD)
    //==================================================================================================================
    public class ShieldItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public ShieldItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //SHIELD
    #endregion
}

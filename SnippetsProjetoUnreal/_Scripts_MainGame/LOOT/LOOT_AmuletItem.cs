//==================================================================================================================
//
//	File:	LOOT_AmuletItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for amulet itens
//
//==================================================================================================================

//#define AMULET

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Amulet Item Class
#if (AMULET)
    //==================================================================================================================
    public class AmuletItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public AmuletItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //AMULET
    #endregion
}

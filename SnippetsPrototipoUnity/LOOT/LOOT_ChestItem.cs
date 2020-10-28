//==================================================================================================================
//
//	File:	LOOT_ChestItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for chest itens
//
//==================================================================================================================

//#define CHEST

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Chest Item Class
#if (CHEST)
    //==================================================================================================================
    public class ChestItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public ChestItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //CHEST
    #endregion
}

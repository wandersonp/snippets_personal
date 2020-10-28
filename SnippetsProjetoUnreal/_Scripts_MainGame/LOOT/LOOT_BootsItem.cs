//==================================================================================================================
//
//	File:	LOOT_BootsItem.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot for boots itens
//
//==================================================================================================================

//#define BOOTS

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    #region Boots Item Class
#if (BOOTS)
    //==================================================================================================================
    public class BootsItem : ILoot
    {
        private SortedList<EnumLootStat, float> m_stats;
        private string m_name;

        //------------------------------------------------------------------------------------------------------------------
        public BootsItem()
        {
            this.m_stats = new SortedList<EnumLootStat, float>();
        }
    }
#endif  //BOOTS
    #endregion
}

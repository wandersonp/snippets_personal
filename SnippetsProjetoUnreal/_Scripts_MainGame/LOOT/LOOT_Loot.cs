//==================================================================================================================
//
//	File:	SYS_Loot.cs
//	Date:	21-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot class
//
//==================================================================================================================

using UnityEngine;
using System.Collections.Generic;

namespace Loot
{
    //==================================================================================================================
    public class SLootDescription
    {
        public SortedList<EnumLootStat, float> m_primaryStats;
        public SortedList<EnumLootStat, float> m_secondaryStats;
        public SortedList<EnumLootStat, float> m_bonusStats;
        public string m_name;
        public string m_typeName;
        public EnumLootType m_type;
        public int m_levelRequirement;

        public SLootDescription()
        {
            this.m_primaryStats = new SortedList<EnumLootStat, float>();
            this.m_secondaryStats = new SortedList<EnumLootStat, float>();
            this.m_bonusStats = new SortedList<EnumLootStat, float>();
        }
    }

    //==================================================================================================================
    public enum EnumLootType
    {
        LOOT_BATTLEAXE,
        LOOT_SWORD,
        LOOT_WARHAMMER,
    }

    //==================================================================================================================
    public abstract class ILoot
    {
        public abstract void AddPrimaryStat(EnumLootStat statType, float statValue);
        public abstract void AddSecondaryStat(EnumLootStat statType, float statValue);
        public abstract void AddBonusStat(EnumLootStat statType, float statValue);

        public abstract void SetName(string name);
        public abstract string GetName();

        public abstract void SetLevelRequirement(int level);
        public abstract int GetLevelRequirement();

        public abstract void SetItemTypeName(string type);
        public abstract string GetItemTypeName();

        public abstract int GetPrimaryStatCount();
        public abstract int GetSecondaryStatCount();
        public abstract int GetBonusStatCount();
        public abstract void GetStatInfo(int index, out string name, out float value);
        public abstract string GetPrimaryStatNiceNameDescription(int index);
        public abstract string GetSecondaryStatNiceNameDescription(int index);
        public abstract string GetBonusStatNiceNameDescription(int index);
        public abstract string GetStringByEnumStat(EnumLootStat statType);
        public abstract void ShowStats();
    }
}

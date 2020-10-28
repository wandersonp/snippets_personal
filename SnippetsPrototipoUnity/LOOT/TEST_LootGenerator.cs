//==================================================================================================================
//
//	File:	LootGenerator.cs
//	Date:	22-04-2016
//	Author:	wandersonp@gmail.com
//
//	Description:	loot generator on game
//
//==================================================================================================================

using UnityEngine;
//using UnityEditor;
using System.Collections;

//==================================================================================================================
static class UsefulShortcuts
{
    //[MenuItem("Custom/Clear Console %#c")] // CMD + SHIFT + C
    public static void ClearConsole()
    {
        var logEntries = System.Type.GetType("UnityEditorInternal.LogEntries,UnityEditor.dll");
        var clearMethod = logEntries.GetMethod("Clear", System.Reflection.BindingFlags.Static | System.Reflection.BindingFlags.Public);
        clearMethod.Invoke(null, null);
    }
}

//==================================================================================================================
public class TEST_LootGenerator : MonoBehaviour
{
    private Texture m_rectangleMiddle;
    private Texture m_rectangleTop;
    private Texture m_rectangleBottom;
    private Texture m_dotStat;
    private Loot.ILoot m_weapon;
    private bool m_showLootWindow;

    //------------------------------------------------------------------------------------------------------------------
    void Start()
    {
		Debug.developerConsoleVisible = true;

        this.m_weapon = Loot.LootFactory.CreateBattleAxe(1);

        string assetPath = "UI/Loot/window_background";
        this.m_rectangleMiddle = (Texture)Resources.Load(assetPath, typeof(Texture));
        this.m_showLootWindow = false;

        assetPath = "UI/Loot/top_window_background";
        this.m_rectangleTop = (Texture)Resources.Load(assetPath, typeof(Texture));

        assetPath = "UI/Loot/bottom_window_background";
        this.m_rectangleBottom = (Texture)Resources.Load(assetPath, typeof(Texture));
    
        assetPath = "UI/Loot/dot_stat";
        this.m_dotStat = (Texture)Resources.Load(assetPath, typeof(Texture));
    }

    //------------------------------------------------------------------------------------------------------------------
    void FixedUpdate()
    {
        //UsefulShortcuts.ClearConsole();

        this.m_showLootWindow = RayCastLoot();
        if (GameSystem.HeroControl.ButtonNumber1Down())
        {
            this.m_weapon = Loot.LootFactory.CreateBattleAxe(1);
        }

        if (GameSystem.HeroControl.ButtonNumber2Down())
        {
            this.m_weapon = Loot.LootFactory.CreateSword(1);
        }

        if (GameSystem.HeroControl.ButtonNumber3Down())
        {
            this.m_weapon = Loot.LootFactory.CreateWarHammer(1);
        }
    }

    //------------------------------------------------------------------------------------------------------------------
    void OnGUI()
    {
        if (this.m_showLootWindow)
        {
            DrawWindowLootDescription();
        }
    }

    //------------------------------------------------------------------------------------------------------------------
    private void DrawWindowLootDescription()
    {
        GUIStyle style = new GUIStyle();
        style.fontSize = 20;
        style.alignment = TextAnchor.UpperCenter;

        //background window
        GUI.color = new Color(1.0f, 1.0f, 1.0f, 0.8f);
        float sizeY = 30;   //type name
        sizeY += this.m_weapon.GetPrimaryStatCount() * 25 + 40;
        sizeY += this.m_weapon.GetSecondaryStatCount() * 25 + 40;
        sizeY += this.m_weapon.GetBonusStatCount() * 25 + 40;
        sizeY += 30;    //level requirement
        Vector2 mousePosition = Input.mousePosition;
        
        //top border
        Rect topRectanglePosition = new Rect(mousePosition.x, Screen.height - mousePosition.y - 13, 426, 13);
        GUI.DrawTexture(topRectanglePosition, this.m_rectangleTop);

        //middle area
        Rect titlePosition = new Rect(mousePosition.x, Screen.height - mousePosition.y, 426, sizeY);
        GUI.DrawTexture(titlePosition, this.m_rectangleMiddle);

        //bottom border
        Rect bottomRectanglePosition = new Rect(mousePosition.x, Screen.height - mousePosition.y + sizeY, 426, 11);
        GUI.DrawTexture(bottomRectanglePosition, this.m_rectangleBottom);

        //draw item name
        style.normal.textColor = Color.yellow;
        GUI.color = new Color(1.0f, 1.0f, 1.0f, 1.0f);
        GUI.Label(titlePosition, this.m_weapon.GetName(), style);

        //draw item type name
        Rect statPosition = new Rect(mousePosition.x + 25, Screen.height - mousePosition.y + 30, 350, 20);
        style.normal.textColor = Color.gray;
        style.fontSize = 15;
        style.alignment = TextAnchor.UpperRight;
        GUI.color = new Color(1.0f, 1.0f, 1.0f, 1.0f);
        GUI.Label(statPosition, this.m_weapon.GetItemTypeName(), style);
        
        //draw primary word
        style.normal.textColor = new Color(1.0f,1.0f,1.0f,1.0f);
        style.fontSize = 15;
        style.alignment = TextAnchor.UpperLeft;
        statPosition.y += 30.0f;
        GUI.Label(statPosition, "Primary", style);

        //draw primary stats
        style.normal.textColor = new Color(98.0f / 255, 98.0f / 255, 238.0f / 255, 1.0f);
        statPosition.x += 25.0f;
        for (int i = 0; i < this.m_weapon.GetPrimaryStatCount(); i++)
        {
            statPosition.y += 25.0f;

            Rect positionDot = new Rect(statPosition.x-25.0f, statPosition.y+5, 10, 10);
            GUI.DrawTexture(positionDot, this.m_dotStat);

            string info = this.m_weapon.GetPrimaryStatNiceNameDescription(i);
            GUI.Label(statPosition, info, style);
        }

        //draw secondary stats
        if (this.m_weapon.GetSecondaryStatCount() > 0)
        {
            //Debug.Log(this.m_weapon.GetSecondaryStatCount());
            style.normal.textColor = new Color(1.0f, 1.0f, 1.0f, 1.0f);
            style.fontSize = 15;
            style.alignment = TextAnchor.UpperLeft;
            statPosition.x -= 25.0f;
            statPosition.y += 30.0f;
            GUI.Label(statPosition, "Secondary", style);

            statPosition.x += 25.0f;
            style.normal.textColor = new Color(98.0f / 255, 98.0f / 255, 238.0f / 255, 1.0f);
            for (int i = 0; i < this.m_weapon.GetSecondaryStatCount(); i++)
            {
                statPosition.y += 25.0f;

                Rect positionDot = new Rect(statPosition.x - 25.0f, statPosition.y + 5, 10, 10);
                GUI.DrawTexture(positionDot, this.m_dotStat);

                string info = this.m_weapon.GetSecondaryStatNiceNameDescription(i);
                GUI.Label(statPosition, info, style);
            }
        }

        //draw bonus stats
        if (this.m_weapon.GetBonusStatCount() > 0)
        {
            style.normal.textColor = new Color(1.0f, 1.0f, 1.0f, 1.0f);
            style.fontSize = 15;
            style.alignment = TextAnchor.UpperLeft;
            statPosition.x -= 25.0f;
            statPosition.y += 30.0f;
            GUI.Label(statPosition, "Bonus", style);

            statPosition.x += 25.0f;
            style.normal.textColor = new Color(98.0f / 255, 98.0f / 255, 238.0f / 255, 1.0f);
            for (int i = 0; i < this.m_weapon.GetBonusStatCount(); i++)
            {
                statPosition.y += 25.0f;

                Rect positionDot = new Rect(statPosition.x - 25.0f, statPosition.y + 5, 10, 10);
                GUI.DrawTexture(positionDot, this.m_dotStat);

                string info = this.m_weapon.GetBonusStatNiceNameDescription(i);
                GUI.Label(statPosition, info, style);
            }
        }

        //draw level requirement
        int level = this.m_weapon.GetLevelRequirement();
        style.fontSize = 15;
        style.alignment = TextAnchor.UpperRight;
        style.normal.textColor = new Color(1.0f, 1.0f, 1.0f, 1.0f);
        statPosition.y += 40.0f;
        GUI.Label(statPosition, "Require Level: " + level, style);
    }

    //------------------------------------------------------------------------------------------------------------------
    private bool RayCastLoot()
    {
        Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
        RaycastHit hit;
 
        if (Physics.Raycast(ray,out hit)) {
            if(hit.collider.gameObject.tag== "Loot")
            {
                return true;
            }
        }
        return false;
    }
}


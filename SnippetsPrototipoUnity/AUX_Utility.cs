//==================================================================================================================
//
//	File:	AUX_Utility.cs
//	Date:	14-04-2016
//	Author:	wandersonp@gmail.com
//
//==================================================================================================================

using UnityEngine;
using System.Collections;

//------------------------------------------------------------------------------------------------------------------
public class AUX_Utility
{

    //------------------------------------------------------------------------------------------------------------------
    public static int IntRandomRange(int min, int max)
    {
        int value = Random.Range(min, max);
        return value;
    }

    //------------------------------------------------------------------------------------------------------------------
    public static float FloatRandomRange(float min, float max)
    {
        float value = Random.Range(min, max);
        return value;
    }

    //------------------------------------------------------------------------------------------------------------------
    public static float FloatRoundRandomRange(float min, float max)
    {
        float value = Mathf.Round(Random.Range(min, max));
        return value;
    }

    //------------------------------------------------------------------------------------------------------------------
    public static void RandomSeedDateTime()
    {
        Random.seed = System.DateTime.Now.Millisecond;
    }
}

using UnityEngine;
using System.Collections;

public class SYS_SplashScreen : MonoBehaviour {

    private string m_fileMP4SplashScreen = "SplashScreen_v001.mp4";

	void Start () {
        StartCoroutine( PlayStreamingVideo(this.m_fileMP4SplashScreen) ); 
	}

    private IEnumerator PlayStreamingVideo(string url)
    {
        Handheld.PlayFullScreenMovie(url, Color.black, FullScreenMovieControlMode.Full, FullScreenMovieScalingMode.AspectFill);
        yield return new WaitForEndOfFrame();
        //yield return new WaitForEndOfFrame();
        Debug.Log("Video playback completed.");
    }
}

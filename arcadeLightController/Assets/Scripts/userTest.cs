using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class userTest : MonoBehaviour
{
    public GameObject alcObject;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void turnLightOn()
    {
        arcadeLightController alc = alcObject.GetComponent<arcadeLightController>();
        alc.LEDSon();
    }
    public void turnLightOff()
    {
        arcadeLightController alc = alcObject.GetComponent<arcadeLightController>();
        alc.LEDSoff();
    }
}
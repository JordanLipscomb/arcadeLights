using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System.Threading;
using UnityEngine;

public class arcadeLightController : MonoBehaviour
{
    public static SerialPort sp = new SerialPort("COM3", 9600);

    // Start is called before the first frame update
    void Start()
    {
        sp.Open();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void LEDSoff()
    {
        sp.Write("of");
        Debug.Log("off");
    }

    public void LEDSon()
    {
        sp.Write("on");
        Debug.Log("on");
    }

    public void LEDSred()
    {
        sp.Write("rd");
        Debug.Log("red");
    }

    public void LEDSviolet()
    {
        sp.Write("vo");
        Debug.Log("violet");
    }

    public void LEDSblue()
    {
        sp.Write("bu");
        Debug.Log("blue");
    }

    public void LEDSgreen()
    {
        sp.Write("gr");
        Debug.Log("green");
    }

    public void LEDSyellow()
    {
        sp.Write("yl");
        Debug.Log("yellow");
    }

    public void LEDSorange()
    {
        sp.Write("og");
        Debug.Log("orange");
    }
}

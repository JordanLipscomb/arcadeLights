using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System.Threading;
using UnityEngine;

public class arcadeLightController : MonoBehaviour
{
    public static SerialPort sp = new SerialPort("COM6", 9600);

    // Start is called before the first frame update
    void Start()
    {
        sp.Open();
    }

    // Update is called once per frame
    void Update()
    {
        
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

    public void LEDSrainbow()
    {
        sp.Write("rb");
        Debug.Log("rainbow");
    }

    public void LEDSoff()
    {
        sp.Write("of");
        Debug.Log("off");
    }
}

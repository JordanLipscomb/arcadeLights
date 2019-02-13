using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System.Threading;
using UnityEngine;

public class lightController : MonoBehaviour
{
    public static SerialPort sp = new SerialPort("COM5", 9600);

    // Start is called before the first frame update
    void Start()
    {
        sp.Open();
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void LEDon()
    {
        sp.Write("o");
        Debug.Log("on");
    }

    public void LEDoff()
    {
        sp.Write("f");
        Debug.Log("off");
    }
}

# Home-Automation-with-Node-Red
Node Red is a flow based tool lets ypu easily build IOT and homeautomation control system using a web browser.
It is written in Nodejs and can run on Windows and Linux operating System.It can run on the NodeMCU/RaspberryPi making it an ideal system for home automation project.

## Features of Node Red
1. Node-RED provides a browser-based flow editor that makes it easy to wire together flows using the wide range of nodes in the palette.
2. The light-weight runtime is built on Node.js, taking full advantage of its event-driven, non-blocking model.
3. A built-in library allows you to save useful functions, templates or flows for re-use.

## How to run Node-Red and create dashboard
###Installing Node-RED on Raspberry Pi
It is pre install node-red in Latest RaspberryPi.Go to: Menu->Programming->Node-RED.
### Running Node-RED
 You can run it from the Menu or by the following command in terminal:
 ```bash
node-red -start
``` 


open the web browser and enter the address you may find as shown in following image after running Node-RED:


![alt text](https://github.com/Anmol17Agarwal/Home-Automation-with-Node-Red/blob/main/terminalScreen.png)


Open the web browser and enter the address of your Raspberry Pi, in my case it is: 192.168.1.12:1880

If everything is correct then you will find following result:

![alt text](https://github.com/Anmol17Agarwal/Home-Automation-with-Node-Red/blob/main/Node-red.png)

On the left side,there are multiple node,for creating this project i gonna use these node,just drag and drop and connect connection between them.

### Installing some extra nodes for UI
Most easiest way to add UI.Just go to left side,and click hamburger icon>manage palette>install> and search for node-red dashboard or node-red-contrib-nora andmany more and then hit install button.

Now create the dashboard for home-automtion.





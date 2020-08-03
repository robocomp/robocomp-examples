# sampleCode
This component is a sample code to edit or modify the DSR using python3.\
For video tutorial go to this [link..](https://youtu.be/-8Rf-b-1mYc)

## How to use this AGMAgent component


```bash
cd ~/robocomp/components/
git clone https://github.com/robocomp/robocomp-examples.git
cd robocomp-examples/getting-started/python/AGM_Agent/
mkdir build
cd build
cmake ..
make
```

sampleCode.cdsl
```
Component sampleCode
{
    Communications
    {

    };
    language Python;
    options agmagent;
};
```
`make sure the options agmagent will be there.`




## Configuration parameters
As any other component, *sampleCode* needs a configuration file to start. In
```
etc/config
```
you can find an example of a configuration file. We can find there the following lines:
```
# Endpoints for implements interfaces
AGMCommonBehavior.Endpoints=tcp -p 45678

# Endpoints for subscriptions interfaces
AGMExecutiveTopicTopic.Endpoints=tcp -p 3127

# Proxies for required interfaces
AGMExecutiveProxy = agmexecutive:tcp -h localhost -p 10198

# This property is used by the clients to connect to IceStorm.
TopicManager.Proxy=IceStorm/TopicManager:default -p 9999

Ice.Warn.Connections=0
Ice.Trace.Network=0
Ice.Trace.Protocol=0
```

### Starting the component
Before starting the component make sure AGMExecutive & rcnode is running.

To know how to start these go to this [link.. starting AGM](startingAGM.md)

You must have AGM installed in your machine.\
Go to this link to install AGM [AGM installation](https://github.com/ljmanso/AGM) clone and install this repo in your home directory
```buildoutcfg
cd ~
git clone https://github.com/ljmanso/AGM
cd AGM
sh compile.sh
```



#### running the component
```
cd ~/robocomp/components/robocomp-examples/getting-started/python/AGM_Agent/
python3 src/sampleCode.py etc/config
```
if you get error as\
`The executive is probably not running, waiting for first AGM model publication...`
\
then make sure AGMExecutive is running.


## About the sampleCode
make sure $ROBOCOMP environment variable is set.
* the function ***self.addNode()*** will add a node in the DSR.
* the function ***self.addLink()*** will add a link between two node in the DSR.
* After making change to the local Graph, the function
***self.updatingDSR()*** will update the DSR with the local Graph.
* There are many more functions that you can use, to view all the functions go to
`/usr/local/share/agm/AGGL.py`\
you can see these function inside the **AGMGraph class**.

***
```
        self.addLink('1','3200')
        self.addNode('5200','object2')
        self.addLink('3','5200')
        self.updatingDSR()
```
* In this sample code we have added a link between a object with id(3200) and
robot with id(1)
* adding a node with id(5200) with name 'object2'
* adding another link between room with id(3) and newly created object with id(5200)
* after creating all this we update all these changes to actual DSR using the updaingDSR function.

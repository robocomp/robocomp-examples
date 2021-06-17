# Communication between two components

## CDSL files
We will need to create two components. You should know by now, how to create the components - if not, please refer to previous tutorials.\
For this example we will need a server and a client. Our server will be called Speaker component and our client will be called Caller. Both have to import Speech interface, the difference between them is that Speaker implements Speech and Caller requires it.\
Speaker.cdsl
```
import "Speech.idsl";

Component Speaker
{
    Communications
    {
        implements Speech;
    };
    language python;
};
```
Caller.cdsl
```
import "Speech.idsl";

Component Caller
{
    Communications
    {
        requires Speech;
    };
    language python;
};
```
## Specificworker changes
Now You need to generate the code using robocompdsl same as in the tutorial where You should learn how to create components. Now we need to navigate to src folder of Speaker's component and open up specificworker.py. You can use any text editor to do so.

We need to edit the function that is created thanks to implementing the Speech interface. By doing it we implement the function that can be used later by the Caller.
```
def Speech_say(self, text, owerwrite):
        ret = bool()
        print(text)
        return ret
```
Then we are supposed to do similar thing to the Caller, but now we will edit the compute method to something like this:
```
def compute(self):
        print('SpecificWorker.compute...')
        self.speech_proxy.say('I can speak!', 0)
        return True
```
## Using the components
This is it. Everything is prepared now we need to run the simulation and open up two tabs for the consoles to watch how the components function. After using the commands for each component in each window:\
Speaker
```bash
cd ~/robocomp/robocomp-examples/getting-started/python/TestingCommunication
src/Speaker.py etc/config
```
Caller
```bash
cd ~/robocomp/robocomp-examples/getting-started/python/TestingCommunication
src/Caller.py etc/config
```

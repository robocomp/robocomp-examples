# This directory contains the implementation of RGB component.

This folder contains only those files which need to be changed to implement a RGB component i.e. the `CDSL` file, the specificworker.py file in src/ directory, and the config file in etc/ directory.

- If you open the `CSDL` file, you can see `implements` keyword is used, which specifies that the component is implemented here.



- Generate a RGB template file.<br>
`robocompdsl ImplementRGB.cdsl`

Change the content of the dummy file
```CDSL
import "RGB.idsl";

Component ImplementRGB
{
	Communications
	{
		implements RGB;
	};
	language Python;
};
```

- Generate a Component using the CDSL file.<br>
`robocompdsl ImplementRGB.cdsl .`

- Verify that you have installed `matplotlib` and `numpy`<br>
`pip install matplotlib`<br>
`pip install numpy`

- Open the `RGB.idsl` file in `/opt/robocomp/interfaces/IDSLs` directory. As you can see, there is only one function i.e. `getImage()`. This function outputs a structure called `Image` and the structure itself has 3 components which stores sequence of Red, Green, and Blue pixels.

- Remember the Ice middleware only supports data type which are python native data structure, hence you cannot transmit data type such as numpy `arrays` or pandas `data frame`. So we will convert the numpy Image matrix to a list.

- Finally change the `RGB.Endpoints` address(etc/config) to any 5 digit number that is not being currently used by any other component(I have used 10001).

- Now we are done with the implementation part of the component.

**NOTE :** You can change the path i.e. `self.path` inside `setParams()` function to any 200x200 image.

Now Follow the steps mentioned in `requires directory`
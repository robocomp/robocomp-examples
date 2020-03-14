# This directory contains the implementation of RGB component.

This folder contains only those files which need to be changed to implement a CameraSimple component i.e. the `CDSL` file, the specificworker.py file in src/ directory, and the config file in etc/ directory.

- If you open the `CSDL` file, you can see `implements` keyword is used, which specifies that the component is implemented here.



- Generate a CameraSimple template file.<br>
`robocompdsl ImplementCameraSimple.cdsl`

Change the content of the dummy file
```CDSL
import "CameraSimple.idsl";

Component ImplementCameraSimple
{
	Communications
	{
		implements CameraSimple;
	};
	language Python;
};
```

- Generate a Component using the CDSL file.<br>
`robocompdsl ImplementCameraSimple.cdsl .`

- Verify that you have installed `cv2` and `numpy`<br>
`pip install cv2`<br>
`pip install numpy`

- Open the `CameraSimple.idsl` file in `/opt/robocomp/interfaces/IDSLs` directory. As you can see, there is only one function i.e. `getImage()`. This function outputs a structure called `TImage` and the structure itself has 4 components which stores  of height, width, depth, and Image itself.

- Remember the Ice middleware only supports data type which are python native data structure, hence you when you transmit data type such as numpy `arrays` or pandas `data frame`. They will be converted to string.

- Finally change the `CameraSimple.Endpoints` address(etc/config) to any 5 digit number that is not being currently used by any other component(I have used 10001).

- Now we are done with the implementation part of the component.

**NOTE :** You can change the path i.e. `self.path` inside `setParams()` function to any  image.

Now Follow the steps mentioned in `requires directory`
# This directory contains the implementation of RGB component.

After implementing the RGB component. We can create another component that will use the information transmitted by the RGB component.

This folder contains only those files which need to be changed to implement a RGB component i.e. the `CDSL` file, the specificworker.py file in src/ directory, and the config file in etc/ directory.

- If you open the `CSDL` file, you can see `requires` keyword is used, which specifies that the interface is referenced here.



- Generate a RequireRGB template file.<br>
`robocompdsl RequireCameraSimple.cdsl`

Change the content of the dummy file to
```CDSL
import "CameraSimple.idsl";

Component RequireCameraSimple
{
	Communications
	{
		requires CameraSimple;
	};
	language Python;
};
```

- Generate a Component using the CDSL file.<br>
`robocompdsl RequireCameraSimple.cdsl .`

- Verify that you have installed `cv2` and `numpy`<br>

- Now, we can receive the information send by the `ImplementCameraSimple` component via proxy `camerasimple_proxy`.

- Finally change the `CameraSimpleProxy` address(etc/config) to the same as that of `CameraSimple.Endpoints`(I used 10001).

- Now we can send the Image data from `ImplementCameraSimple` and receive it in `RequireCameraSimple` component.

- Finally, Run the `ImplementCameraSimple` component using<br>
`python2 src/ImplementCameraSimple.py etc/config`<br>
and then run the `RequireCameraSimple` component using<br>
`python2 src/RequireCameraSimple.py etc/config`
- If every step was correctly followed, You will see Images from your webcam.
# This directory contains the implementation of RGB component.

After implementing the RGB component. We can create another component that will use the information transmitted by the RGB component.

This folder contains only those files which need to be changed to implement a RGB component i.e. the `CDSL` file, the specificworker.py file in src/ directory, and the config file in etc/ directory.

- If you open the `CSDL` file, you can see `requires` keyword is used, which specifies that the component is required here.



- Generate a RequireRGB template file.<br>
`robocompdsl RequireRGB.cdsl`

Change the content of the dummy file to
```CDSL
import "RGB.idsl";

Component RequireRGB
{
	Communications
	{
		requires RGB;
	};
	language Python;
};
```

- Generate a Component using the CDSL file.<br>
`robocompdsl RequireRGB.cdsl .`

- Verify that you have installed `matplotlib` and `numpy`<br>

- Now, we can receive the information send by the `ImplementRGB` component via proxy `rgb_proxy`.

- Finally change the `RGBProxy` address(etc/config) to the same as that of `RGB.Endpoints`(I used 10001).

- Now we can send the Image data from `ImplementRGB` and receive it in `RequireRGB` component.

- Finally, Run the `ImplementRGB` component using<br>
`python2 src/ImplementRGB.py etc/config`<br>
and then run the `RequireRGB` component using<br>
`python2 src/RequireRGB.py etc/config`
- If every step was correctly followed, You will see an Image of a cat(200x200 pixels)
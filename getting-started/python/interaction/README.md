# README

- Ice is an object-oriented middleware platform. It creates servers(checkout etc/config) and proxies(these are just like pointers) that is used by interfaces to communicate with each other.
- As you already know, for data to flow from one component to the other. We need at least 2 components i.e. One for transmitting the data and one for receiving the data.
- We can use `implement` or `publish` keyword in component to specify that the component is actually implementing the interface and the interface will transmit the data.
- We can use `require` or `subscribe` keywords in component to specify that the component requires or need the data from other interfaces.

We will implement a CameraSimple component that will show you how you can share an Image data(Information) between two components.

The implements folder contains implementation of the component. And the requires folder contains the a component that requires the information send by CameraSimple component via proxy.
# README

## The Internet Communications Engine(ICE)
- Ice is an object-oriented middleware platform. Which helps programs written in different language communicate by creating servers and clients. To know more about ICE you can read the ICE [documentation](https://doc.zeroc.com/ice/3.7/ice-overview/ice-architecture). 

## Servers & Clients
- An application will act as server if it transmits some kind of information.
- An application which request's server for information is called client.
- Applications are not necessarily servers or clients but generally mix of those two i.e. peers.
- You should read more about ICE servers, Clients and their architecture, You can find the documentation [here](https://doc.zeroc.com/technical-articles/general-topics/chat-demo/concepts#Concepts-ClientsandServers). 

## Objects & Proxies

- An Ice object is an entity remote address space that can respond to client requests. The objects are created by Server.

- For a client to be able to contact an Ice object, the client must hold a proxy for the Ice object. To know more about objects and Proxies read the ICE [documentation](https://doc.zeroc.com/ice/3.7/ice-overview/ice-architecture/terminology#Terminology-IceObjects)

- You can find the object address in the file [`implements/etc/config`](implements/etc/config).
- You can find the proxy address in the file [`requires/etc/config`](requires/etc/config).

## Example of how the robocomp components uses ICE to share data

- In this tutorial, We are going to learn how the different components in robocomp, share data using the Ice's peer-to-peer systems. 
- For the data to be shared between components, we need to have at least 2 components i.e. One component will act as a server and the other will be the client.

- We can use `implement` or `publish` keyword in the `Component Specific Definition Language(.cdsl)` to specify that the component will be implemented and generally this component will generate some kind of data that might be required by another component of robocomp.

- We can use `require` or `subscribe` keywords in `Component Specific Definition Language(.cdsl)` to specify that the current component needs some information from the required component of the robocomp.

- We will create a server and a client for [`CameraSimple`](https://github.com/robocomp/robocomp/blob/development/interfaces/IDSLs/CameraSimple.idsl) component that will show you how you can share an Image data(Information) from client to server.

- The [`implements`](implements/README.md) folder contains implementation of the CameraSimple(will act as a Server). And the [`requires`](requires/README.md) folder contains a component that requires the information send by CameraSimple component.
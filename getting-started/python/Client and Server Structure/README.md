# README

## The Internet Communications Engine(ICE)
- Ice is an object-oriented middleware platform. Fundamentally, this means that Ice provides tools, APIs, and library support for building object-oriented client-server applications. Ice applications are suitable for use in heterogeneous environments: client and server can be written in different programming languages, can run on different operating systems and machine architectures, and can communicate using a variety of networking technologies. The source code for these applications is portable regardless of the deployment environment.

## Servers & Clients
- The terms client and server are not firm designations for particular parts of an application; rather, they denote roles that are taken by parts of an application for the duration of a request:
    - Clients are active entities. They issue requests for service to servers.
    - Servers are passive entities. They provide services in response to client requests.
- Frequently, servers are not "pure" servers, in the sense that they never issue requests and only respond to requests. Instead, servers often act as a server on behalf of some client but, in turn, act as a client to another server in order to satisfy their client's request.
- Similarly, clients often are not "pure" clients, in the sense that they only request service from an object. Instead, clients are frequently client-server hybrids. For example, a client might start a long-running operation on a server; as part of starting the operation, the client can provide a callback object to the server that is used by the server to notify the client when the operation is complete. In that case, the client acts as a client when it starts the operation, and as a server when it is notified that the operation is complete.

- Such role reversal is common in many systems, so, frequently, client-server systems could be more accurately described as peer-to-peer systems.

## Objects & Proxies

- An Ice object is an entity in the local or a remote address space that can respond to client requests. The objects are created by Server
- Each Ice object has a unique object identity. An object's identity is an identifying value that distinguishes the object from all other objects. The Ice object model assumes that object identities are globally unique, that is, no two objects within an Ice communication domain can have the same object identity.

- For a client to be able to contact an Ice object, the client must hold a proxy for the Ice object. A proxy is an artifact that is local to the client's address space; it represents the (possibly remote) Ice object for the client. A proxy acts as the local ambassador for an Ice object: when the client invokes an operation on the proxy, the Ice run time:
    1. Locates the Ice object
    2. Activates the Ice object's server if it is not running
    3. Activates the Ice object within the server
    4. Transmits any in-parameters to the Ice object
    5. Waits for the operation to complete
    6. Returns any out-parameters and the return value to the client (or throws an exception in case of an error)
- A proxy encapsulates all the necessary information for this sequence of steps to take place.
- A proxy is used by the client to
- You can find the object address in the `implements/etc/config`.
- You can find the proxy address in the `requires/etc/config`.

## Example of how the robocomp components uses ICE to share data

- In this tutorial, We are going to learn how the different components in robocomp, share data using the Ice's peer-to-peer systems. 
- For the data to be shared between components, we need to have at least 2 components i.e. One component will act as a server and the other will be the client.

- We can use `implement` or `publish` keyword in the `Component Specific Definition Language(.cdsl)` to specify that the component will be implemented and generally this component will generate some kind of data that might be required by another component of robocomp.

- We can use `require` or `subscribe` keywords in `Component Specific Definition Language(.cdsl)` to specify that the current component needs some information from the required component of the robocomp.

- We will create a server and a client for CameraSimple component that will show you how you can share an Image data(Information) from client to server.

- The implements folder contains implementation of the CameraSimple(will act as a Server). And the requires folder contains a component that requires the information send by CameraSimple component.
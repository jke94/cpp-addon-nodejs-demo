# cpp-addon-nodejs-demo

C/C++ addons with N-API (Node-API). This code have been developed under windows operating system and using:

```
PS J:\Repositories\cpp-addon-nodejs-demo> node --version
v20.14.0
PS J:\Repositories\cpp-addon-nodejs-demo> npm --version
10.8.1
PS J:\Repositories\cpp-addon-nodejs-demo>
```

## A. Install development environment.

From base repository folder:

```
npm install
```

## B. Generate addon.

From base repository folder:

```
npm run build --prefix .\demoaddon 
```

## C. Run javascript demo client.

From base repository folder:

```
node .\demo_client_message_worker.js
```
```
node .\demo_client_worker.js
```
```
node .\demo_client.js
```

## D. Run typescript demo client.

From base repository folder:

```
node .\demo_client_message_worker.ts
```
```
node .\demo_client_worker.ts
```
```
node .\demo_client.ts
```


## E. Useful links

- [Node.js v21.2.0 documentation](https://nodejs.org/api/addons.html)
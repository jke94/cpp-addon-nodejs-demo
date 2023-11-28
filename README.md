# cpp-addon-nodejs-demo

C/C++ addons with Node-API

## A. NPM install (typescript and node addons dependencies)


From base repository folder:

```
npm install
```

From '.\demoaddon' folder:

```
npm install
```

## B. Generete addon.

From base repository folder:

```
npm run rebuild --prefix .\demoaddon 
```

## C. Run javascript demo client.

From base repository folder:

```
node .\demo_client.js
```

## D. Run typescript demo client.

From base repository folder:

```
ts-node .\demo_client_typescript.ts
```

## Useful links

- [Node.js v21.2.0 documentation](https://nodejs.org/api/addons.html)
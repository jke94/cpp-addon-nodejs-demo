# cpp-addon-nodejs-demo
C/C++ addons with Node-API

## A. Generete addon.

```
npm run rebuild --prefix .\demoaddon 
```

## B. Run javascript demo client.

```
node .\demo_client.js
```

## C. Run typescript demo client.

```
ts-node .\demo_client_typescript.ts
```

## EXTRA: Build  Docker compose (for running unit tests)

- Linux:

```
sudo docker compose -f ./docker-compose.yml -p node-addom-demo up --build
```

- Windows:

```
docker-compose -f ./docker-compose.yml -p node-addom-demo up --build

```

## Useful links

- [Node.js v21.2.0 documentation](https://nodejs.org/api/addons.html)
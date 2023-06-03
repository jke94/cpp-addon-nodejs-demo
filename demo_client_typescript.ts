// demo_client_typescript.ts

// const addon = require('./demoaddon/build/Release/addon');

// console.log('This should be eight:', addon.add(4, 5));

const addon = require('./demoaddon/build/Release/demoaddon');

const fn = addon();
console.log(fn());
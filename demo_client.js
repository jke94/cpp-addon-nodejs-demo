// demo_client.js

const addon = require('./demoaddon/build/Release/addon.node');

console.log('This should be eight:', addon.add(4, 5));
// demo_client_typescript.ts

const addon = require('./demoaddon/build/Release/demoaddon.node')
console.log(addon)

var obj1 = addon.createObject('hello');
var obj2 = addon.createObject('world');

console.log(obj1.msg + ' ' + obj2.msg);

var greet = addon.sayHello('Javi');
var goodbye = addon.sayGoodbye('Javi');

console.log(greet.msg);
console.log(goodbye.msg);

console.log(addon.myPropertyStr)
console.log(addon.myPropertyNumber)
// demo_client.js

var addon = require('./demoaddon/build/Release/demoaddon.node')
console.log(addon)

var obj1 = addon.createObject('hello')
console.log('Created object: ', obj1)

var obj2 = addon.createObject('world')
console.log('Created object: ', obj2)

console.log(obj1.content + ' ' + obj2.created_time)

var greet = addon.sayHello('Javi')
var goodbye = addon.sayGoodbye('Javi')

console.log(greet.msg)
console.log(goodbye.msg)

console.log(addon.myPropertyStr)
console.log(addon.myPropertyNumber)
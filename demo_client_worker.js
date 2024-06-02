// demo_client_worker.js

var addon = require('./demoaddon/build/Release/demoaddon.node')

function callback(err, result) 
{
    if (err) 
    {
        console.error(err);
        return;
    }

    // Print number after two seconds.
    console.log('Result:', result);
}
  
console.log('Starting async work...');
addon.startAsyncWork(callback);
console.log('Async work started');
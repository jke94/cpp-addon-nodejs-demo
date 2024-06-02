// demo_client_message_worker.js

var addon = require('./demoaddon/build/Release/demoaddon.node')

function callback(err) 
{
    if (err) 
    {
        console.error(err);
        return;
    }
    console.log('Async work completed');
}

function progressCallback(message) 
{
    console.log('Received message:', message);
}

console.log('Starting async work...');
addon.startAsyncWorker(callback, progressCallback);
console.log('Async work started');
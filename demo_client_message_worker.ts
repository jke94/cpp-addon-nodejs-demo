// demo_client_message_worker.ts

var addon = require('./demoaddon/build/Release/demoaddon.node')

type Callback = (err: Error | null) => void;
type ProgressCallback = (message: string) => void;

const callback: Callback = (err) => 
{
    if (err) 
    {
        console.error(err);
        return;
    }
    console.log('Async work completed');
};

const progressCallback: ProgressCallback = (message) =>
{
    console.log('Received message:', message); 
};

console.log('Starting async work...');
addon.startAsyncWorker(callback, progressCallback);
console.log('Async work started');

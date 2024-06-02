// demo_client_worker.ts

const addon = require('./demoaddon/build/Release/demoaddon.node')

type Callback = (err: Error | null, result?: number) => void;

const callback: Callback = (err, result) => 
{
    if(err) 
    {
        console.error(err);
        return;
    }

    console.log('Result:', result);
};

console.log('Starting async work...');
addon.startAsyncWork(callback);
console.log('Async work started');

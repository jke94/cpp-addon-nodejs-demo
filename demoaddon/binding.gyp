{
  "targets": [
    {
      "target_name": "demoaddon",
      "sources": [ 
        "src/Demoaddon.cpp",
        "src/CallbackWorker.cpp",
        "src/Goodbye.cpp",
        "src/Greeting.cpp",
        "src/MessageWorker.cpp",
        ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
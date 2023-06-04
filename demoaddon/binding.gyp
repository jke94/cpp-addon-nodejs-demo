{
  "targets": [
    {
      "target_name": "demoaddon",
      "sources": [ 
        "src/index.cpp",
        "src/goodbye.cpp",
        "src/greeting.cpp",
        ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
    }
  ]
}
# From base image node
FROM node:16

# Create app directory
RUN mkdir -p /usr/src/app
WORKDIR /usr/src/app

# Copying all the files from your file system to container file system
COPY /demoaddon/src/ /demoaddon/src/
COPY /demoaddon/binding.gyp /demoaddon/binding.gyp
COPY /demoaddon/package.json /demoaddon/package.json
# COPY /demoaddon/package-lock.json /demoaddon/package-lock.json
COPY /demo_client.js /demo_client.js

# Install all dependencies
RUN npm install

# Build addon
RUN npm run rebuild --prefix .\demoaddon 

# Command to run app when intantiate an image
RUN ["node","./demo_client.js"]
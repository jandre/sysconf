# sysconf 

Node bindings for sysconf(3)

## Installation

```
$ npm install sysconf 
 ```

## Usage

### Example

```js

var sysconf = require('sysconf');

// get clock ticks 
console.log(sysconf.get(sysconf._SC_CLK_TCK)); // 100

```

## License

MIT


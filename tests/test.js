
var sysconf = require('../lib/index.js');

console.log(sysconf.get("_SC_CLK_TCK"));
console.log(sysconf.get(sysconf._SC_VERSION));

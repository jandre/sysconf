var path = require('path');
var _sysconf = require(path.join(__dirname, '../build/Release/sysconf.node'));

/**
 * Get Sysconf
 * @param {Number|String} param - sysconf param 
 *
 * @return {Number} value
 *
 */
exports.get = function(param) {

  if (typeof param == 'string') {
    param = lookup(param);
  }

  return _sysconf.sysconf(param); 
};


function lookup(key) {
  if (module.exports[key]) {
    return module.exports[key];
  } else {
    throw "Invalid option: " + key;
  }
}

var keys = _sysconf.keys();

for (var k in keys) {
  module.exports[k] = keys[k]; 
};


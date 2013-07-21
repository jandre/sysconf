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

exports._SC_ARG_MAX = 1
exports._SC_CHILD_MAX = 2
exports._SC_CLK_TCK = 3
exports._SC_NGROUPS_MAX = 4
exports._SC_OPEN_MAX = 5
exports._SC_JOB_CONTROL = 6
exports._SC_SAVED_IDS = 7
exports._SC_VERSION = 8

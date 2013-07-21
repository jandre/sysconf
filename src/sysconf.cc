/* This code is PUBLIC DOMAIN, and is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND. See the accompanying 
 * LICENSE file.
 */

#include <v8.h>
#include <node.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

using namespace node;
using namespace v8;

Handle<Value> Sysconf(const Arguments& args);

void Init(Handle<Object> target)
{
  HandleScope scope;
  target->Set(String::NewSymbol("sysconf"), FunctionTemplate::New(Sysconf)->GetFunction());
};

Handle<Value> Sysconf(const Arguments& args)
{
  HandleScope scope;
  int value = -1;
  if (args.Length() > 0 && args[0]->IsInt32()) {
    value = args[0]->Int32Value();
  } else {
    return ThrowException(Exception::Error(String::New("you must supply a valid sysconf() parameter")));
  }

  long result = sysconf(value);

  if (result > 0) {
    return scope.Close(Number::New(result));
  } else {
    return ThrowException(Exception::Error(String::New("Invalid parameters")));
  } 
}


extern "C" {
  static void init (Handle<Object> target)
  {
    Init(target);
  }

  NODE_MODULE(sysconf, init);
}

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
Handle<Value> Keys(const Arguments& args);

void Init(Handle<Object> target)
{
  HandleScope scope;
  target->Set(String::NewSymbol("sysconf"), FunctionTemplate::New(Sysconf)->GetFunction());
  target->Set(String::NewSymbol("keys"), FunctionTemplate::New(Keys)->GetFunction());
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

Handle<Value> Keys(const Arguments& args)
{
  HandleScope scope;
  Local<Object> obj = Object::New();
#ifdef _SC_ARG_MAX
  obj->Set(String::New("_SC_ARG_MAX"), Number::New(_SC_ARG_MAX));
#endif
#ifdef _SC_CHILD_MAX
  obj->Set(String::New("_SC_CHILD_MAX"), Number::New(_SC_CHILD_MAX));
#endif

#ifdef _SC_HOST_NAME_MAX
  obj->Set(String::New("_SC_HOST_NAME_MAX"), Number::New(_SC_HOST_NAME_MAX));
#endif

#ifdef _SC_LOGIN_NAME_MAX
  obj->Set(String::New("_SC_LOGIN_NAME_MAX"), Number::New(_SC_LOGIN_NAME_MAX));
#endif

#ifdef _SC_OPEN_MAX
  obj->Set(String::New("_SC_OPEN_MAX"), Number::New(_SC_OPEN_MAX));
#endif

#ifdef _SC_PAGESIZE
  obj->Set(String::New("_SC_PAGESIZE"), Number::New(_SC_PAGESIZE));
#endif

#ifdef _SC_RE_DUP_MAX
  obj->Set(String::New("_SC_RE_DUP_MAX"), Number::New(_SC_RE_DUP_MAX));
#endif

#ifdef _SC_STREAM_MAX
  obj->Set(String::New("_SC_STREAM_MAX"), Number::New(_SC_STREAM_MAX));
#endif

#ifdef _SC_SYMLOOP_MAX
  obj->Set(String::New("_SC_SYMLOOP_MAX"), Number::New(_SC_SYMLOOP_MAX));
#endif

#ifdef _SC_TTY_NAME_MAX
  obj->Set(String::New("_SC_TTY_NAME_MAX"), Number::New(_SC_TTY_NAME_MAX));
#endif

#ifdef _SC_TZNAME_MAX
  obj->Set(String::New("_SC_TZNAME_MAX"), Number::New(_SC_TZNAME_MAX));
#endif

#ifdef _SC_VERSION
  obj->Set(String::New("_SC_VERSION"), Number::New(_SC_VERSION));
#endif

#ifdef _SC_CLK_TCK
  obj->Set(String::New("_SC_CLK_TCK"), Number::New(_SC_CLK_TCK));
#endif

  return scope.Close(obj);
}



extern "C" {
  static void init (Handle<Object> target)
  {
    Init(target);
  }

  NODE_MODULE(sysconf, init);
}

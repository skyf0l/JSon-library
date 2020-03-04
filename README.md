# JSon-library
### JSon-library supports 6 data types:
```
null
boolean
integer
string
object
array
```
### Easy to use:
#### json object:
```
#include <json.h>
...
json_object_t *jo = json_object_create();   // create

json_object_put_null(jo, "null_key");
json_object_put_bool(jo, "bool_key", 0);
json_object_put_int(jo, "int_key", 144);
json_object_put_string(jo, "string_key", "hello world!");

json_object_get_size(jo);                   // return 4

json_object_has(jo, "unexist_key");         // return 0
json_object_has(jo, "bool_key");            // return 1

json_object_is_null(jo, "null_key");        // return 0
json_object_is_null(jo, "string_key");      // return 1

json_object_get_int(jo, "int_key");         // return 144
json_object_put_int(jo, "int_key", 0);
json_object_get_size(jo);                   // return 4
json_object_get_int(jo, "int_key");         // return 0
json_object_remove(jo, "int_key");
json_object_get_size(jo);                   // return 3

json_object_to_string(jo);                  // return {"null_key":null, "bool_key":false, "string_key":"hello world!"}

json_object_t *jo2 = json_object_create_from_string("{\"null_key\":null, \"bool_key\":false, \"string_key\":\"hello world!\"}");   // `\"` because " is an escape char

// jo content is completly equal to jo2 content

json_object_destroy(jo);                    // destroy and return NULL
json_object_destroy(jo2);
```
#### json array:
```
#include <json.h>
...
json_array_t *ja = json_array_create();     // create

json_array_put_int(ja, 0);
json_array_put_int(ja, 2);
json_array_put_object_at(ja, 1, json_object_create());

json_array_get_size(ja);                    // return 3

json_array_to_string(ja);                   // return [0, {}, 2]

json_object_put_null(json_array_get_object(ja, 1), "null_key");

json_array_to_string(ja);                   // return [0, {"null_key":null}, 2]

json_array_remove(ja, 2);

json_array_put_array_at(ja, 1, json_array_clone(ja));

json_array_to_string(ja);                   // return [0, [0, {"null_key":null}], {"null_key":null}]

json_array_destroy(ja);                     // destroy and return NULL
```

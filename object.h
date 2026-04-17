#ifndef OBJECT_H
#define OBJECT_H
#include <stddef.h>
#include <stdint.h>
typedef enum { OBJ_BLOB, OBJ_TREE, OBJ_COMMIT } ObjectType;
typedef struct { uint8_t hash[32]; } ObjectID;
int object_write(ObjectType type, const void *data, size_t len, ObjectID *id_out);
int object_read(const ObjectID *id, ObjectType *type_out, void **data_out, size_t *len_out);
void compute_hash(const void *data, size_t len, ObjectID *id_out);
int object_exists(const ObjectID *id);
void object_path(const ObjectID *id, char *buf, size_t size);
#endif

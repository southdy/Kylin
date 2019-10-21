/*
** Lua binding: DatabaseLuaAPI
*/

//
// Copyright (c) 2008-2019 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#include <toluapp/tolua++.h>
#include "LuaScript/ToluaUtils.h"

#if __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-function"
#endif

/* Exported function */
TOLUA_API int tolua_DatabaseLuaAPI_open (lua_State* tolua_S);

#include "Database/DbResult.h"
#include "Database/DbConnection.h"
#include "Database/Database.h"
using namespace Urho3D;
#pragma warning(disable:4800)

#define DatabaseGetAPI Database::GetAPI

#define TOLUA_DISABLE_tolua_DatabaseLuaAPI_GetDatabase00
static int tolua_DatabaseLuaAPI_GetDatabase00(lua_State* tolua_S)
{
    return ToluaGetSubsystem<Database>(tolua_S);
}

#define TOLUA_DISABLE_tolua_get_database_ptr
#define tolua_get_database_ptr tolua_DatabaseLuaAPI_GetDatabase00

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_DbResult (lua_State* tolua_S)
{
 DbResult* self = (DbResult*) tolua_tousertype(tolua_S,1,0);
 Mtolua_delete(self);
 return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Database");
 tolua_usertype(tolua_S,"DbConnection");
 tolua_usertype(tolua_S,"DbResult");
 tolua_usertype(tolua_S,"Object");
}

/* method: GetNumColumns of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbResult_GetNumColumns00
static int tolua_DatabaseLuaAPI_DbResult_GetNumColumns00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DbResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DbResult* self = (const DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumColumns'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumColumns();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumColumns'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumRows of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbResult_GetNumRows00
static int tolua_DatabaseLuaAPI_DbResult_GetNumRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DbResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DbResult* self = (const DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumRows'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetNumRows();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumAffectedRows of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbResult_GetNumAffectedRows00
static int tolua_DatabaseLuaAPI_DbResult_GetNumAffectedRows00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DbResult",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DbResult* self = (const DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumAffectedRows'", NULL);
#endif
 {
  long tolua_ret = (long)  self->GetNumAffectedRows();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumAffectedRows'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numColumns of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_get_DbResult_numColumns
static int tolua_get_DbResult_numColumns(lua_State* tolua_S)
{
  DbResult* self = (DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numColumns'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumColumns());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numRows of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_get_DbResult_numRows
static int tolua_get_DbResult_numRows(lua_State* tolua_S)
{
  DbResult* self = (DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: numAffectedRows of class  DbResult */
#ifndef TOLUA_DISABLE_tolua_get_DbResult_numAffectedRows
static int tolua_get_DbResult_numAffectedRows(lua_State* tolua_S)
{
  DbResult* self = (DbResult*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'numAffectedRows'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetNumAffectedRows());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Finalize of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbConnection_Finalize00
static int tolua_DatabaseLuaAPI_DbConnection_Finalize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DbConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DbConnection* self = (DbConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Finalize'", NULL);
#endif
 {
  self->Finalize();
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Finalize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Execute of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbConnection_Execute00
static int tolua_DatabaseLuaAPI_DbConnection_Execute00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"DbConnection",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isboolean(tolua_S,3,1,&tolua_err) ||
 !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  DbConnection* self = (DbConnection*)  tolua_tousertype(tolua_S,1,0);
  const String sql = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
  bool useCursorEvent = ((bool)  tolua_toboolean(tolua_S,3,false));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Execute'", NULL);
#endif
 {
  DbResult tolua_ret = (DbResult)  self->Execute(sql,useCursorEvent);
 {
#ifdef __cplusplus
 void* tolua_obj = Mtolua_new((DbResult)(tolua_ret));
  tolua_pushusertype(tolua_S,tolua_obj,"DbResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
 void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(DbResult));
  tolua_pushusertype(tolua_S,tolua_obj,"DbResult");
 tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
 }
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Execute'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetConnectionString of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbConnection_GetConnectionString00
static int tolua_DatabaseLuaAPI_DbConnection_GetConnectionString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DbConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DbConnection* self = (const DbConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetConnectionString'", NULL);
#endif
 {
  const String tolua_ret = (const String)  self->GetConnectionString();
 tolua_pushurho3dstring(tolua_S,(const char*)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConnectionString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsConnected of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_DbConnection_IsConnected00
static int tolua_DatabaseLuaAPI_DbConnection_IsConnected00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const DbConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const DbConnection* self = (const DbConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsConnected'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsConnected();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsConnected'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: connectionString of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_get_DbConnection_connectionString
static int tolua_get_DbConnection_connectionString(lua_State* tolua_S)
{
  DbConnection* self = (DbConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'connectionString'",NULL);
#endif
 tolua_pushurho3dstring(tolua_S,(const char*)self->GetConnectionString());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: connected of class  DbConnection */
#ifndef TOLUA_DISABLE_tolua_get_DbConnection_connected
static int tolua_get_DbConnection_connected(lua_State* tolua_S)
{
  DbConnection* self = (DbConnection*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'connected'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsConnected());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Connect of class  Database */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_Database_Connect00
static int tolua_DatabaseLuaAPI_Database_Connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Database",0,&tolua_err) ||
 !tolua_isurho3dstring(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
  const String connectionString = ((const String)  tolua_tourho3dstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Connect'", NULL);
#endif
 {
  DbConnection* tolua_ret = (DbConnection*)  self->Connect(connectionString);
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"DbConnection");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Disconnect of class  Database */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_Database_Disconnect00
static int tolua_DatabaseLuaAPI_Database_Disconnect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Database",0,&tolua_err) ||
 !tolua_isusertype(tolua_S,2,"DbConnection",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
  DbConnection* connection = ((DbConnection*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Disconnect'", NULL);
#endif
 {
  self->Disconnect(connection);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Disconnect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPooling of class  Database */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_Database_IsPooling00
static int tolua_DatabaseLuaAPI_Database_IsPooling00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Database",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Database* self = (const Database*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPooling'", NULL);
#endif
 {
  bool tolua_ret = (bool)  self->IsPooling();
 tolua_pushboolean(tolua_S,(bool)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPooling'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoolSize of class  Database */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_Database_GetPoolSize00
static int tolua_DatabaseLuaAPI_Database_GetPoolSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"const Database",0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  const Database* self = (const Database*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoolSize'", NULL);
#endif
 {
  unsigned tolua_ret = (unsigned)  self->GetPoolSize();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoolSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPoolSize of class  Database */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_Database_SetPoolSize00
static int tolua_DatabaseLuaAPI_Database_SetPoolSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isusertype(tolua_S,1,"Database",0,&tolua_err) ||
 !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
 !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
  unsigned poolSize = ((unsigned)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPoolSize'", NULL);
#endif
 {
  self->SetPoolSize(poolSize);
 }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPoolSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pooling of class  Database */
#ifndef TOLUA_DISABLE_tolua_get_Database_pooling
static int tolua_get_Database_pooling(lua_State* tolua_S)
{
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pooling'",NULL);
#endif
 tolua_pushboolean(tolua_S,(bool)self->IsPooling());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: poolSize of class  Database */
#ifndef TOLUA_DISABLE_tolua_get_Database_poolSize
static int tolua_get_Database_poolSize(lua_State* tolua_S)
{
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'poolSize'",NULL);
#endif
 tolua_pushnumber(tolua_S,(lua_Number)self->GetPoolSize());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: poolSize of class  Database */
#ifndef TOLUA_DISABLE_tolua_set_Database_poolSize
static int tolua_set_Database_poolSize(lua_State* tolua_S)
{
  Database* self = (Database*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'poolSize'",NULL);
 if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
 tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetPoolSize(((unsigned)  tolua_tonumber(tolua_S,2,0))
)
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* function: DatabaseGetAPI */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_GetDBAPI00
static int tolua_DatabaseLuaAPI_GetDBAPI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  DBAPI tolua_ret = (DBAPI)  DatabaseGetAPI();
 tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDBAPI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: GetDatabase */
#ifndef TOLUA_DISABLE_tolua_DatabaseLuaAPI_GetDatabase00
static int tolua_DatabaseLuaAPI_GetDatabase00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
 !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
 goto tolua_lerror;
 else
#endif
 {
 {
  Database* tolua_ret = (Database*)  GetDatabase();
  tolua_pushusertype(tolua_S,(void*)tolua_ret,"Database");
 }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDatabase'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: database */
#ifndef TOLUA_DISABLE_tolua_get_database_ptr
static int tolua_get_database_ptr(lua_State* tolua_S)
{
  tolua_pushusertype(tolua_S,(void*)GetDatabase(),"Database");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_DatabaseLuaAPI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,1);
 tolua_beginmodule(tolua_S,NULL);
 #ifdef __cplusplus
 tolua_cclass(tolua_S,"DbResult","DbResult","",tolua_collect_DbResult);
 #else
 tolua_cclass(tolua_S,"DbResult","DbResult","",NULL);
 #endif
 tolua_beginmodule(tolua_S,"DbResult");
  tolua_function(tolua_S,"GetNumColumns",tolua_DatabaseLuaAPI_DbResult_GetNumColumns00);
  tolua_function(tolua_S,"GetNumRows",tolua_DatabaseLuaAPI_DbResult_GetNumRows00);
  tolua_function(tolua_S,"GetNumAffectedRows",tolua_DatabaseLuaAPI_DbResult_GetNumAffectedRows00);
  tolua_variable(tolua_S,"numColumns",tolua_get_DbResult_numColumns,NULL);
  tolua_variable(tolua_S,"numRows",tolua_get_DbResult_numRows,NULL);
  tolua_variable(tolua_S,"numAffectedRows",tolua_get_DbResult_numAffectedRows,NULL);
 tolua_endmodule(tolua_S);
 tolua_cclass(tolua_S,"DbConnection","DbConnection","Object",NULL);
 tolua_beginmodule(tolua_S,"DbConnection");
  tolua_function(tolua_S,"Finalize",tolua_DatabaseLuaAPI_DbConnection_Finalize00);
  tolua_function(tolua_S,"Execute",tolua_DatabaseLuaAPI_DbConnection_Execute00);
  tolua_function(tolua_S,"GetConnectionString",tolua_DatabaseLuaAPI_DbConnection_GetConnectionString00);
  tolua_function(tolua_S,"IsConnected",tolua_DatabaseLuaAPI_DbConnection_IsConnected00);
  tolua_variable(tolua_S,"connectionString",tolua_get_DbConnection_connectionString,NULL);
  tolua_variable(tolua_S,"connected",tolua_get_DbConnection_connected,NULL);
 tolua_endmodule(tolua_S);
 tolua_constant(tolua_S,"DBAPI_SQLITE",DBAPI_SQLITE);
 tolua_constant(tolua_S,"DBAPI_ODBC",DBAPI_ODBC);
 tolua_cclass(tolua_S,"Database","Database","Object",NULL);
 tolua_beginmodule(tolua_S,"Database");
  tolua_function(tolua_S,"Connect",tolua_DatabaseLuaAPI_Database_Connect00);
  tolua_function(tolua_S,"Disconnect",tolua_DatabaseLuaAPI_Database_Disconnect00);
  tolua_function(tolua_S,"IsPooling",tolua_DatabaseLuaAPI_Database_IsPooling00);
  tolua_function(tolua_S,"GetPoolSize",tolua_DatabaseLuaAPI_Database_GetPoolSize00);
  tolua_function(tolua_S,"SetPoolSize",tolua_DatabaseLuaAPI_Database_SetPoolSize00);
  tolua_variable(tolua_S,"pooling",tolua_get_Database_pooling,NULL);
  tolua_variable(tolua_S,"poolSize",tolua_get_Database_poolSize,tolua_set_Database_poolSize);
 tolua_endmodule(tolua_S);
 tolua_function(tolua_S,"GetDBAPI",tolua_DatabaseLuaAPI_GetDBAPI00);
 tolua_function(tolua_S,"GetDatabase",tolua_DatabaseLuaAPI_GetDatabase00);
 tolua_variable(tolua_S,"database",tolua_get_database_ptr,NULL);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_DatabaseLuaAPI (lua_State* tolua_S) {
 return tolua_DatabaseLuaAPI_open(tolua_S);
}
#endif

#if __clang__
#pragma clang diagnostic pop
#endif
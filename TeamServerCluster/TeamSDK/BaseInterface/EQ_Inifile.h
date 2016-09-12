#pragma once

#ifndef EQ_INIFILE_H_
#define EQ_INIFILE_H_

#ifdef __cplusplus
extern "C"
{

#endif

int EQ_ReadInifileString( const char *section, const char *key,char *value, int size,const char *default_value, const char *file);
int EQ_ReadInifileInt( const char *section, const char *key,int default_value, const char *file);
int EQ_WriteInifileString( const char *section, const char *key,const char *value, const char *file);

#ifdef __cplusplus
}; //end of extern "C" {
#endif

#endif //end of INI_FILE_H_


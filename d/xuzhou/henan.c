
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"henan"
#define TO __DIR__"hebei"

#include "shiproom.c";

void create ()
{
  set ("short","�����ϰ�");
  set ("long", @LONG
�����ǳ������ϰ�����ǰ�ǹ����ĳ������㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵����������ˡ�
LONG);

  set("exits", ([ 

  "southeast":__DIR__"dadao6",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}




#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"hebei"
#define TO __DIR__"henan"

#include "shiproom.c";

void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����ǳ����ı�������ǰ�ǹ����ĳ������㲻������һ�ɺ�������
�����ڽд���(yell boat)���Ϳ��Գ��۵������ϰ��ˡ�
LONG);

  set("exits", ([ 

  "northwest":__DIR__"dadao7",
         ]));

  set("valid_startroom", 1);
  set("outdoors","huanghe");
  setup();
 
}



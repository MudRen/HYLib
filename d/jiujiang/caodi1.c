
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ݵ�");
  set ("long", @LONG
������Ƭʪ��Ĳݵأ��Ա߾��ǹ����ĳ���������羰������ɽˮ
�续���������¡���ˮ�ĳ�ʪ��Ϣ�˱Ƕ�����
LONG);

  set("exits", ([ 

  "east":__DIR__"caodi2",
  "west":__DIR__"xiaolu3",
  "north":__DIR__"yucun",
  
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiujiang");
  setup();
 
}


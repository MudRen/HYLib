
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�Ž��㳡");
  set ("long", @LONG
�����ǾŽ�����ĵش��ˡ�����㼯������ĺ������ˡ��ο͡�
�����������ò����֡���Ȼ�������Ҳ�ס������������Ȼ���ַǷ�����
˵����������ǰ�����ﱻ��ɱ�������ÿ��ٺ��������������𽭺���
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie1",
  "north":__DIR__"beidajie2",
  "east":__DIR__"dongdajie1",
  "west":__DIR__"xidajie1",
         ]));
  set("objects",([
  __DIR__"npc/feiyan":1,
  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
����������֡�������ǾŽ��������ˡ������ǾŽ����ξ֡�����
Ŀǰ�������ң�����Ӧ�йٸ����εĶ��������к�����ʿ��ֻ����¡��
�У�һ���������͸��ų��������ȥ�������ǾŽ������ţ��м����ٱ�
�����������Ž��������ˡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"yanju",
  "east":__DIR__"xidajie1",
  "west":__DIR__"ximen",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}


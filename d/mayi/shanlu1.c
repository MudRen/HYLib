
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ·");
  set ("long", @LONG
������һ��ɽ·�������Ǿ��ǳ��ǣ�����һ����ȥ��һƬ���֣���
�ֿ������ܴ������Ѿ���ɽ���ľ����ˡ����ܹ�ʯ��ᾣ��������ϲ�
��ǰ��ĵ�·��
LONG);

  set("exits", ([
 "northeast":__DIR__"changcheng14",
 "southdown":__DIR__"shanlu2",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


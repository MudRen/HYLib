
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɽ��С·");
  set ("long", @LONG
������һ��ɽ·�������Ǿ��ǳ��ǣ�����һ����ȥ��һƬ���֣���
�ֿ������ܴ������Ѿ���ɽ���ľ����ˡ����ܹ�ʯ��ᾣ��������ϲ�
��ǰ��ĵ�·��
LONG);

  set("exits", ([
 "northup":__DIR__"shanlu1",
 "southeast":__DIR__"shanlu3",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


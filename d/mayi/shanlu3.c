
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
 "northwest":__DIR__"shanlu2",
 "eastdown":__DIR__"xiaolu1",
        ]));
  set("outdoors","mayi");

  set("valid_startroom", 1);
  setup();

}


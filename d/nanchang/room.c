
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�뷿");
  set ("long", @LONG
�����������Ů���Ĺ뷿������ܸɾ��������ո����˴�ɨ������
ͷ����ױ̨���ż���װ��Ʒ���������ǳ�����
LONG);

  set("exits", ([ 

  "out":__DIR__"guifang",
    ]));

  set("objects",([
	  __DIR__"npc/xiaojie":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}

	

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","é����");
  set ("long", @LONG
������һ���ũס��é���ݣ����ڲ�û��ʲô������װ�Σ�������
�����࣬��Ʒ�ڷŵľ�Ȼ�����������ڿ���������ũæ�������㻹��
�Ͽ��ȥ���ˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"guolin",
    ]));

  set("valid_startroom", 1);
  setup();
 
}

	

#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ķ���");
  set ("long", @LONG
�ķ���λ�ڰ����سǶ����ʺ��ϡ�ʼ����������������
��1630�꣩�����߼�����Լ���ɣ���שʯ���������Σ���
����̨�ס���¥���Ŵ����ɹ����������� 
LONG);

  set("exits", ([ 
  "southwest":__DIR__"hupao",
        ]));
  set("objects",([
       __DIR__"npc/daoke":2,
       ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}


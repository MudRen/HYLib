
inherit ROOM;


void create ()
{
  set ("short","��ɽ");
  set ("long", @LONG
�����Ǽ�ɽ�֣�����ļ�ɽ��ʯ��ᾣ��������أ��е������ӥҰ
�ã��е������ɽ��Ȫ���е�����������·���е���������̩ɽ����״
���죬�����˺ܶ�����ˡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"yuanlin",
       ]));
  set("objects",([
	  __DIR__"npc/gongzi":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}



inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�������ϲ�������֡������߿��Ե��ϲ��������˵ĵط�۶��������
�����ϲ��������ˡ��кܶ��οͶ�����۶������ȥ��������һ�Ҿ�¥����
����������㣬�ȾƳ��ֵ�����ͬʱҲ�����������ͷ��
LONG);

  set("exits", ([ 
 "north":__DIR__"xihulou",
  "west":__DIR__"xidajie2",
  "east":__DIR__"center",
         ]));
  set("objects",([
	  __DIR__"npc/wushi":1,
	  ]));

set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}


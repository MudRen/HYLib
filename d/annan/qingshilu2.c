
inherit ROOM;


void create ()
{
  set ("short","��ʯ·");
  set ("long", @LONG
����������ʯ·�������ǰ��ϵı��š���������˺ܶ࣬���ϱ���
�Ϳ��Ե����ϵ������ˡ����ڽ��갲�ϰ���Ᵽ����������Է�����
��Ϊְҵ�����԰��ϵĽ�ͷ�ټ�����Ů���ˡ�
LONG);

  set("exits", ([ 

  "south":__DIR__"qingshilu1",
// "east":"/d/clone/room/cityroom/baling",
  "north":__DIR__"beimen",
       ]));
 set("objects",([
	 __DIR__"npc/boy":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}


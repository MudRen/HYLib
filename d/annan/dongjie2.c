
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����ǰ��ϵĶ��֡����߾��ǰ��ϵĶ����ˡ�������һ��Ǯׯ��Ǯ
ׯ�Ľ����������������ҫ���������⡣���ߵĶ��Ŵ����˹ٱ�ߺ�ȵ�
������
LONG);

  set("exits", ([ 

  "north":__DIR__"qianzhuang",
  "east":__DIR__"dongmen",
  "west":__DIR__"dongjie1",
      ]));
 set("objects",([
   "/clone/npc/man":2,
   ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}


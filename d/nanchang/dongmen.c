
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�������ϲ��Ķ��š��ϲ�������ʤ�أ�����������Ȼ��ս��ʱ�֣�
����Ȼ�ڸǲ������ﷱ���ľ���ͬ������ȣ������й����޲�������
����������˺ܶࡣ�����������ٱ����ڼ�������������ˡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"dongdajie2",
  "east":__DIR__"guandao1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
set("outdoors","nanchang");
  
  set("valid_startroom", 1);
  setup();
 
}


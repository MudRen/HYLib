
inherit ROOM;


void create ()
{
  set ("short","����");
  set ("long", @LONG
�����Ƕ����ˡ��кܶ����˶����������ߡ���ս�ҵ�������Ž���
Ȼ��������֡��м����ٱ���ҫ��������վ�������������������ˡ�
LONG);

  set("exits", ([ 

 "west":__DIR__"dongdajie3",
 "east":"/d/nanchang/guanlu1",
        ]));
  set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}


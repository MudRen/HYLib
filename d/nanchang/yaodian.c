
inherit ROOM;


void create ()
{
  set ("short","ҩ��");
  set ("long", @LONG
������һ��ҩ�ꡣ�����ҩ��������ȫ�����ϲ��м��ߵ���������
�ھ��ƻ��ң�ҩ����������������ֻ����ǰ����һ�����ң�����д�ţ�
��٢�������β����� �˸����֡��������������������˰�ҩ�����к�
�ಡ�����������ŶӵȺ�
LONG);

  set("exits", ([ 

  "north":__DIR__"dongdajie1",
        ]));

  set("objects",([
	  __DIR__"npc/huang":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}


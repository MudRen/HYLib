
inherit ROOM;


void create ()
{
  set ("short","Ǯׯ");
  set ("long", @LONG
������һ��Ǯׯ������������ܸߣ������ϲ��˵����Ρ�ÿ������
����˺ܶ࣬�ϰ�æ����ͣ��ֻ�����̵��Ա߷���һ�������ӣ�����д
�ţ��������ۡ�
LONG);

  set("exits", ([ 

  "west":__DIR__"nandajie2",
     ]));

  set("objects",([
	  __DIR__"npc/zhou":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}


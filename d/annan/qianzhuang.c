
inherit ROOM;


void create ()
{
  set ("short","����Ǯׯ");
  set ("long", @LONG
�����ǰ��ϵ�Ǯׯ������������ܺã��кܶ����������Ǯ���ϰ�
��������������̣��������ǰ������к��ſ��ˡ�
LONG);

  set("exits", ([ 

 "south":__DIR__"dongjie2",
      ]));
 
  set("objects",([
	  __DIR__"npc/wu":1,
	  ]));
  
  set("valid_startroom", 1);
  setup();
 
}



inherit ROOM;


void create ()
{
  set ("short","����¥");
  set ("long", @LONG
�����ǾŽ������ľ�¥--����¥��ȡ��[�з�����]���֡���������
��Ϊ����Ů���򸻼ҵ�С�㣬�������ſڽӴ����˵ĵ�С�����Ǳ����
��¥ǰ�����ĸ��������ֱ�д��[�з�����]�ĸ���ӭ����չ��������
���˷���һ�㡣
LONG);

  set("exits", ([ 

  "west":__DIR__"nandajie1",
        ]));
  set("objects",([
	  __DIR__"npc/qu":1,
	  __DIR__"npc/nvxia":1,
__DIR__"npc/xiaoer4":1,
	  ]));
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ϷԺ");
  set ("long", @LONG
������һ��ϷԺ��ƽʱ�кܶ��������￴Ϸ����˵�����������ݺ�
Ϸ�������������˺ܶ��ˣ����Ƚ���ǰ������ѷɫ�˲��١�ϷԺ���к�
����������С��������Ϸ��û��ʼ����������˽������������ҳ���һ
Ƭ��
LONG);

  set("exits", ([ 
	  "west":__DIR__"nandajie3",
  ]));

set("objects",([
	__DIR__"npc/xiyou":1,
	]));
  set("valid_startroom", 1);
  setup();
 
}


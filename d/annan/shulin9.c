
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ع���");
  set ("long", @LONG
�ع��ӷ�Դ���й���ظ�ԭ�����γ����׽��������Ρ�̩��������կ
���밲���ϲ�����Ϊ�ϱ���������������ǰ�����ϸ����ƺ󽭣����
���������ֳַɾ���֧���뺣�����ֳƾ�������
LONG);

  set("exits", ([ 
  "south":__DIR__"shulin7",
  "northwest":"d/kunming/nanmen",

  "west":__DIR__"shulin2",
  "northeast":__DIR__"shulin7",
  "southeast":__DIR__"shulin8",
    ]));
   set("objects",([
	 __DIR__"npc/daxiang":1,
	 __DIR__"npc/tiger":1,	
	 __DIR__"npc/dushe":2,	
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}


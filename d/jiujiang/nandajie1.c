
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�ϴ��");
  set ("long", @LONG
�������ϴ�֡������ǾŽ��ķ����ش��ˡ�������һ�Ҿ�¥������
������¥�кȾƽ�Ц��������һ����ʱ�����Ʋ˵���������¥�ĵ�С
�������ſ�������к��������Ŀ��ˡ�ֻ����˻�������У���һ������
����ͣ�ھ�¥��ǰ��
LONG);

  set("exits", ([ 

  "south":__DIR__"nandajie2",
  "north":__DIR__"center",
  "east":__DIR__"fengyilou",
         ]));
  set("objects",([
    __DIR__"npc/huxiaoxian":1,
    ]));
  
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǺϷʵ�����֡������߾��ǺϷʵ������ˡ��ϱ���һ�Ҳ÷�
�ꡣֻ�������м����ٱ����Խ��ǵİ������ϸ���Ѳ顣�÷�������
�����壬��Ȼ��˵�÷�����ղ��������ڹ�����������Խ��Խ���ˡ�
LONG);

  set("exits", ([ 
  "northeast":__DIR__"xidajie1",
  "west":__DIR__"xidajie3",
  "south":__DIR__"caifengdian",
     ]));
     
  set("objects",([
  	__DIR__"npc/zhangxiaojie":1,
  ]));

set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","���");
  set ("long", @LONG
��ӷ�Դ���й�����ʡΡɽ�أ����й����ڳ�ΪԪ����ȫ��1200���
���й����Ͼ��ڳ�695�����ڰ��Ͼ��ڳ�505����,��Ӻ��ع���ˮ��
��Դ�ḻ�������߳�3260ǧ�ף��ذ�����Ȼ���ۡ�
LONG);

  set("exits", ([ 
  "north":__DIR__"shulin1",
  "south":__DIR__"matou",

  //"northeast":__DIR__"tulu2",
  "northwest":__DIR__"shulin4",
    ]));
   set("objects",([
	 __DIR__"npc/daxiang":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}


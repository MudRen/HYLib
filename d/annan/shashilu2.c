
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ɳʯ·");
  set ("long", @LONG
��������ɳʯ·���������һƬ�������Ĵ���ȥһƬƽ̹����ʱ��
��������ͷ�Ϸɹ�������û��ʲô�ˣ��㲻���ӿ����н��ĽŲ���
LONG);

  set("exits", ([ 

  "northwest":__DIR__"shashilu1",
  "southwest":__DIR__"qiuling6",
 // "west":__DIR__"hg",
       ]));
 
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}


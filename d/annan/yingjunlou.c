
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","ӭ��¥");
  set ("long", @LONG
�����ǰ������Ĵ�¥--��ӭ��¥�����ſ��м����������к�����
�����ˡ�̧ͷ��ȥ������¥��������֮�ߣ�ÿ��¥�϶�������Ц��������
��ӭ��¥�������ƹ��������棬�ƺ����������廹Ҫ���ɡ���ʱ�а���
��ĵ��Ӵ�����������롣
LONG);

  set("exits", ([ 

  "west":__DIR__"qingshilu1",
       ]));
 set("objects",([
	 __DIR__"npc/xiaocui":1,
	 ]));
set("outdoors","annan");
  
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��������");
  set ("long", @LONG
�����Ǵ��ӵ����ġ��������Ӳ���һ����Ӱ��վ���������һ�ֿ�
���ĸо��������м���ʬ�������ܶ����ջٻ򵹵��ķ��ݣ�һ�ɻ�����
���ա�
LONG);

  set("exits",([
	  "west":__DIR__"cundong",
	  "east":__DIR__"cunxi",
	  "south":__DIR__"tiandi",
	  ]));
  set("outdoors","xucheng");
  set("valid_startroom", 1);
  setup();
 
}


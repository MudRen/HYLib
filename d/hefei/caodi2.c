
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","��ң��");
  set ("long", @LONG
����������ʮ�꣨215�꣩,��Ȩ����10�������Ϸ�δ�£�������Ϊ�ܲ��ؽ�
������Ϯ����Ȩ�ֻʳ��ӣ�����Ծ���������գ��Ӵ���ң���������������Ĺŵ�
С˵���������塷��"����������ң��"�Ĺ��¼����ڴˡ�
LONG);

  set("exits", ([ 

  "north":__DIR__"shanlu3",
  "south":"/d/jiujiang/jiangbei",
       ]));
  
set("outdoors","hefei");
  
  set("valid_startroom", 1);
  setup();
 
}



#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","�����");
  set ("long", @LONG
�����ǾŽ��ı���֡������ǾŽ��ı��š�������һ�Ҳ�ݡ�����
����������Ĳ��㣬��С�����ſ�������к��ſ��ˡ�������һ���ӻ�
�̣�������ƷƷ�ַ��࣬�кܶ��˵�����ȥ��������������˺ܶ࣬
�Ƚ����֡�
LONG);

  set("exits", ([ 

  "south":__DIR__"beidajie2",
  "north":__DIR__"beimen",
  "west":__DIR__"chaguan",
         ]));
         
       
set("outdoors","jiujiang");
  set("valid_startroom", 1);
  setup();
 
}


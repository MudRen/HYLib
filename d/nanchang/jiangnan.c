
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangnan"
#define TO __DIR__"jiangbei"
#include "shiproom.c";
void create ()
{
  set ("short","�Ͻ��ϰ�");
  set ("long", @LONG
�������Ͻ����ϰ����кܶ�����������˴����ǳ����֡����С��
С��������������򼴽��Ǵ�չʾ�Լ��Ļ�������ļ๤���ڴ�����
����Ĺ��ˣ��ߴٵ�����������ֻ��һ��������������һ�Ҵ�ʻ���˸�
�ڡ�
LONG);

  set("exits", ([ 

  "southwest":__DIR__"caodi2",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}


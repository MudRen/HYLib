
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","®ɽ�ٲ�Ⱥ");
  set ("long", @LONG
®ɽ�ٲ�Ⱥ������ʷ�ģ������������ɧ���ڴ˸�ʫ��ʣ�������׳��
��ΰ����®ɽ�ٲ������˼��ߵ�����������������Ȼ���ƴ�ʫ����׵ġ���
®ɽ�ٲ������ѳ�ǧ�ž����������١�ʯ�Ž�������Ȫ������̶������̶��
���ȡ�®ɽ�ٲ�Ⱥ�����Բ�ͬ�ķ�ò������չʾ���������顣
LONG);

  set("exits", ([ 
 "north":__DIR__"shanlu2",
 "southwest":__DIR__"shanlu4",
         ]));
  set("outdoors","jiujiang"); 
  set("valid_startroom", 1);
  setup();
 
}


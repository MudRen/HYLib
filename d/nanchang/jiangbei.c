
#include <ansi.h>

inherit ROOM;

#define SHIPDIR __DIR__"ship"
#define FROM __DIR__"jiangbei"
#define TO __DIR__"jiangnan"
#include "shiproom.c";
void create ()
{
  set ("short","�Ͻ�����");
  set ("long", @LONG
�������Ͻ��ı������кܶ�����������˴����ǳ����֡����С��
С��������������򼴽��Ǵ�չʾ�Լ��Ļ�������ļ๤���ڴ�����
����Ĺ��ˣ��ߴٵ�����������ֻ��һ��������������һ�Ҵ�ʻ���˸�
�ڡ�
LONG);

  set("exits", ([ 

  "north":"/d/yixing/nanxun",
//  "west":"/u/kouzhong/shichang",
//  "east":"/d/job/sjbjob/dongan",
 //"northwest":"/d/clone/room/yzplayerhome/door",
         ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}


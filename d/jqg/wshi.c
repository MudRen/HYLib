// wshi.c By River 98/08/29
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
          set("short",HIC"����"NOR);
          set("long", @LONG
�ٲ����ڣ�һƳ�ۼ䣬ֻ�����г����ª�����ྻ�쳣������ֻһ��һ����
������ޱ���������þ����Ĺʯ���е�����һģһ����ֻ�ǹ�Ĺ���þߴ�
��ʯ�ƣ��˴���ȴ�ɴ�ľ��ɡ�����������齡�
LONG        );

          set("exits", ([
               "south" : __DIR__"zhongtang",
          ]));         
          set("sleep_room", 1);
          set("no_fight", 1);
          
          setup();
}

#include <room.h>
inherit ROOM;

void create()
{
      set("short", "���");
      set("long", @LONG
������һ�侲����С�ݣ����������͵Ĵ�����Կ�������Ĵ�֡�������
һ�Ŵ�����ͷС���Ϸ��˼�ֻ�򵥵����С����������һ�ź�ľ������
LONG );
      set("exits", ([
          "east" : __DIR__"beijie3",
        ]));
        
      set("objects", ([
               __DIR__"npc/pingsi" : 1,
      ]));

      setup();
}

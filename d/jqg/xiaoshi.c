// xiaoshi.c

inherit ROOM;
#include <ansi.h>

void create()
{
       set("short",HIC"С��"NOR);
       set("long", @LONG
��ٲ�����һ��С�ң�ֻ������������������������һ�Ѳ������֮
��������м������Ƶ���޺�һ����ľ���Ƶĵ��ӡ�
LONG
        );
       set("exits", ([
	  "west" : __DIR__"zhongtang",
	  "east" : __DIR__"dashi",
       ]));	

       set("objects", ([
               __DIR__"npc/yangguo" : 1,
       ]));
       setup();
}


// /d/tiezhang/gjfang.c

#include <ansi.h>
inherit ROOM;

void create()
{

          set("short","���߷�");
          set("long", @LONG
����һ�乤�߷��������Ե���Щ�ƾɣ�ǽ���ĽǶ��������ǽ��һ�߷�
�Ÿ����߼ܣ����߼��Ϸ��Ÿ��ֹ��ߣ���Щ�Ѿ���Щ�����ˡ�����������һ��
���ŵ���ζ��ʹ�㲻��΢΢������üͷ��
LONG
);
           set("exits",([
"west": __DIR__"zoulang-4",
]));

           set("objects",([
__DIR__"npc/xiaotong2":1,
]));

            set("no_fight",1);
            set("no_sleep",1);
            setup();
            replace_program(ROOM);
}


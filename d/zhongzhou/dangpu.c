#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������쿪�ĵ��̡��⵱�̿��ܺ͹ٸ��й��ᡣ������
������Ķ�������·��ζ����ա���Ҳ���Կ�����ʲô������
��ҪҲ����ȥ��һ�㡣������Ǯ���ܱ������ط�Ҫ��һ�㡣��
̨��ǽ�Ϲ���һ������(paizi)��
LONG);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg", 1);
        set("item_desc", ([
                "paizi" : WHT "\n\n        ����������������������\n"
                              "        ��                  ��\n"
                              "        ��     ��ƽ����     ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��   " NOR + HIY "sell" NOR + WHT "   ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "���" NOR + WHT "��   " NOR + HIY "buy" NOR + WHT "    ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "��   " NOR + HIY "value" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��                  ��\n"
                              "        ����������������������\n\n\n" NOR,
        ]));


        set("objects", ([
  		__DIR__"npc/zhousongtian" : 1,
  		__DIR__"npc/yitai" : 1,
	]));

        set("exits", ([
  		"north" : __DIR__"yanling",
	]));

        set("coor/x", -240);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

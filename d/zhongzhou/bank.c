#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "Ǯׯ");
        set("long", @LONG
�������ݳ���һ�����ֺ�Ǯׯ����˵����������ܺá���
������ڹ�̨��æ�š���̨�ϻ���һ������ (paizi)�����Ǹ�
Ǯ��Ӫ��������ı������ֲ���������򲻵�ʲô�����⡣
LONG);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg",1);
        set("exits", ([
                "east" : __DIR__"wendingnan1",
                 
        ]));
        set("item_desc", ([
                "paizi" : WHT "\n\n        ����������������������\n"
                              "        ��                  ��\n"
                              "        ��     ��ƽ����     ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "��Ǯ" NOR + WHT "�� " NOR + HIY "deposit" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "ȡǮ" NOR + WHT "�� " NOR + HIY "withdraw" NOR + WHT " ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "�һ�" NOR + WHT "�� " NOR + HIY "convert" NOR + WHT "  ��\n"
                              "        ��                  ��\n"
                              "        ��  " NOR + HIW "����" NOR + WHT "�� " NOR + HIY "check" NOR + WHT "    ��\n"
                              "        ��                  ��\n"
                              "        ��                  ��\n"
                              "        ����������������������\n\n\n" NOR,
        ]));

        set("objects" , ([
                __DIR__"npc/yaodezhong":1,
        ]));

        set("coor/x", -240);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}


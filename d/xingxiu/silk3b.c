// /d/xingxiu/silk3.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ������Ķ�Ѩ����������ʯѤ�����ˣ��������档��Ϭţ���¡���
�����졢����ƺ��������������������ݡ���ľ�ŵȣ�������ǧ������Ѱζ��
LONG);
        set("outdoors", "yili");

        set("exits", ([
                "east" : __DIR__"silk3a",
                "northwest" : __DIR__"silk3c",
        ]));

        setup();
//        replace_program(ROOM);
}


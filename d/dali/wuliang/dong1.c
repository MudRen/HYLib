// Room: /dali/dong1.c
// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����֮������Բ��ʯ�ң����ʯ��������һ��ˮ����Լ��ͭ���С������
����ˮ����͸�롣������ȥ���ɿ���ˮ����ͣ�ζ���ԭ������ش�ˮ�ס�����
��һʯ���������������֪���ж������������ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
           "enter" : __DIR__"dong2",
           "out" : __DIR__"dongkou",
           "up" : __DIR__"taijie",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

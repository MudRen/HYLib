//jinling  jiulou.c
inherit ROOM;

void create()
{
        set("short", "��¥");
        set("long", @LONG
�����ǽ�������һ����¥�ˣ���¥�������ػ��Ӱ���������ٳ�ķ��
�����۵ס������˰�������,Ҫ����С�ˣ����һ�������������£�������
Ӣ�ۣ����ǿ���Ƿ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"dongjie1",

]));
        set("objects", ([
		__DIR__"npc/waiter" : 1,
              __DIR__"npc/obj/songbing" : 1,
              __DIR__"npc/rascal" : 1,
]) );
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
//jinling  beijie2.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ����򱱱ߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�������ߣ��������ǵ��̣��ұ���һ�������꣬�ֵ�������������
һ�ɷ����ľ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"beijie1",
           "south" : __DIR__"zhongxin",
           "west" : __DIR__"dangpu",
           "east" : __DIR__"wuqidian",
]));
        set("objects", ([
              __DIR__"npc/stealer" : 1,
              __DIR__"npc/boy" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
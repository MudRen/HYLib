//jinling  beijie1.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ����򱱱ߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�������ߣ������������ţ��ұ���һ��Ǯׯ���ֵ�������������
һ�ɷ����ľ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"yuhuatai",
           "south" : __DIR__"beijie2",
           "west" : __DIR__"yamen",
           "east" : __DIR__"qianzhuang",
]));
        set("objects", ([
              __DIR__"npc/wulinren" : 1,
              __DIR__"npc/shangren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
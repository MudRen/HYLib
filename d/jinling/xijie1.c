//jinling  xijie1.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ��������ߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�����ţ��ֵ�������������һ�ɷ����ľ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"xijie2",
           "east" : __DIR__"zhongxin",
]));
        set("objects", ([
              __DIR__"npc/yiren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
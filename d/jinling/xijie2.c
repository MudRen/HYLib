//jinling  xijie2.c
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǽ��������ߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�����ţ��ֵ�������������һ�ɷ����ľ��󡣱��������һ�ҳ��
�̣�������һ����ҩ�̡�
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "west" : __DIR__"ximen",
           "east" : __DIR__"xijie1",
           "north" : __DIR__"duanchoupu",
           "south" : __DIR__"zhongyaopu",
]));
        set("objects", ([
              __DIR__"npc/yiren" : 1,
              __DIR__"npc/pizi" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
//jinling  nanjie2.c
inherit ROOM;

void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
�����ǽ������ϱߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�����ţ���������һ���������ֵ�������������һ�ɷ����ľ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"nanjie1",
           "south" : __DIR__"nanmen",
           "west" : __DIR__"fuzimiao",
   ]));
        set("objects", ([
              __DIR__"npc/shangren" : 1,
			]) );

 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
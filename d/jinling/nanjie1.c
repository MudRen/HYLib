//jinling  nanjie1.c
inherit ROOM;

void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
�����ǽ������ϱߵ���Ҫ�ֵ�������ͨ�����������ֵĹ㳡������
��ͨ�����ţ���������һ�һ��꣬�ֵ�������������һ�ɷ����ľ���
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"zhongxin",
           "south" : __DIR__"nanjie2",
           "west" : __DIR__"huadian",
           "east" : __DIR__"caifengdian",
   ]));
        set("objects", ([
              __DIR__"npc/girl" : 2,
              __DIR__"npc/bukuai" : 1,
			]) );

 set("outdoors", "jinling");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
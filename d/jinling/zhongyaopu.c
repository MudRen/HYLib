//jinling  zhongyaopu.c
inherit ROOM;

void create()
{
        set("short", "��ҩ��");
        set("long", @LONG
������һ����ҩ�̣����õ�����һ��ҩ���˱Ƕ��������㾫��Ϊ֮һ��
�����ҩƷ������ȫ�������Ĳ�ҩ��ƽ���Ĳ�ҩ��һ�����㡣�ϰ����
һ��ʥ�֣���Ҫ����ʲô��ʹ��֢������һ������
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "north" : __DIR__"xijie2",

]));
        set("objects", ([
		__DIR__"npc/yaoseller" : 1,
]) );

        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
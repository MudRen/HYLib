inherit ROOM;

void create()
{
        set("short", "�ݳ�����");
        set("long", @LONG
������Ǵ�����̨��������Ϸ�أ����������������һ��
�裬�úõ���һ��Ʊ�ѡ�̨����λ��Ա�䲻�����ǣ�����Ϸ��
��Ҳ���а����ۣ���������һ����żȻ�Ĳ����ʱ������ɢ��
LONG);

	set("outdoors", "zhongzhou");

        set("exits", ([
                "east" : __DIR__"xiyuan",
                "west" : __DIR__"huazhuang",    
	]));

        set("objects",([
                "/d/beijing/npc/guanzhong" : 2,
        ]));

        set("coor/x", -250);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

inherit ROOM;

void create()
{
        set("short", "ҩ����Ժ");
        set("long", @LONG
�������ҩ����Ժ����һ�߽����;���һ�����ˡ�ֻ��ʮ
��ֻ¯�Ӷ��ڰ�ҩ���м���ҩ�̵Ļ����æµ�š���Ҫ��ҩ��
����Ҫ����ҩ���ѷŽ�ҩ���
LONG);
        set("exits", ([
                "north" : __DIR__"yaopu",
                
        ]));

        set("coor/x", -220);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

// Room: tomb
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "��Ĺ�ڲ�");
	set("long", @LONG
�����ż�����ǰ�ߣ�Զ���ƺ�������֨֨�Ľ��������в��Ǻ����С����ڹ���̫��
��ֻ�ܿ���ģģ�����Ķ�����
LONG
	);
        

	set("exits", ([
		"southdown" : __DIR__"sec2",
		"north" : __DIR__"tomb"
			]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	

        set("no_clean_up", 0);
        

        setup();
        replace_program(ROOM);
}

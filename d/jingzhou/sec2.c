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
		"south" : __DIR__"sec3",
		"northup" : __DIR__"sec1"
			]));
//	set("objects", ([
//		CLASS_D("mingjiao") + "/zhangwuji" : 1,
//	]));

	

        set("no_clean_up", 0);
        

        setup();
        replace_program(ROOM);
}

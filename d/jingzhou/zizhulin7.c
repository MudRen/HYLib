// Room: zizhulin
// congw 980829
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ǰͻȻһ���������������һ������������ɵĻ�԰��xiaoyuan��
��ǰ������Ʈ�������㣬�������񻷱���˵������ʫ�黭�⡣��Լ��������
����Щ���ܡ�
LONG
	);
        set("outdoors", "jingzhou");

	set("exits", ([
	"north" : __DIR__"zizhulin6",
	"enter" : __DIR__"xiaoyuan",
	]));
        set("item_desc", ([
                "xiaoyuan": "������һ���ֻ��ĺõط�����Լ���Կ�����������������Ļ��ܣ���������������\n"
        ]) );


	setup();
	replace_program(ROOM);
}


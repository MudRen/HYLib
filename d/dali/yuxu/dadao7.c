// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "���");
	set("long", @LONG
���ڴ���ϣ����߶���������������·���������˲����ࡣ����͵��Ĵ�
�����ˡ�
LONG
	);
        set("outdoors", "����");
	set("exits", ([ 
            "west" : "/d/qingcheng/qcroad3",
	    "south" : __DIR__"dadao6",
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

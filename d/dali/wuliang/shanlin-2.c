// Modify By River 98/12
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��������Ƨ��ɽ���ˣ�������ɽ�µ�б��������ȥ��������һ
Ƭ��ѹѹ��ɭ���ˣ����ۼ�������һ���Ӿ��ӽ��˺����С�
LONG
	);
        set("outdoors", "����");
	set("exits", ([
            "eastup" : __DIR__"shanlin-3",
	    "west" : __DIR__"shanlin-1",
	]));

	setup();
	replace_program(ROOM);
}

// Room: /guiyun/jinship.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "�ٴ�");
	set("long", @LONG
��������ʹ��ս������������Ϸ���������ţ������
���Ѽ���������̰����һ����Ц��
LONG );
        set("outdoors", "guiyun");
//	set("no_clean_up", 0);

	set("exits", ([
		"out" : __DIR__"ship",
	]));
	set("objects", ([
		"/quest/menpaijob/taohua/guan" : 1,
	]));
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;
	
       if (  me->query("taohuajob") && dir == "out" )
        me->set("taohuajob",0);
	return ::valid_leave(me, dir);
}

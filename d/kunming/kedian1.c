// Room: /city/kedian2.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	string *order = ({"master1", "master2", "master3","master4","master5","master6","master7",
"master8","master9","master10","master11","master12","master13","master14","master15","master16"});
set("short", "�͵��¥");
	set("long", @LONG
�����ǿ͵�Ķ�¥���Ŵ�һ���ſ���һЩ����������˯��
���������죬�Ŵ����գ����λ谵���㲻��Ҳ��˯ɽ��һ����
LONG
	);
	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);
	set("exits", ([
		"eastdown" : __DIR__"kedian",
		
	]));
	setup();
	
}
int valid_leave(object me, string dir)
{
	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}

// /d/gaoli/jefang
// Room in ����
inherit ROOM;

void create()
{
	set("short", "�ͷ�");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ֻ�������ǽ���˼��Ŵ󴲣�������
���Ŵ���˯�����㣬�����Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���
������ŵ����˹�ȥ��
LONG
	);

	set("sleep_room", "1");
	set("no_fight", "1");
        set("hotel",1);

	set("exits", ([
        "down" : __DIR__"yingbinguan",
	]));

	setup();
}

int valid_leave(object ob,string dir)
{
   ob->delete_temp("rent_paid");
   return ::valid_leave(ob,dir);
}